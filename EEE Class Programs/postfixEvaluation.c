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
			switch(exp[i])
			{
				case '+': push(x+y); break;
				case '-': push(x-y); break;
				case '*': push(x*y); break;
				case '/': push(x/y); break;
			}
		}
		i++;
	}
	top==0 ? printf("Result is: %d",pop()) : printf("Invalid Input");
	return 0;
}
