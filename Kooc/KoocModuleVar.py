import sys
from cnorm import nodes
from copy import copy
from pyrser import parsing, meta
from cnorm.parsing.declaration import Declaration
from KoocMangling import KoocMangling

class KoocModuleVar:
    def __init__(self, val = None, sym = "Symbol", t = []):
        self._module = val
        self._sym = sym
        self._type = t
        if not t :
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

    def decorateType(self, t):
        mangl = KoocMangling()
        c = ""
        if hasattr(t, 'node'):
            c += mangl.decorate_type(t.node)
        elif hasattr(t, '_ctype'):
            c += mangl.decorate_type(t)
        else:
            c += "i"
        return c
        
    def to_c(self):
        c = "V__" + self._module.name + "_"
        c += self.decorateType(self.getType())
        c += "_" + self._sym;
        c += "_V"
        return c
    
    def getModule(self):
        return self._module.name

    def getSymbol(self):
        return self._sym

    def resolve(self):
        return self._type
