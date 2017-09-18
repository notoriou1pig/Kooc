#include <setjmp.h>
extern jmp_buf kooc_global_env;
#include <stdlib.h>
#include <stdio.h>
#include <setjmp.h>
#ifndef __IN3_MODULE_MOD__
#define __IN3_MODULE_MOD__
#include "in3.h"
#endif /* __IN3_MODULE_MOD__ */

#define __EXCEPTION_FILE__
#include "Exception.h"
jmp_buf kooc_global_env;
Exception *kooc_global_exception;
int KOOC_EXCEPTION_COUNT = 1;
int main()
{
    if (!(setjmp(kooc_global_env)))
        {
            return (0);
        }
    else
        {
            fprintf(stderr, "Process terminated by an unknown exception\n");
            return (EXIT_FAILURE);
        }
    return (EXIT_SUCCESS);
}
