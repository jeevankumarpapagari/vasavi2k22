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

void findMin()
{
    if(top == -1)
        printf("Invalid\n");
    else
    {
        int min = stack[top];
        for(int i=top-1;i>=0;i--)
            if(min > stack[i])
                min = stack[i];
        printf("%d\n",min);
    }
}

void findMax()
{
    if(top == -1)
        printf("Invalid\n");
    else
    {
        int max = stack[top];
        for(int i=top-1;i>=0;i--)
            if(max < stack[i])
                max = stack[i];
        printf("%d\n",max);
    }
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
            case 5: findMin(); break;
            case 6: findMax(); break;
        }
    }
    return 0;
}
