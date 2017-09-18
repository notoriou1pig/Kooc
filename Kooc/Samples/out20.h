#if defined(__IN20_MODULE_TOTO__) || defined(__IN20_FILE__)
# ifndef __IN20_MODULE_TOTO_INC__
#  define __IN20_MODULE_TOTO_INC__


/**********************************
 ** class Toto
 **********************************/


typedef struct s_Toto Toto;


/**********************************
 ** class Toto vtable
 **********************************/

typedef struct s_Toto_table {
	int (*F__M_Toto_i_funcb_c_c_i_F)(Toto *, char, char, int);
} Toto_table;


/**********************************
 ** class Toto life cycle
 **********************************/

typedef struct s_Toto_life {
	void *base;
	void (*delete)(Toto *);
	void (*clean)(Toto *);
} Toto_life;


/**********************************
 ** class Toto struct
 **********************************/

struct s_Toto {
	void *func_table;

	void *life_table;

	char V__M_Toto_c_i_V;
	int V__M_Toto_i_p_V;
};


/**********************************
 ** class Toto members
 **********************************/

int F__M_Toto_i_funcb_c_c_i_F(Toto *, char, char, int);

Toto *Toto_alloc(void);
void Toto_delete(Toto *);
Toto *Toto_new(void);

/**********************************
 ** class Toto thunk functions
 **********************************/

int F__M_Toto_i_funcb_c_c_i_F_thunkToto(Toto *, char p1, char p2, int p3);

/**********************************
 ** class Toto non-members
 **********************************/



# endif
#endif
#if defined(__MODULE_TEST__) || defined(__IN20_FILE__)
#ifndef __MODULE_TEST_INC__
#define __MODULE_TEST_INC__

extern char V__Test_c_i_V;

#endif
#endif

