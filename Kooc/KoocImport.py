from cnorm import nodes
from pyrser import meta
from cnorm.parsing.declaration import Declaration

class   KoocImport():
    inc_file = ""
    inc_module = ""
    def __init__(self, decl, name):
        self.inc_file = decl
        self.inc_module = name

    def to_c(self):
        ret = "#ifndef __"            \
            + self.inc_file.upper()   \
            + "_"                     \
            + self.inc_module.upper() \
            + "__"                    \
            + "\n"                    \
            + "#define __"            \
            + self.inc_file.upper()   \
            + "_"                     \
            + self.inc_module.upper() \
            + "__"                    \
            + "\n"                    \
            + "#include \""           \
            + self.inc_file           \
            + ".h\"\n"                \
            + "#endif /* __"          \
            + self.inc_file.upper()   \
            + "_"                     \
            + self.inc_module.upper() \
            + "__ */"                 \
            + "\n\n"
        return ret
