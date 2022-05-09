/*
				STACK
	1. Linear data structure
	2. Works based on a principle known as LIFO or FILO
	3. Insertion and Deletion both will be performed from only
		one end known as TOP location
	4. Operations:
		1. Insertion -> Push
		2. Deletion -> Pop
		3. Top of stack -> Peek
		4. Total number of elements -> Size
		5. Is stack is full -> isFull
		6. Is stack is empty -> isEmpty
		7. Searching of an element -> Search
	5. Implementations:
		1. By using an Array
		2. By using a Linked list
*/
#include<stdbool.h>
#include<stdio.h>
#define SIZE 5
int stack[SIZE], top = -1;

bool isFull()
{
	return top == SIZE-1;
}

void push()
{
	if(isFull())
		printf("Stack is full");
	else
	{
		int element;
		printf("Enter new element value: ");
		scanf("%d",&element);
		top = top+1; //top++ or ++top
		stack[top] = element;
	}
}

bool isEmpty()
{
	return top == -1;
}

void pop()
{
	if(isEmpty())
		printf("Stack is empty, Not possible to delete");
	else
		printf("Element to be deleted is: %d",stack[top--]);
}

void peek()//Top of stack
{
	if(isEmpty())
		printf("NO top element because stack is empty");
 	else
		printf("TOp of stack is: %d",stack[top]);
}

int size()
{
	return top+1;
}






