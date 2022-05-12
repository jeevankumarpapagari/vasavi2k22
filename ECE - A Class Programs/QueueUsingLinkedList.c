#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
struct queueNode
{
	int data;
	struct queueNode *next;
}*front = NULL, *rear = NULL;

typedef struct queueNode QN;

void enQueue(int ele) //=> O(1)
{
	QN *newNode = (QN*) malloc(sizeof(QN));
	newNode->data = ele;
	newNode->next = NULL;
	if(rear == NULL)
		front = rear = newNode;
	else
	{
		rear->next = newNode;
		rear = newNode;
	}
}

void frontElement()
{
	isEmpty() ? printf("Empty") : printf("%d",front->data);
}

void rearElement()
{
	isEmpty() ? printf("Empty") : printf("%d",rear->data);
}

bool isEmpty() //=> O(1)
{
	return front==NULL;
}

void deQueue() //=> O(1)
{
	if(isEmpty())
		printf("Empty Queue");
	else if(front->next == NULL)
	{
		free(front);
		front = rear = NULL;
	}
	else
	{
		QN *temp = front;
		front = front->next;
		free(temp);
	}
}

int size() //=> O(N)
{
	if(isEmpty())
		return 0;
	else
	{
		QN *ptr = front;
		int count = 0;
		while(ptr)//ptr!=NULL
		{
			count++;
			ptr = ptr->next;
		}
		return count;
	}
}

int main()
{
	for(i=1;i<=5;i++)
		enQueue(rand()%100);
	for(i=1;i<=6;i++)
		deQueue();
	return 0;
}
