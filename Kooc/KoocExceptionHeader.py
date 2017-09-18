from cnorm.parsing.declaration import Declaration
from pyrser.parsing import Node

from KoocClass import KoocClass
from KoocMangling import KoocMangling

class           KoocExceptionHeader(KoocClass):

    def __init__(self, filename, n, inherit, parser):
        super().__init__(filename, n, inherit, parser)
        n = Node()
        n.value = "id"
        n.node = Declaration().parse("int id;").body[0]
        self.add_node(n)
        




    def generateGlobales(self):
        ret = "extern int KOOC_EXCEPTION_COUNT;\n\n"
        ret += "#include <setjmp.h>\n"
        ret += "extern jmp_buf kooc_global_env;\n\n"
        ret += "extern Exception *kooc_global_exception;\n\n\n"
        return ret




    def generateIdInitialiser(self):
        ret = "void " + self.name + "_INIT_ID(void) __attribute__((constructor));\n\n"
        return ret




    def generateDefaultFuncsImpl(self):
        ret = super().generateDefaultFuncsImpl()

        ret += "void " + self.name + "_INIT_ID(void)\n"
        ret += "{\n"
        ret += "\tV__" + self.name + "_i_id_V = KOOC_EXCEPTION_COUNT;\n"

        ret += "\tKOOC_EXCEPTION_COUNT++;\n"
        ret += "}\n\n"

        return ret




    def to_c(self):
        tmp = (super().to_c())[:-(len(super().generateENDIF()))]
        tmp += super().fancyComments("Globales variables for Exceptions")
        tmp += self.generateGlobales()
        tmp += super().fancyComments("Initialisation Id Exception")
        tmp += self.generateIdInitialiser()
        tmp += super().generateENDIF()
        return tmp
