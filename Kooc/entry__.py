#!/usr/bin/env python3.3

import os
import sys
from KoocDecl import KoocDecl
from KoocHeader import KoocHeader
from cnorm.passes import to_c
from pyrser import fmt, error

class main:
    def entry(arg, print_debug, current):
        if current[1] == "kc":
            cparse = KoocDecl()
        else:
            cparse = KoocHeader(arg[:-3])
        cparse.cleanup()
        try:
            if os.stat(arg)[6] == 0:
                print("Warning : " + arg + " is empty, skipping.")
                return ""
        except IOError:
            print("File not found :", arg)
            sys.exit(0)
        ast = None
        try:
            ast = cparse.parse_file(arg)
        except error.ParseError as err:
            print("Syntax error :",
                  current[0]+"."+current[1],
                  "line", err.error_position.lineno,
                  "near", err.error_line)
            # raise err
            return ""
        except Exception as err:
            print(current[0]+"."+current[1] + ":", err)
            raise err
            return ""
        try:
            ret = ast.to_c()
        except Exception as err:
            raise err
            print(current[0]+"."+current[1], err)
            return ""
        return ret
