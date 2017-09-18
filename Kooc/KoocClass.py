import cnorm
from cnorm import nodes
from pyrser import meta, parsing
from KoocModule import KoocModule
from cnorm.parsing.declaration import Declaration
from KoocMangling import KoocMangling
from os.path import splitext
from copy import deepcopy
from copy import copy
from OrderedDict import OrderedDict

class KoocClass(KoocModule):
    def __init__(self, filename, n, inherit, parser):
      self.name = n
      self.filename = splitext(filename)[0]
      self.func = []
      self.var = []
      self.inherit = []
      self.thunkFuncs = []
      self.thunkName = ""
      if inherit != None:
          self.inherit.append(inherit)
      self.parser = parser
      self.vtableFuncs = OrderedDict()
      self.vtableAccess = "func_table"
      self.initFuncName = "NULL"
      self.cleanFuncName = "NULL"
      self.implemented = False

    def add_node(self, ast):
        cpy = copy(ast)
        cpy.classname = self.name
        cpy.selfAdded = False
        if isinstance(cpy.node._ctype, nodes.FuncType):
            self.func.append(cpy)
        else:
            self.var.append(cpy)

    def fancyComments(self, comment):
        ret = "\n"
        ret += "/**********************************\n"
        ret += " ** " + comment + "\n"
        ret += " **********************************/\n\n"
        return ret

    def getVarPath(self, node):
        mangl = KoocMangling()
        mangl.decorate(node, "")
        for var in self.var:
            var.classname = self.name
            if not hasattr(var, "member"):
                continue
            mangl.decorate(var, "")
            if node.node._name == var.node._name:
                mangl.decorate(var, self.name)
                return var.node._name
        parent = self.getParent()
        if parent == []:
            return None
        i = 1
        for par in parent:
            ret = par.getVarPath(node)
            if ret != None:
                return "parent" + str(i) + "." + ret
            i = i + 1
        return None

    def getFuncPath2(self, node):
        mangl = KoocMangling()
        decorated = mangl.decorate(node, self.name)
        for func in self.func:
            func._name = ""
            func.classname = self.name
            if not hasattr(func, "member"):
                continue
            if not hasattr(func, "selfAdded"):
                func.selfAdded = False
            if func.selfAdded == True:
                if func.node._ctype._params:
                    func.node._ctype._params.pop(0)
                func.selfAdded = False
            tmp = mangl.decorate(func, self.name)
            if func.node._name == node.node._name:
                return func.node._name
        parent = self.getParent()
        if parent == []:
            return None
        for par in parent:
            tmp = par.getFuncPath2(node)
            if tmp != None:
                return tmp
        return None

    def getFuncPath(self, node, stick):
        mangle = KoocMangling()
        mangle.decorate(node, '')
        if node._name == "delete":
            return "((" + self.name + "_life *)" + stick + "life_table)->delete"
        if node._name == "clean":
            return "((" + self.name + "_life *)" + stick + "life_table)->clean"
        name = self.getFuncPath2(node)
        if name == None:
            return None
        ret = "((" + self.name + "_table *)" + stick
        if isinstance(self.vtableAccess, list):
            ret += self.vtableAccess[0]
        else:
            ret += self.vtableAccess
        ret += ")->" + name
        return ret

    def getVarListFromSym(self, name):
        ret = []
        for var in self.var:
            if not hasattr(var, "member"):
                continue
            varname = var.node._name
            if hasattr(var, "basename"):
                varname = var.basename
            if varname == name:
                ret.append(var)
        parent = self.getParent()
        if parent != []:
            for par in parent:
                ret = ret + par.getVarListFromSym(name)
        return ret

    def getFuncListFromSym(self, name):
        ret = []
        for func in self.func:
            if not hasattr(func, "member"):
                continue
            funcname = func.node._name
            if hasattr(func, "basename"):
                funcname = func.basename
            if funcname == name:
                ret.append(func)
        parent = self.getParent()
        if parent != []:
            for par in parent:
                ret = ret + par.getFuncListFromSym(name)
        return ret

    def generateTypedef(self):
      ret = "\ntypedef struct s_" + self.name + " " + self.name + ";\n\n"
      return ret

    def generateVtableInit(self):
        mangl = KoocMangling()
        ret = ""
        for funcname in self.vtableFuncs:
            func = self.vtableFuncs[funcname]
            ret += "\t((" + self.name + "_table *)"
            if isinstance(self.vtableAccess, list):
                ret += "(ret->" + self.vtableAccess[0] + "))->" + funcname
            else:
                ret += "(ret->" + self.vtableAccess + "))->" + funcname
            mangl.decorate(func, func.className)
            ret += " = &" + func.node._name + "_thunk" + self.name + ";\n"

        ret += "\t((" + self.name + "_life *)"
        ret += "(ret->life_table))->clean = "
        if self.cleanFuncName == "NULL":
            ret += "NULL;\n"
        else:
            ret += "&" + self.cleanFuncName + ";\n"

        ret += "\t((" + self.name + "_life *)"
        ret += "(ret->life_table))->delete = "
        ret += "&" + self.name + "_delete;\n"
        return ret;

    def concatList(self, list1, list2):
        if list1 != [] and list2 != []:
            for tmp2 in list2:
                isInList = False
                for tmp1 in list1:
                    if tmp1 == tmp2:
                        isInList = True
                if isInList == False:
                    list1.append(tmp2)
        return list1

    def getParentList(self, vtableAddr):
        ret = []
        parent = self.getParent()
        oldName = ""
        if parent != []:
            for par in parent:
                if oldName != "":
                    vtableAddr += " + sizeof(" + oldName + "_table)"
                if ret == [] or ret[-1] != vtableAddr:
                    ret.append(vtableAddr)
                oldName = par.name
                retTmp = par.getParentList(vtableAddr)
                ret = self.concatList(ret, retTmp)
        return ret

    def generateLifeParent(self, prev):
        ret = ""
        parent = self.getParent()
        if parent != []:
            i = 1
            for par in parent:
                tmp = prev + "parent" + str(i)
                ret += tmp + ".life_table = ret->life_table;\n"
                ret += par.generateLifeParent(tmp + ".")
                i = i + 1
        return ret

    def generateAllocFunc(self):
      ret = ""
      ret += self.name + " *" + self.name + "_alloc(void)\n"
      ret += "{\n"
      ret += "\t" + self.name + " *ret;\n"
      ret += "\tret = malloc(sizeof(*ret));\n"
      ret += "\tret->life_table = malloc(sizeof(" + self.name + "_life));\n"
      ret += "\t((" + self.name + "_life*)(ret->life_table))->base = ret;\n"
      ret += self.generateLifeParent("\tret->")
      if isinstance(self.vtableAccess, list):
          vtableAddr = "ret->" + self.vtableAccess[0]
      else:
          vtableAddr = "ret->" + self.vtableAccess
      ret += "\t" + vtableAddr + " = malloc(sizeof(" + self.name + "_table));\n"
      i = 0
      sizeof = self.getParentList(vtableAddr)
      if isinstance(self.vtableAccess, list):
          for p in self.vtableAccess:
              if i != 0:
                  ret += "\tret->" + p + " = " + sizeof[i] + ";\n"
              i = i + 1
      ret += self.generateVtableInit()
      ret += "\treturn (ret);\n"
      ret += "}\n\n"
      return ret;

    def generateDeleteFunc(self):
      ret = ""
      ret += "void " + self.name + "_delete(" + self.name + " *obj)\n"
      ret += "{\n"
      ret += "\tif ("
      ret += "((" + self.name + "_life *)(obj->life_table"
      ret += "))->clean != NULL"
      ret += ") {\n"
      ret += "\t\t((" + self.name + "_life *)(obj->life_table))->clean(obj);\n"
      ret += "\t}\n"
      if isinstance(self.vtableAccess, list):
          ret += "\tfree(obj->" + self.vtableAccess[0] + ");\n"
      else:
          ret += "\tfree(obj->" + self.vtableAccess + ");\n"
      ret += "\tfree(obj->life_table);\n"
      ret += "\tfree(obj);\n"
      ret += "}\n\n"
      return ret

    def generateNewFunc(self):
        initFunc = None
        ret = ""
        n_params = 0
        for key in self.vtableFuncs:
            func = self.vtableFuncs[key]
            if func.basename == "init":
                initFunc = func
            if func.basename == "clean":
                cleanFunc = func
                self.cleanFuncName = func.node._name
        if self.initFuncName == "NULL":
            ret += self.name + " *" + self.name + "_new(void);\n"
        else:
            # create new func
            backupParams = initFunc.node._ctype._params
            backupName = initFunc.node._name
            backupIdentifier = initFunc.node._ctype._identifier
            backupDeclType = initFunc.node._ctype._decltype
            params = deepcopy(backupParams)
            i = 0
            for param in params:
                param._name = "p_" + str(i)
                i += 1
            n_params = i
            backupName = initFunc.node._name
            initFunc.node._name = self.name + "_new"
            initFunc.node._ctype._params = params
            initFunc.node._ctype._identifier = self.name
            initFunc.node._ctype._decltype = cnorm.nodes.PointerType()
            test = str(initFunc.node.to_c())
            ret += test
            initFunc.node._name = backupName
            initFunc.node._ctype._params = backupParams
            initFunc.node._ctype._identifier = backupIdentifier
            initFunc.node._ctype._decltype = backupDeclType
            # removing the last ';'
        ret = ret[:-2]
        ret += "\n"
        ret += "{\n"
        ret += "\t" + self.name + " *self;\n"
        ret += "\tself = " + self.name + "_alloc();\n"
        if self.initFuncName != "NULL":
            ret += "\t" + self.initFuncName + "((void *)self"
            for i in range(0, n_params):
                ret += ", p_" + str(i)
            ret += ");\n"
        ret += "\treturn (self);\n"
        ret += "}\n\n"
        return ret
  
    def generateDefaultFuncsImpl(self):
      self.generateFuncList()
      self.generateVTableFuncs()
      self.generateDefaultFuncs()
      self.checkInheritException()
      ret = "#include <stdlib.h>\n\n"
      # alloc
      ret += self.generateAllocFunc()
      # delete
      ret += self.generateDeleteFunc()
      # new
      ret += self.generateNewFunc()
      # clean
      return ret


    def getParent(self):
        parent = []
        for _class in self.parser._class:
            for inParent in self.inherit:
                if _class.name == inParent:
                    parent.append(_class)
        return parent

    def generateParentVTableFuncs(self):
        if (not hasattr(self, 'inherit')) or self.inherit == []:
            return OrderedDict()
        parent = self.getParent()
        if parent == []:
            raise Exception("couldn't find class '" + self.inherit[0] + "'.")
        ret = None
        for inhe in self.inherit:
            notFound = True
            for par in parent:
                if par.name == inhe:
                    par.generateVTableFuncs()
                    if ret == None:
                        ret = par.vtableFuncs
                    else:
                        ret.merge(par.vtableFuncs)
                    notFound = False
            if notFound == True:
                raise Exception("couldn't find class '" + inhe + "'.")
        return ret

    def generateVTableFuncs(self):
        mangl = KoocMangling()
        self.vtableFuncs = self.generateParentVTableFuncs()
        for func in self.func:
            if (not hasattr(func, "member")) or func.member != True:
                continue
            if hasattr(func, "selfAdded") and func.selfAdded == True:
                if func.node._ctype._params:
                    func.node._ctype._params.pop(0)
                func.selfAdded = False
            mangl.decorate(func, func.className)
            name = func.node._name
            self.vtableFuncs[name] = func
            mangl.decorate(func, "")
            name = func.node._name
            if (func.virtual == True) or (name in self.vtableFuncs):
                self.vtableFuncs[name] = func

    def generateVTableAll(self):
      ret = "typedef struct s_" + self.name + "_table {\n"
      ret += self.generateVTable()
      ret += "} " + self.name + "_table;\n\n"
      return ret

    def generateLifeTable(self):
      ret = "typedef struct s_" + self.name + "_life {\n"
      ret += "\tvoid *base;\n"
      ret += "\tvoid (*delete)(" + self.name + " *);\n"
      ret += "\tvoid (*clean)(" + self.name + " *);\n"
      ret += "} " + self.name + "_life;\n\n"
      return ret

    def generateParentFuncList(self):
        parent = self.getParent()
        if parent == []:
            raise Exception("couldn't find class '" + self.inherit[0] + "'.")
        ret = []
        for par in parent:
            ret.append(par.generateFuncList())
        return ret

    def generateFuncList(self):
        funcList = []
        for var in self.func:
            if (not hasattr(var, "member")) or var.member != True:
                continue
            var.className = self.name
            funcList.append(var)
        if hasattr(self, 'inherit') and self.inherit != []:
            funcList = funcList + self.generateParentFuncList()
        return funcList

    def generateVTable(self, scopename = None):
        mangl = KoocMangling()
        ret = ""
        funcList = self.vtableFuncs
        addedFuncs = []
        for varname in funcList:
            var = self.vtableFuncs[varname]
            virtualName = ""
            if (not hasattr(var, "member")) or var.member != True:
                continue
            if type(var.node._ctype) != cnorm.nodes.FuncType:
                continue
            if hasattr(var, "selfAdded") and var.selfAdded == True:
                if var.node._ctype._params:
                    var.node._ctype._params.pop(0)
                var.selfAdded = False
            if var.virtual == True:
                mangl.decorate(var, "")
                virtualName = var.node._name
                if virtualName in addedFuncs:
                    continue
            var.node._name = varname
            if var.node._name in addedFuncs:
                continue
            addedFuncs.append(var.node._name)
            backup = var.node
            #creating temp node for func pointers
            tmp = cnorm.nodes.Decl(var.node._name)
            tmp._ctype._identifier = var.node._ctype._identifier
            tmp._ctype._decltype = cnorm.nodes.PointerType()
            tmp._ctype._decltype._decltype = cnorm.nodes.ParenType()
            tmp._ctype._decltype._decltype._decltype = var.node._ctype._decltype
            params = var.node._ctype._params
            thunk = parsing.Node()
            thunk.node = None
            thunk.basename = var.basename
            thunk.member = True
            # adding self argument to member functions
            if (not hasattr(var, "selfAdded")) or var.selfAdded != True:
                if (len(params) == 1) and (params[0]._name == '')   \
                    and (params[0]._ctype._identifier == 'void')    \
                    and (params[0]._ctype._decltype == None):
                    if params:
                        params.pop()
                thunk_params = deepcopy(params)
                selfParam = cnorm.nodes.Decl("")
                selfParam._ctype = cnorm.nodes.PrimaryType(var.className)
                selfParam._ctype._decltype = cnorm.nodes.PointerType()
                params.insert(0, selfParam)
                var.selfAdded = True
                thunkParam = cnorm.nodes.Decl("")
                thunkParam._ctype = cnorm.nodes.PrimaryType(self.name)
                thunkParam._name = self.thunkName
                thunkParam._value = self.thunkName
                thunkParam._ctype._decltype = cnorm.nodes.PointerType()
                thunk_params.insert(0, thunkParam)
                f = nodes.FuncType(var.node._ctype._identifier,
                                  thunk_params,
                                  var.node._ctype._decltype)
                thunk.node = nodes.Decl(var.node._name + "_thunk" +
                                        self.name, f)
                thunk.classname = var.classname
                self.thunkFuncs.append(thunk)
                i = 0
                for p in thunk_params :
                    if i > 0 :
                        p._name = "p" + str(i)
                        p._value = "p" + str(i)
                    i = i + 1
            tmp._ctype._decltype._decltype._params = params
            var.node = tmp
            ret += "\t" + str(var.node.to_c())
            var.node = backup
        return ret

    def generateThunkFuncs(self):
        res = ""
        for t in self.thunkFuncs:
            res += str(t.node.to_c())
        return res

    def generateStruct(self):
        mangl = KoocMangling()
        ret = "struct s_" + self.name + " {\n"
        if self.inherit == []:
            ret += "\tvoid *func_table;\n\n"
        else:
            i = 1
            for inhe in self.inherit:
                ret += "\t" + inhe + " parent" + str(i) + ";\n"
                i = i + 1
            ret += "\n"
        ret += "\tvoid *life_table;\n\n"
        for var in self.var:
            if not hasattr(var, "member"):
                continue
            if hasattr(var.node, "_assign_expr"):
                raise Exception("'Error ! you can't initialize a member variable in @class.\nPlease do it in @implementation\n")
            ret += "\t" + mangl.decorate(var, self.name)
        ret += "};\n\n"
        return ret

    def generateMemberFunc(self):
        mangl = KoocMangling()
        ret = ""
        for var in self.func:
            if not hasattr(var, "member"):
                continue
            if type(var.node._ctype) != cnorm.nodes.FuncType:
                continue
            if hasattr(var, "selfAdded") and var.selfAdded == True:
                if var.node._ctype._params:
                    var.node._ctype._params.pop(0)
                var.selfAdded = False
            mangl.decorate(var, self.name)
            params = var.node._ctype._params
            if (not hasattr(var, "selfAdded")) or var.selfAdded != True:
                if (len(params) == 1) and (params[0]._name == '')   \
                    and (params[0]._ctype._identifier == 'void')    \
                    and (params[0]._ctype._decltype == None):
                    if params:
                        params.pop()
                selfParam = cnorm.nodes.Decl("")
                selfParam._ctype = cnorm.nodes.PrimaryType(self.name)
                selfParam._ctype._decltype = cnorm.nodes.PointerType()
                params.insert(0, selfParam)
                var.selfAdded = True
            ret += str(var.node.to_c())
        ret += "\n"
        return ret

    def generateNonMember(self):
      mangl = KoocMangling()
      ret = ""
      for var in self.func:
        if hasattr(var, "member") and var.member == True:
          continue
        ret += mangl.decorate(var, self.name)
      for var in self.var:
        if hasattr(var, "member") and var.member == True:
            continue
        if hasattr(var.node, "_assign_expr"):
            delattr(var.node, "_assign_expr")
        var.node.ctype._storage = nodes.Storages.EXTERN
        ret += mangl.decorate(var, self.name)
      ret += "\n"
      return ret

    def generateThunkFuncsImpl(self):
        mangl = KoocMangling()
        res = ""
        func_name = ""
        self.thunkName = "thunk"
        self.generateVTable()
        ptr = ""
        for t in self.thunkFuncs:
            func_name = str(t.node.to_c())
            func_name = func_name[:-2]
            t.node._ctype._params.pop(0)
            mangl.decorate(t, t.classname)
            res += func_name + "\n{"
            ptr = "("
            ptr += "((" + self.name + " *)"
            ptr += "((" + self.name + "_life *)"
            ptr += self.thunkName + "->life_table)"
            ptr += "->base)"
            path = self.getPathParent(t.classname)
            if path:
                ptr += "->" + path[1:]
                ptr = "&" + ptr
            ptr += ")"
            res += """
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( """ + ptr + """ ), "r" ( """
            res += t.node._name.split("_thunk")[0]
            res += """ )
            : "%rdi"
            );
            """
            res += "\n}\n\n"
            if t.node._ctype._params:
                t.node._ctype._params.pop()
        self.thunkName = ""
        return res

    def getPathParent(self, name):
        path = ""
        i = 1
        parent = self.getParent()
        if self.name == name:
            return ""
        for p in parent:
            if p.name == name:
                path = ".parent" + str(i)
                break
            else:
                path = p.getPathParent(name)
                if path:
                    return ".parent" + str(i) + path
            i = i + 1
        return path

    def generateDefaultFuncs(self):
      mangl = KoocMangling()
      initFunc = None
      cleanFunc = None
      ret = self.name + " *" + self.name + "_alloc(void);\n"
      ret += "void " + self.name + "_delete(" + self.name + " *);\n"
      for key in self.vtableFuncs:
          func = self.vtableFuncs[key]
          if func.basename == "init":
              initFunc = func
          if func.basename == "clean":
              cleanFunc = func
              self.cleanFuncName = func.node._name
      if initFunc != None:
          mangl.decorate(initFunc, initFunc.classname)
          self.initFuncName = initFunc.node._name
      if initFunc == None:
          ret += self.name + " *" + self.name + "_new(void);\n"
      else:
          # create new func
          backupName = initFunc.node._name
          backupIdentifier = initFunc.node._ctype._identifier
          backupDeclType = initFunc.node._ctype._decltype
          initFunc.node._name = self.name + "_new"
          if hasattr(initFunc, "selfAdded") and initFunc.selfAdded == True:
              if initFunc.node._ctype._params:
                  initFunc.node._ctype._params.pop(0)
              initFunc.selfAdded = False
          initFunc.node._ctype._identifier = self.name
          initFunc.node._ctype._decltype = cnorm.nodes.PointerType()
          ret += str(initFunc.node.to_c())
          initFunc.node._name = backupName
          initFunc.node._ctype._identifier = backupIdentifier
          initFunc.node._ctype._decltype = backupDeclType
      return ret

    def getFuncFromName(self, name):
        for func in self.func:
            if func.node._name == name:
                return func
        return None

    def checkVirtualInList(self, parentFuncs):
        mangl = KoocMangling()
        for Func in parentFuncs:
            if isinstance(Func, list):
                self.checkVirtualInList(Func)
            else:
                mangl.decorate(Func, Func.className)
                func = self.getFuncFromName(Func.basename)
                if func == None:
                    continue

    def checkVirtualInheritance(self):
        parentFuncs = self.generateParentFuncList()
        self.checkVirtualInList(parentFuncs)

    def isHeir(self, class_):
        for _cl in class_.inherit:
            if _cl == self.name:
                return True
            parent = []
            for _class in self.parser._class:
                for inParent in class_.inherit:
                    if _class.name == inParent:
                        parent.append(_class)
                        break
            if parent == []:
                return False
            for par in parent:
                if self.isHeir(par) == True:
                    return True
        return False

    def generateIFDEF(self):
        ret = "#if defined(__" + self.filename.upper() + "_MODULE_" \
            + self.name.upper() + "__)"
        ret += " || defined(__" + self.filename.upper() + "_FILE__)"
        for _class in self.parser._class:
            if _class.inherit != []:
                if self.isHeir(_class):
                    ret += " || defined(__" + self.filename.upper() + "_MODULE_" \
                        + _class.name.upper() + "__)"
        ret += "\n"
        ret += "# ifndef __" + self.filename.upper() + "_MODULE_"   \
            + self.name.upper() + "_INC__\n"
        ret += "#  define __" + self.filename.upper() + "_MODULE_"  \
            + self.name.upper() + "_INC__\n\n"
        return ret

    def generateENDIF(self):
        ret = "\n# endif"
        ret += "\n#endif\n"
        return ret

    def addInherit(self, inherit = ""):
        self.inherit.append(inherit)

    def setVTableAccess(self):
        parent = self.getParent()
        if parent != []:
            self.vtableAccess = []
            i = 1
            for par in parent:
                if isinstance(par.vtableAccess, list):
                    for p in par.vtableAccess:
                        self.vtableAccess.append("parent" + str(i) + "." + p)
                else:
                    self.vtableAccess.append("parent" + str(i) + "." + par.vtableAccess)
                i = i + 1

    def checkInheritException(self):
      if not (self.name == "Exception" or \
          (len(self.inherit) == 1 and self.inherit[0] == "Exception")):
        parents = self.getParent()
        for p in parents:
          if "Exception" in p.inherit:
            raise Exception("Class " + self.name + \
                " : You must inherit directly from Exception class")

    def to_c(self):

        self.checkInheritException()

        ret = ""
        if self.inherit != []:
            self.checkVirtualInheritance()
        self.generateFuncList()
        self.generateVTableFuncs()
        ret += self.generateIFDEF()
        ret += self.fancyComments("class " + self.name)
        ret += self.generateTypedef()
        ret += self.fancyComments("class " + self.name + " vtable")
        ret += self.generateVTableAll()
        ret += self.fancyComments("class " + self.name + " life cycle")
        ret += self.generateLifeTable()
        ret += self.fancyComments("class " + self.name + " struct")
        ret += self.generateStruct()
        ret += self.fancyComments("class " + self.name + " members")
        ret += self.generateMemberFunc()
        ret += self.generateDefaultFuncs()
        ret += self.fancyComments("class " + self.name + " thunk functions")
        ret += self.generateThunkFuncs()
        ret += self.fancyComments("class " + self.name + " non-members")
        ret += self.generateNonMember()
        ret += self.generateENDIF()
        return ret
