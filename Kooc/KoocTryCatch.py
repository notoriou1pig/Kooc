from cnorm import nodes
from pyrser import meta
from cnorm.parsing.declaration import Declaration
import cnorm.passes.to_c



class KoocTryCatch:
    def __repr__(self):
        return "KoocTry(" + repr(self.body) + ")"
    def __init__(self, kooc_try_bloc):
        self.body = kooc_try_bloc
        self.catchBlocs = []
    def addCatch(self, kooc_type, kooc_name, kooc_bloc):
        self.catchBlocs.append(KoocCatch(kooc_type, kooc_name, kooc_bloc))



    def to_c(self):

        ret = "jmp_buf\tkooc_local_env;\n"
        ret += "#include <string.h>\n"
        ret += "memcpy(&kooc_local_env, &kooc_global_env, sizeof(jmp_buf));\n"
        ret += "int\tkooc_local_ret;\n\n"

        ret += "if (!(kooc_local_ret = setjmp(kooc_global_env)))\n"
        ret += str(self.body.to_c())

        ret += "else\n"
        ret += "{\n"
        
        ret += "\t#include <string.h>\n"
        ret += "\tmemcpy(&kooc_global_env, &kooc_local_env, sizeof(jmp_buf));\n"


        firstIf = True
        doneCatch = False
        for catch in self.catchBlocs:
            if firstIf == True:
                ret += "\tif (kooc_local_ret == V__" + catch.type + "_i_id_V)\n"
                firstIf = False
            else:
                ret += "\telse if (kooc_local_ret == V__" + catch.type + "_i_id_V)\n"
            doneCatch = True
            ret += catch.to_c()


        if doneCatch == True:
            ret += "\telse\n"
            ret += "\t{\n"
            ret += "\t\tlongjmp(kooc_global_env, kooc_local_ret);\n"
            ret += "\t}\n"
        else:
            ret += "\tlongjmp(kooc_global_env, kooc_local_ret);\n"

        ret += "}\n"

        return ret




class KoocCatch:
    def __repr__(self):
        return "KoocCatch(" + repr(self.body) + ")"
    def __init__(self, kooc_catch_type, kooc_catch_name, kooc_catch_bloc):
        self.type = kooc_catch_type
        self.name = kooc_catch_name
        self.body = kooc_catch_bloc
        

        var = Declaration().parse("int *" + self.name + " = (" + self.type + "*)kooc_global_exception;").body[0]
        var._ctype._identifier = self.type
        self.body.body.insert(0, var)


    def to_c(self):
 
        ret = str(self.body.to_c())

        return ret
