#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        char exp[100], stack[100];
        int top = -1;
        scanf("%s",exp);
        int i = -1, flag = 1;
        while(exp[++i])
        {
            if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
                stack[++top] = exp[i];
            else if((exp[i]==')' && stack[top]=='(') || (exp[i]==']' && stack[top]=='[') || (exp[i]=='}' && stack[top]=='{'))
                top--;
            else
            {
                printf("Invalid\n");
                flag = 0;
                break;
            }
        }
        if(exp[i] == '\0' && top==-1)
            printf("Valid\n");
        else if(flag)
            printf("Invalid\n");
    }
    return 0;
}
