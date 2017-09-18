#include <setjmp.h>
extern jmp_buf kooc_global_env;
#include <stdlib.h>
#include <stdio.h>
#include <setjmp.h>
#ifndef __IN17_MODULE_TOTO__
#define __IN17_MODULE_TOTO__
#include "in17.h"
#endif /* __IN17_MODULE_TOTO__ */

#ifndef __IN17_MODULE_TEST__
#define __IN17_MODULE_TEST__
#include "in17.h"
#endif /* __IN17_MODULE_TEST__ */


int F__M_Toto_i_funcb_i_i_i_F(Toto *self, int a, int b, int c)
{
    self->V__M_Toto_c_i_V = a;
    return (a + b + c);
}

#include <stdlib.h>

Toto *Toto_alloc(void)
{
	Toto *ret;
	ret = malloc(sizeof(*ret));
	ret->life_table = malloc(sizeof(Toto_life));
	((Toto_life*)(ret->life_table))->base = ret;
	ret->func_table = malloc(sizeof(Toto_table));
	((Toto_table *)(ret->func_table))->F__M_Toto_i_funcb_i_i_i_F = &F__M_Toto_i_funcb_i_i_i_F_thunkToto;
	((Toto_life *)(ret->life_table))->clean = NULL;
	((Toto_life *)(ret->life_table))->delete = &Toto_delete;
	return (ret);
}

void Toto_delete(Toto *obj)
{
	if (((Toto_life *)(obj->life_table))->clean != NULL) {
		((Toto_life *)(obj->life_table))->clean(obj);
	}
	free(obj->func_table);
	free(obj->life_table);
	free(obj);
}

Toto *Toto_new(void)
{
	Toto *self;
	self = Toto_alloc();
	return (self);
}

int F__M_Toto_i_funcb_i_i_i_F_thunkToto(Toto *thunk, int p1, int p2, int p3)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( (((Toto *)((Toto_life *)thunk->life_table)->base)) ), "r" ( F__M_Toto_i_funcb_i_i_i_F )
            : "%rdi"
            );
            
}

char V__Test_c_i_V;

#define __EXCEPTION_FILE__
#include "Exception.h"
jmp_buf kooc_global_env;
Exception *kooc_global_exception;
int KOOC_EXCEPTION_COUNT = 1;
int main()
{
    if (!(setjmp(kooc_global_env)))
        {
            Toto *to = Toto_new();
            to->V__M_Toto_c_i_V = 42;
            V__Test_c_i_V = 'a';
            return (0);
        }
    else
        {
            fprintf(stderr, "Process terminated by an unknown exception\n");
            return (EXIT_FAILURE);
        }
    return (EXIT_SUCCESS);
}
