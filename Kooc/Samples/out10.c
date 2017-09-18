#include <setjmp.h>
extern jmp_buf kooc_global_env;
#include <stdlib.h>
#include <stdio.h>
#include <setjmp.h>
#ifndef __IN10_FILE__
#define __IN10_FILE__
#include "in10.h"
#endif /* __IN10_FILE__ */

int V__klauss_i_a_V;
double V__klauss_d_d_V = 79.2;
char **V__klauss_ppc_tab_V;
char *V__klauss_pc_str_V = "dump !";
int V__klauss_pi_tab_V[3] = { 1, 2, 3 };

void F__M_klauss_v_my_putchar_c_F(klauss *self, char c)
{
    write(1, &c, 1);
}

void F__klauss_v_my_putchar_c_F(char c)
{
    write(1, &c, 1);
}

#include <stdlib.h>

klauss *klauss_alloc(void)
{
	klauss *ret;
	ret = malloc(sizeof(*ret));
	ret->life_table = malloc(sizeof(klauss_life));
	((klauss_life*)(ret->life_table))->base = ret;
	ret->func_table = malloc(sizeof(klauss_table));
	((klauss_table *)(ret->func_table))->F__M_klauss_v_my_putchar_c_F = &F__M_klauss_v_my_putchar_c_F_thunkklauss;
	((klauss_life *)(ret->life_table))->clean = NULL;
	((klauss_life *)(ret->life_table))->delete = &klauss_delete;
	return (ret);
}

void klauss_delete(klauss *obj)
{
	if (((klauss_life *)(obj->life_table))->clean != NULL) {
		((klauss_life *)(obj->life_table))->clean(obj);
	}
	free(obj->func_table);
	free(obj->life_table);
	free(obj);
}

klauss *klauss_new(void)
{
	klauss *self;
	self = klauss_alloc();
	return (self);
}

void F__M_klauss_v_my_putchar_c_F_thunkklauss(klauss *thunk, char p1)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( (((klauss *)((klauss_life *)thunk->life_table)->base)) ), "r" ( F__M_klauss_v_my_putchar_c_F )
            : "%rdi"
            );
            
}

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
