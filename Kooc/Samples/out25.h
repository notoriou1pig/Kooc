#ifndef __EXCEPTION_FILE__
#define __EXCEPTION_FILE__
#include "Exception.h"
#endif /* __EXCEPTION_FILE__ */

#if defined(__IN25_MODULE_MY_EXCEPTION1__) || defined(__IN25_FILE__)
# ifndef __IN25_MODULE_MY_EXCEPTION1_INC__
#  define __IN25_MODULE_MY_EXCEPTION1_INC__


/**********************************
 ** class my_exception1
 **********************************/


typedef struct s_my_exception1 my_exception1;


/**********************************
 ** class my_exception1 vtable
 **********************************/

typedef struct s_my_exception1_table {
	void (*F__M_Exception_v_init_pc_F)(Exception *, char *);
} my_exception1_table;


/**********************************
 ** class my_exception1 life cycle
 **********************************/

typedef struct s_my_exception1_life {
	void *base;
	void (*delete)(my_exception1 *);
	void (*clean)(my_exception1 *);
} my_exception1_life;


/**********************************
 ** class my_exception1 struct
 **********************************/

struct s_my_exception1 {
	Exception parent1;

	void *life_table;

};


/**********************************
 ** class my_exception1 members
 **********************************/


my_exception1 *my_exception1_alloc(void);
void my_exception1_delete(my_exception1 *);
my_exception1 *my_exception1_new(char *);

/**********************************
 ** class my_exception1 thunk functions
 **********************************/

void F__M_Exception_v_init_pc_F_thunkmy_exception1(my_exception1 *, char *p1);

/**********************************
 ** class my_exception1 non-members
 **********************************/

extern int V__my_exception1_i_id_V;


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

void my_exception1_INIT_ID(void) __attribute__((constructor));


# endif
#endif
#if defined(__IN25_MODULE_MY_EXCEPTION2__) || defined(__IN25_FILE__)
# ifndef __IN25_MODULE_MY_EXCEPTION2_INC__
#  define __IN25_MODULE_MY_EXCEPTION2_INC__


/**********************************
 ** class my_exception2
 **********************************/


typedef struct s_my_exception2 my_exception2;


/**********************************
 ** class my_exception2 vtable
 **********************************/

typedef struct s_my_exception2_table {
	void (*F__M_Exception_v_init_pc_F)(Exception *, char *);
} my_exception2_table;


/**********************************
 ** class my_exception2 life cycle
 **********************************/

typedef struct s_my_exception2_life {
	void *base;
	void (*delete)(my_exception2 *);
	void (*clean)(my_exception2 *);
} my_exception2_life;


/**********************************
 ** class my_exception2 struct
 **********************************/

struct s_my_exception2 {
	Exception parent1;

	void *life_table;

};


/**********************************
 ** class my_exception2 members
 **********************************/


my_exception2 *my_exception2_alloc(void);
void my_exception2_delete(my_exception2 *);
my_exception2 *my_exception2_new(char *);

/**********************************
 ** class my_exception2 thunk functions
 **********************************/

void F__M_Exception_v_init_pc_F_thunkmy_exception2(my_exception2 *, char *p1);

/**********************************
 ** class my_exception2 non-members
 **********************************/

extern int V__my_exception2_i_id_V;


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

void my_exception2_INIT_ID(void) __attribute__((constructor));


# endif
#endif
#if defined(__IN25_MODULE_MY_EXCEPTION3__) || defined(__IN25_FILE__)
# ifndef __IN25_MODULE_MY_EXCEPTION3_INC__
#  define __IN25_MODULE_MY_EXCEPTION3_INC__


/**********************************
 ** class my_exception3
 **********************************/


typedef struct s_my_exception3 my_exception3;


/**********************************
 ** class my_exception3 vtable
 **********************************/

typedef struct s_my_exception3_table {
	void (*F__M_Exception_v_init_pc_F)(Exception *, char *);
} my_exception3_table;


/**********************************
 ** class my_exception3 life cycle
 **********************************/

typedef struct s_my_exception3_life {
	void *base;
	void (*delete)(my_exception3 *);
	void (*clean)(my_exception3 *);
} my_exception3_life;


/**********************************
 ** class my_exception3 struct
 **********************************/

struct s_my_exception3 {
	Exception parent1;

	void *life_table;

};


/**********************************
 ** class my_exception3 members
 **********************************/


my_exception3 *my_exception3_alloc(void);
void my_exception3_delete(my_exception3 *);
my_exception3 *my_exception3_new(char *);

/**********************************
 ** class my_exception3 thunk functions
 **********************************/

void F__M_Exception_v_init_pc_F_thunkmy_exception3(my_exception3 *, char *p1);

/**********************************
 ** class my_exception3 non-members
 **********************************/

extern int V__my_exception3_i_id_V;


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

void my_exception3_INIT_ID(void) __attribute__((constructor));


# endif
#endif
