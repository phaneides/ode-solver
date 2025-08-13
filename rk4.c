#include "ode.h"

void rk4(const RHS *rhs, 
         double t0, double y0, 
         double dt, int n, 
         double *t_arr, double *y_arr) 

{
    const ode_rhs f = rhs->f; 

    t_arr[0] = t0;
    y_arr[0] = y0; 

    for (int k=0; k < n; ++k) 
    {
        double t = t_arr[k]; 
        double y = y_arr[k]; 

        double k1 = f(t, y, rhs->params); 
        double k2 = f(t + 0.5*dt, y + 0.5*dt*k1, rhs->params); 
        double k3 = f(t + 0.5*dt, y + 0.5*dt*k2, rhs->params);
        double k4 = f(t + 1.0*dt, y + 1.0*dt*k3, rhs->params); 

        y_arr[k+1]  = y + (dt/6.0)*(k1 + 2*k2 + 2*k3 + k4);

        t_arr[k+1] = t + dt;
    }


}
