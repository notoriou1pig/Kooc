#if defined(__IN22_MODULE_BASECLASSA__) || defined(__IN22_FILE__) || defined(__IN22_MODULE_BASECLASSC__) || defined(__IN22_MODULE_BASECLASSD__) || defined(__IN22_MODULE_SON__)
# ifndef __IN22_MODULE_BASECLASSA_INC__
#  define __IN22_MODULE_BASECLASSA_INC__


/**********************************
 ** class BaseClassA
 **********************************/


typedef struct s_BaseClassA BaseClassA;


/**********************************
 ** class BaseClassA vtable
 **********************************/

typedef struct s_BaseClassA_table {
	void (*F__M_BaseClassA_v_printA_F)(BaseClassA *);
} BaseClassA_table;


/**********************************
 ** class BaseClassA life cycle
 **********************************/

typedef struct s_BaseClassA_life {
	void *base;
	void (*delete)(BaseClassA *);
	void (*clean)(BaseClassA *);
} BaseClassA_life;


/**********************************
 ** class BaseClassA struct
 **********************************/

struct s_BaseClassA {
	void *func_table;

	void *life_table;

};


/**********************************
 ** class BaseClassA members
 **********************************/

void F__M_BaseClassA_v_printA_F(BaseClassA *);

BaseClassA *BaseClassA_alloc(void);
void BaseClassA_delete(BaseClassA *);
BaseClassA *BaseClassA_new(void);

/**********************************
 ** class BaseClassA thunk functions
 **********************************/

void F__M_BaseClassA_v_printA_F_thunkBaseClassA(BaseClassA *);

/**********************************
 ** class BaseClassA non-members
 **********************************/



# endif
#endif
#if defined(__IN22_MODULE_BASECLASSB__) || defined(__IN22_FILE__) || defined(__IN22_MODULE_BASECLASSC__) || defined(__IN22_MODULE_BASECLASSD__) || defined(__IN22_MODULE_SON__)
# ifndef __IN22_MODULE_BASECLASSB_INC__
#  define __IN22_MODULE_BASECLASSB_INC__


/**********************************
 ** class BaseClassB
 **********************************/


typedef struct s_BaseClassB BaseClassB;


/**********************************
 ** class BaseClassB vtable
 **********************************/

typedef struct s_BaseClassB_table {
	void (*F__M_BaseClassB_v_printB_F)(BaseClassB *);
} BaseClassB_table;


/**********************************
 ** class BaseClassB life cycle
 **********************************/

typedef struct s_BaseClassB_life {
	void *base;
	void (*delete)(BaseClassB *);
	void (*clean)(BaseClassB *);
} BaseClassB_life;


/**********************************
 ** class BaseClassB struct
 **********************************/

struct s_BaseClassB {
	void *func_table;

	void *life_table;

};


/**********************************
 ** class BaseClassB members
 **********************************/

void F__M_BaseClassB_v_printB_F(BaseClassB *);

BaseClassB *BaseClassB_alloc(void);
void BaseClassB_delete(BaseClassB *);
BaseClassB *BaseClassB_new(void);

/**********************************
 ** class BaseClassB thunk functions
 **********************************/

void F__M_BaseClassB_v_printB_F_thunkBaseClassB(BaseClassB *);

/**********************************
 ** class BaseClassB non-members
 **********************************/



# endif
#endif
#if defined(__IN22_MODULE_BASECLASSC__) || defined(__IN22_FILE__) || defined(__IN22_MODULE_BASECLASSD__) || defined(__IN22_MODULE_SON__)
# ifndef __IN22_MODULE_BASECLASSC_INC__
#  define __IN22_MODULE_BASECLASSC_INC__


/**********************************
 ** class BaseClassC
 **********************************/


typedef struct s_BaseClassC BaseClassC;


/**********************************
 ** class BaseClassC vtable
 **********************************/

typedef struct s_BaseClassC_table {
	void (*F__M_BaseClassA_v_printA_F)(BaseClassA *);
	void (*F__M_BaseClassB_v_printB_F)(BaseClassB *);
	void (*F__M_BaseClassC_v_printC_F)(BaseClassC *);
} BaseClassC_table;


/**********************************
 ** class BaseClassC life cycle
 **********************************/

typedef struct s_BaseClassC_life {
	void *base;
	void (*delete)(BaseClassC *);
	void (*clean)(BaseClassC *);
} BaseClassC_life;


/**********************************
 ** class BaseClassC struct
 **********************************/

struct s_BaseClassC {
	BaseClassA parent1;
	BaseClassB parent2;

	void *life_table;

};


/**********************************
 ** class BaseClassC members
 **********************************/

void F__M_BaseClassC_v_printC_F(BaseClassC *);

BaseClassC *BaseClassC_alloc(void);
void BaseClassC_delete(BaseClassC *);
BaseClassC *BaseClassC_new(void);

/**********************************
 ** class BaseClassC thunk functions
 **********************************/

void F__M_BaseClassA_v_printA_F_thunkBaseClassC(BaseClassC *);
void F__M_BaseClassB_v_printB_F_thunkBaseClassC(BaseClassC *);
void F__M_BaseClassC_v_printC_F_thunkBaseClassC(BaseClassC *);

/**********************************
 ** class BaseClassC non-members
 **********************************/



# endif
#endif
#if defined(__IN22_MODULE_BASECLASSD__) || defined(__IN22_FILE__) || defined(__IN22_MODULE_SON__)
# ifndef __IN22_MODULE_BASECLASSD_INC__
#  define __IN22_MODULE_BASECLASSD_INC__


/**********************************
 ** class BaseClassD
 **********************************/


typedef struct s_BaseClassD BaseClassD;


/**********************************
 ** class BaseClassD vtable
 **********************************/

typedef struct s_BaseClassD_table {
	void (*F__M_BaseClassA_v_printA_F)(BaseClassA *);
	void (*F__M_BaseClassB_v_printB_F)(BaseClassB *);
	void (*F__M_BaseClassC_v_printC_F)(BaseClassC *);
	void (*F__M_BaseClassD_v_printD_F)(BaseClassD *);
} BaseClassD_table;


/**********************************
 ** class BaseClassD life cycle
 **********************************/

typedef struct s_BaseClassD_life {
	void *base;
	void (*delete)(BaseClassD *);
	void (*clean)(BaseClassD *);
} BaseClassD_life;


/**********************************
 ** class BaseClassD struct
 **********************************/

struct s_BaseClassD {
	BaseClassC parent1;

	void *life_table;

};


/**********************************
 ** class BaseClassD members
 **********************************/

void F__M_BaseClassD_v_printD_F(BaseClassD *);

BaseClassD *BaseClassD_alloc(void);
void BaseClassD_delete(BaseClassD *);
BaseClassD *BaseClassD_new(void);

/**********************************
 ** class BaseClassD thunk functions
 **********************************/

void F__M_BaseClassA_v_printA_F_thunkBaseClassD(BaseClassD *);
void F__M_BaseClassB_v_printB_F_thunkBaseClassD(BaseClassD *);
void F__M_BaseClassC_v_printC_F_thunkBaseClassD(BaseClassD *);
void F__M_BaseClassD_v_printD_F_thunkBaseClassD(BaseClassD *);

/**********************************
 ** class BaseClassD non-members
 **********************************/



# endif
#endif
#if defined(__IN22_MODULE_BASECLASSE__) || defined(__IN22_FILE__) || defined(__IN22_MODULE_BASECLASSG__) || defined(__IN22_MODULE_SON__)
# ifndef __IN22_MODULE_BASECLASSE_INC__
#  define __IN22_MODULE_BASECLASSE_INC__


/**********************************
 ** class BaseClassE
 **********************************/


typedef struct s_BaseClassE BaseClassE;


/**********************************
 ** class BaseClassE vtable
 **********************************/

typedef struct s_BaseClassE_table {
	void (*F__M_BaseClassE_v_printE_F)(BaseClassE *);
} BaseClassE_table;


/**********************************
 ** class BaseClassE life cycle
 **********************************/

typedef struct s_BaseClassE_life {
	void *base;
	void (*delete)(BaseClassE *);
	void (*clean)(BaseClassE *);
} BaseClassE_life;


/**********************************
 ** class BaseClassE struct
 **********************************/

struct s_BaseClassE {
	void *func_table;

	void *life_table;

};


/**********************************
 ** class BaseClassE members
 **********************************/

void F__M_BaseClassE_v_printE_F(BaseClassE *);

BaseClassE *BaseClassE_alloc(void);
void BaseClassE_delete(BaseClassE *);
BaseClassE *BaseClassE_new(void);

/**********************************
 ** class BaseClassE thunk functions
 **********************************/

void F__M_BaseClassE_v_printE_F_thunkBaseClassE(BaseClassE *);

/**********************************
 ** class BaseClassE non-members
 **********************************/



# endif
#endif
#if defined(__IN22_MODULE_BASECLASSF__) || defined(__IN22_FILE__) || defined(__IN22_MODULE_BASECLASSG__) || defined(__IN22_MODULE_SON__)
# ifndef __IN22_MODULE_BASECLASSF_INC__
#  define __IN22_MODULE_BASECLASSF_INC__


/**********************************
 ** class BaseClassF
 **********************************/


typedef struct s_BaseClassF BaseClassF;


/**********************************
 ** class BaseClassF vtable
 **********************************/

typedef struct s_BaseClassF_table {
	void (*F__M_BaseClassF_v_printF_F)(BaseClassF *);
} BaseClassF_table;


/**********************************
 ** class BaseClassF life cycle
 **********************************/

typedef struct s_BaseClassF_life {
	void *base;
	void (*delete)(BaseClassF *);
	void (*clean)(BaseClassF *);
} BaseClassF_life;


/**********************************
 ** class BaseClassF struct
 **********************************/

struct s_BaseClassF {
	void *func_table;

	void *life_table;

};


/**********************************
 ** class BaseClassF members
 **********************************/

void F__M_BaseClassF_v_printF_F(BaseClassF *);

BaseClassF *BaseClassF_alloc(void);
void BaseClassF_delete(BaseClassF *);
BaseClassF *BaseClassF_new(void);

/**********************************
 ** class BaseClassF thunk functions
 **********************************/

void F__M_BaseClassF_v_printF_F_thunkBaseClassF(BaseClassF *);

/**********************************
 ** class BaseClassF non-members
 **********************************/



# endif
#endif
#if defined(__IN22_MODULE_BASECLASSG__) || defined(__IN22_FILE__) || defined(__IN22_MODULE_SON__)
# ifndef __IN22_MODULE_BASECLASSG_INC__
#  define __IN22_MODULE_BASECLASSG_INC__


/**********************************
 ** class BaseClassG
 **********************************/


typedef struct s_BaseClassG BaseClassG;


/**********************************
 ** class BaseClassG vtable
 **********************************/

typedef struct s_BaseClassG_table {
	void (*F__M_BaseClassE_v_printE_F)(BaseClassE *);
	void (*F__M_BaseClassF_v_printF_F)(BaseClassF *);
	void (*F__M_BaseClassG_v_printG_F)(BaseClassG *);
} BaseClassG_table;


/**********************************
 ** class BaseClassG life cycle
 **********************************/

typedef struct s_BaseClassG_life {
	void *base;
	void (*delete)(BaseClassG *);
	void (*clean)(BaseClassG *);
} BaseClassG_life;


/**********************************
 ** class BaseClassG struct
 **********************************/

struct s_BaseClassG {
	BaseClassE parent1;
	BaseClassF parent2;

	void *life_table;

};


/**********************************
 ** class BaseClassG members
 **********************************/

void F__M_BaseClassG_v_printG_F(BaseClassG *);

BaseClassG *BaseClassG_alloc(void);
void BaseClassG_delete(BaseClassG *);
BaseClassG *BaseClassG_new(void);

/**********************************
 ** class BaseClassG thunk functions
 **********************************/

void F__M_BaseClassE_v_printE_F_thunkBaseClassG(BaseClassG *);
void F__M_BaseClassF_v_printF_F_thunkBaseClassG(BaseClassG *);
void F__M_BaseClassG_v_printG_F_thunkBaseClassG(BaseClassG *);

/**********************************
 ** class BaseClassG non-members
 **********************************/



# endif
#endif
#if defined(__IN22_MODULE_SON__) || defined(__IN22_FILE__)
# ifndef __IN22_MODULE_SON_INC__
#  define __IN22_MODULE_SON_INC__


/**********************************
 ** class Son
 **********************************/


typedef struct s_Son Son;


/**********************************
 ** class Son vtable
 **********************************/

typedef struct s_Son_table {
	void (*F__M_BaseClassA_v_printA_F)(BaseClassA *);
	void (*F__M_BaseClassB_v_printB_F)(BaseClassB *);
	void (*F__M_BaseClassC_v_printC_F)(BaseClassC *);
	void (*F__M_BaseClassD_v_printD_F)(BaseClassD *);
	void (*F__M_BaseClassE_v_printE_F)(BaseClassE *);
	void (*F__M_BaseClassF_v_printF_F)(BaseClassF *);
	void (*F__M_BaseClassG_v_printG_F)(BaseClassG *);
	void (*F__M_Son_v_printSon_F)(Son *);
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
	BaseClassD parent1;
	BaseClassG parent2;

	void *life_table;

};


/**********************************
 ** class Son members
 **********************************/

void F__M_Son_v_printSon_F(Son *);

Son *Son_alloc(void);
void Son_delete(Son *);
Son *Son_new(void);

/**********************************
 ** class Son thunk functions
 **********************************/

void F__M_BaseClassA_v_printA_F_thunkSon(Son *);
void F__M_BaseClassB_v_printB_F_thunkSon(Son *);
void F__M_BaseClassC_v_printC_F_thunkSon(Son *);
void F__M_BaseClassD_v_printD_F_thunkSon(Son *);
void F__M_BaseClassE_v_printE_F_thunkSon(Son *);
void F__M_BaseClassF_v_printF_F_thunkSon(Son *);
void F__M_BaseClassG_v_printG_F_thunkSon(Son *);
void F__M_Son_v_printSon_F_thunkSon(Son *);

/**********************************
 ** class Son non-members
 **********************************/



# endif
#endif
