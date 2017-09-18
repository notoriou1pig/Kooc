import sys
from cnorm import nodes
from copy import copy
from pyrser import parsing, meta
from cnorm.parsing.declaration import Declaration
from KoocMangling import KoocMangling

class KoocClassVar:
    def __init__(self, mod = None, v = "Variable", sym = "Symbol", t = []):
        self._module = mod
        self._var = v
        self._sym = sym
        self._type = t
        if t == []:
            self.resolveType()

    def getType(self):
        default = parsing.Node()
        default.node = nodes.Decl("Default")
        default.default = True
        if not self._type:
            return default
        return self._type[0]

    def resolveType(self):
        for c in self._module.getVarListFromSym(self._sym):
            self._type.append(c)

    def to_c(self):
        mangl = KoocMangling()
        type = self.getType()
        type.basename = self._sym
        type.value = self._sym
        type.member = True
        c = self._var
        c += "->"
        path = self._module.getVarPath(type)
        if path is None:
            type.node._name = self._sym
            err = "In class " + self._module.name
            err += " undefined reference to " + str(type.node.to_c())
            li = self._module.getVarListFromSym(self._sym)
            if li:
                err += "Candidates are :\n"
                for c in li:
                    c.node._name = c.basename
                    err += str(c.node.to_c())
            raise Exception(err)
        c += path
        return c
    
    def getModule(self):
        return self._module.name

    def getSymbol(self):
        return self._sym
