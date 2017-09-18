#if defined(__IN11_MODULE_TOTO__) || defined(__IN11_FILE__)
# ifndef __IN11_MODULE_TOTO_INC__
#  define __IN11_MODULE_TOTO_INC__


/**********************************
 ** class Toto
 **********************************/


typedef struct s_Toto Toto;


/**********************************
 ** class Toto vtable
 **********************************/

typedef struct s_Toto_table {
	int (*F__M_Toto_i_funcb_i_i_i_F)(Toto *, int, int, int);
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

	int V__M_Toto_i_i_V;
	int V__M_Toto_i_p_V;
};


/**********************************
 ** class Toto members
 **********************************/

int F__M_Toto_i_funcb_i_i_i_F(Toto *, int, int, int);

Toto *Toto_alloc(void);
void Toto_delete(Toto *);
Toto *Toto_new(void);

/**********************************
 ** class Toto thunk functions
 **********************************/

int F__M_Toto_i_funcb_i_i_i_F_thunkToto(Toto *, int p1, int p2, int p3);

/**********************************
 ** class Toto non-members
 **********************************/



# endif
#endif
