/*
				Postfix Evaluation
	A+B => AB+
	5+3 => 53+
	1. Read input [postfix notation] in the form of string
	2. Scan the characters from left to right side one by one
	3. If scanned character is:
		1. Operand: Push it into stack
		2. Operator:
			1. Pop top two operands from stack
			2. Apply operator in between operands
			3. Store result back into stack
	4. Repeat step2 and step3 until all characters scanned
	5. In case top of stack is 0, Valid result would be printed
		Otherwise, Postfix notation is invalid
*/
#include<stdio.h>
#include<ctype.h>

int stack[100], top = -1;

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
	char exp[100];
	printf("Enter postfix notation: ");
	scanf("%s",exp);
	
	int i = 0;
	while(exp[i] != '\0')
	{
		if(isdigit(exp[i]))
			push(exp[i]-'0');
		else
		{
			int y = pop();
			int x = pop();
			int z;
			switch(exp[i])
			{
				case '+': z = x + y; break;
				case '-': z = x - y; break;
				case '*': z = x * y; break;
				case '/': z = x / y; break;
			}
			push(z);
		}
		i++;
	}
	top == 0 ? printf("Result is: %d",pop()) : printf("Invalid postfix notation");
	return 0;
}












