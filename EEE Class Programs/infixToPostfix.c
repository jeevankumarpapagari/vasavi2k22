/*
			Infix to Postfix
	1. Read an expression into the program as string1
	2. Scan the characters of an expression from left to right one by one
	3. If scanned character:
		1. An operand: Add it into post-fix notation
		2. An Open paranthesis: Push it into stack
		3. A close paranthesis: Perform pop operation
			until next open paranthesis and add to
			the post-fix notation
		4. An operator:
			1. Pop all the operators which are having
				greaterthan or equal precedence in the
				stack and add it to the post-fix notation
			2. Push an operator into stack
	4. In case stack is not empty, Pop all operators
		until stack is empty.
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

int priority(char ch)
{
	return (ch=='*'||ch=='/') ? 2 : (ch=='+'||ch=='-') ? 1 : 0;
}

int main()
{
	char expr[100];
	printf("Enter infix notation: ");
	scanf("%s",expr);

	int i = 0;
	while(expr[i] != '\0')
	{
		if(isupper(expr[i]) || islower(expr[i]) || isdigit(expr[i]))
			printf("%c",expr[i]);
		else if(expr[i] == '(')
			push(expr[i]);
		else if(expr[i] == ')')
		{
			char ch;
			while((ch=pop()) != '(')
				printf("%c",ch);
		}
		else
		{
			while(priority(stack[top]) >= priority(expr[i]))
				printf("%c",pop());
			push(expr[i]);
		}
		i++;
	}
	while(top != -1)
		printf("%c",pop());

	return 0;
}











