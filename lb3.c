#include <stdio.h>
#include <math.h>
int main () {
    double x = 0, h, f, i, n;
    printf ("Enter h (step) -> ");
    scanf ("%lf", &h);
    printf("\nx             f(x)\n- - - - - - - - - - - -\n");
    n = 3 / h;
    for (i = 0; i <= n; i++)
    {
        if (i <= (n / 2))
            f = ((pow(x, 2)-pow(2*x, 3))*cos(pow(x,2)));
        else
            f = exp(sin(x));
        printf("%lf      %lf\n", x, f);
        x += h;
    }
    return 0;
}
