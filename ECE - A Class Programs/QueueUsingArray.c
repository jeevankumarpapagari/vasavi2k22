/*
				Queue
	1. Queue is a linear data structure
	2. Queue works based on a principle FIFO
		[First In First Out] or LILO [Last In
		Last Out]
	3. The position where insertion can be done will
		be known as rear position
	4. The position where deletion can takes place
		will be known as front position
	5. Operations:
		1. Enqueue => Insertion
		2. Dequeue => Deletion
		3. rearOperation => Last inserted element
		4. frontOperation => First element to be delete
		5. isEmpty => Checking Queue is empty
		6. isFull => Checking Queue is full
		7. Size => Total number of elements
	6. Implementation ways:
		1. Using an Array
		2. Using a Linked list
*/
#include<stdio.h>
#include<stdbool.h>
#define SIZE 100
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

void rearValue()
{
	if(front > rear)    printf("Queue is empty");
	else                printf("Rear Value is: %d",queue[rear]);
}

void frontValue()
{
	if(front > rear)    printf("Queue is empty");
	else                printf("Front Value is: %d",queue[front);
}

void isEmpty()
{
	front > rear ? printf("Yes") : printf("No");
}

void isFull()
{
	rear == SIZE-1 ? printf("Yes") : printf("No");
}

int size()
{
	return (rear-front)+1;
}

int main()
{
	enQueue(100);
	enQueue(200);
	enQueue(150);
	enQueue(250);
	deQueue();
	rearValue();
}











