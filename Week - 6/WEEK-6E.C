#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int *queue, queueSize, front = -1, rear = -1;

void enQueue(int ele)
{
    if((front==0 && rear==queueSize-1) || front==rear+1)
    {
        printf("Queue is Full\n");
        return;
    }
    if(front==-1)
        front = rear = 0;
    else
        rear = (rear+1)%queueSize;
    queue[rear] = ele;
}

bool isEmpty()
{
    return front == -1;
}

void deQueue()
{
    if(isEmpty())
        printf("Queue is Empty\n");
    else if(front==rear)
        front = rear = -1;
    else
        front = (front+1)%queueSize;
}

void frontElement()
{
    isEmpty() ? printf("Queue is Empty\n") : printf("%d\n",queue[front]);
}

void rearElement()
{
    isEmpty() ? printf("Queue is Empty\n") : printf("%d\n",queue[rear]);
}

int main()
{
    scanf("%d",&queueSize);
    queue = (int*) malloc(sizeof(int) * queueSize);
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int choice, ele;
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: scanf("%d",&ele); enQueue(ele); break;
            case 2: deQueue(); break;
            case 3: frontElement(); break;
            case 4: rearElement(); break;
            case 5: isEmpty() ? printf("1\n") : printf("0\n"); break;
        }
    }
    return 0;
}
