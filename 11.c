#include <stdio.h>
#include <math.h>
int main() {
    double x;
    printf("Введите значение x {0 <= x <= 0.45} \n");
    scanf("%lf", &x);
    if (x >= 0 && x <= 0.45) { 
        double y = acos(2*x / (1+sqrt(x)));
        double z = log(sin(M_PI / y));
        printf("y(x) = %lf\nz(y) = %lf\n", y, z);
    }
    else {
        printf("Некорректное значение x \n");
    }
    return 0;
}
