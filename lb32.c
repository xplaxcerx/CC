#include <stdio.h>
#include <math.h>
int main()
{
    double x = 0, h, f, i, n;
    printf ("Введите h -> ");
    scanf ("%lf", &h);
    printf("\nx             f(x)\n- - - - - - - - - - - -\n");
    i = 3 / h;
    while (n <= i)
    {
        if (-1.5 <= x && x <= 0)
            f = ((pow(x, 2)-pow(2*x, 3))*cos(pow(x,2)));
        else if (0 < x && x <= 1.5)
            f = exp(sin(x));
        printf("%lf      %lf\n", x, f);
        x += h;
        n++;
    }
    return 0;
}