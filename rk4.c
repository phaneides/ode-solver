#include "ode.h"

void rk4(const ODEProblem *prob, 
         double t0, double y0, 
         double dt, int n, 
         double *t_arr, double *y_arr) 

{
    const ode_rhs f = prob->f; 

    t_arr[0] = t0;
    y_arr[0] = y0; 

    for (int k=0; k < n; ++k) 
    {
        double t = t_arr[k]; 
        double y = y_arr[k]; 

        double k1 = f(t, y, prob->params); 
        double k2 = f(t + 0.5*dt, y + 0.5*dt*k1, prob->params); 
        double k3 = f(t + 0.5*dt, y + 0.5*dt*k2, prob->params);
        double k4 = f(t + 1.0*dt, y + 1.0*dt*k3, prob->params); 

        y_arr[k+1]  = y + (dt/6.0)*(k1 + 2*k2 + 2*k3 + k4);

        t_arr[k+1] = t + dt;
    }


}
