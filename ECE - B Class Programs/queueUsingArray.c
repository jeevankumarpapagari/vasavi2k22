#include<stdio.h>
#define SIZE 10

int queue[SIZE], front = 0, rear = -1;

void enQueue(int ele)
{
	if(rear == SIZE-1)      printf("Queue is Full");
	else                    queue[++rear] = ele;
}

void deQueue()
{
	if(front > rear)        printf("Queue is empty");
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

void isFull()
{
	rear==SIZE-1 ? printf("Yes") : printf("No");
}

void isEmpty()
{
	front > rear ? printf("Yes") : printf("No");
}

void frontElement()
{
	front>rear ? printf("Queue is empty") : printf("Front ele is: %d",queue[front]);
}

void rearElement()
{
	front>rear ? printf("Queue is empty") : printf("Rear ele is: %d",queue[rear]);
}

int main()
{
	enQueue(147);
	enQueue(258);
	enQueue(369);
	enQueue(123);
	enQueue(456);
	deQueue();
	printf("Total elements in queue: %d",size());
	isFull();
	return 0;
}
