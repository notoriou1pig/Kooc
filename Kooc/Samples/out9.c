#include <setjmp.h>
extern jmp_buf kooc_global_env;
#include <stdlib.h>
#include <stdio.h>
#include <setjmp.h>
#ifndef __IN9_FILE__
#define __IN9_FILE__
#include "in9.h"
#endif /* __IN9_FILE__ */

int V__klauss_i_a_V;
float V__klauss_f_a_V = 68954.45;
char V__klauss_c_b_V;
double V__klauss_d_d_V = 79.2;
void **V__klauss_ppv_tab_V;
char *V__klauss_pc_str_V = "dump !";
int V__klauss_pi_tab_V[3] = { 1, 2, 3 };

int F__klauss_i_my_putchar_c_pf_F(char c, float *f)
{
    write(1, &c, 1);
}

void F__klauss_v_my_putchar_c_F(char c)
{
    write(1, &c, 1);
}

#define __EXCEPTION_FILE__
#include "Exception.h"
jmp_buf kooc_global_env;
Exception *kooc_global_exception;
int KOOC_EXCEPTION_COUNT = 1;
int main()
{
    if (!(setjmp(kooc_global_env)))
        {
            return (0);
        }
    else
        {
            fprintf(stderr, "Process terminated by an unknown exception\n");
            return (EXIT_FAILURE);
        }
    return (EXIT_SUCCESS);
}
