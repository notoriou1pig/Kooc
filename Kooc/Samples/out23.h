#if defined(__IN23_MODULE_PARENT1__) || defined(__IN23_FILE__) || defined(__IN23_MODULE_SON__)
# ifndef __IN23_MODULE_PARENT1_INC__
#  define __IN23_MODULE_PARENT1_INC__


/**********************************
 ** class Parent1
 **********************************/


typedef struct s_Parent1 Parent1;


/**********************************
 ** class Parent1 vtable
 **********************************/

typedef struct s_Parent1_table {
} Parent1_table;


/**********************************
 ** class Parent1 life cycle
 **********************************/

typedef struct s_Parent1_life {
	void *base;
	void (*delete)(Parent1 *);
	void (*clean)(Parent1 *);
} Parent1_life;


/**********************************
 ** class Parent1 struct
 **********************************/

struct s_Parent1 {
	void *func_table;

	void *life_table;

	int V__M_Parent1_i_p1_V;
};


/**********************************
 ** class Parent1 members
 **********************************/


Parent1 *Parent1_alloc(void);
void Parent1_delete(Parent1 *);
Parent1 *Parent1_new(void);

/**********************************
 ** class Parent1 thunk functions
 **********************************/


/**********************************
 ** class Parent1 non-members
 **********************************/



# endif
#endif
#if defined(__IN23_MODULE_PARENT2__) || defined(__IN23_FILE__) || defined(__IN23_MODULE_SON__)
# ifndef __IN23_MODULE_PARENT2_INC__
#  define __IN23_MODULE_PARENT2_INC__


/**********************************
 ** class Parent2
 **********************************/


typedef struct s_Parent2 Parent2;


/**********************************
 ** class Parent2 vtable
 **********************************/

typedef struct s_Parent2_table {
	int (*F__M_Parent2_i_test_F)(Parent2 *);
} Parent2_table;


/**********************************
 ** class Parent2 life cycle
 **********************************/

typedef struct s_Parent2_life {
	void *base;
	void (*delete)(Parent2 *);
	void (*clean)(Parent2 *);
} Parent2_life;


/**********************************
 ** class Parent2 struct
 **********************************/

struct s_Parent2 {
	void *func_table;

	void *life_table;

	int V__M_Parent2_i_p2_V;
};


/**********************************
 ** class Parent2 members
 **********************************/

int F__M_Parent2_i_test_F(Parent2 *);

Parent2 *Parent2_alloc(void);
void Parent2_delete(Parent2 *);
Parent2 *Parent2_new(void);

/**********************************
 ** class Parent2 thunk functions
 **********************************/

int F__M_Parent2_i_test_F_thunkParent2(Parent2 *);

/**********************************
 ** class Parent2 non-members
 **********************************/



# endif
#endif
#if defined(__IN23_MODULE_SON__) || defined(__IN23_FILE__)
# ifndef __IN23_MODULE_SON_INC__
#  define __IN23_MODULE_SON_INC__


/**********************************
 ** class Son
 **********************************/


typedef struct s_Son Son;


/**********************************
 ** class Son vtable
 **********************************/

typedef struct s_Son_table {
	int (*F__M_Parent2_i_test_F)(Parent2 *);
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
	Parent1 parent1;
	Parent2 parent2;

	void *life_table;

	int V__M_Son_i_s_V;
};


/**********************************
 ** class Son members
 **********************************/


Son *Son_alloc(void);
void Son_delete(Son *);
Son *Son_new(void);

/**********************************
 ** class Son thunk functions
 **********************************/

int F__M_Parent2_i_test_F_thunkSon(Son *);

/**********************************
 ** class Son non-members
 **********************************/



# endif
#endif
