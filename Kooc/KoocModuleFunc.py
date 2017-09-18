import sys
from cnorm import nodes
from copy import copy
from pyrser import parsing, meta
from cnorm.parsing.declaration import Declaration
from KoocMangling import KoocMangling
import KoocModuleVar
import KoocClassVar
import KoocClassFunc

class KoocModuleFunc:
    def __init__(self, val = "Module", sym = "Symbol", t = []):
        self._module = val
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

    def genParam(self):
        c_str = ""
        for p in self._param:
            c_str += "_"
            if isinstance(p.node,  KoocModuleVar.KoocModuleVar) or \
                   isinstance(p.node, KoocClassVar.KoocClassVar) or \
                   isinstance(p.node, KoocClassFunc.KoocClassFunc):
                c_str += self.decorateType(p.node.getType())
            else:
                c_str += self.decorateType(p.node)
        return c_str
    
    def to_c(self):
        if self._sym == "new":
            c_str = self._module + "_" + self._sym;
        else:
            c_str = "F__" + self._module + "_"
            c_str += self.decorateType(self.getType())
            c_str += "_" + self._sym
            c_str += self.genParam()
            c_str += "_F"
        c_str += "("
        c_str += ", ".join(p.node.to_c() for p in self._param)
        c_str += ")"
        return c_str
