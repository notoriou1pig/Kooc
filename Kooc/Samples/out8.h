#if defined(__IN8_MODULE_BASECLASS__) || defined(__IN8_FILE__) || defined(__IN8_MODULE_SON__)
# ifndef __IN8_MODULE_BASECLASS_INC__
#  define __IN8_MODULE_BASECLASS_INC__


/**********************************
 ** class BaseClass
 **********************************/


typedef struct s_BaseClass BaseClass;


/**********************************
 ** class BaseClass vtable
 **********************************/

typedef struct s_BaseClass_table {
	void (*F__M_BaseClass_v_print_F)(BaseClass *);
	void (*F__M__v_print_F)(BaseClass *);
} BaseClass_table;


/**********************************
 ** class BaseClass life cycle
 **********************************/

typedef struct s_BaseClass_life {
	void *base;
	void (*delete)(BaseClass *);
	void (*clean)(BaseClass *);
} BaseClass_life;


/**********************************
 ** class BaseClass struct
 **********************************/

struct s_BaseClass {
	void *func_table;

	void *life_table;

	int V__M_BaseClass_i_a_V;
	double V__M_BaseClass_d_a_V;
};


/**********************************
 ** class BaseClass members
 **********************************/

void F__M_BaseClass_v_print_F(BaseClass *);

BaseClass *BaseClass_alloc(void);
void BaseClass_delete(BaseClass *);
BaseClass *BaseClass_new(void);

/**********************************
 ** class BaseClass thunk functions
 **********************************/

void F__M_BaseClass_v_print_F_thunkBaseClass(BaseClass *);
void F__M__v_print_F_thunkBaseClass(BaseClass *);

/**********************************
 ** class BaseClass non-members
 **********************************/

void F__BaseClass_v_print_pc_F(char *a);
extern int V__BaseClass_i_a_V;
extern double V__BaseClass_d_a_V;


# endif
#endif
#if defined(__IN8_MODULE_SON__) || defined(__IN8_FILE__)
# ifndef __IN8_MODULE_SON_INC__
#  define __IN8_MODULE_SON_INC__


/**********************************
 ** class Son
 **********************************/


typedef struct s_Son Son;


/**********************************
 ** class Son vtable
 **********************************/

typedef struct s_Son_table {
	void (*F__M_BaseClass_v_print_F)(BaseClass *);
	void (*F__M__v_print_F)(Son *);
	void (*F__M_Son_v_print_F)(Son *);
} Son_table;


/**********************************
 ** class Son life cycle
 **********************************/

typedef struct s_Son_life {
	void *base;
	void (*delete)(Son *);
	void (*clean)(Son *);
} Son_life;


/**********************************
 ** class Son struct
 **********************************/

struct s_Son {
	BaseClass parent1;

	void *life_table;

	char V__M_Son_c_a_V;
};


/**********************************
 ** class Son members
 **********************************/

void F__M_Son_v_print_F(Son *);

Son *Son_alloc(void);
void Son_delete(Son *);
Son *Son_new(void);

/**********************************
 ** class Son thunk functions
 **********************************/

void F__M_BaseClass_v_print_F_thunkSon(Son *);
void F__M__v_print_F_thunkSon(Son *);
void F__M_Son_v_print_F_thunkSon(Son *);

/**********************************
 ** class Son non-members
 **********************************/



# endif
#endif
