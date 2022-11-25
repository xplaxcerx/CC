#include <stdio.h>
#include <stdlib.h>
#include <time.h>
unsigned long long int Nod(unsigned long long int a, unsigned long long int b)
{
    while (a && b)
        if (a >= b)
           a %= b;
        else
           b %= a;
    return a | b;
}
void mass (unsigned long long int n, unsigned long long int a[])
{
    int i;
    for (i = 0; i < n; i++)
        a[i] = rand ();
}
unsigned long long int u (unsigned long long int a, unsigned long long int b)

    // scanf("%d", &a);
    // scanf("%d",&b);
    // if (Nod(a,b)==1){

    //     printf("Числа взаимно простые\n");
    // }
    // else 
    // {
    //     printf("Числа НЕ взаимно простые\n");
    // }
    // printf("%d\n", Nod(a,b));
int main()
{   
    srand(time(NULL));
    int n;
    printf("n -> ");
    scanf("%d", &n);
    int A[n];
    fill(n, A);
    int i;
    for (i = 0; i < n; i++)
    printf("%d", A[i]);


    // int a,b;
    // scanf("%d", &a);
    // scanf("%d",&b);
    // if (Nod(a,b)==1){

    //     printf("Числа взаимно простые\n");
    // }
    // else 
    // {
    //     printf("Числа НЕ взаимно простые\n");
    // }
    // printf("%d\n", Nod(a,b));
    return 0;
}