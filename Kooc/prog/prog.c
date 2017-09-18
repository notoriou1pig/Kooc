#include <setjmp.h>
extern jmp_buf kooc_global_env;
#include <stdlib.h>
#include <stdio.h>
#include <setjmp.h>
#include <string.h>
#include <stdio.h>
#ifndef __PROG_MODULE_CALC__
#define __PROG_MODULE_CALC__
#include "prog.h"
#endif /* __PROG_MODULE_CALC__ */

#ifndef __PROG_MODULE_ANIMAL__
#define __PROG_MODULE_ANIMAL__
#include "prog.h"
#endif /* __PROG_MODULE_ANIMAL__ */

#ifndef __PROG_MODULE_PROF__
#define __PROG_MODULE_PROF__
#include "prog.h"
#endif /* __PROG_MODULE_PROF__ */

#ifndef __PROG_MODULE_KOALA__
#define __PROG_MODULE_KOALA__
#include "prog.h"
#endif /* __PROG_MODULE_KOALA__ */

#ifndef __PROG_MODULE_BABOUCHE__
#define __PROG_MODULE_BABOUCHE__
#include "prog.h"
#endif /* __PROG_MODULE_BABOUCHE__ */


void F__M_Animal_v_scream_F(Animal *self)
{
    printf("(unkown animal type)");
}

#include <stdlib.h>

Animal *Animal_alloc(void)
{
	Animal *ret;
	ret = malloc(sizeof(*ret));
	ret->life_table = malloc(sizeof(Animal_life));
	((Animal_life*)(ret->life_table))->base = ret;
	ret->func_table = malloc(sizeof(Animal_table));
	((Animal_table *)(ret->func_table))->F__M_Animal_v_scream_F = &F__M_Animal_v_scream_F_thunkAnimal;
	((Animal_table *)(ret->func_table))->F__M__v_scream_F = &F__M_Animal_v_scream_F_thunkAnimal;
	((Animal_life *)(ret->life_table))->clean = NULL;
	((Animal_life *)(ret->life_table))->delete = &Animal_delete;
	return (ret);
}

void Animal_delete(Animal *obj)
{
	if (((Animal_life *)(obj->life_table))->clean != NULL) {
		((Animal_life *)(obj->life_table))->clean(obj);
	}
	free(obj->func_table);
	free(obj->life_table);
	free(obj);
}

Animal *Animal_new(void)
{
	Animal *self;
	self = Animal_alloc();
	return (self);
}

void F__M_Animal_v_scream_F_thunkAnimal(Animal *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( (((Animal *)((Animal_life *)thunk->life_table)->base)) ), "r" ( F__M_Animal_v_scream_F )
            : "%rdi"
            );
            
}

void F__M__v_scream_F_thunkAnimal(Animal *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( (((Animal *)((Animal_life *)thunk->life_table)->base)) ), "r" ( F__M_Animal_v_scream_F )
            : "%rdi"
            );
            
}

int V__Calc_i_res_V = 0;
double V__Calc_d_res_V = 0;

int F__Calc_i_add_i_i_F(int a, int b)
{
    V__Calc_i_res_V = a + b;
    printf("adding int\n");
    return V__Calc_i_res_V;
}

double F__Calc_d_add_d_d_F(double a, double b)
{
    V__Calc_d_res_V = a + b;
    printf("adding double\n");
    return V__Calc_d_res_V;
}

void F__Calc_v_print_i_F(int type)
{
    if (type)
        {
            printf("int = %d\n", V__Calc_i_res_V);
        }
    else
        {
            printf("double = %f\n", V__Calc_d_res_V);
        }
}


void F__M_Prof_v_enseigner_F(Prof *self)
{
    printf("A great power comes with a great responsibility !\n");
}

#include <stdlib.h>

Prof *Prof_alloc(void)
{
	Prof *ret;
	ret = malloc(sizeof(*ret));
	ret->life_table = malloc(sizeof(Prof_life));
	((Prof_life*)(ret->life_table))->base = ret;
	ret->func_table = malloc(sizeof(Prof_table));
	((Prof_table *)(ret->func_table))->F__M_Prof_v_enseigner_F = &F__M_Prof_v_enseigner_F_thunkProf;
	((Prof_table *)(ret->func_table))->F__M__v_enseigner_F = &F__M_Prof_v_enseigner_F_thunkProf;
	((Prof_life *)(ret->life_table))->clean = NULL;
	((Prof_life *)(ret->life_table))->delete = &Prof_delete;
	return (ret);
}

void Prof_delete(Prof *obj)
{
	if (((Prof_life *)(obj->life_table))->clean != NULL) {
		((Prof_life *)(obj->life_table))->clean(obj);
	}
	free(obj->func_table);
	free(obj->life_table);
	free(obj);
}

Prof *Prof_new(void)
{
	Prof *self;
	self = Prof_alloc();
	return (self);
}

void F__M_Prof_v_enseigner_F_thunkProf(Prof *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( (((Prof *)((Prof_life *)thunk->life_table)->base)) ), "r" ( F__M_Prof_v_enseigner_F )
            : "%rdi"
            );
            
}

void F__M__v_enseigner_F_thunkProf(Prof *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( (((Prof *)((Prof_life *)thunk->life_table)->base)) ), "r" ( F__M_Prof_v_enseigner_F )
            : "%rdi"
            );
            
}


void F__M_Student_v_learn_F(Student *self)
{
    printf("I love junk food !");
}

#include <stdlib.h>

Student *Student_alloc(void)
{
	Student *ret;
	ret = malloc(sizeof(*ret));
	ret->life_table = malloc(sizeof(Student_life));
	((Student_life*)(ret->life_table))->base = ret;
	ret->func_table = malloc(sizeof(Student_table));
	((Student_table *)(ret->func_table))->F__M_Student_v_learn_F = &F__M_Student_v_learn_F_thunkStudent;
	((Student_table *)(ret->func_table))->F__M__v_learn_F = &F__M_Student_v_learn_F_thunkStudent;
	((Student_life *)(ret->life_table))->clean = NULL;
	((Student_life *)(ret->life_table))->delete = &Student_delete;
	return (ret);
}

void Student_delete(Student *obj)
{
	if (((Student_life *)(obj->life_table))->clean != NULL) {
		((Student_life *)(obj->life_table))->clean(obj);
	}
	free(obj->func_table);
	free(obj->life_table);
	free(obj);
}

Student *Student_new(void)
{
	Student *self;
	self = Student_alloc();
	return (self);
}

void F__M_Student_v_learn_F_thunkStudent(Student *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( (((Student *)((Student_life *)thunk->life_table)->base)) ), "r" ( F__M_Student_v_learn_F )
            : "%rdi"
            );
            
}

void F__M__v_learn_F_thunkStudent(Student *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( (((Student *)((Student_life *)thunk->life_table)->base)) ), "r" ( F__M_Student_v_learn_F )
            : "%rdi"
            );
            
}


void F__M_Koala_v_setColor_pc_F(Koala *self, char *color)
{
    self->V__M_Koala_pc_color_V = strdup(color);
}

char *F__M_Koala_pc_whichColor_F(Koala *self)
{
    char *tmp = self->V__M_Koala_pc_color_V;
    return tmp;
}

void F__M_Koala_v_scream_F(Koala *self)
{
    printf("GROAAAR\n");
}

#include <stdlib.h>

Koala *Koala_alloc(void)
{
	Koala *ret;
	ret = malloc(sizeof(*ret));
	ret->life_table = malloc(sizeof(Koala_life));
	((Koala_life*)(ret->life_table))->base = ret;
	ret->parent1.life_table = ret->life_table;
	ret->parent2.life_table = ret->life_table;
	ret->parent1.func_table = malloc(sizeof(Koala_table));
	ret->parent2.func_table = ret->parent1.func_table + sizeof(Animal_table);
	((Koala_table *)(ret->parent1.func_table))->F__M_Animal_v_scream_F = &F__M_Animal_v_scream_F_thunkKoala;
	((Koala_table *)(ret->parent1.func_table))->F__M__v_scream_F = &F__M_Koala_v_scream_F_thunkKoala;
	((Koala_table *)(ret->parent1.func_table))->F__M_Prof_v_enseigner_F = &F__M_Prof_v_enseigner_F_thunkKoala;
	((Koala_table *)(ret->parent1.func_table))->F__M__v_enseigner_F = &F__M_Prof_v_enseigner_F_thunkKoala;
	((Koala_table *)(ret->parent1.func_table))->F__M_Koala_v_setColor_pc_F = &F__M_Koala_v_setColor_pc_F_thunkKoala;
	((Koala_table *)(ret->parent1.func_table))->F__M_Koala_pc_whichColor_F = &F__M_Koala_pc_whichColor_F_thunkKoala;
	((Koala_table *)(ret->parent1.func_table))->F__M_Koala_v_scream_F = &F__M_Koala_v_scream_F_thunkKoala;
	((Koala_life *)(ret->life_table))->clean = NULL;
	((Koala_life *)(ret->life_table))->delete = &Koala_delete;
	return (ret);
}

void Koala_delete(Koala *obj)
{
	if (((Koala_life *)(obj->life_table))->clean != NULL) {
		((Koala_life *)(obj->life_table))->clean(obj);
	}
	free(obj->parent1.func_table);
	free(obj->life_table);
	free(obj);
}

Koala *Koala_new(void)
{
	Koala *self;
	self = Koala_alloc();
	return (self);
}

void F__M_Animal_v_scream_F_thunkKoala(Koala *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( &(((Koala *)((Koala_life *)thunk->life_table)->base)->parent1) ), "r" ( F__M_Animal_v_scream_F )
            : "%rdi"
            );
            
}

void F__M__v_scream_F_thunkKoala(Koala *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( (((Koala *)((Koala_life *)thunk->life_table)->base)) ), "r" ( F__M_Koala_v_scream_F )
            : "%rdi"
            );
            
}

void F__M_Prof_v_enseigner_F_thunkKoala(Koala *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( &(((Koala *)((Koala_life *)thunk->life_table)->base)->parent2) ), "r" ( F__M_Prof_v_enseigner_F )
            : "%rdi"
            );
            
}

void F__M__v_enseigner_F_thunkKoala(Koala *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( &(((Koala *)((Koala_life *)thunk->life_table)->base)->parent2) ), "r" ( F__M_Prof_v_enseigner_F )
            : "%rdi"
            );
            
}

void F__M_Koala_v_setColor_pc_F_thunkKoala(Koala *thunk, char *p1)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( (((Koala *)((Koala_life *)thunk->life_table)->base)) ), "r" ( F__M_Koala_v_setColor_pc_F )
            : "%rdi"
            );
            
}

char *F__M_Koala_pc_whichColor_F_thunkKoala(Koala *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( (((Koala *)((Koala_life *)thunk->life_table)->base)) ), "r" ( F__M_Koala_pc_whichColor_F )
            : "%rdi"
            );
            
}

void F__M_Koala_v_scream_F_thunkKoala(Koala *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( (((Koala *)((Koala_life *)thunk->life_table)->base)) ), "r" ( F__M_Koala_v_scream_F )
            : "%rdi"
            );
            
}


void F__M_Babouche_v_init_pc_F(Babouche *self, char *_name)
{
    self->V__M_Babouche_pc_name_V = strdup(_name);
}

void F__M_Babouche_v_scream_F(Babouche *self)
{
    printf("%s says : beeeuuuuhet !\n", self->V__M_Babouche_pc_name_V);
}

#include <stdlib.h>

Babouche *Babouche_alloc(void)
{
	Babouche *ret;
	ret = malloc(sizeof(*ret));
	ret->life_table = malloc(sizeof(Babouche_life));
	((Babouche_life*)(ret->life_table))->base = ret;
	ret->parent1.life_table = ret->life_table;
	ret->parent2.life_table = ret->life_table;
	ret->parent1.func_table = malloc(sizeof(Babouche_table));
	ret->parent2.func_table = ret->parent1.func_table + sizeof(Animal_table);
	((Babouche_table *)(ret->parent1.func_table))->F__M_Animal_v_scream_F = &F__M_Animal_v_scream_F_thunkBabouche;
	((Babouche_table *)(ret->parent1.func_table))->F__M__v_scream_F = &F__M_Babouche_v_scream_F_thunkBabouche;
	((Babouche_table *)(ret->parent1.func_table))->F__M_Student_v_learn_F = &F__M_Student_v_learn_F_thunkBabouche;
	((Babouche_table *)(ret->parent1.func_table))->F__M__v_learn_F = &F__M_Student_v_learn_F_thunkBabouche;
	((Babouche_table *)(ret->parent1.func_table))->F__M_Babouche_v_init_pc_F = &F__M_Babouche_v_init_pc_F_thunkBabouche;
	((Babouche_table *)(ret->parent1.func_table))->F__M_Babouche_v_scream_F = &F__M_Babouche_v_scream_F_thunkBabouche;
	((Babouche_life *)(ret->life_table))->clean = NULL;
	((Babouche_life *)(ret->life_table))->delete = &Babouche_delete;
	return (ret);
}

void Babouche_delete(Babouche *obj)
{
	if (((Babouche_life *)(obj->life_table))->clean != NULL) {
		((Babouche_life *)(obj->life_table))->clean(obj);
	}
	free(obj->parent1.func_table);
	free(obj->life_table);
	free(obj);
}

Babouche *Babouche_new(char *p_0)
{
	Babouche *self;
	self = Babouche_alloc();
	F__M_Babouche_v_init_pc_F((void *)self, p_0);
	return (self);
}

void F__M_Animal_v_scream_F_thunkBabouche(Babouche *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( &(((Babouche *)((Babouche_life *)thunk->life_table)->base)->parent1) ), "r" ( F__M_Animal_v_scream_F )
            : "%rdi"
            );
            
}

void F__M__v_scream_F_thunkBabouche(Babouche *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( (((Babouche *)((Babouche_life *)thunk->life_table)->base)) ), "r" ( F__M_Babouche_v_scream_F )
            : "%rdi"
            );
            
}

void F__M_Student_v_learn_F_thunkBabouche(Babouche *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( &(((Babouche *)((Babouche_life *)thunk->life_table)->base)->parent2) ), "r" ( F__M_Student_v_learn_F )
            : "%rdi"
            );
            
}

void F__M__v_learn_F_thunkBabouche(Babouche *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( &(((Babouche *)((Babouche_life *)thunk->life_table)->base)->parent2) ), "r" ( F__M_Student_v_learn_F )
            : "%rdi"
            );
            
}

void F__M_Babouche_v_init_pc_F_thunkBabouche(Babouche *thunk, char *p1)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( (((Babouche *)((Babouche_life *)thunk->life_table)->base)) ), "r" ( F__M_Babouche_v_init_pc_F )
            : "%rdi"
            );
            
}

void F__M_Babouche_v_scream_F_thunkBabouche(Babouche *thunk)
{
            asm("mov %0, %%rdi;"
            "call *%1;"
            : 
            : "r" ( (((Babouche *)((Babouche_life *)thunk->life_table)->base)) ), "r" ( F__M_Babouche_v_scream_F )
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
            printf("%d + %d = %d\n", 42, 42, F__Calc_i_add_i_i_F(42, 42));
            F__Calc_v_print_i_F(1);
            printf("\n");
            printf("%f + %f = %f\n", 42.2, 42.2, F__Calc_d_add_d_d_F(42.2, 42.2));
            F__Calc_v_print_i_F(0);
            Koala *k = Koala_new();
            Koala *l = Koala_new();
            Babouche *anonyme = Babouche_new("undisclosed identity");
            ((Koala_table *)k->parent1.func_table)->F__M_Koala_v_setColor_pc_F((void *)k, "black and white");
            ((Koala_table *)l->parent1.func_table)->F__M_Koala_v_setColor_pc_F((void *)l, "red and blue");
            printf("k is %p and l is %p\n", ((Koala_table *)k->parent1.func_table)->F__M_Koala_pc_whichColor_F((void *)k), ((Koala_table *)l->parent1.func_table)->F__M_Koala_pc_whichColor_F((void *)l));
            printf("k is %s and l is %s\n", ((Koala_table *)k->parent1.func_table)->F__M_Koala_pc_whichColor_F((void *)k), ((Koala_table *)l->parent1.func_table)->F__M_Koala_pc_whichColor_F((void *)l));
            ((Koala_table *)k->parent1.func_table)->F__M_Koala_v_scream_F((void *)k);
            ((Koala_table *)l->parent1.func_table)->F__M_Koala_v_scream_F((void *)l);
            ((Koala_table *)k->parent1.func_table)->F__M_Prof_v_enseigner_F((void *)k);
            ((Babouche_table *)anonyme->parent1.func_table)->F__M_Babouche_v_scream_F((void *)anonyme);
            return 0;
        }
    else
        {
            fprintf(stderr, "Process terminated by an unknown exception\n");
            return (EXIT_FAILURE);
        }
    return (EXIT_SUCCESS);
}
