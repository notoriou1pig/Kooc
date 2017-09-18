#if defined(__MODULE_GARBAGE__) || defined(__IN10_FILE__)
#ifndef __MODULE_GARBAGE_INC__
#define __MODULE_GARBAGE_INC__

int my_putstr(char *);

#endif
#endif

#if defined(__IN10_MODULE_KLAUSS__) || defined(__IN10_FILE__)
# ifndef __IN10_MODULE_KLAUSS_INC__
#  define __IN10_MODULE_KLAUSS_INC__


/**********************************
 ** class klauss
 **********************************/


typedef struct s_klauss klauss;


/**********************************
 ** class klauss vtable
 **********************************/

typedef struct s_klauss_table {
	void (*F__M_klauss_v_my_putchar_c_F)(klauss *, char);
} klauss_table;


/**********************************
 ** class klauss life cycle
 **********************************/

typedef struct s_klauss_life {
	void *base;
	void (*delete)(klauss *);
	void (*clean)(klauss *);
} klauss_life;


/**********************************
 ** class klauss struct
 **********************************/

struct s_klauss {
	void *func_table;

	void *life_table;

	char V__M_klauss_c_b_V;
	float V__M_klauss_f_c_V;
};


/**********************************
 ** class klauss members
 **********************************/

void F__M_klauss_v_my_putchar_c_F(klauss *, char);

klauss *klauss_alloc(void);
void klauss_delete(klauss *);
klauss *klauss_new(void);

/**********************************
 ** class klauss thunk functions
 **********************************/

void F__M_klauss_v_my_putchar_c_F_thunkklauss(klauss *, char p1);

/**********************************
 ** class klauss non-members
 **********************************/

void F__klauss_v_my_putchar_c_F(char);
extern int V__klauss_i_a_V;
extern double V__klauss_d_d_V;
extern char **V__klauss_ppc_tab_V;
extern char *V__klauss_pc_str_V;
extern int V__klauss_pi_tab_V[3];


# endif
#endif
