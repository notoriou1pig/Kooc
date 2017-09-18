#!/usr/bin/env python3

from cnorm import nodes
from cnorm.parsing.declaration import Declaration

class KoocMangling:
    def decorate(self, var, scope_name = ""):
        self.name = scope_name
        if hasattr(var, "basename"):
          var.node._name = var.basename
        else:
          var.basename = var.node._name
        var.mangled = True
        if isinstance(var.node._ctype, nodes.FuncType):
            return self._decorate_func(var)
        elif isinstance(var.node._ctype, nodes.PrimaryType):
            return self._decorate_var(var)
        else:
            return ""
        
    def getMangledPrototype(self, var, scope_name = ""):
        if hasattr(var, "basename"):
          var.node._name = var.basename
        else:
          var.basename = var.node._name
        name = "F__"
        if hasattr(var, 'member') and var.member == True:
            name += "M_"
        name += scope_name
        name += "_"
        name += self.decorate_type(var.node)
        name += "_"
        name += var.node._name
        if hasattr(var.node._ctype, "params"):
            name += self._decorate_param(var.node._ctype.params)
        name += "_F"
        return (name)

    def _decorate_var(self, var):
        name = "V__"
        if hasattr(var, 'member') and var.member == True:
            name += "M_"
        name += self.name
        name += "_"
        name += self.decorate_type(var.node)
        name += "_"
        name += var.node._name
        name += "_V"
        var.node._name = name
        return (str(var.node.to_c()))

    def _decorate_func(self, var):
        name = "F__"
        if hasattr(var, 'member') and var.member == True:
            name += "M_"
        name += self.name
        name += "_"
        name += self.decorate_type(var.node)
        name += "_"
        name += var.node._name
        name += self._decorate_param(var.node._ctype.params)
        name += "_F"
        var.node._name = name
        return (str(var.node.to_c()))

    def _decorate_param(self, var):
        name = ""
        for p in var :
            # not decorating void param
            if p._name == '' and p._ctype._identifier == 'void' \
                and p._ctype._decltype == None:
                  continue
            name += "_"
            name += self.decorate_type(p)
        return name

    def decorate_type(self, var):
        m = self._get_function_pointer(var)
        if not m == "":
            return m
        m = self._get_pointer(var._ctype)
        m += self._get_tab(var._ctype)
        m += self._get_spec(var._ctype)
        m += self._get_sign(var._ctype)
        m += self._get_qual(var._ctype)
        m += var._ctype._identifier[0]
        return m

    def _get_function_pointer(self, obj):
        r = ""
        li = obj._ctype.link()
        while li != None:
            if hasattr(li, "_decltype") and \
                   isinstance(li._decltype, nodes.ParenType) :
                r += "pF_"
                r += obj._ctype._identifier[0] + "_"
                r += obj._name
                r += self._decorate_param(li._decltype.params)
                r += "_F"
            li = li.link()
        return r

    def _get_pointer(self, obj):
        r = ""
        li = obj.link()
        while li != None:
            if isinstance(li, nodes.PointerType):
                r += "p"
            if isinstance(li, nodes.QualType) and li._qualifier != None:
                if li._qualifier == nodes.Qualifiers.CONST:
                    r += "C"
                if li._qualifier == nodes.Qualifiers.VOLATILE:
                    r += "V"
            li = li.link()
        return r

    def _get_tab(self, obj):
        r = ""
        li = obj.link()
        while li != None :
            if isinstance(li, nodes.ArrayType):
              r += "p"  
            li = li.link()
        return r

    def _get_spec(self, obj):
        if obj._specifier == nodes.Specifiers.LONG:
            return "l"
        elif obj._specifier == nodes.Specifiers.LONGLONG:
            return "ll"
        elif obj._specifier == nodes.Specifiers.SHORT:
            return "s"
        else:
            return ""

    def _get_sign(self, obj):
        if hasattr(obj, '_sign') and obj._sign != nodes.Signs.AUTO:
            if obj._sign == nodes.Signs.SIGNED:
                return "S"
        return ""

    def _get_qual(self, obj):
        li = obj.link()
        r = ""
        while li != None:
            if isinstance(li, nodes.QualType):
                if li._decltype == None and \
                       li._qualifier == nodes.Qualifiers.CONST:
                    r += "C"
                if li._decltype == None and \
                    li._qualifier == nodes.Qualifiers.VOLATILE:
                    r += "V"
            li = li.link()
        return r
                                                                                            
                        
