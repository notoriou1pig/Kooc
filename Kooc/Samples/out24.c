#include <setjmp.h>
extern jmp_buf kooc_global_env;
#include <stdlib.h>
#include <stdio.h>
#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#ifndef __IN24_FILE__
#define __IN24_FILE__
#include "in24.h"
#endif /* __IN24_FILE__ */

int V__my_exception_i_id_V;

#include <stdlib.h>

my_exception *my_exception_alloc(void)
{
	my_exception *ret;
	ret = malloc(sizeof(*ret));
	ret->life_table = malloc(sizeof(my_exception_life));
	((my_exception_life*)(ret->life_table))->base = ret;
	ret->parent1.life_table = ret->life_table;
	ret->parent1.func_table = malloc(sizeof(my_exception_table));
	((my_exception_table *)(ret->parent1.func_table))->F__M_Exception_v_init_pc_F = &F__M_Exception_v_init_pc_F_thunkmy_exception;
	((my_exception_life *)(ret->life_table))->clean = NULL;
	((my_exception_life *)(ret->life_table))->delete = &my_exception_delete;
	return (ret);
}

void my_exception_delete(my_exception *obj)
{
	if (((my_exception_life *)(obj->life_table))->clean != NULL) {
		((my_exception_life *)(obj->life_table))->clean(obj);
	}
	free(obj->parent1.func_table);
	free(obj->life_table);
	free(obj);
}

my_exception *my_exception_new(char *p_0)
{
	my_exception *self;
	self = my_exception_alloc();
	F__M_Exception_v_init_pc_F((void *)self, p_0);
	return (self);
}

void my_exception_INIT_ID(void)
{
	V__my_exception_i_id_V = KOOC_EXCEPTION_COUNT;
	KOOC_EXCEPTION_COUNT++;
}

void F__M_Exception_v_init_pc_F_thunkmy_exception(my_exception *thunk, char *p1)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( &(((my_exception *)((my_exception_life *)thunk->life_table)->base)->parent1) ), "r" ( F__M_Exception_v_init_pc_F )
            : "%rdi"
            );
            
}

void some_func(void)
{
    kooc_global_exception = my_exception_new("An error occured");
    longjmp(kooc_global_env, V__my_exception_i_id_V);
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
            	if (kooc_local_ret == V__my_exception_i_id_V)
            {
                my_exception *ex = (my_exception *) kooc_global_exception;
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
