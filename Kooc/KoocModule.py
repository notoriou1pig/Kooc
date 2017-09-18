from cnorm import nodes
from copy import copy
from pyrser import meta
from cnorm.parsing.declaration import Declaration
from KoocMangling import KoocMangling

class KoocModule:
    def __init__(self, n = "data", file_name = "file_name", mangle = True) :
        self.name = n
        self.func = []
        self.var = []
        self._fileName = file_name
        self.mangling = mangle

    def add_node(self, ast):
        cpy = copy(ast)
        if isinstance(cpy.node._ctype, nodes.FuncType):
            self.func.append(cpy)
        else:
            self.var.append(cpy)

    def getVar(self):
        return self.var

    def getFunc(self):
        return self.func

    def getName(self):
        return self.name

    def getVarListFromSym(self, sym):
        res = []
        for v in self.var:
            if hasattr(v, 'node'):
                if hasattr(v.node, '_name'):
                    if v.node._name == sym:
                        res.append(v)
        return res

    def getFuncListFromSym(self, sym):
        res = []
        for v in self.func:
            if hasattr(v, 'node'):
                if hasattr(v.node, '_name'):
                    if v.node._name == sym:
                        res.append(v)
        return res

    def dumpAst(self):
        if hasattr(self, "ast"):
            print(self.ast)
        else:
            print("Nothing in")

    def to_c(self):
        mangl = KoocMangling()
        c_trans = "#if defined(__MODULE_" + self.name.upper() + \
                  "__) || defined(__" + self._fileName.upper() + "_FILE__)\n"
        c_trans += "#ifndef __MODULE_" + self.name.upper() + "_INC__\n"
        c_trans += "#define __MODULE_" + self.name.upper() + "_INC__\n\n"
        if not hasattr(self, "var"):
            print("Warning: Empty module", self.name)
            return (c_trans)
        for var in self.var:
            if self.mangling == True:
                var.node.ctype._storage = nodes.Storages.EXTERN
            if hasattr(var.node, "_assign_expr"):
                delattr(var.node, "_assign_expr")
            if self.mangling == True:
                c_trans += mangl.decorate(var, self.name)
            else:
                c_trans += str(var.node.to_c())
        for var in self.func:
            if self.mangling == True:
                c_trans += mangl.decorate(var, self.name)
            else:
                c_trans += str(var.node.to_c())
        c_trans += "\n#endif\n#endif\n\n"
        return c_trans
