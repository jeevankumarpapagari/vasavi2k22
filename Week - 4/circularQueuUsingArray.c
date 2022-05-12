#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
#define SIZE 5
int cQueue[SIZE], front = -1, rear = -1;

bool isFull() //-> O(1)
{
	return (front==0 && rear==SIZE-1) || (rear+1==front);
}

void enQueue(int ele) //-> O(1)
{
	if(isFull())
		printf("Circular Queue is full");
	else if(rear == -1)
		front = rear = 0;
	else
		rear = (rear+1)%SIZE;
	cQueue[rear] = ele;
}

bool isEmpty() //-> O(1)
{
	return front == -1;
}

void deQueue() //-> O(1)
{
	if(isEmpty())
		printf("Circular Queue is empty");
	else if(front==rear)
		front = rear = -1;
	else
		front = (front+1)%SIZE;
}

int size() //-> O(N) N:-> Total elements
{
	if(isEmpty())
		return 0;
	else
	{
		int i, count = 0;
		for(i=front;i!=rear;i=(i+1)%SIZE)
			count++;
		return count+1;
	}
}

void frontElement() //-> O(1)
{
	isEmpty() ? printf("Empty") : printf("%d",cQueue[front]);
}

void rearElement() //-> O(1)
{
	isEmpty() ? printf("Empty") : printf("%d",cQueue[rear]);
}

int main()
{
	int i;
 	for(i=1;i<=6;i++)
		enQueue(rand()%100);
	for(i=1;i<=6;i++)
		deQueue();
	printf("Total elements: %d",size());
	return 0;
}
