#include <setjmp.h>
extern jmp_buf kooc_global_env;
#include <stdlib.h>
#include <stdio.h>
#include <setjmp.h>
#ifndef __IN21_FILE__
#define __IN21_FILE__
#include "in21.h"
#endif /* __IN21_FILE__ */


int F__M_klaus_i_my_putchar_F(klaus *self)
{
}

int F__M_klaus_i_my_putchar2_F(klaus *self)
{
}

#include <stdlib.h>

klaus *klaus_alloc(void)
{
	klaus *ret;
	ret = malloc(sizeof(*ret));
	ret->life_table = malloc(sizeof(klaus_life));
	((klaus_life*)(ret->life_table))->base = ret;
	ret->func_table = malloc(sizeof(klaus_table));
	((klaus_table *)(ret->func_table))->F__M_klaus_i_my_putchar_F = &F__M_klaus_i_my_putchar_F_thunkklaus;
	((klaus_table *)(ret->func_table))->F__M_klaus_i_my_putchar2_F = &F__M_klaus_i_my_putchar2_F_thunkklaus;
	((klaus_life *)(ret->life_table))->clean = NULL;
	((klaus_life *)(ret->life_table))->delete = &klaus_delete;
	return (ret);
}

void klaus_delete(klaus *obj)
{
	if (((klaus_life *)(obj->life_table))->clean != NULL) {
		((klaus_life *)(obj->life_table))->clean(obj);
	}
	free(obj->func_table);
	free(obj->life_table);
	free(obj);
}

klaus *klaus_new(void)
{
	klaus *self;
	self = klaus_alloc();
	return (self);
}

int F__M_klaus_i_my_putchar_F_thunkklaus(klaus *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( (((klaus *)((klaus_life *)thunk->life_table)->base)) ), "r" ( F__M_klaus_i_my_putchar_F )
            : "%rdi"
            );
            
}

int F__M_klaus_i_my_putchar2_F_thunkklaus(klaus *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( (((klaus *)((klaus_life *)thunk->life_table)->base)) ), "r" ( F__M_klaus_i_my_putchar2_F )
            : "%rdi"
            );
            
}

#define __EXCEPTION_FILE__
#include "Exception.h"
jmp_buf kooc_global_env;
Exception *kooc_global_exception;
int KOOC_EXCEPTION_COUNT = 1;
int main(void)
{
    if (!(setjmp(kooc_global_env)))
        {
            return 0;
        }
    else
        {
            fprintf(stderr, "Process terminated by an unknown exception\n");
            return (EXIT_FAILURE);
        }
    return (EXIT_SUCCESS);
}
