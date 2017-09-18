#include <setjmp.h>
extern jmp_buf kooc_global_env;
#include <stdlib.h>
#include <stdio.h>
#include <setjmp.h>
#ifndef __IN19_FILE__
#define __IN19_FILE__
#include "in19.h"
#endif /* __IN19_FILE__ */


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
	ret->func_table = malloc(sizeof(BaseClassD_table));
	((BaseClassD_table *)(ret->func_table))->F__M_BaseClassD_v_printD_F = &F__M_BaseClassD_v_printD_F_thunkBaseClassD;
	((BaseClassD_life *)(ret->life_table))->clean = NULL;
	((BaseClassD_life *)(ret->life_table))->delete = &BaseClassD_delete;
	return (ret);
}

void BaseClassD_delete(BaseClassD *obj)
{
	if (((BaseClassD_life *)(obj->life_table))->clean != NULL) {
		((BaseClassD_life *)(obj->life_table))->clean(obj);
	}
	free(obj->func_table);
	free(obj->life_table);
	free(obj);
}

BaseClassD *BaseClassD_new(void)
{
	BaseClassD *self;
	self = BaseClassD_alloc();
	return (self);
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
	ret->parent1.life_table = ret->life_table;
	ret->parent2.life_table = ret->life_table;
	ret->parent1.func_table = malloc(sizeof(BaseClassF_table));
	ret->parent2.func_table = ret->parent1.func_table + sizeof(BaseClassD_table);
	((BaseClassF_table *)(ret->parent1.func_table))->F__M_BaseClassD_v_printD_F = &F__M_BaseClassD_v_printD_F_thunkBaseClassF;
	((BaseClassF_table *)(ret->parent1.func_table))->F__M_BaseClassE_v_printE_F = &F__M_BaseClassE_v_printE_F_thunkBaseClassF;
	((BaseClassF_table *)(ret->parent1.func_table))->F__M_BaseClassF_v_printF_F = &F__M_BaseClassF_v_printF_F_thunkBaseClassF;
	((BaseClassF_life *)(ret->life_table))->clean = NULL;
	((BaseClassF_life *)(ret->life_table))->delete = &BaseClassF_delete;
	return (ret);
}

void BaseClassF_delete(BaseClassF *obj)
{
	if (((BaseClassF_life *)(obj->life_table))->clean != NULL) {
		((BaseClassF_life *)(obj->life_table))->clean(obj);
	}
	free(obj->parent1.func_table);
	free(obj->life_table);
	free(obj);
}

BaseClassF *BaseClassF_new(void)
{
	BaseClassF *self;
	self = BaseClassF_alloc();
	return (self);
}

void F__M_BaseClassD_v_printD_F_thunkBaseClassF(BaseClassF *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( &(((BaseClassF *)((BaseClassF_life *)thunk->life_table)->base)->parent1) ), "r" ( F__M_BaseClassD_v_printD_F )
            : "%rdi"
            );
            
}

void F__M_BaseClassE_v_printE_F_thunkBaseClassF(BaseClassF *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( &(((BaseClassF *)((BaseClassF_life *)thunk->life_table)->base)->parent2) ), "r" ( F__M_BaseClassE_v_printE_F )
            : "%rdi"
            );
            
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
	ret->func_table = malloc(sizeof(BaseClassG_table));
	((BaseClassG_table *)(ret->func_table))->F__M_BaseClassG_v_printG_F = &F__M_BaseClassG_v_printG_F_thunkBaseClassG;
	((BaseClassG_life *)(ret->life_table))->clean = NULL;
	((BaseClassG_life *)(ret->life_table))->delete = &BaseClassG_delete;
	return (ret);
}

void BaseClassG_delete(BaseClassG *obj)
{
	if (((BaseClassG_life *)(obj->life_table))->clean != NULL) {
		((BaseClassG_life *)(obj->life_table))->clean(obj);
	}
	free(obj->func_table);
	free(obj->life_table);
	free(obj);
}

BaseClassG *BaseClassG_new(void)
{
	BaseClassG *self;
	self = BaseClassG_alloc();
	return (self);
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


void F__M_BaseClassH_v_printH_F(BaseClassH *self)
{
    puts("H");
}

#include <stdlib.h>

BaseClassH *BaseClassH_alloc(void)
{
	BaseClassH *ret;
	ret = malloc(sizeof(*ret));
	ret->life_table = malloc(sizeof(BaseClassH_life));
	((BaseClassH_life*)(ret->life_table))->base = ret;
	ret->func_table = malloc(sizeof(BaseClassH_table));
	((BaseClassH_table *)(ret->func_table))->F__M_BaseClassH_v_printH_F = &F__M_BaseClassH_v_printH_F_thunkBaseClassH;
	((BaseClassH_life *)(ret->life_table))->clean = NULL;
	((BaseClassH_life *)(ret->life_table))->delete = &BaseClassH_delete;
	return (ret);
}

void BaseClassH_delete(BaseClassH *obj)
{
	if (((BaseClassH_life *)(obj->life_table))->clean != NULL) {
		((BaseClassH_life *)(obj->life_table))->clean(obj);
	}
	free(obj->func_table);
	free(obj->life_table);
	free(obj);
}

BaseClassH *BaseClassH_new(void)
{
	BaseClassH *self;
	self = BaseClassH_alloc();
	return (self);
}

void F__M_BaseClassH_v_printH_F_thunkBaseClassH(BaseClassH *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( (((BaseClassH *)((BaseClassH_life *)thunk->life_table)->base)) ), "r" ( F__M_BaseClassH_v_printH_F )
            : "%rdi"
            );
            
}


void F__M_BaseClassI_v_printI_F(BaseClassI *self)
{
    puts("I");
}

#include <stdlib.h>

BaseClassI *BaseClassI_alloc(void)
{
	BaseClassI *ret;
	ret = malloc(sizeof(*ret));
	ret->life_table = malloc(sizeof(BaseClassI_life));
	((BaseClassI_life*)(ret->life_table))->base = ret;
	ret->parent1.life_table = ret->life_table;
	ret->parent2.life_table = ret->life_table;
	ret->parent1.func_table = malloc(sizeof(BaseClassI_table));
	ret->parent2.func_table = ret->parent1.func_table + sizeof(BaseClassG_table);
	((BaseClassI_table *)(ret->parent1.func_table))->F__M_BaseClassG_v_printG_F = &F__M_BaseClassG_v_printG_F_thunkBaseClassI;
	((BaseClassI_table *)(ret->parent1.func_table))->F__M_BaseClassH_v_printH_F = &F__M_BaseClassH_v_printH_F_thunkBaseClassI;
	((BaseClassI_table *)(ret->parent1.func_table))->F__M_BaseClassI_v_printI_F = &F__M_BaseClassI_v_printI_F_thunkBaseClassI;
	((BaseClassI_life *)(ret->life_table))->clean = NULL;
	((BaseClassI_life *)(ret->life_table))->delete = &BaseClassI_delete;
	return (ret);
}

void BaseClassI_delete(BaseClassI *obj)
{
	if (((BaseClassI_life *)(obj->life_table))->clean != NULL) {
		((BaseClassI_life *)(obj->life_table))->clean(obj);
	}
	free(obj->parent1.func_table);
	free(obj->life_table);
	free(obj);
}

BaseClassI *BaseClassI_new(void)
{
	BaseClassI *self;
	self = BaseClassI_alloc();
	return (self);
}

void F__M_BaseClassG_v_printG_F_thunkBaseClassI(BaseClassI *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( &(((BaseClassI *)((BaseClassI_life *)thunk->life_table)->base)->parent1) ), "r" ( F__M_BaseClassG_v_printG_F )
            : "%rdi"
            );
            
}

void F__M_BaseClassH_v_printH_F_thunkBaseClassI(BaseClassI *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( &(((BaseClassI *)((BaseClassI_life *)thunk->life_table)->base)->parent2) ), "r" ( F__M_BaseClassH_v_printH_F )
            : "%rdi"
            );
            
}

void F__M_BaseClassI_v_printI_F_thunkBaseClassI(BaseClassI *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( (((BaseClassI *)((BaseClassI_life *)thunk->life_table)->base)) ), "r" ( F__M_BaseClassI_v_printI_F )
            : "%rdi"
            );
            
}


void F__M_BaseClassJ_v_printJ_F(BaseClassJ *self)
{
    puts("J");
}

#include <stdlib.h>

BaseClassJ *BaseClassJ_alloc(void)
{
	BaseClassJ *ret;
	ret = malloc(sizeof(*ret));
	ret->life_table = malloc(sizeof(BaseClassJ_life));
	((BaseClassJ_life*)(ret->life_table))->base = ret;
	ret->parent1.life_table = ret->life_table;
	ret->parent1.parent1.life_table = ret->life_table;
	ret->parent1.parent2.life_table = ret->life_table;
	ret->parent2.life_table = ret->life_table;
	ret->parent2.parent1.life_table = ret->life_table;
	ret->parent2.parent2.life_table = ret->life_table;
	ret->parent3.life_table = ret->life_table;
	ret->parent3.parent1.life_table = ret->life_table;
	ret->parent3.parent2.life_table = ret->life_table;
	ret->parent1.parent1.func_table = malloc(sizeof(BaseClassJ_table));
	ret->parent1.parent2.func_table = ret->parent1.parent1.func_table + sizeof(BaseClassA_table);
	ret->parent2.parent1.func_table = ret->parent1.parent1.func_table + sizeof(BaseClassC_table);
	ret->parent2.parent2.func_table = ret->parent1.parent1.func_table + sizeof(BaseClassC_table) + sizeof(BaseClassD_table);
	ret->parent3.parent1.func_table = ret->parent1.parent1.func_table + sizeof(BaseClassC_table) + sizeof(BaseClassF_table);
	ret->parent3.parent2.func_table = ret->parent1.parent1.func_table + sizeof(BaseClassC_table) + sizeof(BaseClassF_table) + sizeof(BaseClassG_table);
	((BaseClassJ_table *)(ret->parent1.parent1.func_table))->F__M_BaseClassA_v_printA_F = &F__M_BaseClassA_v_printA_F_thunkBaseClassJ;
	((BaseClassJ_table *)(ret->parent1.parent1.func_table))->F__M_BaseClassB_v_printB_F = &F__M_BaseClassB_v_printB_F_thunkBaseClassJ;
	((BaseClassJ_table *)(ret->parent1.parent1.func_table))->F__M_BaseClassC_v_printC_F = &F__M_BaseClassC_v_printC_F_thunkBaseClassJ;
	((BaseClassJ_table *)(ret->parent1.parent1.func_table))->F__M_BaseClassD_v_printD_F = &F__M_BaseClassD_v_printD_F_thunkBaseClassJ;
	((BaseClassJ_table *)(ret->parent1.parent1.func_table))->F__M_BaseClassE_v_printE_F = &F__M_BaseClassE_v_printE_F_thunkBaseClassJ;
	((BaseClassJ_table *)(ret->parent1.parent1.func_table))->F__M_BaseClassF_v_printF_F = &F__M_BaseClassF_v_printF_F_thunkBaseClassJ;
	((BaseClassJ_table *)(ret->parent1.parent1.func_table))->F__M_BaseClassG_v_printG_F = &F__M_BaseClassG_v_printG_F_thunkBaseClassJ;
	((BaseClassJ_table *)(ret->parent1.parent1.func_table))->F__M_BaseClassH_v_printH_F = &F__M_BaseClassH_v_printH_F_thunkBaseClassJ;
	((BaseClassJ_table *)(ret->parent1.parent1.func_table))->F__M_BaseClassI_v_printI_F = &F__M_BaseClassI_v_printI_F_thunkBaseClassJ;
	((BaseClassJ_table *)(ret->parent1.parent1.func_table))->F__M_BaseClassJ_v_printJ_F = &F__M_BaseClassJ_v_printJ_F_thunkBaseClassJ;
	((BaseClassJ_life *)(ret->life_table))->clean = NULL;
	((BaseClassJ_life *)(ret->life_table))->delete = &BaseClassJ_delete;
	return (ret);
}

void BaseClassJ_delete(BaseClassJ *obj)
{
	if (((BaseClassJ_life *)(obj->life_table))->clean != NULL) {
		((BaseClassJ_life *)(obj->life_table))->clean(obj);
	}
	free(obj->parent1.parent1.func_table);
	free(obj->life_table);
	free(obj);
}

BaseClassJ *BaseClassJ_new(void)
{
	BaseClassJ *self;
	self = BaseClassJ_alloc();
	return (self);
}

void F__M_BaseClassA_v_printA_F_thunkBaseClassJ(BaseClassJ *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( &(((BaseClassJ *)((BaseClassJ_life *)thunk->life_table)->base)->parent1.parent1) ), "r" ( F__M_BaseClassA_v_printA_F )
            : "%rdi"
            );
            
}

void F__M_BaseClassB_v_printB_F_thunkBaseClassJ(BaseClassJ *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( &(((BaseClassJ *)((BaseClassJ_life *)thunk->life_table)->base)->parent1.parent2) ), "r" ( F__M_BaseClassB_v_printB_F )
            : "%rdi"
            );
            
}

void F__M_BaseClassC_v_printC_F_thunkBaseClassJ(BaseClassJ *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( &(((BaseClassJ *)((BaseClassJ_life *)thunk->life_table)->base)->parent1) ), "r" ( F__M_BaseClassC_v_printC_F )
            : "%rdi"
            );
            
}

void F__M_BaseClassD_v_printD_F_thunkBaseClassJ(BaseClassJ *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( &(((BaseClassJ *)((BaseClassJ_life *)thunk->life_table)->base)->parent2.parent1) ), "r" ( F__M_BaseClassD_v_printD_F )
            : "%rdi"
            );
            
}

void F__M_BaseClassE_v_printE_F_thunkBaseClassJ(BaseClassJ *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( &(((BaseClassJ *)((BaseClassJ_life *)thunk->life_table)->base)->parent2.parent2) ), "r" ( F__M_BaseClassE_v_printE_F )
            : "%rdi"
            );
            
}

void F__M_BaseClassF_v_printF_F_thunkBaseClassJ(BaseClassJ *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( &(((BaseClassJ *)((BaseClassJ_life *)thunk->life_table)->base)->parent2) ), "r" ( F__M_BaseClassF_v_printF_F )
            : "%rdi"
            );
            
}

void F__M_BaseClassG_v_printG_F_thunkBaseClassJ(BaseClassJ *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( &(((BaseClassJ *)((BaseClassJ_life *)thunk->life_table)->base)->parent3.parent1) ), "r" ( F__M_BaseClassG_v_printG_F )
            : "%rdi"
            );
            
}

void F__M_BaseClassH_v_printH_F_thunkBaseClassJ(BaseClassJ *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( &(((BaseClassJ *)((BaseClassJ_life *)thunk->life_table)->base)->parent3.parent2) ), "r" ( F__M_BaseClassH_v_printH_F )
            : "%rdi"
            );
            
}

void F__M_BaseClassI_v_printI_F_thunkBaseClassJ(BaseClassJ *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( &(((BaseClassJ *)((BaseClassJ_life *)thunk->life_table)->base)->parent3) ), "r" ( F__M_BaseClassI_v_printI_F )
            : "%rdi"
            );
            
}

void F__M_BaseClassJ_v_printJ_F_thunkBaseClassJ(BaseClassJ *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( (((BaseClassJ *)((BaseClassJ_life *)thunk->life_table)->base)) ), "r" ( F__M_BaseClassJ_v_printJ_F )
            : "%rdi"
            );
            
}


void F__M_BaseClassK_v_printK_F(BaseClassK *self)
{
    puts("K");
}

#include <stdlib.h>

BaseClassK *BaseClassK_alloc(void)
{
	BaseClassK *ret;
	ret = malloc(sizeof(*ret));
	ret->life_table = malloc(sizeof(BaseClassK_life));
	((BaseClassK_life*)(ret->life_table))->base = ret;
	ret->func_table = malloc(sizeof(BaseClassK_table));
	((BaseClassK_table *)(ret->func_table))->F__M_BaseClassK_v_printK_F = &F__M_BaseClassK_v_printK_F_thunkBaseClassK;
	((BaseClassK_life *)(ret->life_table))->clean = NULL;
	((BaseClassK_life *)(ret->life_table))->delete = &BaseClassK_delete;
	return (ret);
}

void BaseClassK_delete(BaseClassK *obj)
{
	if (((BaseClassK_life *)(obj->life_table))->clean != NULL) {
		((BaseClassK_life *)(obj->life_table))->clean(obj);
	}
	free(obj->func_table);
	free(obj->life_table);
	free(obj);
}

BaseClassK *BaseClassK_new(void)
{
	BaseClassK *self;
	self = BaseClassK_alloc();
	return (self);
}

void F__M_BaseClassK_v_printK_F_thunkBaseClassK(BaseClassK *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( (((BaseClassK *)((BaseClassK_life *)thunk->life_table)->base)) ), "r" ( F__M_BaseClassK_v_printK_F )
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
	ret->parent1.parent2.life_table = ret->life_table;
	ret->parent1.parent2.parent1.life_table = ret->life_table;
	ret->parent1.parent2.parent2.life_table = ret->life_table;
	ret->parent1.parent3.life_table = ret->life_table;
	ret->parent1.parent3.parent1.life_table = ret->life_table;
	ret->parent1.parent3.parent2.life_table = ret->life_table;
	ret->parent2.life_table = ret->life_table;
	ret->parent1.parent1.parent1.func_table = malloc(sizeof(Son_table));
	ret->parent1.parent1.parent2.func_table = ret->parent1.parent1.parent1.func_table + sizeof(BaseClassA_table);
	ret->parent1.parent2.parent1.func_table = ret->parent1.parent1.parent1.func_table + sizeof(BaseClassC_table);
	ret->parent1.parent2.parent2.func_table = ret->parent1.parent1.parent1.func_table + sizeof(BaseClassC_table) + sizeof(BaseClassD_table);
	ret->parent1.parent3.parent1.func_table = ret->parent1.parent1.parent1.func_table + sizeof(BaseClassC_table) + sizeof(BaseClassF_table);
	ret->parent1.parent3.parent2.func_table = ret->parent1.parent1.parent1.func_table + sizeof(BaseClassC_table) + sizeof(BaseClassF_table) + sizeof(BaseClassG_table);
	ret->parent2.func_table = ret->parent1.parent1.parent1.func_table + sizeof(BaseClassJ_table);
	((Son_table *)(ret->parent1.parent1.parent1.func_table))->F__M_BaseClassA_v_printA_F = &F__M_BaseClassA_v_printA_F_thunkSon;
	((Son_table *)(ret->parent1.parent1.parent1.func_table))->F__M_BaseClassB_v_printB_F = &F__M_BaseClassB_v_printB_F_thunkSon;
	((Son_table *)(ret->parent1.parent1.parent1.func_table))->F__M_BaseClassC_v_printC_F = &F__M_BaseClassC_v_printC_F_thunkSon;
	((Son_table *)(ret->parent1.parent1.parent1.func_table))->F__M_BaseClassD_v_printD_F = &F__M_BaseClassD_v_printD_F_thunkSon;
	((Son_table *)(ret->parent1.parent1.parent1.func_table))->F__M_BaseClassE_v_printE_F = &F__M_BaseClassE_v_printE_F_thunkSon;
	((Son_table *)(ret->parent1.parent1.parent1.func_table))->F__M_BaseClassF_v_printF_F = &F__M_BaseClassF_v_printF_F_thunkSon;
	((Son_table *)(ret->parent1.parent1.parent1.func_table))->F__M_BaseClassG_v_printG_F = &F__M_BaseClassG_v_printG_F_thunkSon;
	((Son_table *)(ret->parent1.parent1.parent1.func_table))->F__M_BaseClassH_v_printH_F = &F__M_BaseClassH_v_printH_F_thunkSon;
	((Son_table *)(ret->parent1.parent1.parent1.func_table))->F__M_BaseClassI_v_printI_F = &F__M_BaseClassI_v_printI_F_thunkSon;
	((Son_table *)(ret->parent1.parent1.parent1.func_table))->F__M_BaseClassJ_v_printJ_F = &F__M_BaseClassJ_v_printJ_F_thunkSon;
	((Son_table *)(ret->parent1.parent1.parent1.func_table))->F__M_BaseClassK_v_printK_F = &F__M_BaseClassK_v_printK_F_thunkSon;
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
            : "r" ( &(((Son *)((Son_life *)thunk->life_table)->base)->parent1.parent2.parent1) ), "r" ( F__M_BaseClassD_v_printD_F )
            : "%rdi"
            );
            
}

void F__M_BaseClassE_v_printE_F_thunkSon(Son *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( &(((Son *)((Son_life *)thunk->life_table)->base)->parent1.parent2.parent2) ), "r" ( F__M_BaseClassE_v_printE_F )
            : "%rdi"
            );
            
}

void F__M_BaseClassF_v_printF_F_thunkSon(Son *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( &(((Son *)((Son_life *)thunk->life_table)->base)->parent1.parent2) ), "r" ( F__M_BaseClassF_v_printF_F )
            : "%rdi"
            );
            
}

void F__M_BaseClassG_v_printG_F_thunkSon(Son *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( &(((Son *)((Son_life *)thunk->life_table)->base)->parent1.parent3.parent1) ), "r" ( F__M_BaseClassG_v_printG_F )
            : "%rdi"
            );
            
}

void F__M_BaseClassH_v_printH_F_thunkSon(Son *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( &(((Son *)((Son_life *)thunk->life_table)->base)->parent1.parent3.parent2) ), "r" ( F__M_BaseClassH_v_printH_F )
            : "%rdi"
            );
            
}

void F__M_BaseClassI_v_printI_F_thunkSon(Son *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( &(((Son *)((Son_life *)thunk->life_table)->base)->parent1.parent3) ), "r" ( F__M_BaseClassI_v_printI_F )
            : "%rdi"
            );
            
}

void F__M_BaseClassJ_v_printJ_F_thunkSon(Son *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( &(((Son *)((Son_life *)thunk->life_table)->base)->parent1) ), "r" ( F__M_BaseClassJ_v_printJ_F )
            : "%rdi"
            );
            
}

void F__M_BaseClassK_v_printK_F_thunkSon(Son *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( &(((Son *)((Son_life *)thunk->life_table)->base)->parent2) ), "r" ( F__M_BaseClassK_v_printK_F )
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
            to = (BaseClassB *) to;
            ((Son_table *)to->parent1.parent1.parent1.func_table)->F__M_BaseClassB_v_printB_F((void *)to);
            to = (BaseClassC *) to;
            ((Son_table *)to->parent1.parent1.parent1.func_table)->F__M_BaseClassC_v_printC_F((void *)to);
            to = (BaseClassD *) to;
            ((Son_table *)to->parent1.parent1.parent1.func_table)->F__M_BaseClassD_v_printD_F((void *)to);
            to = (BaseClassE *) to;
            ((Son_table *)to->parent1.parent1.parent1.func_table)->F__M_BaseClassE_v_printE_F((void *)to);
            to = (BaseClassF *) to;
            ((Son_table *)to->parent1.parent1.parent1.func_table)->F__M_BaseClassF_v_printF_F((void *)to);
            to = (BaseClassG *) to;
            ((Son_table *)to->parent1.parent1.parent1.func_table)->F__M_BaseClassG_v_printG_F((void *)to);
            to = (BaseClassH *) to;
            ((Son_table *)to->parent1.parent1.parent1.func_table)->F__M_BaseClassH_v_printH_F((void *)to);
            to = (BaseClassI *) to;
            ((Son_table *)to->parent1.parent1.parent1.func_table)->F__M_BaseClassI_v_printI_F((void *)to);
            to = (BaseClassJ *) to;
            ((Son_table *)to->parent1.parent1.parent1.func_table)->F__M_BaseClassJ_v_printJ_F((void *)to);
            to = (BaseClassK *) to;
            ((Son_table *)to->parent1.parent1.parent1.func_table)->F__M_BaseClassK_v_printK_F((void *)to);
            to = (Son *) to;
            ((Son_table *)to->parent1.parent1.parent1.func_table)->F__M_Son_v_printSon_F((void *)to);
            return (0);
        }
    else
        {
            fprintf(stderr, "Process terminated by an unknown exception\n");
            return (EXIT_FAILURE);
        }
    return (EXIT_SUCCESS);
}
