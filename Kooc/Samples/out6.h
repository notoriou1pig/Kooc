#if defined(__IN6_MODULE_SIMPLECLASS__) || defined(__IN6_FILE__)
# ifndef __IN6_MODULE_SIMPLECLASS_INC__
#  define __IN6_MODULE_SIMPLECLASS_INC__


/**********************************
 ** class SimpleClass
 **********************************/


typedef struct s_SimpleClass SimpleClass;


/**********************************
 ** class SimpleClass vtable
 **********************************/

typedef struct s_SimpleClass_table {
} SimpleClass_table;


/**********************************
 ** class SimpleClass life cycle
 **********************************/

typedef struct s_SimpleClass_life {
	void *base;
	void (*delete)(SimpleClass *);
	void (*clean)(SimpleClass *);
} SimpleClass_life;


/**********************************
 ** class SimpleClass struct
 **********************************/

struct s_SimpleClass {
	void *func_table;

	void *life_table;

};


/**********************************
 ** class SimpleClass members
 **********************************/


SimpleClass *SimpleClass_alloc(void);
void SimpleClass_delete(SimpleClass *);
SimpleClass *SimpleClass_new(void);

/**********************************
 ** class SimpleClass thunk functions
 **********************************/


/**********************************
 ** class SimpleClass non-members
 **********************************/

void F__SimpleClass_v_print_pc_F(char *a);
extern int V__SimpleClass_i_a_V;
extern double V__SimpleClass_d_a_V;


# endif
#endif
