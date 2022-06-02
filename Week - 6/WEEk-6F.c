#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char stack[1000];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

bool isPalindrome(char str[],int len)
{
    int i;
    for(i=0;i<len/2;i++)
        push(str[i]);
    if(len%2)
        i++;
    while(str[i])
    {
        if(str[i] != pop())
            return false;
        i++;
    }
    return true;
}

int main()
{
    int n;
    scanf("%d",&n);

    while(n--)
    {
        char str[55];
        scanf("%s",str);
        isPalindrome(str,strlen(str)) ? printf("YES\n") : printf("NO\n");
    }
    return 0;
}
