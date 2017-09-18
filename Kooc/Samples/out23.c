#include <setjmp.h>
extern jmp_buf kooc_global_env;
#include <stdlib.h>
#include <stdio.h>
#include <setjmp.h>
#include <stdio.h>
#ifndef __IN23_FILE__
#define __IN23_FILE__
#include "in23.h"
#endif /* __IN23_FILE__ */


#include <stdlib.h>

Parent1 *Parent1_alloc(void)
{
	Parent1 *ret;
	ret = malloc(sizeof(*ret));
	ret->life_table = malloc(sizeof(Parent1_life));
	((Parent1_life*)(ret->life_table))->base = ret;
	ret->func_table = malloc(sizeof(Parent1_table));
	((Parent1_life *)(ret->life_table))->clean = NULL;
	((Parent1_life *)(ret->life_table))->delete = &Parent1_delete;
	return (ret);
}

void Parent1_delete(Parent1 *obj)
{
	if (((Parent1_life *)(obj->life_table))->clean != NULL) {
		((Parent1_life *)(obj->life_table))->clean(obj);
	}
	free(obj->func_table);
	free(obj->life_table);
	free(obj);
}

Parent1 *Parent1_new(void)
{
	Parent1 *self;
	self = Parent1_alloc();
	return (self);
}


int F__M_Parent2_i_test_F(Parent2 *self)
{
    return (42);
}

#include <stdlib.h>

Parent2 *Parent2_alloc(void)
{
	Parent2 *ret;
	ret = malloc(sizeof(*ret));
	ret->life_table = malloc(sizeof(Parent2_life));
	((Parent2_life*)(ret->life_table))->base = ret;
	ret->func_table = malloc(sizeof(Parent2_table));
	((Parent2_table *)(ret->func_table))->F__M_Parent2_i_test_F = &F__M_Parent2_i_test_F_thunkParent2;
	((Parent2_life *)(ret->life_table))->clean = NULL;
	((Parent2_life *)(ret->life_table))->delete = &Parent2_delete;
	return (ret);
}

void Parent2_delete(Parent2 *obj)
{
	if (((Parent2_life *)(obj->life_table))->clean != NULL) {
		((Parent2_life *)(obj->life_table))->clean(obj);
	}
	free(obj->func_table);
	free(obj->life_table);
	free(obj);
}

Parent2 *Parent2_new(void)
{
	Parent2 *self;
	self = Parent2_alloc();
	return (self);
}

int F__M_Parent2_i_test_F_thunkParent2(Parent2 *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( (((Parent2 *)((Parent2_life *)thunk->life_table)->base)) ), "r" ( F__M_Parent2_i_test_F )
            : "%rdi"
            );
            
}


#include <stdlib.h>

Son *Son_alloc(void)
{
	Son *ret;
	ret = malloc(sizeof(*ret));
	ret->life_table = malloc(sizeof(Son_life));
	((Son_life*)(ret->life_table))->base = ret;
	ret->parent1.life_table = ret->life_table;
	ret->parent2.life_table = ret->life_table;
	ret->parent1.func_table = malloc(sizeof(Son_table));
	ret->parent2.func_table = ret->parent1.func_table + sizeof(Parent1_table);
	((Son_table *)(ret->parent1.func_table))->F__M_Parent2_i_test_F = &F__M_Parent2_i_test_F_thunkSon;
	((Son_life *)(ret->life_table))->clean = NULL;
	((Son_life *)(ret->life_table))->delete = &Son_delete;
	return (ret);
}

void Son_delete(Son *obj)
{
	if (((Son_life *)(obj->life_table))->clean != NULL) {
		((Son_life *)(obj->life_table))->clean(obj);
	}
	free(obj->parent1.func_table);
	free(obj->life_table);
	free(obj);
}

Son *Son_new(void)
{
	Son *self;
	self = Son_alloc();
	return (self);
}

int F__M_Parent2_i_test_F_thunkSon(Son *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( &(((Son *)((Son_life *)thunk->life_table)->base)->parent2) ), "r" ( F__M_Parent2_i_test_F )
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
            Son *s = Son_new();
            int ret;
            s->parent1.V__M_Parent1_i_p1_V = 1;
            s->parent2.V__M_Parent2_i_p2_V = 2;
            s->V__M_Son_i_s_V = 12;
            ret = ((Son_table *)s->parent1.func_table)->F__M_Parent2_i_test_F((void *)s);
            return (0);
        }
    else
        {
            fprintf(stderr, "Process terminated by an unknown exception\n");
            return (EXIT_FAILURE);
        }
    return (EXIT_SUCCESS);
}
