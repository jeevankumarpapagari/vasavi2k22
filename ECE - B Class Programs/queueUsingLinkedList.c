//Target: Try to complete all operations with O(1) time complexiy
#include<stdlib.h>
#include<stdbool.h>
struct queueNode
{
	struct queueNode *prev;
	int data;
	struct queueNode *next;
}*front = NULL, *rear = NULL;

typedef struct queueNode QN;

void enQueue(int ele) //=> O(1)
{
	QN *newNode = (QN*) malloc(sizeof(QN));
	if(newNode == NULL)
		printf("Queue is Full");
	else
	{
		newNode->data = ele;
		newNode->next = NULL;
		if(rear == NULL)
		{
			newNode->prev = NULL;
			front = rear = newNode;
		}
		else
		{
			rear->next = newNode;
			newNode->prev = rear;
			rear = newNode;
		}
	}
}

bool isEmpty() //=> O(1)
{
	return front == NULL;
}

void deQueue() //=> O(1)
{
	if(isEmpty())//Queue is empty
		printf("Queue is empty");
	else if(front == rear) //Queue contains only one node
	{
		free(front);
		front = rear = NULL;
	}
	else//Queue is having more than one node
	{
		QN *temp = front;
		front = front->next;
		free(temp);
		front->prev = NULL;
	}
}

int size() //=> O(n) n:-> Total Elements
{
	if(isEmpty())
		return 0;
	else
	{
		QN *ptr = front;
		int count = 0;
		while(ptr != NULL)
		{
			count++;
			ptr = ptr->next;
		}
		return count;
	}
}

void frontElement()//=> O(1)
{
	isEmpty() ? printf("Empty") : printf("Front: %d",front->data);
}

void rearElement()//=> O(1)
{
	isEmpty() ? printf("Empty") : printf("Rear: %d",rear->data);
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
