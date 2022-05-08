#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct stackNode
{
    int data;
    struct stackNode *next;
}*top = NULL;

typedef struct stackNode SN;

SN* push(SN *top)
{
    SN *newNode = (SN*) malloc(sizeof(SN));
    scanf("%d",&(newNode->data));
    newNode->next = top;
    return newNode;
}

SN* pop()
{
    if(top == NULL)
    {
        printf("Invalid\n");
        return NULL;
    }
    else
        return top->next;
}

bool isEmpty()
{
    return top==NULL;
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int choice;
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: top = push(top); break;
            case 2: top = pop(top); break;
            case 3: isEmpty() ? printf("Invalid\n") : printf("%d\n",top->data); break;
            case 4: isEmpty() ? printf("1\n") : printf("0\n"); break;
        }
    }
    return 0;
}

