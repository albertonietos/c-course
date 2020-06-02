#include <math.h>
#include <stdio.h>

double vectorlength(double x, double y, double z)
{
    double x_pow = pow(x, 2);
    double y_pow  = pow(y, 2);
    double z_pow = pow(z, 2);

    return sqrt(x_pow + y_pow + z_pow); 
}



