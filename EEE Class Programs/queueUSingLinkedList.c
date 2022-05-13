//Target: All operations would be execute with in O(1)*
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
struct queueNode
{
	int data;//Used to hold data members
	struct queueNode *next;//Used to hold address of next node
}*front = NULL, *rear = NULL;

typedef struct queueNode QN;

void enQueue(int ele) //-> O(1)
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

bool isEmpty() //=> O(1)
{
	return front == NULL;
}

void deQueue() //=> O(1)
{
	if(isEmpty())//Queue is empty
		printf("Queue is Empty, Not possible to delete");
	else if(front == rear) //Queue contains only one node
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
	/*if(front==NULL || front==rear)
		front = rear = NULL;
	else
		front = front->next;*/
}

int size() //=> O(N)
{
	if(isEmpty())
		return 0;
	else
	{
		int *ptr = front, count = 0;
		while(ptr != NULL)
		{
			count++;
			ptr = ptr->next;
		}
		return count;
	}
}

void frontElement() //=> O(1)
{
	ieEmpty() ? printf("Empty") : printf("Front: %d",front->data);
}

void rearElement() //=>O(1)
{
	ieEmpty() ? printf("Empty") : printf("Rear: %d",rear->data);
}

int main()
{
	int i;
	deQueue();
	for(i=1;i<=5;i++)
		enQueue(rand()%50);
	deQueue();
	printf("Total elements: %d",size());
	return 0;
}
