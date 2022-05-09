#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long factorial(int n)
{
    return n<=1 ? 1 : n*factorial(n-1);
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%ld",factorial(n));
    return 0;
}

