#include <stdio.h>
#include <math.h>
unsigned long long int cycle (unsigned long long int a, unsigned long long int b){
    unsigned long long int k, i;
    k = 0;
    for (i = 1 ;; i++){
    k = i;
    if (k%a==0 && k%b==0)
    {
    return(k);
    break;
    }
}
}
}

unsigned long long int rec (unsigned long long int a, unsigned long long int b, unsigned long long int k)
{ if (k%a==0 && k%b==0)
  return k;
  else 
{
  k++
  rec(a,b,k);
}
int main()
{   unsigned long long int a, b;
    printf("Введите значение a ->\n");
    scanf("%llu", &a);
    printf("Введите значение b ->\n");
    scanf("%llu", &b);
    printf("%llu\n", cycle(a,b));
    printf("%llu\n", rec(a,b,1));
    return 0;
}
