from cnorm import nodes
from cnorm.nodes import *
from cnorm.parsing.declaration import Declaration


class           KoocFuncDecorator():



    @staticmethod
    def addExtern(ast: RootBlockStmt) -> RootBlockStmt:

        ast.body.insert(0, Declaration().parse("#include <setjmp.h>\n").body[0])
        
        var = Declaration().parse("extern int kooc_global_env;").body[0]
        var._ctype._identifier = "jmp_buf"
        ast.body.insert(1, var)

        return ast






    @staticmethod
    def handleMainBody(main: Decl) -> Decl:

        contentMain = Declaration().parse("""
        {
                if (!(setjmp(kooc_global_env)))
                        {}
                else
                {
                        fprintf(stderr, \"Process terminated by an unknown exception\\n\");
                        return (EXIT_FAILURE);
                }
                return (EXIT_SUCCESS);
        }
        """).body[0].body

        contentMain.body[0].thencond = main.body
        main.body = contentMain

        return main




    @staticmethod
    def addIncludes(ast: RootBlockStmt) -> RootBlockStmt:
        ast.body.insert(0, Declaration().parse("#include <stdlib.h>\n").body[0])
        ast.body.insert(1, Declaration().parse("#include <stdio.h>\n").body[0])
        ast.body.insert(2, Declaration().parse("#include <setjmp.h>\n").body[0])
        return ast



    @staticmethod
    def addGlobalesVariables(ast: RootBlockStmt, pos: int) -> RootBlockStmt:

        ast.body.insert(pos, Declaration().parse("#define __EXCEPTION_FILE__\n").body[0])
        ast.body.insert(pos+1, Declaration().parse("#include \"Exception.h\"\n").body[0])

        tmp = Declaration().parse("int kooc_global_env;\n").body[0]
        tmp._ctype._identifier = "jmp_buf"
        ast.body.insert(pos+2, tmp)

        tmp2 = Declaration().parse("int *kooc_global_exception;\n").body[0]
        tmp2._ctype._identifier = "Exception"
        ast.body.insert(pos+3, tmp2)

        ast.body.insert(pos+4, Declaration().parse("int KOOC_EXCEPTION_COUNT = 1;").body[0])

        return ast




    @staticmethod
    def decorateMain(ast: RootBlockStmt) -> RootBlockStmt:
        
        positionMain = -1

        for i in range(0, len(ast.body)):
            elem = ast.body[i]

            if hasattr(elem, "_ctype") and elem._ctype.__class__ == FuncType and hasattr(elem, "_name") and elem._name == "main" and hasattr(elem, "body"):
                positionMain = i


        #####
        # Check if the implementation of the main function was found
        #####
        if positionMain != -1:

            #####
            # Handle the main content
            #####
            ast.body[positionMain] = KoocFuncDecorator.handleMainBody(ast.body[positionMain])

            #####
            # Add the globales exceptions variables
            #####
            ast = KoocFuncDecorator.addGlobalesVariables(ast, positionMain)

            #####
            # Add the includes
            #####
            ast = KoocFuncDecorator.addIncludes(ast)

        return ast
