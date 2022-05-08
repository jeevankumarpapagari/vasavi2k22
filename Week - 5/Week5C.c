#include <stdio.h>
#include <ctype.h>

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
    char exp[100];
    scanf("%s",exp);

    int i = -1;
    while(exp[++i])
    {
        if(islower(exp[i]))
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
    }
    while(top != -1)
        printf("%c",pop());
    return 0;
}

