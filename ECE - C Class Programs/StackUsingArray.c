#include<stdio.h>
#include<stdbool.h>
#define SIZE 5
int stack[SIZE], top = -1;

bool isStackFull()// O(1)
{
	return top == SIZE-1;
}

void push()//Inserting element into stack => O(1)
{
	if(isStackFull())
		printf("STack is overflow\n");
	else
	{
		int ele;
		printf("\nEnter an element: ");
		scanf("%d",&ele);
		top = top+1; //top++ or ++top or top += 1
		stack[top] = ele;//scanf("%d",&stack[++top]);
		printf("Element placed successfully\n");
	}
}

bool isStackEmpty()//O(1)
{
	return top == -1;
}

void pop()//O(1)
{
	if(isStackEmpty())
		printf("Stack is Underflow\n");
	else
		printf("Element to be deleted is: %d",stack[top--]);
}
void display() //O(N)
{
	if(isStackEmpty())
		printf("STack is empty, No elements presented\n");
	else
	{
		int i;
		for(i=top;i>=0;i--)
			printf("%d\n",stack[i]);
	}
}

void peek()//O(1)
{
	if(isStackEmpty())
		printf("Stack is empty\n");
	else
		printf("Top of stack is: %d\n",stack[top]);
}

int size()//O(1)
{
	return top+1;
}

int main()
{
	display();
	pop();
	push();
	push();
	push();
	display();
	pop();
	push();
	push();
	push();
	pop();
	display();
	peek();
	return 0;
}
