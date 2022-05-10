#include<stdio.h>
#include<stdbool.h>
#define SIZE 5

int stack[SIZE], top = -1;

bool isFull()
{
	return top == SIZE-1;
}

void push()
{
	if(isFull())
		printf("\nStack is overflow");
	else
	{
		printf("\nEnter a new value: ");
		scanf("%d",&stack[++top]);
		printf("\nElement placed successfully");
	}
}

bool isEmpty()
{
	return top == -1;
}

void pop()
{
	if(isEmpty())
		printf("\nStack is underflow");
	else
		printf("\nElement to be deleted is: %d",stack[top--]);
}

void peek()//TOp of stack
{
	if(isEmpty())
		printf("\nStack is empty, No more top element");
	else
		printf("\nTop of stack is: %d",stack[top]);
}

int size()
{
	return top+1;
}

void display()
{
	if(isEmpty())
		printf("\nSTack is empty, No elements to print");
	else
	{
		int i;
		for(i=top;i>=0;i--)
			printf("\n%d",stack[i]);
	}
}

int main()
{
	push();
	pop();
	push();
	push();
	push();
	display();
}














