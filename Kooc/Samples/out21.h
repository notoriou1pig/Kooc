#if defined(__IN21_MODULE_KLAUS__) || defined(__IN21_FILE__)
# ifndef __IN21_MODULE_KLAUS_INC__
#  define __IN21_MODULE_KLAUS_INC__


/**********************************
 ** class klaus
 **********************************/


typedef struct s_klaus klaus;


/**********************************
 ** class klaus vtable
 **********************************/

typedef struct s_klaus_table {
	int (*F__M_klaus_i_my_putchar_F)(klaus *);
	int (*F__M_klaus_i_my_putchar2_F)(klaus *);
} klaus_table;


/**********************************
 ** class klaus life cycle
 **********************************/

typedef struct s_klaus_life {
	void *base;
	void (*delete)(klaus *);
	void (*clean)(klaus *);
} klaus_life;


/**********************************
 ** class klaus struct
 **********************************/

struct s_klaus {
	void *func_table;

	void *life_table;

};


/**********************************
 ** class klaus members
 **********************************/

int F__M_klaus_i_my_putchar_F(klaus *);
int F__M_klaus_i_my_putchar2_F(klaus *);

klaus *klaus_alloc(void);
void klaus_delete(klaus *);
klaus *klaus_new(void);

/**********************************
 ** class klaus thunk functions
 **********************************/

int F__M_klaus_i_my_putchar_F_thunkklaus(klaus *);
int F__M_klaus_i_my_putchar2_F_thunkklaus(klaus *);

/**********************************
 ** class klaus non-members
 **********************************/



# endif
#endif
