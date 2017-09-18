import sys
from cnorm import nodes
from copy import copy
from pyrser import parsing, meta
from cnorm.parsing.declaration import Declaration
from KoocMangling import KoocMangling
import KoocModuleVar
import KoocModuleFunc
import KoocClassVar

class KoocClassFunc:
    def __init__(self, mod = None, v = "Variable", sym = "Symbol", t = []):
        self._module = mod
        self._var = v
        self._sym = sym
        self._type = t
        self._param = []

    def add_param(self, p):
        self._param.append(copy(p))

    def getType(self):
        default = parsing.Node()
        default.node = nodes.Decl("Default")
        default.default = True
        if not self._type:
            return default
        return self._type[0]

    def getSymbol(self):
        return self._sym

    def getModule(self):
        return self._module

    def noMatchError(self, func):
        func.node._name = self._sym
        err = "In class " + self._module.name
        err += " undefined reference to " + self._sym
        li = self._module.getFuncListFromSym(self._sym)
        if li:
            err += "\nCandidates are :\n"
            for c in li:
                c.node._name = c.basename
                err += str(c.node.to_c())
        raise Exception(err)

    def getAstForm(self):
        ret =  self.getType()
        func = parsing.Node()
        p_list = []
        for p in self._param:
            if isinstance(p.node, KoocModuleVar.KoocModuleVar) or \
                   isinstance(p.node, KoocClassVar.KoocClassVar) or \
                   isinstance(p.node, KoocClassFunc) or \
                   isinstance(p.node, KoocModuleFunc.KoocModuleFunc):
                p = p.node.getType()
                p_list.append(p.node)
            else:
                p_list.append(nodes.Decl('', p.node._ctype))
            p._name = ""
        func.node = nodes.Decl(self._sym,
                               nodes.FuncType(ret.node._ctype._identifier,
                                              p_list,
                                              ret.node._ctype._decltype))
        func.basename = self._sym
        func._name = self._sym
        func.member = True
        return func

    def raiseExcept(self):
        err = "In class " + self._module.name
        err += " undefined reference to " + str(self._sym) + "\n"
        li = self._module.getFuncListFromSym(self._sym)
        if li:
            err += "Candidates are :\n"
            for c in li:
                c.node._name = c.basename
                err += str(c.node.to_c())
        raise Exception(err)

    def formatParam(self, p):
        if isinstance(p.node, KoocModuleVar.KoocModuleVar) or \
                isinstance(p.node, KoocClassVar.KoocClassVar) or \
                isinstance(p.node, KoocModuleFunc.KoocModuleFunc):
            return p.node.to_c()
        if hasattr(p, 'value'):
            return p.value
        else:
            return "missing"

    def getGoodParam(self):
        res2 = ""
        res2Tmp = ""
        mangl = KoocMangling()
        funcList = self._module.getFuncListFromSym(self._sym)
        for func in funcList:
            funcTmp = func
            res1 = func.node._name
            res2Tmp = ""
            for funcParams in func.node._ctype._params:
                i = 0
                res2 = ""
                for param in self._param:
                    if i != 0:
                        res2 += ", "
                    else:
                        res2 += "((void *)"
                    res2Tmp = res2
                    res = ""
                    if isinstance(param.node, KoocClassVar.KoocClassVar): 
                        test = False
                        for val in param.node._type:
                            if funcParams._ctype._identifier == val.node._ctype._identifier:
                                res += self._var
                                res += "->"
                                path = self._module.getVarPath(val)
                                res += path
                                test = True
                                break
                        if test == True:
                            res2 += res
                        else:
                            break
                    elif isinstance(param.node, KoocClassFunc):
                        res2 += param.node.getGoodParam()
                    else:
                        res2 += param.value
                    i = 1
                if res == "":
                    break
            if res2 == res2Tmp:
                continue
            return funcTmp, res2 + ")"
        self.raiseExcept()

    def to_c(self):
        mangl = KoocMangling()
        func = self.getAstForm()
        path = self._module.getFuncPath(func, str(self._var + "->"))
        if path != None:
            c = path
            obj = parsing.Node()
            obj.node = nodes.Decl('')
            obj.value = self._var
            self._param.insert(0, obj)
            c += "((void *)"
            c += ", ".join(self.formatParam(p) for p in self._param)
        else:
            obj = parsing.Node()
            obj.node = nodes.Decl('')
            obj.value = self._var
            self._param.insert(0, obj)
            funcTmp, tmp = self.getGoodParam()
            path = self._module.getFuncPath(funcTmp, str(self._var + "->"))
            c = path + tmp
        if c[-1:] != ")":
            c += ")"
        return c


