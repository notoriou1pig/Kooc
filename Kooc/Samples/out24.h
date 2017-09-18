#ifndef __EXCEPTION_FILE__
#define __EXCEPTION_FILE__
#include "Exception.h"
#endif /* __EXCEPTION_FILE__ */

#if defined(__IN24_MODULE_MY_EXCEPTION__) || defined(__IN24_FILE__)
# ifndef __IN24_MODULE_MY_EXCEPTION_INC__
#  define __IN24_MODULE_MY_EXCEPTION_INC__


/**********************************
 ** class my_exception
 **********************************/


typedef struct s_my_exception my_exception;


/**********************************
 ** class my_exception vtable
 **********************************/

typedef struct s_my_exception_table {
	void (*F__M_Exception_v_init_pc_F)(Exception *, char *);
} my_exception_table;


/**********************************
 ** class my_exception life cycle
 **********************************/

typedef struct s_my_exception_life {
	void *base;
	void (*delete)(my_exception *);
	void (*clean)(my_exception *);
} my_exception_life;


/**********************************
 ** class my_exception struct
 **********************************/

struct s_my_exception {
	Exception parent1;

	void *life_table;

};


/**********************************
 ** class my_exception members
 **********************************/


my_exception *my_exception_alloc(void);
void my_exception_delete(my_exception *);
my_exception *my_exception_new(char *);

/**********************************
 ** class my_exception thunk functions
 **********************************/

void F__M_Exception_v_init_pc_F_thunkmy_exception(my_exception *, char *p1);

/**********************************
 ** class my_exception non-members
 **********************************/

extern int V__my_exception_i_id_V;


/**********************************
 ** Globales variables for Exceptions
 **********************************/

extern int KOOC_EXCEPTION_COUNT;

#include <setjmp.h>
extern jmp_buf kooc_global_env;

extern Exception *kooc_global_exception;



/**********************************
 ** Initialisation Id Exception
 **********************************/

void my_exception_INIT_ID(void) __attribute__((constructor));


# endif
#endif
