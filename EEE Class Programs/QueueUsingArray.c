#include<stdbool.h>
#define SIZE 5

int queue[SIZE], rear = -1, front = 0;

bool isFull()
{
	return rear == SIZE-1;
}

void enQueue(int ele)
{
	if(isFull())    printf("Queue is Full");
	else            queue[++rear] = ele;
}

bool isEmpty()
{
	return rear < front;
}

void deQueue()
{
	if(isEmpty())       printf("Queue is empty");
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

int size()
{
	return rear-front+1;
}

void frontElement()
{
	isempty() ? printf("Queue is empty") : printf("%d",queue[front]);
}

void rearElement()
{
	isEmpty() ? printf("Queue is empty") : printf("%d",queue[rear]);
}

int main()
{
	enQueue(10);
	enQueue(6);
	enQueue(9);
	enQueue(15);
	enQueue(32);
	enQueue(52);
	deQueue();
	deQueue();
	deQueue();
	deQueue();
	deQueue();
	deQueue();
	printf("TOtal elements of Queue: %d",size());
	frontElement();
	rearElement();
}
