import os
import sys
from copy import copy
from pyrser.grammar import Grammar
from pyrser import parsing,meta
from cnorm import nodes
from cnorm.parsing.declaration import Declaration
from KoocImport import KoocImport
from KoocImplementation import KoocImplementation
import KoocModuleVar
import KoocModuleFunc
import KoocClassVar
import KoocClassFunc
from KoocHeader import KoocHeader
from KoocFuncDecorator import KoocFuncDecorator
from KoocTryCatch import *
from KoocThrow import KoocThrow

class KoocDecl(Declaration, Grammar):
    entry = "kooc_declaration"
    grammar = """
 kooc_declaration ::= translation_unit:_
                #kooc_decorate_main(_)
                      ;

 declaration ::= ';' // garbage single comma
               | c_decl
               | preproc_decl
               | asm_decl
               | kooc_decl
               ;

 kooc_decl ::= import
             | kooc_implementation
             ;

 import ::= "@import" [ module_inc:decl | file_inc:decl ]:decl
            #end_decl(current_block, decl)
            ;

 module_inc ::= '"' Base.id:mod_name '"'
                "from" '"'
                Base.id:decl
                ".kh" '"'
                #set_import(_, decl, mod_name)
                ;

 file_inc ::= '"'
              Base.id:decl
              ".kh" '"'
              #set_import(_, decl, "file")
              ;

 kooc_implementation ::= "@implementation" Base.id:name '{'
                         #set_implementation(_, name)
                         #handle_scope(_, 1)
                         member_decl*
                         #handle_scope(_, 2)
                         '}'
                         #end_decl(current_block, _)
                         ;

 member_decl ::=  "@member" '{' #setMember implementation_decl* '}' #unsetMember
                | "@member" #setMember implementation_decl #unsetMember
                | implementation_decl
                ;
                
 implementation_decl ::= "":local_specifier
            #create_ctype(local_specifier)
            declaration_specifier*:dsp
            init_declarator:decl
            #not_empty(current_block, dsp, decl)
            #end_impl(decl)
            #var(decl)
          [
            ';' |
             compound_statement:b
             #add_body(decl, b)
          ]
          ;

 c_decl ::= "":local_specifier
            #create_ctype(local_specifier)
            declaration_specifier*:dsp
            init_declarator:decl
            #not_empty(current_block, dsp, decl)
            #end_decl(current_block, decl)
            #var(decl)
          [ ',' 
            #copy_ctype(local_specifier, decl)
            init_declarator:decl
            #end_decl(current_block, decl)
          ]*
          [
            ';' #protoTypeCheck(decl)
          |
             compound_statement:b
             #add_body(decl, b)
          ]
          ;

 compound_statement ::=
            [
            '{' "":current_block
                #new_blockstmt(_, current_block)
                #handle_scope(_, 1)
                [
                    line_of_code
                ]*
                #handle_scope(_, 2)
            '}'
            ]
            ;


 kooc_call ::= kooc_class_var:_
             | kooc_mod_var:_
             | kooc_class_func:_
             | kooc_mod_func:_ 
             ;


 expression_statement ::= Statement.expression_statement:_
                          ;

 assignement_expression ::= Expression.assignement_expression:_
                        | kooc_call:_ 
                         [
                         assign_op:op
                         assignement_expression:param
                         #new_binary(_, op, param)
                         ]*
                         ;

 kooc_mod_var ::= [ kooc_type:_ ]?
              '[' Base.id:mod '.' Base.id:sym ']' #set_mod_var(_, mod, sym)
              ;

 kooc_class_var ::= [ kooc_type:_ ]?
              '[' Base.id:var "->" Base.id:sym ']' #set_class_var(_, var, sym)
              ;

 kooc_mod_func ::= [ kooc_type:_ ]?
                   '[' Base.id:mod Base.id:sym #set_mod_func(_, mod, sym)
                   [ kooc_param:p #set_call_param(_, p) ]* ']'
                   ;

 kooc_class_func ::= [ kooc_type:_ ]?
                     '['
                      [
                       Base.id:mod Base.id:sym ':' Base.id:var
                       #set_class_func(_, var, sym, mod)
                       |
                       Base.id:var Base.id:sym #set_class_func(_, var, sym)
                      ]
                      [ kooc_param:p #set_call_param(_, p) ]*
                     ']'
                     ;

 kooc_param ::= ':' [ kooc_call:_
                |
                [
                  [ kooc_type:type ]?:type
                  primary_expression:_ #set_param_type(_, type)
                ]]
                ;

 kooc_type ::= "!@("
                "":type
                "":local_specifier #create_ctype(local_specifier)
                Base.id:natural #new_decl_spec(local_specifier, natural, _)
                declarator:type ")"
                #set_kooc_type(_, type)
                 ;

////
//BEGIN TRY CATCH
////

cnorm_labeled_statement ::=
        rootidentifier:id
            [
            #check_stmt(id, "if") if_statement:_
            | #check_stmt(id, "for") for_statement:_
            | #check_stmt(id, "while") while_statement:_
            | #check_stmt(id, "switch") switch_statement:_
            | #check_stmt(id, "do") do_statement:_
            | #check_stmt(id, "return") return_statement:_
            | #check_stmt(id, "goto") goto_statement:_
            | #check_stmt(id, "case") case_statement:_
            | #check_stmt(id, "break") ';' #new_break(_)
            | #check_stmt(id, "continue") ';' #new_continue(_)
            | ':' #new_label(_, id)
            ]
        ;

labeled_statement ::=
        cnorm_labeled_statement:_ | KoocTryCatch:_ | KoocThrow:_
        ;

KoocThrow ::=   "@throw"
                '('
                @ignore('null')
                [
                KoocExceptionType:type
                ' '*
                '*'
                ' '*
                ]
                ')'
                '('
                KoocMessage:msg
                ')'
                ';'
                #add_kooc_throw(_, type, msg)
        ;


KoocMessage ::= Base.string
        ;


KoocTryCatch ::=
        "@try"
        compound_statement:kooc_try_bloc
        #new_KoocTry(_, kooc_try_bloc)
        KoocCatchBloc*
        #end_KoocTryCatch(_)
        ;

KoocCatchBloc ::=
        "@catch"
        '('
        @ignore('null')
        [
        KoocExceptionType:type
        ' '*
        '*'
        ' '*
        KoocExceptionName:name
        ]
        ')'
        #add_catch_exception(type, name)
        compound_statement:bloc
        #new_KoocCatch(_, type, name, bloc)
        ;

KoocExceptionType ::=
        Base.id
        ;

KoocExceptionName ::=
        Base.id
        ;
/////
//END TRY CATCH
 """

    _module = []
    _class = []
    _proto = []
    _obj = []
    _scope = 0
    obj = True
    member = False

    def getModule(self):
        return self._module

    def getClass(self):
        return self._module

    def getProto(self):
        return self._proto

    def after_parse(self, res):
        return res.node

    def cleanup(self):
        if self._module :
            self._module = []
        if self._class :
            self._class = []
        if self._proto :
            self._proto = []
        if self._obj :
            self._obj = []
        self._scope = 0
        self.obj = True
        self.member = False


@meta.hook(KoocDecl)
def add_catch_exception(self, t, name):
    var = Declaration().parse("int *" + name.value + ";").body[0]
    var._ctype._identifier = t.value
    self._obj.append(var)
    return True

@meta.hook(KoocDecl)
def protoTypeCheck(self, ast):
    if type(ast.node._ctype).__name__ == "FuncType":
        self._proto.append(ast.node)
    return True

@meta.hook(KoocDecl)
def set_import(self, ast, decl, name):
    if hasattr(name, "value"):
        name = "module_" + name.value
    ast.node = KoocImport(decl.value, name)
    if os.path.exists(decl.value + ".kh") == False:
        raise Exception("Error : " + decl.value + ".kh" + 
                        " no such file or directory.")
    if os.stat(decl.value + ".kh")[6] == 0:
        print("Warning :", decl.value, ".kh is empty.")
    else:
        inc_parse = KoocHeader(decl.value)
        b_proto = self._proto
        b_module = self._module
        b_class = self._class
        inc_parse.cleanup()
        inc_parse.parse_file(decl.value + ".kh")
        b_proto.extend(inc_parse.getProto())
        self._proto = b_proto
        b_module.extend(inc_parse.getModule())
        self._module = b_module
        b_class.extend(inc_parse.getClass())
        self._class = b_class
    return True

@meta.hook(KoocDecl)
def set_implementation(self, ast, name):
    ast.node = KoocImplementation(name.value, self._module, self._class)
    ptr = nodes.Decl("self")
    ptr.ctype._identifier = name.value
    ptr.ctype.push(nodes.PointerType())
    self._obj.append(ptr)
    self._current = ast.node
    return True    

@meta.hook(KoocDecl)
def setMember(self):
    self.member = True
    return True
    
@meta.hook(KoocDecl)
def unsetMember(self):
    self.member = False
    return True

@meta.hook(KoocDecl)
def end_impl(self, ast):
    self._current.add_node(ast, self.member)
    return True                                

@meta.hook(KoocDecl)
def handle_scope(self, ast, io):
    if io == 1:
        self._scope += 1
    else:
        self._scope -= 1
    if self._scope == 0:
        del self._obj[0:]
    return True

@meta.hook(KoocDecl)
def var(self, decl):
    if hasattr(decl, 'node'):
        self._obj.append(copy(decl.node))
    return True

@meta.hook(KoocDecl)
def register_kooc_obj(self, ast):
    if hasattr(ast, 'node'):
        self._obj.append(copy(ast.node))
    return True

@meta.hook(Declaration)
def add_param(self, lspec, param):
    lspec.cur_paren[-1]()._params.append(param.node)
    if hasattr(self, '_scope'):
        if self._scope == 0:
            if hasattr(param, 'node'):
                self._obj.append(copy(param.node))
    return True

@meta.hook(KoocDecl)
def set_mod_var(self, ast, mod, sym):
    module = None
    for m in self._module:
        if m.name == mod.value:
            module = m
    if module is None:
        print("Undefined reference to [", mod.value, ".", sym.value, "]")
        return False
    if hasattr(ast, 'type'):
        ast.node = KoocModuleVar.KoocModuleVar(module,
                                               sym.value,
                                               [ast.type])
        delattr(ast, 'type')
    else:
        ast.node = KoocModuleVar.KoocModuleVar(module, sym.value, [])
    return True

@meta.hook(KoocDecl)
def set_class_var(self, ast, var, sym):
    module_name = "None"
    module = None
    for c in self._obj:
        if isKoocDecl(c, var.value):
            module_name = moduleFromExprStmt(c)
        if isSelfPointer(c, var.value):
            module_name = c._ctype._identifier
        if isScopeParam(c, var.value):
            module_name = c._ctype._identifier
    for m in self._class:
        if m.name == module_name:
            module = m
    if module is None:
        print("Undefined reference to [", var.value, "->", sym.value, "]")
        return False
    if hasattr(ast, 'type'):
        ast.node = KoocClassVar.KoocClassVar(module,
                                             var.value,
                                             sym.value,
                                             [ast.type])
        delattr(ast, 'type')
    else:
        ast.node = KoocClassVar.KoocClassVar(module,
                                             var.value,
                                             sym.value,
                                             [])
    return True

def isScopeParam(obj, name):
    if hasattr(obj, '_name'):
        if obj._name == name:
            return True
    return False

def isSelfPointer(obj, name):
    if name != "self":
        return False
    if obj._name != "self":
        return False
    return True

def isKoocDecl(expr, mod):
    if not isinstance(expr, nodes.ExprStmt):
        return False
    if hasattr(expr.expr, 'params'):
        if hasattr(expr.expr.params[0], 'params'):
            if hasattr(expr.expr.params[0].params[-1], 'value'):
                if expr.expr.params[0].params[-1].value == mod:
                    return True
    return False

def moduleFromExprStmt(s):
    if not isinstance(s, nodes.ExprStmt):
        return ""
    return s.expr.params[-1].getModule()

@meta.hook(KoocDecl)
def set_kooc_type(self, ast, val):
    ast.type = copy(val)
    return True

@meta.hook(KoocDecl)
def set_mod_func(self, ast, mod, sym):
    if hasattr(ast, 'type'):
        ast.node = KoocModuleFunc.KoocModuleFunc(mod.value,
                                                 sym.value, [ast.type])
        delattr(ast, 'type')
    else:
        ast.node = KoocModuleFunc.KoocModuleFunc(mod.value, sym.value, [])
    return True


@meta.hook(KoocDecl)
def set_class_func(self, ast, var = "Var", sym = "Sym", module_name = "None"):
    module = None
    if hasattr(module_name, 'value'):
        module_name = module_name.value
    if module_name == "None":
        for c in self._obj:
            if isKoocDecl(c, var.value):
                module_name = moduleFromExprStmt(c)
            if isSelfPointer(c, var.value):
                module_name = c._ctype._identifier
            if isScopeParam(c, var.value):
                module_name = c._ctype._identifier
    if module_name == "None":
        return False
    for m in self._class:
        if m.name == module_name:
            module = m
    if module is None:
        print("Undefined reference to class", module_name)
        return False
    if hasattr(ast, 'type'):
        ast.node = KoocClassFunc.KoocClassFunc(module,
                                               var.value,
                                               sym.value,
                                               [ast.type])
        delattr(ast, 'type')
    else:
        ast.node = KoocClassFunc.KoocClassFunc(module,
                                               var.value,
                                               sym.value,
                                               [])
    return True


@meta.hook(KoocDecl)
def set_call_param(self, ast, val):
    val._name = ""
    ast.node.add_param(val)
    return True

@meta.hook(KoocDecl)
def set_param_type(self, ast, t):
    if hasattr(t, 'type'):
        if hasattr(t.type, 'node'):
            ast.node._ctype = copy(t.type.node._ctype)
    else:
        ast.node._ctype = nodes.Decl('')._ctype
    return True


#####
# BEGIN Parsing Try Catch
#####

@meta.hook(KoocDecl)
def new_KoocTry(self, ast, kooc_try_bloc):
    setattr(self, 'koocTryCatch', KoocTryCatch(kooc_try_bloc.node))
    return True

@meta.hook(KoocDecl)
def new_KoocCatch(self, ast, kooc_type, kooc_name, kooc_bloc):
    if hasattr(self, 'koocTryCatch'):
        self.koocTryCatch.addCatch(kooc_type.value, kooc_name.value, kooc_bloc.node)
    return True

@meta.hook(KoocDecl)
def end_KoocTryCatch(self, ast):
    if hasattr(self, 'koocTryCatch'):
        ast.node = self.koocTryCatch
        delattr(self, 'koocTryCatch')
    return True

                
@meta.hook(KoocDecl)
def add_kooc_throw(self, ast, t, msg):
    ast.node = KoocThrow(t.value, msg.value)
    return True


@meta.hook(KoocDecl)
def kooc_decorate_main(self, ast):
    ast.node = KoocFuncDecorator.decorateMain(ast.node)
    ast.node = KoocFuncDecorator.addExtern(ast.node)
    return True

#####
# END Parsing Try Catch
#####
