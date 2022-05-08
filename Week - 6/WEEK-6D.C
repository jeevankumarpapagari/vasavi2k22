//DSOE 6D: Bracket Sequence Validation
/*
Input Format

First line an integer N
Next N lines each line contain single string that denotes the bracket sequence
Constraints

Input string should contain the (,),[,],{ and } brackets

Output Format

Print “Valid” or “Invalid” in N lines according to the problem statement

Sample Input 0

3
{[()]}[()]({})
{[(])} 
{{[[(())]]}} 
Sample Output 0

Valid
Invalid
Valid
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
char s[100];
int top=-1;
void push(char x)
{
    top++;
    s[top]=x;
}
void pop()
{
    top--;
}
int main() 
{

    int t;
    scanf("%d",&t);
    while(t--)
    {
        char str[100];
        scanf("%s",str);
        int i=0,f=0;
        while(str[i])
        {
            if((str[i]==']' || str[i]=='}' || str[i]==')') && top==-1)
            {
                printf("Invalid\n");
                f=1;
                break;
            }
            else if(str[i]=='[' || str[i]=='{' || str[i]=='(' )
            {
                push(str[i]);
            }
            else if(str[i]==']' && s[top]=='[' )
                pop();
            else if(str[i]=='}' && s[top]=='{')
                pop();
            else if( str[i]==')' && s[top]=='(') 
                pop();
            else 
            {
                printf("Invalid\n");
                f=1;
                break;
            }
            i++;
        }
        if(top==-1 && str[i]=='\0')
            printf("Valid\n");
        else if(f==0)
            printf("Invalid\n");
        else 
        {
            
        }
        top=-1;
    }
    return 0;
}


