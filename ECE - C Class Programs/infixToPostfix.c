/*
				Infix notation to Postfix notation
	1. Read an expression into the program in the form of string
	2. Scan the characters of an expression from left to right
		one by one
	3. If scanned character is:
		1. Operand: Add it into the postfix notation
		2. OPen paranthesis: Push it into stack
		3. Close paranthesis: Pop all operators until open
			paranthesis from stack and add to postfix notation
		4. Operator:
			1. Pop all the operators from stack if it is having
				equal or greaterthan precedence level while
				comparing with scanned character
			2. Push an operator into stack
	4. In case stack is not empty, Pop all operators from stack
		and add it into postfix notation until stack becomes empty
*/
#include<stdio.h>
#include<ctype.h>
char stack[50];
int top = -1;

void push(char ch)
{
	stack[++top] = ch;
}

char pop()
{
	return stack[top--];
}

int prio(char ch)
{
	return (ch=='*'||ch=='/') ? 2 : (ch=='+'||ch=='-') ? 1 : 0;
}

int main()
{
	char expression[100];
	printf("Enter an expression in the format of infix: ");
	scanf("%s",expression);
	
	int index = 0;
	while(expression[index] != '\0')
	{
		if(isupper(expression[index]) || islower(expression[index]) || isdigit(expression[index]))
			printf("%c",expression[index]);
		else if(expression[index] == '(')
			push(expression[index])
		else if(exprssion[index] == ')')
		{
			char ch;
			while((ch=pop())!='(')
				printf("%c",ch);
		}
		else
		{
			while(prio(stack[top]) >= prio(expression[index]))
				printf("%c",pop());
			push(expression[index]);
		}
		index++;
	}
	while(top != -1)
		printf("%c",pop());
	return 0;
}












