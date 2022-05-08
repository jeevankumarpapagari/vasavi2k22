//Postfix Expression Evaluation
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int stack[100],top=-1;
void push(int x)
{
    top++;
    stack[top]=x;
}
int pop()
{
    int x=stack[top];
    top--;
    return x;
}
int main()
{
    char str[100];
    scanf("%s",str);
    int i=0;
    while(str[i])
    {
        if(str[i]>='0' && str[i]<='9')
            push(str[i]-48);
        else 
        {
            int x=pop();
            int y=pop();
            if(str[i]=='+')
                push(x+y);
            else if(str[i]=='-')
                push(y-x);
            else if(str[i]=='/')
                push(y/x);
            else if(str[i]=='*')
                push(y*x);
            else 
                push(y%x);
        }
        i++;
    }
    printf("%d",stack[top]);
    return 0;
}

