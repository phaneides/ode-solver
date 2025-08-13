//euler.c
#include "ode.h"

void euler(const RHS *rhs,
           double t0, double y0,
           double dt, int n,
           double *t_out, double *y_out)
{
    t_out[0] = t0;
    y_out[0] = y0;

    for (int k = 0; k < n; ++k) {

        y_out[k + 1] = y_out[k] + dt * rhs->f(t_out[k], y_out[k], rhs->params);

        t_out[k + 1] = t_out[k] + dt;

    }
}
