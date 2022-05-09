/*
		Topic: Infix to Postfix
	1. Read input of expression in form of string
	2. Scan the expression from left to right one by one
	3. If scanned character is:
		1. an operand: Add it into post-fix notation
		2. an open paranthesis: Push it into stack
		3. a close paranthesis: Pop all of the operators
			from stack until open paranthesis and add it
			to post-fix notation
		4. an operator:
			1. Pop all of the operators from stack if
				those are having equal or highiest
				precedence than scanned character and add
				it to post-fix notation
			2. Push operator into stack
	4. In case stack is not empty, pop all operators from
		stack until stack is empty and add it to
		post-fix notation
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
	char exp[100];
	printf("Enter an In-fix notation: ");
	scanf("%s",exp);
	
	int i = 0;
	while(exp[i] != '\0')
	{
		if(isupper(exp[i]) || islower(exp[i]) || isdigit(exp[i]))
			printf("%c",exp[i]);
		else if(exp[i] == '(')
			push(exp[i]);
		else if(exp[i] == ')')
		{
			char ch;
			while((ch=pop())!='(')
				printf("%c",ch);
		}
		else
		{
			while(prio(stack[top]) >= prio(exp[i]))//prio(stack[top]>=prio(exp[i])
				printf("%c",pop());
			push(exp[i]);
		}
		i++;
	}
	while(top!=-1)
		printf("%c",pop());
	return 0;
}
