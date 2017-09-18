#include <setjmp.h>
extern jmp_buf kooc_global_env;
#include <stdlib.h>
#include <stdio.h>
#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#ifndef __IN25_FILE__
#define __IN25_FILE__
#include "in25.h"
#endif /* __IN25_FILE__ */

int V__my_exception1_i_id_V;

#include <stdlib.h>

my_exception1 *my_exception1_alloc(void)
{
	my_exception1 *ret;
	ret = malloc(sizeof(*ret));
	ret->life_table = malloc(sizeof(my_exception1_life));
	((my_exception1_life*)(ret->life_table))->base = ret;
	ret->parent1.life_table = ret->life_table;
	ret->parent1.func_table = malloc(sizeof(my_exception1_table));
	((my_exception1_table *)(ret->parent1.func_table))->F__M_Exception_v_init_pc_F = &F__M_Exception_v_init_pc_F_thunkmy_exception1;
	((my_exception1_life *)(ret->life_table))->clean = NULL;
	((my_exception1_life *)(ret->life_table))->delete = &my_exception1_delete;
	return (ret);
}

void my_exception1_delete(my_exception1 *obj)
{
	if (((my_exception1_life *)(obj->life_table))->clean != NULL) {
		((my_exception1_life *)(obj->life_table))->clean(obj);
	}
	free(obj->parent1.func_table);
	free(obj->life_table);
	free(obj);
}

my_exception1 *my_exception1_new(char *p_0)
{
	my_exception1 *self;
	self = my_exception1_alloc();
	F__M_Exception_v_init_pc_F((void *)self, p_0);
	return (self);
}

void my_exception1_INIT_ID(void)
{
	V__my_exception1_i_id_V = KOOC_EXCEPTION_COUNT;
	KOOC_EXCEPTION_COUNT++;
}

void F__M_Exception_v_init_pc_F_thunkmy_exception1(my_exception1 *thunk, char *p1)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( &(((my_exception1 *)((my_exception1_life *)thunk->life_table)->base)->parent1) ), "r" ( F__M_Exception_v_init_pc_F )
            : "%rdi"
            );
            
}

int V__my_exception2_i_id_V;

#include <stdlib.h>

my_exception2 *my_exception2_alloc(void)
{
	my_exception2 *ret;
	ret = malloc(sizeof(*ret));
	ret->life_table = malloc(sizeof(my_exception2_life));
	((my_exception2_life*)(ret->life_table))->base = ret;
	ret->parent1.life_table = ret->life_table;
	ret->parent1.func_table = malloc(sizeof(my_exception2_table));
	((my_exception2_table *)(ret->parent1.func_table))->F__M_Exception_v_init_pc_F = &F__M_Exception_v_init_pc_F_thunkmy_exception2;
	((my_exception2_life *)(ret->life_table))->clean = NULL;
	((my_exception2_life *)(ret->life_table))->delete = &my_exception2_delete;
	return (ret);
}

void my_exception2_delete(my_exception2 *obj)
{
	if (((my_exception2_life *)(obj->life_table))->clean != NULL) {
		((my_exception2_life *)(obj->life_table))->clean(obj);
	}
	free(obj->parent1.func_table);
	free(obj->life_table);
	free(obj);
}

my_exception2 *my_exception2_new(char *p_0)
{
	my_exception2 *self;
	self = my_exception2_alloc();
	F__M_Exception_v_init_pc_F((void *)self, p_0);
	return (self);
}

void my_exception2_INIT_ID(void)
{
	V__my_exception2_i_id_V = KOOC_EXCEPTION_COUNT;
	KOOC_EXCEPTION_COUNT++;
}

void F__M_Exception_v_init_pc_F_thunkmy_exception2(my_exception2 *thunk, char *p1)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( &(((my_exception2 *)((my_exception2_life *)thunk->life_table)->base)->parent1) ), "r" ( F__M_Exception_v_init_pc_F )
            : "%rdi"
            );
            
}

int V__my_exception3_i_id_V;

#include <stdlib.h>

my_exception3 *my_exception3_alloc(void)
{
	my_exception3 *ret;
	ret = malloc(sizeof(*ret));
	ret->life_table = malloc(sizeof(my_exception3_life));
	((my_exception3_life*)(ret->life_table))->base = ret;
	ret->parent1.life_table = ret->life_table;
	ret->parent1.func_table = malloc(sizeof(my_exception3_table));
	((my_exception3_table *)(ret->parent1.func_table))->F__M_Exception_v_init_pc_F = &F__M_Exception_v_init_pc_F_thunkmy_exception3;
	((my_exception3_life *)(ret->life_table))->clean = NULL;
	((my_exception3_life *)(ret->life_table))->delete = &my_exception3_delete;
	return (ret);
}

void my_exception3_delete(my_exception3 *obj)
{
	if (((my_exception3_life *)(obj->life_table))->clean != NULL) {
		((my_exception3_life *)(obj->life_table))->clean(obj);
	}
	free(obj->parent1.func_table);
	free(obj->life_table);
	free(obj);
}

my_exception3 *my_exception3_new(char *p_0)
{
	my_exception3 *self;
	self = my_exception3_alloc();
	F__M_Exception_v_init_pc_F((void *)self, p_0);
	return (self);
}

void my_exception3_INIT_ID(void)
{
	V__my_exception3_i_id_V = KOOC_EXCEPTION_COUNT;
	KOOC_EXCEPTION_COUNT++;
}

void F__M_Exception_v_init_pc_F_thunkmy_exception3(my_exception3 *thunk, char *p1)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( &(((my_exception3 *)((my_exception3_life *)thunk->life_table)->base)->parent1) ), "r" ( F__M_Exception_v_init_pc_F )
            : "%rdi"
            );
            
}

void some_other_func(void)
{
    kooc_global_exception = my_exception3_new("My_exception3 Error Message");
    longjmp(kooc_global_env, V__my_exception3_i_id_V);
}
void some_func(void)
{
    jmp_buf	kooc_local_env;
    #include <string.h>
    memcpy(&kooc_local_env, &kooc_global_env, sizeof(jmp_buf));
    int	kooc_local_ret;
    
    if (!(kooc_local_ret = setjmp(kooc_global_env)))
    {
        some_other_func();
    }
    else
    {
    	#include <string.h>
    	memcpy(&kooc_global_env, &kooc_local_env, sizeof(jmp_buf));
    	if (kooc_local_ret == V__my_exception1_i_id_V)
    {
        my_exception1 *ex = (my_exception1 *) kooc_global_exception;
    }
    	else if (kooc_local_ret == V__my_exception2_i_id_V)
    {
        my_exception2 *ex = (my_exception2 *) kooc_global_exception;
    }
    	else
    	{
    		longjmp(kooc_global_env, kooc_local_ret);
    	}
    }
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
            jmp_buf	kooc_local_env;
            #include <string.h>
            memcpy(&kooc_local_env, &kooc_global_env, sizeof(jmp_buf));
            int	kooc_local_ret;
            
            if (!(kooc_local_ret = setjmp(kooc_global_env)))
            {
                some_func();
            }
            else
            {
            	#include <string.h>
            	memcpy(&kooc_global_env, &kooc_local_env, sizeof(jmp_buf));
            	if (kooc_local_ret == V__my_exception3_i_id_V)
            {
                my_exception3 *ex = (my_exception3 *) kooc_global_exception;
                printf("Catched Exception. Message : %s\n", ex->parent1.V__M_Exception_pc_msg_V);
                return (EXIT_SUCCESS);
            }
            	else
            	{
            		longjmp(kooc_global_env, kooc_local_ret);
            	}
            }
            return (EXIT_FAILURE);
        }
    else
        {
            fprintf(stderr, "Process terminated by an unknown exception\n");
            return (EXIT_FAILURE);
        }
    return (EXIT_SUCCESS);
}
