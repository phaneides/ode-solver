#include <stdio.h>
#include "ode.h"


/*
 IVP PROBLEM | 
RHS: dy/dt = y; y(0) = 1.

*/

static double rhs_exp(double t, double y, void *params)
{
    (void)t; 
    (void)params; 
    return y;
}

int main(void) 
{

    const int N = 10; 
    const double dt = 0.1; 

    double t[N+1]; 
    double y[N+1]; 

    ODEProblem prob = { .f = rhs_exp, .params = NULL}; //setup the problem. 
    
    /*

    */ 
    
    ode_solver method = rk4; 

    method(&prob, 0.0, 1.0, dt, N, t, y); 


    puts(" k   t        y (rk4)");
    puts("---------------------------");

    for (int k = 0; k <= N; ++k)
    {
        printf("%2d  %5.2f   %.15f\n", k, t[k], y[k]);
    }

   return 0; 
}




