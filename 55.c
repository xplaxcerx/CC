#include <stdio.h>
#include <math.h>
int main() {
    double x, y, z;
    printf("enter x \n");
    scanf("lf", &x);
    if ((x >= -0.5) && (x <= 0.5)){
    y = acos(2*x / (1 + pow (x, 2)));
    z = log(sin(M_PI / y));
    printf("y(x) = %lf\nz(x) = %lf\n", y, z);
    }
    return 0;
}