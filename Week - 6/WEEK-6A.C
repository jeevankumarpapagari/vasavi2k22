#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int *queue, front = 0, rear = -1;

void enQueue()
{
    scanf("%d",&queue[++rear]);
}

void deQueue()
{
    if(front > rear)
        printf("invalid\n");
    else
    {
        front++;
        if(front > rear)
        {
            front = 0;
            rear = -1;
        }
    }
}

bool isEmpty()
{
    return front>rear;
}

int main()
{
    queue = (int*) malloc(100 * sizeof(int));
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int choice;
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: enQueue(); break;
            case 2: deQueue(); break;
            case 3: isEmpty() ? printf("invalid\n") : printf("%d\n",queue[front]); break;
            case 4: isEmpty() ? printf("invalid\n") : printf("%d\n",queue[rear]); break;
            case 5: isEmpty() ? printf("1\n") : printf("0\n"); break;
        }
    }
    return 0;
}
