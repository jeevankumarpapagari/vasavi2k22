#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int *stack, top = -1;

void push()
{
    int ele;
    scanf("%d",&ele);
    stack[++top] = ele;
}

void pop()
{
    if(top==-1)     printf("Invalid\n");
    else            top--;
}

bool isEmpty()
{
    return top==-1;
}

int main()
{
    stack = (int*) malloc(100*sizeof(int));

    int n;
    scanf("%d",&n);
    while(n--)
    {
        int choice;
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: isEmpty() ? printf("Invalid\n") : printf("%d\n",stack[top]); break;
            case 4: isEmpty() ? printf("1\n") : printf("0\n"); break;
        }
    }
    return 0;
}
