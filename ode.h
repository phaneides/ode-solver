#ifndef ODE_H
#define ODE_H 

/* Problem Description */ 

typedef double (*ode_rhs)(double t, double y, void *params); 

typedef struct {
    ode_rhs f;  // Right hand side function. 
    void *params; // Params (may be NULL) 
}  ODEProblem;

/* Generic Solver Signature */ 
typedef void (*ode_solver)(const ODEProblem *prob, 
                        double t0, double y0, 
                        double dt, int n, 
                        double *t_arr, double *y_arr); 

/* Setup Solvers */ 

void euler(const ODEProblem *prob, 
           double t0, double y0, // initial conditions
           double dt, int n, 
           double *t_arr, double *y_arr); 


void rk4(const ODEProblem *prob, 
           double t0, double y0, // initial conditions
           double dt, int n, 
           double *t_arr, double *y_arr); 

#endif 
