from cnorm import nodes
from pyrser import meta
from cnorm.parsing.declaration import Declaration
from cnorm.parsing.expression import Idset
from KoocModule import KoocModule
from KoocClass import KoocClass
from KoocImport import KoocImport
from KoocExceptionHeader import KoocExceptionHeader
from pyrser.grammar import Grammar
import os
import sys

class KoocHeader(Declaration, Grammar):
    entry = "kooc_declaration"
    grammar = """
 kooc_declaration ::=
                        translation_unit:_
                      ;

 declaration ::= ';' // garbage single comma 
               | c_decl
               | preproc_decl
               | asm_decl
               | kooc_head
                 ;

 kooc_head ::= import
             | module
             | class
             | class_inherit
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

 module ::= "@module " Base.id:name '{'
             #set_module(_, name)
             module_decl* '}'
             #end_decl(current_block, _)
             ;

 module_decl ::= "":local_specifier
            #create_ctype(local_specifier)
            declaration_specifier*:dsp
            init_declarator:decl
            #not_empty(current_block, dsp, decl)
            #module_decl(decl)
          [ ',' 
            #copy_ctype(local_specifier, decl)
            init_declarator:decl
            #module_decl(decl)
          ]*
          [
            ';' | Statement.compound_statement:b
             #add_body(decl, b)
          ]
          ;

 class ::= "@class" Base.id:name '{'
             #set_class(_, name, "")
             [standalone_virtual | standalone_virtual_block | member_block
                | member | class_decl]* '}'
             #end_decl(current_block, _)
             ;

 class_inherit ::= "@class" Base.id:name ':' Base.id:inherit
             #set_class(_, name, inherit)
             [',' Base.id:inherit #set_new_inherit(_, inherit)]*
             '{' #set_vtable_path
             [standalone_virtual | standalone_virtual_block | member_block
                | member | class_decl]* '}'
             #end_decl(current_block, _)
             ;

 class_decl ::= "":local_specifier
            #create_ctype(local_specifier)
            declaration_specifier*:dsp
            init_declarator:decl
            #not_empty(current_block, dsp, decl)
            #class_decl(decl)
          [ ','
            #copy_ctype(local_specifier, decl)
            init_declarator:decl
            #class_decl(decl)
          ]*
          [
            ';' | Statement.compound_statement:b
             #add_body(decl, b)
          ]
          ;

 member_block ::= "@member" '{'
             [member_decl | virtual_block | virtual]*
             '}'
             ;

 member ::= "@member"
             [member_decl | virtual_block | virtual]
             ;

 virtual ::= "@virtual" #set_virtual member_decl #end_virtual ;

 standalone_virtual ::= "@virtual" #set_virtual member_decl #end_virtual ;

 virtual_block ::= "@virtual" '{' #set_virtual
                    member_decl*
                  '}' #end_virtual
                  ;

 standalone_virtual_block ::= "@virtual" '{' #set_virtual
                    member_decl*
                  '}' #end_virtual
                  ;

 member_decl ::= "":local_specifier
            #create_ctype(local_specifier)
            declaration_specifier*:dsp
            init_declarator:decl
            #not_empty(current_block, dsp, decl)
            #member_decl(decl)
          [ ','
            #copy_ctype(local_specifier, decl)
            init_declarator:decl
            #member_decl(decl)
          ]*
          [
            ';' | Statement.compound_statement:b
             #add_body(decl, b)
          ]
          ;

 c_decl ::= "":local_specifier
            #create_ctype(local_specifier)
            declaration_specifier*:dsp
            init_declarator:decl
            #not_empty(current_block, dsp, decl)
            #garbage_decl(decl)
          [ ',' 
            #copy_ctype(local_specifier, decl)
            init_declarator:decl
            #garbage_decl(decl)
          ]*
          [
            ';' #protoTypeCheck(decl)
          |  Statement.compound_statement:b
             #add_body(decl, b)
          ]
          ;

 """
    def __init__(self, filename):
        super().__init__()
        self.filename = filename.split('/')[-1]
        self._garbage = None

    _module = []
    _class = []
    _proto = []
    _virtual = False

    def getModule(self):
        return self._module

    def getClass(self):
        return self._class

    def getProto(self):
        return self._proto

    def after_parse(self, res):
        if self._garbage != None:
            res.node.body.insert(0, self._garbage)
        return res.node

    def cleanup(self):
        if self._module :
            self._module = []
        if self._class :
            self._class = []
        if self._proto :
            self._proto = []
        self._virtual = False


@meta.hook(KoocHeader)
def garbage_decl(self, ast):
    if self._garbage == None:
        self._garbage = KoocModule("garbage", self.filename, False)
    self._garbage.add_node(ast)
    return True

@meta.hook(KoocHeader)
def set_module(self, ast, name):
    ast.node = KoocModule(name.value, self.filename)
    self._module.append(ast.node)
    return True

@meta.hook(KoocHeader)
def module_decl(self, ast):
    self._module[-1].add_node(ast)
    return True

@meta.hook(KoocHeader)
def set_class(self, ast, name, inherit):
    for obj in self._class:
        if hasattr(name, "value") and obj.name == name.value:
            return False
    if inherit == "":
        ast.node = KoocClass(self.filename, name.value, None, self)
    elif inherit.value == "Exception":
      ast.node = KoocExceptionHeader(self.filename, name.value, inherit.value, self)
    else:
        ast.node = KoocClass(self.filename, name.value, inherit.value, self)
    self._class.append(ast.node)
    Idset[name.value] = "type"
    return True

@meta.hook(KoocHeader)
def set_new_inherit(self, ast, inherit):
    self._class[-1].addInherit(inherit.value)
    return True

@meta.hook(KoocHeader)
def set_vtable_path(self):
    self._class[-1].setVTableAccess()
    return True

@meta.hook(KoocHeader)
def class_decl(self, ast):
    self._class[-1].add_node(ast)
    return True

@meta.hook(KoocHeader)
def member_decl(self, ast):
    ast.virtual = self._virtual
    ast.member = True
    self._class[-1].add_node(ast)
    return True

@meta.hook(KoocHeader)
def set_virtual(self):
  self._virtual = True
  self._virtual = True
  return True

@meta.hook(KoocHeader)
def end_virtual(self):
  self._virtual = False
  return True

@meta.hook(KoocHeader)
def protoTypeCheck(self, ast):
    if type(ast.node._ctype).__name__ == "FuncType":
        self._proto.append(ast.node)
    return True

@meta.hook(KoocHeader)
def set_import(self, ast, decl, name):
    if hasattr(name, "value"):
        name = "module_" + name.value
    ast.node = KoocImport(decl.value, name)
    if os.path.exists(decl.value + ".kh") == False:
        raise Exception("Error :" + decl.value +
                        ".kh" + " no such file or directory")
    if os.stat(decl.value + ".kh")[6] == 0:
        print("Warning : " + decl.value + ".kh" + " is empty.")
    else:
        inc_parse = KoocHeader(decl.value)
        b_module = self._module
        b_class = self._class
        inc_parse.cleanup()
        inc_parse.parse_file(decl.value + ".kh")
        for mod in inc_parse.getModule():
            ok = True
            for mod2 in b_module:
                if mod.name == mod2.name:
                    ok = False
            if ok == True:
                b_module.append(mod)
        self._module = b_module
        for clas in inc_parse.getClass():
            ok = True
            for clas2  in b_class:
                if clas.name == clas2.name:
                    ok = False
            if ok == True:
                b_class.append(clas)
        self._class = b_class
    return True
