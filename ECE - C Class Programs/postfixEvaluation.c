/*
			Postfix Evaluation
	1. Read expression into program in the form of string
		as Postfix notation
	2. Scan the characters from left to right one by one
	3. If scanned character is:
		1. operand: Push it into stack
		2. operator:
			1. Extract top two values from stack
			2. Perform evaluation for result
			3. Store result back into stack
	4. In case top value is 0, print result [top of stack],
		Otherwise print invalid postfix notation
*/
#include<stdio.h>
#include<ctype.h>

int stack[50], top = -1;

void push(int ele)
{
	stack[++top] = ele;
}

int pop()
{
	return stack[top--];
}

int main()
{
	char pfExp[100];
	printf("Enter postfix notation: ");
	scanf("%s",pfExp);
	
	int i = 0;
	while(pfExp[i] != '\0')
	{
		if(isdigit(pfExp[i]))
			push(pfExp[i]-'0');
		else
		{
			int y = pop();
			int x = pop();
			switch(pfExp[i])
			{
				case '+': push(x+y); break;
				case '-': push(x-y); break;
				case '*': push(x*y); break;
				case '/': push(x/y); break;
			}
		}
		i++;
	}
	top==0 ? printf("Result is: %d",pop()) : printf("Invalid input");
	return 0;
}



















