#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int fib(int n)
{
    return n==0 ? 0 : n==1 ? 1 : (fib(n-1)+fib(n-2));
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",fib(n));
    return 0;
}
