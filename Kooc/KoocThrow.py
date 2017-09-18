


class   KoocThrow:

    def __init__(self, t, msg):
        self.type = t
        self.msg = msg

    def to_c(self):
        ret = "kooc_global_exception = " + self.type + "_new(" + self.msg + ");\n"
#        ret = "kooc_global_exception = " + self.type + "_new();\n"
        ret += "longjmp(kooc_global_env, V__" + self.type + "_i_id_V);\n"
        return ret
