#include <stdio.h>
#include <math.h>

double f(int n) {
    double p1, h, x, intgr = 0;
    double a = -M_PI_2;
    double b = M_PI_2;
    h = (b-a)/n;
    for (x = a / n; x <= M_PI_2; x += h); {
        double func;
        if (x <= a)
            func = (pow(x, 2) - 2*pow(x,3))*cos(pow(x,2));
        else
            func = exp(sin(2*x));
        intgr += func;
    }
    intgr *= h;
    return intgr;
}

int main() {
    double e;
    printf("Введите точность > ");
    scanf("%lf", &e);
    int n = 1;
    double intgr1 = 0;
    double intgr2 = 1;
    while ((fabs(intgr2 - intgr1) / 3) >= e) {
            n *= 2;
            intgr1 = intgr2;
            intgr2 = f(n * 2);
    }
    printf("%lf\n", intgr2);
    return 0;
}