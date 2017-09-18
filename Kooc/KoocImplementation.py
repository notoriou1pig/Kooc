import sys
from cnorm import nodes
from copy import copy
from pyrser import meta
from cnorm.parsing.declaration import Declaration
from KoocMangling import KoocMangling

class KoocImplementation:
    def __init__(self, name, modlist = [], classlist = []) :
        self.name = name
        self.findTheModule(modlist, classlist)
        self.mangl = KoocMangling()

    def findTheModule(self, modlist, classlist):
        for module in modlist:
            if module.getName() == self.name:
                self.item = module
                self.module = True
                return
        for class_ in classlist:
            if class_.getName() == self.name:
                self.item = class_
                self.class_ = True
                return
        raise Exception("Error: Undefined reference to " + self.name + " item.")

    def checkMatch(self, prototype):
        for func in self.item.func:
            if prototype == self.mangl.getMangledPrototype(func, self.name):
                return True
        return False

    def checkRedefinition(self, prototype):
        if not hasattr(self, "ast"):
            return True
        for func in self.ast:            
            if prototype == self.mangl.getMangledPrototype(func, self.name):
                return False
        return True
    
    def add_node(self, ast, member):
        cpy = copy(ast)
        if member == True:
            cpy.member = True
            if len(cpy.node._ctype._params) != 0 and cpy.node._ctype._params[0]._name == '' and cpy.node._ctype._params[0]._ctype._identifier == 'void':
                del cpy.node._ctype._params[0]
        prototype = self.mangl.getMangledPrototype(cpy, self.name)
        if self.checkMatch(prototype) == False:
            raise Exception("error: " + cpy.node._name + "' doesn't match any object in " + self.name)
        if self.checkRedefinition(prototype) == False:
            raise Exception("error: redefinition of '" + cpy.node._name + "' in " + self.name)
        if hasattr(self, "ast"):
            self.ast.append(cpy)
        else:
            self.ast = [cpy]

    def dumpAst(self):
        if hasattr(self, "ast"):
            print(self.ast)
        else:
            print("Nothing in")

    def to_c(self):
        c_trans = ""
        for var in self.item.var:
            if hasattr(var, "member") and var.member == True:
                continue
            c_trans += self.mangl.decorate(var, self.name)
        c_trans += "\n"
        if (hasattr(self, "ast")):
            for func in self.ast:
                self.mangl.decorate(func, self.name)
                if hasattr(func, "member"):
                    selfParam = nodes.Decl("self")
                    selfParam._ctype = nodes.PrimaryType(self.name)
                    selfParam._ctype._decltype = nodes.PointerType()
                    func.node._ctype._params.insert(0, selfParam)
                c_trans += str(func.node.to_c()) + "\n"
        if (hasattr(self.item, "implemented") == True) and \
               (self.item.implemented != True):
            c_trans += self.item.generateDefaultFuncsImpl()
            c_trans += self.item.generateThunkFuncsImpl()
        return c_trans
