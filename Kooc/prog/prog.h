#if defined(__MODULE_CALC__) || defined(__PROG_FILE__)
#ifndef __MODULE_CALC_INC__
#define __MODULE_CALC_INC__

extern int V__Calc_i_res_V;
extern double V__Calc_d_res_V;
int F__Calc_i_add_i_i_F(int, int);
double F__Calc_d_add_d_d_F(double, double);
void F__Calc_v_print_i_F(int);

#endif
#endif

#if defined(__PROG_MODULE_ANIMAL__) || defined(__PROG_FILE__) || defined(__PROG_MODULE_KOALA__) || defined(__PROG_MODULE_BABOUCHE__)
# ifndef __PROG_MODULE_ANIMAL_INC__
#  define __PROG_MODULE_ANIMAL_INC__


/**********************************
 ** class Animal
 **********************************/


typedef struct s_Animal Animal;


/**********************************
 ** class Animal vtable
 **********************************/

typedef struct s_Animal_table {
	void (*F__M_Animal_v_scream_F)(Animal *);
	void (*F__M__v_scream_F)(Animal *);
} Animal_table;


/**********************************
 ** class Animal life cycle
 **********************************/

typedef struct s_Animal_life {
	void *base;
	void (*delete)(Animal *);
	void (*clean)(Animal *);
} Animal_life;


/**********************************
 ** class Animal struct
 **********************************/

struct s_Animal {
	void *func_table;

	void *life_table;

};


/**********************************
 ** class Animal members
 **********************************/

void F__M_Animal_v_scream_F(Animal *);

Animal *Animal_alloc(void);
void Animal_delete(Animal *);
Animal *Animal_new(void);

/**********************************
 ** class Animal thunk functions
 **********************************/

void F__M_Animal_v_scream_F_thunkAnimal(Animal *);
void F__M__v_scream_F_thunkAnimal(Animal *);

/**********************************
 ** class Animal non-members
 **********************************/



# endif
#endif
#if defined(__PROG_MODULE_PROF__) || defined(__PROG_FILE__) || defined(__PROG_MODULE_KOALA__)
# ifndef __PROG_MODULE_PROF_INC__
#  define __PROG_MODULE_PROF_INC__


/**********************************
 ** class Prof
 **********************************/


typedef struct s_Prof Prof;


/**********************************
 ** class Prof vtable
 **********************************/

typedef struct s_Prof_table {
	void (*F__M_Prof_v_enseigner_F)(Prof *);
	void (*F__M__v_enseigner_F)(Prof *);
} Prof_table;


/**********************************
 ** class Prof life cycle
 **********************************/

typedef struct s_Prof_life {
	void *base;
	void (*delete)(Prof *);
	void (*clean)(Prof *);
} Prof_life;


/**********************************
 ** class Prof struct
 **********************************/

struct s_Prof {
	void *func_table;

	void *life_table;

};


/**********************************
 ** class Prof members
 **********************************/

void F__M_Prof_v_enseigner_F(Prof *);

Prof *Prof_alloc(void);
void Prof_delete(Prof *);
Prof *Prof_new(void);

/**********************************
 ** class Prof thunk functions
 **********************************/

void F__M_Prof_v_enseigner_F_thunkProf(Prof *);
void F__M__v_enseigner_F_thunkProf(Prof *);

/**********************************
 ** class Prof non-members
 **********************************/



# endif
#endif
#if defined(__PROG_MODULE_STUDENT__) || defined(__PROG_FILE__) || defined(__PROG_MODULE_BABOUCHE__)
# ifndef __PROG_MODULE_STUDENT_INC__
#  define __PROG_MODULE_STUDENT_INC__


/**********************************
 ** class Student
 **********************************/


typedef struct s_Student Student;


/**********************************
 ** class Student vtable
 **********************************/

typedef struct s_Student_table {
	void (*F__M_Student_v_learn_F)(Student *);
	void (*F__M__v_learn_F)(Student *);
} Student_table;


/**********************************
 ** class Student life cycle
 **********************************/

typedef struct s_Student_life {
	void *base;
	void (*delete)(Student *);
	void (*clean)(Student *);
} Student_life;


/**********************************
 ** class Student struct
 **********************************/

struct s_Student {
	void *func_table;

	void *life_table;

};


/**********************************
 ** class Student members
 **********************************/

void F__M_Student_v_learn_F(Student *);

Student *Student_alloc(void);
void Student_delete(Student *);
Student *Student_new(void);

/**********************************
 ** class Student thunk functions
 **********************************/

void F__M_Student_v_learn_F_thunkStudent(Student *);
void F__M__v_learn_F_thunkStudent(Student *);

/**********************************
 ** class Student non-members
 **********************************/



# endif
#endif
#if defined(__PROG_MODULE_KOALA__) || defined(__PROG_FILE__)
# ifndef __PROG_MODULE_KOALA_INC__
#  define __PROG_MODULE_KOALA_INC__


/**********************************
 ** class Koala
 **********************************/


typedef struct s_Koala Koala;


/**********************************
 ** class Koala vtable
 **********************************/

typedef struct s_Koala_table {
	void (*F__M_Animal_v_scream_F)(Animal *);
	void (*F__M__v_scream_F)(Koala *);
	void (*F__M_Prof_v_enseigner_F)(Prof *);
	void (*F__M__v_enseigner_F)(Prof *);
	void (*F__M_Koala_v_setColor_pc_F)(Koala *, char *);
	char *(*F__M_Koala_pc_whichColor_F)(Koala *);
	void (*F__M_Koala_v_scream_F)(Koala *);
} Koala_table;


/**********************************
 ** class Koala life cycle
 **********************************/

typedef struct s_Koala_life {
	void *base;
	void (*delete)(Koala *);
	void (*clean)(Koala *);
} Koala_life;


/**********************************
 ** class Koala struct
 **********************************/

struct s_Koala {
	Animal parent1;
	Prof parent2;

	void *life_table;

	char *V__M_Koala_pc_color_V;
};


/**********************************
 ** class Koala members
 **********************************/

void F__M_Koala_v_setColor_pc_F(Koala *, char *);
char *F__M_Koala_pc_whichColor_F(Koala *);
void F__M_Koala_v_scream_F(Koala *);

Koala *Koala_alloc(void);
void Koala_delete(Koala *);
Koala *Koala_new(void);

/**********************************
 ** class Koala thunk functions
 **********************************/

void F__M_Animal_v_scream_F_thunkKoala(Koala *);
void F__M__v_scream_F_thunkKoala(Koala *);
void F__M_Prof_v_enseigner_F_thunkKoala(Koala *);
void F__M__v_enseigner_F_thunkKoala(Koala *);
void F__M_Koala_v_setColor_pc_F_thunkKoala(Koala *, char *p1);
char *F__M_Koala_pc_whichColor_F_thunkKoala(Koala *);
void F__M_Koala_v_scream_F_thunkKoala(Koala *);

/**********************************
 ** class Koala non-members
 **********************************/



# endif
#endif
#if defined(__PROG_MODULE_BABOUCHE__) || defined(__PROG_FILE__)
# ifndef __PROG_MODULE_BABOUCHE_INC__
#  define __PROG_MODULE_BABOUCHE_INC__


/**********************************
 ** class Babouche
 **********************************/


typedef struct s_Babouche Babouche;


/**********************************
 ** class Babouche vtable
 **********************************/

typedef struct s_Babouche_table {
	void (*F__M_Animal_v_scream_F)(Animal *);
	void (*F__M__v_scream_F)(Babouche *);
	void (*F__M_Student_v_learn_F)(Student *);
	void (*F__M__v_learn_F)(Student *);
	void (*F__M_Babouche_v_init_pc_F)(Babouche *, char *name);
	void (*F__M_Babouche_v_scream_F)(Babouche *);
} Babouche_table;


/**********************************
 ** class Babouche life cycle
 **********************************/

typedef struct s_Babouche_life {
	void *base;
	void (*delete)(Babouche *);
	void (*clean)(Babouche *);
} Babouche_life;


/**********************************
 ** class Babouche struct
 **********************************/

struct s_Babouche {
	Animal parent1;
	Student parent2;

	void *life_table;

	char *V__M_Babouche_pc_name_V;
};


/**********************************
 ** class Babouche members
 **********************************/

void F__M_Babouche_v_init_pc_F(Babouche *, char *name);
void F__M_Babouche_v_scream_F(Babouche *);

Babouche *Babouche_alloc(void);
void Babouche_delete(Babouche *);
Babouche *Babouche_new(char *name);

/**********************************
 ** class Babouche thunk functions
 **********************************/

void F__M_Animal_v_scream_F_thunkBabouche(Babouche *);
void F__M__v_scream_F_thunkBabouche(Babouche *);
void F__M_Student_v_learn_F_thunkBabouche(Babouche *);
void F__M__v_learn_F_thunkBabouche(Babouche *);
void F__M_Babouche_v_init_pc_F_thunkBabouche(Babouche *, char *p1);
void F__M_Babouche_v_scream_F_thunkBabouche(Babouche *);

/**********************************
 ** class Babouche non-members
 **********************************/



# endif
#endif
