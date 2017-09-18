#if defined(__IN19_MODULE_BASECLASSA__) || defined(__IN19_FILE__) || defined(__IN19_MODULE_BASECLASSC__) || defined(__IN19_MODULE_BASECLASSJ__) || defined(__IN19_MODULE_SON__)
# ifndef __IN19_MODULE_BASECLASSA_INC__
#  define __IN19_MODULE_BASECLASSA_INC__


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
#if defined(__IN19_MODULE_BASECLASSB__) || defined(__IN19_FILE__) || defined(__IN19_MODULE_BASECLASSC__) || defined(__IN19_MODULE_BASECLASSJ__) || defined(__IN19_MODULE_SON__)
# ifndef __IN19_MODULE_BASECLASSB_INC__
#  define __IN19_MODULE_BASECLASSB_INC__


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
#if defined(__IN19_MODULE_BASECLASSC__) || defined(__IN19_FILE__) || defined(__IN19_MODULE_BASECLASSJ__) || defined(__IN19_MODULE_SON__)
# ifndef __IN19_MODULE_BASECLASSC_INC__
#  define __IN19_MODULE_BASECLASSC_INC__


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
#if defined(__IN19_MODULE_BASECLASSD__) || defined(__IN19_FILE__) || defined(__IN19_MODULE_BASECLASSF__) || defined(__IN19_MODULE_BASECLASSJ__) || defined(__IN19_MODULE_SON__)
# ifndef __IN19_MODULE_BASECLASSD_INC__
#  define __IN19_MODULE_BASECLASSD_INC__


/**********************************
 ** class BaseClassD
 **********************************/


typedef struct s_BaseClassD BaseClassD;


/**********************************
 ** class BaseClassD vtable
 **********************************/

typedef struct s_BaseClassD_table {
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
	void *func_table;

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

void F__M_BaseClassD_v_printD_F_thunkBaseClassD(BaseClassD *);

/**********************************
 ** class BaseClassD non-members
 **********************************/



# endif
#endif
#if defined(__IN19_MODULE_BASECLASSE__) || defined(__IN19_FILE__) || defined(__IN19_MODULE_BASECLASSF__) || defined(__IN19_MODULE_BASECLASSJ__) || defined(__IN19_MODULE_SON__)
# ifndef __IN19_MODULE_BASECLASSE_INC__
#  define __IN19_MODULE_BASECLASSE_INC__


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
#if defined(__IN19_MODULE_BASECLASSF__) || defined(__IN19_FILE__) || defined(__IN19_MODULE_BASECLASSJ__) || defined(__IN19_MODULE_SON__)
# ifndef __IN19_MODULE_BASECLASSF_INC__
#  define __IN19_MODULE_BASECLASSF_INC__


/**********************************
 ** class BaseClassF
 **********************************/


typedef struct s_BaseClassF BaseClassF;


/**********************************
 ** class BaseClassF vtable
 **********************************/

typedef struct s_BaseClassF_table {
	void (*F__M_BaseClassD_v_printD_F)(BaseClassD *);
	void (*F__M_BaseClassE_v_printE_F)(BaseClassE *);
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
	BaseClassD parent1;
	BaseClassE parent2;

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

void F__M_BaseClassD_v_printD_F_thunkBaseClassF(BaseClassF *);
void F__M_BaseClassE_v_printE_F_thunkBaseClassF(BaseClassF *);
void F__M_BaseClassF_v_printF_F_thunkBaseClassF(BaseClassF *);

/**********************************
 ** class BaseClassF non-members
 **********************************/



# endif
#endif
#if defined(__IN19_MODULE_BASECLASSG__) || defined(__IN19_FILE__) || defined(__IN19_MODULE_BASECLASSI__) || defined(__IN19_MODULE_BASECLASSJ__) || defined(__IN19_MODULE_SON__)
# ifndef __IN19_MODULE_BASECLASSG_INC__
#  define __IN19_MODULE_BASECLASSG_INC__


/**********************************
 ** class BaseClassG
 **********************************/


typedef struct s_BaseClassG BaseClassG;


/**********************************
 ** class BaseClassG vtable
 **********************************/

typedef struct s_BaseClassG_table {
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
	void *func_table;

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

void F__M_BaseClassG_v_printG_F_thunkBaseClassG(BaseClassG *);

/**********************************
 ** class BaseClassG non-members
 **********************************/



# endif
#endif
#if defined(__IN19_MODULE_BASECLASSH__) || defined(__IN19_FILE__) || defined(__IN19_MODULE_BASECLASSI__) || defined(__IN19_MODULE_BASECLASSJ__) || defined(__IN19_MODULE_SON__)
# ifndef __IN19_MODULE_BASECLASSH_INC__
#  define __IN19_MODULE_BASECLASSH_INC__


/**********************************
 ** class BaseClassH
 **********************************/


typedef struct s_BaseClassH BaseClassH;


/**********************************
 ** class BaseClassH vtable
 **********************************/

typedef struct s_BaseClassH_table {
	void (*F__M_BaseClassH_v_printH_F)(BaseClassH *);
} BaseClassH_table;


/**********************************
 ** class BaseClassH life cycle
 **********************************/

typedef struct s_BaseClassH_life {
	void *base;
	void (*delete)(BaseClassH *);
	void (*clean)(BaseClassH *);
} BaseClassH_life;


/**********************************
 ** class BaseClassH struct
 **********************************/

struct s_BaseClassH {
	void *func_table;

	void *life_table;

};


/**********************************
 ** class BaseClassH members
 **********************************/

void F__M_BaseClassH_v_printH_F(BaseClassH *);

BaseClassH *BaseClassH_alloc(void);
void BaseClassH_delete(BaseClassH *);
BaseClassH *BaseClassH_new(void);

/**********************************
 ** class BaseClassH thunk functions
 **********************************/

void F__M_BaseClassH_v_printH_F_thunkBaseClassH(BaseClassH *);

/**********************************
 ** class BaseClassH non-members
 **********************************/



# endif
#endif
#if defined(__IN19_MODULE_BASECLASSI__) || defined(__IN19_FILE__) || defined(__IN19_MODULE_BASECLASSJ__) || defined(__IN19_MODULE_SON__)
# ifndef __IN19_MODULE_BASECLASSI_INC__
#  define __IN19_MODULE_BASECLASSI_INC__


/**********************************
 ** class BaseClassI
 **********************************/


typedef struct s_BaseClassI BaseClassI;


/**********************************
 ** class BaseClassI vtable
 **********************************/

typedef struct s_BaseClassI_table {
	void (*F__M_BaseClassG_v_printG_F)(BaseClassG *);
	void (*F__M_BaseClassH_v_printH_F)(BaseClassH *);
	void (*F__M_BaseClassI_v_printI_F)(BaseClassI *);
} BaseClassI_table;


/**********************************
 ** class BaseClassI life cycle
 **********************************/

typedef struct s_BaseClassI_life {
	void *base;
	void (*delete)(BaseClassI *);
	void (*clean)(BaseClassI *);
} BaseClassI_life;


/**********************************
 ** class BaseClassI struct
 **********************************/

struct s_BaseClassI {
	BaseClassG parent1;
	BaseClassH parent2;

	void *life_table;

};


/**********************************
 ** class BaseClassI members
 **********************************/

void F__M_BaseClassI_v_printI_F(BaseClassI *);

BaseClassI *BaseClassI_alloc(void);
void BaseClassI_delete(BaseClassI *);
BaseClassI *BaseClassI_new(void);

/**********************************
 ** class BaseClassI thunk functions
 **********************************/

void F__M_BaseClassG_v_printG_F_thunkBaseClassI(BaseClassI *);
void F__M_BaseClassH_v_printH_F_thunkBaseClassI(BaseClassI *);
void F__M_BaseClassI_v_printI_F_thunkBaseClassI(BaseClassI *);

/**********************************
 ** class BaseClassI non-members
 **********************************/



# endif
#endif
#if defined(__IN19_MODULE_BASECLASSJ__) || defined(__IN19_FILE__) || defined(__IN19_MODULE_SON__)
# ifndef __IN19_MODULE_BASECLASSJ_INC__
#  define __IN19_MODULE_BASECLASSJ_INC__


/**********************************
 ** class BaseClassJ
 **********************************/


typedef struct s_BaseClassJ BaseClassJ;


/**********************************
 ** class BaseClassJ vtable
 **********************************/

typedef struct s_BaseClassJ_table {
	void (*F__M_BaseClassA_v_printA_F)(BaseClassA *);
	void (*F__M_BaseClassB_v_printB_F)(BaseClassB *);
	void (*F__M_BaseClassC_v_printC_F)(BaseClassC *);
	void (*F__M_BaseClassD_v_printD_F)(BaseClassD *);
	void (*F__M_BaseClassE_v_printE_F)(BaseClassE *);
	void (*F__M_BaseClassF_v_printF_F)(BaseClassF *);
	void (*F__M_BaseClassG_v_printG_F)(BaseClassG *);
	void (*F__M_BaseClassH_v_printH_F)(BaseClassH *);
	void (*F__M_BaseClassI_v_printI_F)(BaseClassI *);
	void (*F__M_BaseClassJ_v_printJ_F)(BaseClassJ *);
} BaseClassJ_table;


/**********************************
 ** class BaseClassJ life cycle
 **********************************/

typedef struct s_BaseClassJ_life {
	void *base;
	void (*delete)(BaseClassJ *);
	void (*clean)(BaseClassJ *);
} BaseClassJ_life;


/**********************************
 ** class BaseClassJ struct
 **********************************/

struct s_BaseClassJ {
	BaseClassC parent1;
	BaseClassF parent2;
	BaseClassI parent3;

	void *life_table;

};


/**********************************
 ** class BaseClassJ members
 **********************************/

void F__M_BaseClassJ_v_printJ_F(BaseClassJ *);

BaseClassJ *BaseClassJ_alloc(void);
void BaseClassJ_delete(BaseClassJ *);
BaseClassJ *BaseClassJ_new(void);

/**********************************
 ** class BaseClassJ thunk functions
 **********************************/

void F__M_BaseClassA_v_printA_F_thunkBaseClassJ(BaseClassJ *);
void F__M_BaseClassB_v_printB_F_thunkBaseClassJ(BaseClassJ *);
void F__M_BaseClassC_v_printC_F_thunkBaseClassJ(BaseClassJ *);
void F__M_BaseClassD_v_printD_F_thunkBaseClassJ(BaseClassJ *);
void F__M_BaseClassE_v_printE_F_thunkBaseClassJ(BaseClassJ *);
void F__M_BaseClassF_v_printF_F_thunkBaseClassJ(BaseClassJ *);
void F__M_BaseClassG_v_printG_F_thunkBaseClassJ(BaseClassJ *);
void F__M_BaseClassH_v_printH_F_thunkBaseClassJ(BaseClassJ *);
void F__M_BaseClassI_v_printI_F_thunkBaseClassJ(BaseClassJ *);
void F__M_BaseClassJ_v_printJ_F_thunkBaseClassJ(BaseClassJ *);

/**********************************
 ** class BaseClassJ non-members
 **********************************/



# endif
#endif
#if defined(__IN19_MODULE_BASECLASSK__) || defined(__IN19_FILE__) || defined(__IN19_MODULE_SON__)
# ifndef __IN19_MODULE_BASECLASSK_INC__
#  define __IN19_MODULE_BASECLASSK_INC__


/**********************************
 ** class BaseClassK
 **********************************/


typedef struct s_BaseClassK BaseClassK;


/**********************************
 ** class BaseClassK vtable
 **********************************/

typedef struct s_BaseClassK_table {
	void (*F__M_BaseClassK_v_printK_F)(BaseClassK *);
} BaseClassK_table;


/**********************************
 ** class BaseClassK life cycle
 **********************************/

typedef struct s_BaseClassK_life {
	void *base;
	void (*delete)(BaseClassK *);
	void (*clean)(BaseClassK *);
} BaseClassK_life;


/**********************************
 ** class BaseClassK struct
 **********************************/

struct s_BaseClassK {
	void *func_table;

	void *life_table;

};


/**********************************
 ** class BaseClassK members
 **********************************/

void F__M_BaseClassK_v_printK_F(BaseClassK *);

BaseClassK *BaseClassK_alloc(void);
void BaseClassK_delete(BaseClassK *);
BaseClassK *BaseClassK_new(void);

/**********************************
 ** class BaseClassK thunk functions
 **********************************/

void F__M_BaseClassK_v_printK_F_thunkBaseClassK(BaseClassK *);

/**********************************
 ** class BaseClassK non-members
 **********************************/



# endif
#endif
#if defined(__IN19_MODULE_SON__) || defined(__IN19_FILE__)
# ifndef __IN19_MODULE_SON_INC__
#  define __IN19_MODULE_SON_INC__


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
	void (*F__M_BaseClassH_v_printH_F)(BaseClassH *);
	void (*F__M_BaseClassI_v_printI_F)(BaseClassI *);
	void (*F__M_BaseClassJ_v_printJ_F)(BaseClassJ *);
	void (*F__M_BaseClassK_v_printK_F)(BaseClassK *);
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
	BaseClassJ parent1;
	BaseClassK parent2;

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
void F__M_BaseClassH_v_printH_F_thunkSon(Son *);
void F__M_BaseClassI_v_printI_F_thunkSon(Son *);
void F__M_BaseClassJ_v_printJ_F_thunkSon(Son *);
void F__M_BaseClassK_v_printK_F_thunkSon(Son *);
void F__M_Son_v_printSon_F_thunkSon(Son *);

/**********************************
 ** class Son non-members
 **********************************/



# endif
#endif
