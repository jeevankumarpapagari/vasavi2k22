#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct queueNode
{
    int data;
    struct queueNode *next;
}*front=NULL, *rear = NULL;

typedef struct queueNode QN;

void enQueue()
{
    QN *newNode = (QN*) malloc(sizeof(QN));
    scanf("%d",&(newNode->data));
    newNode->next = NULL;
    if(rear == NULL)
        front = rear = newNode;
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

void deQueue()
{
    if(front == NULL)
        printf("invalid\n");
    else
    {
        QN *temp = front;
        front = front->next;
        free(temp);
    }
}

void frontElement()
{
    front == NULL ? printf("invalid\n") : printf("%d\n",front->data);
}

void rearElement()
{
    rear == NULL ? printf("invalid\n") : printf("%d\n",rear->data);
}

bool isEmpty()
{
    return (front == NULL && rear==NULL);
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
            case 1: enQueue(); break;
            case 2: deQueue(); break;
            case 3: frontElement(); break;
            case 4: rearElement(); break;
            case 5: isEmpty() ? printf("1\n") : printf("0\n"); break;
        }
    }
    return 0;
}
