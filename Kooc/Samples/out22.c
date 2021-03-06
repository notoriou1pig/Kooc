#include <setjmp.h>
extern jmp_buf kooc_global_env;
#include <stdlib.h>
#include <stdio.h>
#include <setjmp.h>
#ifndef __IN22_FILE__
#define __IN22_FILE__
#include "in22.h"
#endif /* __IN22_FILE__ */


void F__M_BaseClassA_v_printA_F(BaseClassA *self)
{
    puts("A");
}

#include <stdlib.h>

BaseClassA *BaseClassA_alloc(void)
{
	BaseClassA *ret;
	ret = malloc(sizeof(*ret));
	ret->life_table = malloc(sizeof(BaseClassA_life));
	((BaseClassA_life*)(ret->life_table))->base = ret;
	ret->func_table = malloc(sizeof(BaseClassA_table));
	((BaseClassA_table *)(ret->func_table))->F__M_BaseClassA_v_printA_F = &F__M_BaseClassA_v_printA_F_thunkBaseClassA;
	((BaseClassA_life *)(ret->life_table))->clean = NULL;
	((BaseClassA_life *)(ret->life_table))->delete = &BaseClassA_delete;
	return (ret);
}

void BaseClassA_delete(BaseClassA *obj)
{
	if (((BaseClassA_life *)(obj->life_table))->clean != NULL) {
		((BaseClassA_life *)(obj->life_table))->clean(obj);
	}
	free(obj->func_table);
	free(obj->life_table);
	free(obj);
}

BaseClassA *BaseClassA_new(void)
{
	BaseClassA *self;
	self = BaseClassA_alloc();
	return (self);
}

void F__M_BaseClassA_v_printA_F_thunkBaseClassA(BaseClassA *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( (((BaseClassA *)((BaseClassA_life *)thunk->life_table)->base)) ), "r" ( F__M_BaseClassA_v_printA_F )
            : "%rdi"
            );
            
}


void F__M_BaseClassB_v_printB_F(BaseClassB *self)
{
    puts("B");
}

#include <stdlib.h>

BaseClassB *BaseClassB_alloc(void)
{
	BaseClassB *ret;
	ret = malloc(sizeof(*ret));
	ret->life_table = malloc(sizeof(BaseClassB_life));
	((BaseClassB_life*)(ret->life_table))->base = ret;
	ret->func_table = malloc(sizeof(BaseClassB_table));
	((BaseClassB_table *)(ret->func_table))->F__M_BaseClassB_v_printB_F = &F__M_BaseClassB_v_printB_F_thunkBaseClassB;
	((BaseClassB_life *)(ret->life_table))->clean = NULL;
	((BaseClassB_life *)(ret->life_table))->delete = &BaseClassB_delete;
	return (ret);
}

void BaseClassB_delete(BaseClassB *obj)
{
	if (((BaseClassB_life *)(obj->life_table))->clean != NULL) {
		((BaseClassB_life *)(obj->life_table))->clean(obj);
	}
	free(obj->func_table);
	free(obj->life_table);
	free(obj);
}

BaseClassB *BaseClassB_new(void)
{
	BaseClassB *self;
	self = BaseClassB_alloc();
	return (self);
}

void F__M_BaseClassB_v_printB_F_thunkBaseClassB(BaseClassB *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( (((BaseClassB *)((BaseClassB_life *)thunk->life_table)->base)) ), "r" ( F__M_BaseClassB_v_printB_F )
            : "%rdi"
            );
            
}


void F__M_BaseClassC_v_printC_F(BaseClassC *self)
{
    puts("C");
}

#include <stdlib.h>

BaseClassC *BaseClassC_alloc(void)
{
	BaseClassC *ret;
	ret = malloc(sizeof(*ret));
	ret->life_table = malloc(sizeof(BaseClassC_life));
	((BaseClassC_life*)(ret->life_table))->base = ret;
	ret->parent1.life_table = ret->life_table;
	ret->parent2.life_table = ret->life_table;
	ret->parent1.func_table = malloc(sizeof(BaseClassC_table));
	ret->parent2.func_table = ret->parent1.func_table + sizeof(BaseClassA_table);
	((BaseClassC_table *)(ret->parent1.func_table))->F__M_BaseClassA_v_printA_F = &F__M_BaseClassA_v_printA_F_thunkBaseClassC;
	((BaseClassC_table *)(ret->parent1.func_table))->F__M_BaseClassB_v_printB_F = &F__M_BaseClassB_v_printB_F_thunkBaseClassC;
	((BaseClassC_table *)(ret->parent1.func_table))->F__M_BaseClassC_v_printC_F = &F__M_BaseClassC_v_printC_F_thunkBaseClassC;
	((BaseClassC_life *)(ret->life_table))->clean = NULL;
	((BaseClassC_life *)(ret->life_table))->delete = &BaseClassC_delete;
	return (ret);
}

void BaseClassC_delete(BaseClassC *obj)
{
	if (((BaseClassC_life *)(obj->life_table))->clean != NULL) {
		((BaseClassC_life *)(obj->life_table))->clean(obj);
	}
	free(obj->parent1.func_table);
	free(obj->life_table);
	free(obj);
}

BaseClassC *BaseClassC_new(void)
{
	BaseClassC *self;
	self = BaseClassC_alloc();
	return (self);
}

void F__M_BaseClassA_v_printA_F_thunkBaseClassC(BaseClassC *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( &(((BaseClassC *)((BaseClassC_life *)thunk->life_table)->base)->parent1) ), "r" ( F__M_BaseClassA_v_printA_F )
            : "%rdi"
            );
            
}

void F__M_BaseClassB_v_printB_F_thunkBaseClassC(BaseClassC *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( &(((BaseClassC *)((BaseClassC_life *)thunk->life_table)->base)->parent2) ), "r" ( F__M_BaseClassB_v_printB_F )
            : "%rdi"
            );
            
}

void F__M_BaseClassC_v_printC_F_thunkBaseClassC(BaseClassC *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( (((BaseClassC *)((BaseClassC_life *)thunk->life_table)->base)) ), "r" ( F__M_BaseClassC_v_printC_F )
            : "%rdi"
            );
            
}


void F__M_BaseClassD_v_printD_F(BaseClassD *self)
{
    puts("D");
}

#include <stdlib.h>

BaseClassD *BaseClassD_alloc(void)
{
	BaseClassD *ret;
	ret = malloc(sizeof(*ret));
	ret->life_table = malloc(sizeof(BaseClassD_life));
	((BaseClassD_life*)(ret->life_table))->base = ret;
	ret->parent1.life_table = ret->life_table;
	ret->parent1.parent1.life_table = ret->life_table;
	ret->parent1.parent2.life_table = ret->life_table;
	ret->parent1.parent1.func_table = malloc(sizeof(BaseClassD_table));
	ret->parent1.parent2.func_table = ret->parent1.parent1.func_table + sizeof(BaseClassA_table);
	((BaseClassD_table *)(ret->parent1.parent1.func_table))->F__M_BaseClassA_v_printA_F = &F__M_BaseClassA_v_printA_F_thunkBaseClassD;
	((BaseClassD_table *)(ret->parent1.parent1.func_table))->F__M_BaseClassB_v_printB_F = &F__M_BaseClassB_v_printB_F_thunkBaseClassD;
	((BaseClassD_table *)(ret->parent1.parent1.func_table))->F__M_BaseClassC_v_printC_F = &F__M_BaseClassC_v_printC_F_thunkBaseClassD;
	((BaseClassD_table *)(ret->parent1.parent1.func_table))->F__M_BaseClassD_v_printD_F = &F__M_BaseClassD_v_printD_F_thunkBaseClassD;
	((BaseClassD_life *)(ret->life_table))->clean = NULL;
	((BaseClassD_life *)(ret->life_table))->delete = &BaseClassD_delete;
	return (ret);
}

void BaseClassD_delete(BaseClassD *obj)
{
	if (((BaseClassD_life *)(obj->life_table))->clean != NULL) {
		((BaseClassD_life *)(obj->life_table))->clean(obj);
	}
	free(obj->parent1.parent1.func_table);
	free(obj->life_table);
	free(obj);
}

BaseClassD *BaseClassD_new(void)
{
	BaseClassD *self;
	self = BaseClassD_alloc();
	return (self);
}

void F__M_BaseClassA_v_printA_F_thunkBaseClassD(BaseClassD *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( &(((BaseClassD *)((BaseClassD_life *)thunk->life_table)->base)->parent1.parent1) ), "r" ( F__M_BaseClassA_v_printA_F )
            : "%rdi"
            );
            
}

void F__M_BaseClassB_v_printB_F_thunkBaseClassD(BaseClassD *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( &(((BaseClassD *)((BaseClassD_life *)thunk->life_table)->base)->parent1.parent2) ), "r" ( F__M_BaseClassB_v_printB_F )
            : "%rdi"
            );
            
}

void F__M_BaseClassC_v_printC_F_thunkBaseClassD(BaseClassD *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( &(((BaseClassD *)((BaseClassD_life *)thunk->life_table)->base)->parent1) ), "r" ( F__M_BaseClassC_v_printC_F )
            : "%rdi"
            );
            
}

void F__M_BaseClassD_v_printD_F_thunkBaseClassD(BaseClassD *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( (((BaseClassD *)((BaseClassD_life *)thunk->life_table)->base)) ), "r" ( F__M_BaseClassD_v_printD_F )
            : "%rdi"
            );
            
}


void F__M_BaseClassE_v_printE_F(BaseClassE *self)
{
    puts("E");
}

#include <stdlib.h>

BaseClassE *BaseClassE_alloc(void)
{
	BaseClassE *ret;
	ret = malloc(sizeof(*ret));
	ret->life_table = malloc(sizeof(BaseClassE_life));
	((BaseClassE_life*)(ret->life_table))->base = ret;
	ret->func_table = malloc(sizeof(BaseClassE_table));
	((BaseClassE_table *)(ret->func_table))->F__M_BaseClassE_v_printE_F = &F__M_BaseClassE_v_printE_F_thunkBaseClassE;
	((BaseClassE_life *)(ret->life_table))->clean = NULL;
	((BaseClassE_life *)(ret->life_table))->delete = &BaseClassE_delete;
	return (ret);
}

void BaseClassE_delete(BaseClassE *obj)
{
	if (((BaseClassE_life *)(obj->life_table))->clean != NULL) {
		((BaseClassE_life *)(obj->life_table))->clean(obj);
	}
	free(obj->func_table);
	free(obj->life_table);
	free(obj);
}

BaseClassE *BaseClassE_new(void)
{
	BaseClassE *self;
	self = BaseClassE_alloc();
	return (self);
}

void F__M_BaseClassE_v_printE_F_thunkBaseClassE(BaseClassE *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( (((BaseClassE *)((BaseClassE_life *)thunk->life_table)->base)) ), "r" ( F__M_BaseClassE_v_printE_F )
            : "%rdi"
            );
            
}


void F__M_BaseClassF_v_printF_F(BaseClassF *self)
{
    puts("F");
}

#include <stdlib.h>

BaseClassF *BaseClassF_alloc(void)
{
	BaseClassF *ret;
	ret = malloc(sizeof(*ret));
	ret->life_table = malloc(sizeof(BaseClassF_life));
	((BaseClassF_life*)(ret->life_table))->base = ret;
	ret->func_table = malloc(sizeof(BaseClassF_table));
	((BaseClassF_table *)(ret->func_table))->F__M_BaseClassF_v_printF_F = &F__M_BaseClassF_v_printF_F_thunkBaseClassF;
	((BaseClassF_life *)(ret->life_table))->clean = NULL;
	((BaseClassF_life *)(ret->life_table))->delete = &BaseClassF_delete;
	return (ret);
}

void BaseClassF_delete(BaseClassF *obj)
{
	if (((BaseClassF_life *)(obj->life_table))->clean != NULL) {
		((BaseClassF_life *)(obj->life_table))->clean(obj);
	}
	free(obj->func_table);
	free(obj->life_table);
	free(obj);
}

BaseClassF *BaseClassF_new(void)
{
	BaseClassF *self;
	self = BaseClassF_alloc();
	return (self);
}

void F__M_BaseClassF_v_printF_F_thunkBaseClassF(BaseClassF *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( (((BaseClassF *)((BaseClassF_life *)thunk->life_table)->base)) ), "r" ( F__M_BaseClassF_v_printF_F )
            : "%rdi"
            );
            
}


void F__M_BaseClassG_v_printG_F(BaseClassG *self)
{
    puts("G");
}

#include <stdlib.h>

BaseClassG *BaseClassG_alloc(void)
{
	BaseClassG *ret;
	ret = malloc(sizeof(*ret));
	ret->life_table = malloc(sizeof(BaseClassG_life));
	((BaseClassG_life*)(ret->life_table))->base = ret;
	ret->parent1.life_table = ret->life_table;
	ret->parent2.life_table = ret->life_table;
	ret->parent1.func_table = malloc(sizeof(BaseClassG_table));
	ret->parent2.func_table = ret->parent1.func_table + sizeof(BaseClassE_table);
	((BaseClassG_table *)(ret->parent1.func_table))->F__M_BaseClassE_v_printE_F = &F__M_BaseClassE_v_printE_F_thunkBaseClassG;
	((BaseClassG_table *)(ret->parent1.func_table))->F__M_BaseClassF_v_printF_F = &F__M_BaseClassF_v_printF_F_thunkBaseClassG;
	((BaseClassG_table *)(ret->parent1.func_table))->F__M_BaseClassG_v_printG_F = &F__M_BaseClassG_v_printG_F_thunkBaseClassG;
	((BaseClassG_life *)(ret->life_table))->clean = NULL;
	((BaseClassG_life *)(ret->life_table))->delete = &BaseClassG_delete;
	return (ret);
}

void BaseClassG_delete(BaseClassG *obj)
{
	if (((BaseClassG_life *)(obj->life_table))->clean != NULL) {
		((BaseClassG_life *)(obj->life_table))->clean(obj);
	}
	free(obj->parent1.func_table);
	free(obj->life_table);
	free(obj);
}

BaseClassG *BaseClassG_new(void)
{
	BaseClassG *self;
	self = BaseClassG_alloc();
	return (self);
}

void F__M_BaseClassE_v_printE_F_thunkBaseClassG(BaseClassG *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( &(((BaseClassG *)((BaseClassG_life *)thunk->life_table)->base)->parent1) ), "r" ( F__M_BaseClassE_v_printE_F )
            : "%rdi"
            );
            
}

void F__M_BaseClassF_v_printF_F_thunkBaseClassG(BaseClassG *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( &(((BaseClassG *)((BaseClassG_life *)thunk->life_table)->base)->parent2) ), "r" ( F__M_BaseClassF_v_printF_F )
            : "%rdi"
            );
            
}

void F__M_BaseClassG_v_printG_F_thunkBaseClassG(BaseClassG *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( (((BaseClassG *)((BaseClassG_life *)thunk->life_table)->base)) ), "r" ( F__M_BaseClassG_v_printG_F )
            : "%rdi"
            );
            
}


void F__M_Son_v_printSon_F(Son *self)
{
    puts("Son");
}

#include <stdlib.h>

Son *Son_alloc(void)
{
	Son *ret;
	ret = malloc(sizeof(*ret));
	ret->life_table = malloc(sizeof(Son_life));
	((Son_life*)(ret->life_table))->base = ret;
	ret->parent1.life_table = ret->life_table;
	ret->parent1.parent1.life_table = ret->life_table;
	ret->parent1.parent1.parent1.life_table = ret->life_table;
	ret->parent1.parent1.parent2.life_table = ret->life_table;
	ret->parent2.life_table = ret->life_table;
	ret->parent2.parent1.life_table = ret->life_table;
	ret->parent2.parent2.life_table = ret->life_table;
	ret->parent1.parent1.parent1.func_table = malloc(sizeof(Son_table));
	ret->parent1.parent1.parent2.func_table = ret->parent1.parent1.parent1.func_table + sizeof(BaseClassA_table);
	ret->parent2.parent1.func_table = ret->parent1.parent1.parent1.func_table + sizeof(BaseClassD_table);
	ret->parent2.parent2.func_table = ret->parent1.parent1.parent1.func_table + sizeof(BaseClassD_table) + sizeof(BaseClassE_table);
	((Son_table *)(ret->parent1.parent1.parent1.func_table))->F__M_BaseClassA_v_printA_F = &F__M_BaseClassA_v_printA_F_thunkSon;
	((Son_table *)(ret->parent1.parent1.parent1.func_table))->F__M_BaseClassB_v_printB_F = &F__M_BaseClassB_v_printB_F_thunkSon;
	((Son_table *)(ret->parent1.parent1.parent1.func_table))->F__M_BaseClassC_v_printC_F = &F__M_BaseClassC_v_printC_F_thunkSon;
	((Son_table *)(ret->parent1.parent1.parent1.func_table))->F__M_BaseClassD_v_printD_F = &F__M_BaseClassD_v_printD_F_thunkSon;
	((Son_table *)(ret->parent1.parent1.parent1.func_table))->F__M_BaseClassE_v_printE_F = &F__M_BaseClassE_v_printE_F_thunkSon;
	((Son_table *)(ret->parent1.parent1.parent1.func_table))->F__M_BaseClassF_v_printF_F = &F__M_BaseClassF_v_printF_F_thunkSon;
	((Son_table *)(ret->parent1.parent1.parent1.func_table))->F__M_BaseClassG_v_printG_F = &F__M_BaseClassG_v_printG_F_thunkSon;
	((Son_table *)(ret->parent1.parent1.parent1.func_table))->F__M_Son_v_printSon_F = &F__M_Son_v_printSon_F_thunkSon;
	((Son_life *)(ret->life_table))->clean = NULL;
	((Son_life *)(ret->life_table))->delete = &Son_delete;
	return (ret);
}

void Son_delete(Son *obj)
{
	if (((Son_life *)(obj->life_table))->clean != NULL) {
		((Son_life *)(obj->life_table))->clean(obj);
	}
	free(obj->parent1.parent1.parent1.func_table);
	free(obj->life_table);
	free(obj);
}

Son *Son_new(void)
{
	Son *self;
	self = Son_alloc();
	return (self);
}

void F__M_BaseClassA_v_printA_F_thunkSon(Son *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( &(((Son *)((Son_life *)thunk->life_table)->base)->parent1.parent1.parent1) ), "r" ( F__M_BaseClassA_v_printA_F )
            : "%rdi"
            );
            
}

void F__M_BaseClassB_v_printB_F_thunkSon(Son *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( &(((Son *)((Son_life *)thunk->life_table)->base)->parent1.parent1.parent2) ), "r" ( F__M_BaseClassB_v_printB_F )
            : "%rdi"
            );
            
}

void F__M_BaseClassC_v_printC_F_thunkSon(Son *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( &(((Son *)((Son_life *)thunk->life_table)->base)->parent1.parent1) ), "r" ( F__M_BaseClassC_v_printC_F )
            : "%rdi"
            );
            
}

void F__M_BaseClassD_v_printD_F_thunkSon(Son *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( &(((Son *)((Son_life *)thunk->life_table)->base)->parent1) ), "r" ( F__M_BaseClassD_v_printD_F )
            : "%rdi"
            );
            
}

void F__M_BaseClassE_v_printE_F_thunkSon(Son *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( &(((Son *)((Son_life *)thunk->life_table)->base)->parent2.parent1) ), "r" ( F__M_BaseClassE_v_printE_F )
            : "%rdi"
            );
            
}

void F__M_BaseClassF_v_printF_F_thunkSon(Son *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( &(((Son *)((Son_life *)thunk->life_table)->base)->parent2.parent2) ), "r" ( F__M_BaseClassF_v_printF_F )
            : "%rdi"
            );
            
}

void F__M_BaseClassG_v_printG_F_thunkSon(Son *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( &(((Son *)((Son_life *)thunk->life_table)->base)->parent2) ), "r" ( F__M_BaseClassG_v_printG_F )
            : "%rdi"
            );
            
}

void F__M_Son_v_printSon_F_thunkSon(Son *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( (((Son *)((Son_life *)thunk->life_table)->base)) ), "r" ( F__M_Son_v_printSon_F )
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
            Son *to = Son_new();
            to = (BaseClassA *) to;
            ((Son_table *)to->parent1.parent1.parent1.func_table)->F__M_BaseClassA_v_printA_F((void *)to);
            ((Son_life *)to->life_table)->delete((void *)to);
            return (0);
        }
    else
        {
            fprintf(stderr, "Process terminated by an unknown exception\n");
            return (EXIT_FAILURE);
        }
    return (EXIT_SUCCESS);
}
