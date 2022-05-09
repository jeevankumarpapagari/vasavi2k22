/*
		In-fix to Post-fix:
	1. Read input value in the form of string
	2. Scan characters one by one from left to right
	3. If scanned character is:
		1. An operand:- Add it into post-fix notation
		2. Open paranthesis:- Push it into stack
		3. Close paranthesis:- Perform pop operation until Open paranthesis
		4. An operator:-
			1. Remove all operators from stack which are having precedence
				value greaterthan or equal to an operator
			2. Push operator into stack
	4. If no more character are there to scan, Perfomr pop operation until
		stack is empty
*/
#include<stdio.h>
#include<ctype.h>

char stack[100];
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
	char exp[100];
	printf("Enter infix notation: ");
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
			while((ch=pop()) != '(')
				printf("%c",ch);
		}
		else
		{
			while(priority(stack[top]) >= priority(exp[i]))
				printf("%c",pop());
			push(exp[i]);
		}
		i++;
	}
	while(top != -1)
		printf("%c",pop());
	return 0;
}





















