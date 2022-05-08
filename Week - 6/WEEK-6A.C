//DSOE 6A: Queue using dynamic array
/*
Input Format

First line an integer N
Next N lines each line contain one operation each:1 X denotes insert X value to queue, 2 denotes delete the first element,3 denotes print first element, 4 denotes print last element,5 denotes check the queue is empty or not.

Output Format

If you are unable to delete an element from the queue print “invalid”

Sample Input 0

9
5
1 10
1 20
1 30
3
5
4
2
3
Sample Output 0

1
10
0
30
20
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int f=-1,r=-1;
int *q;
void isempty()
{
    if(f==-1)
        printf("1\n");
    else 
        printf("0\n");
}
void enq(int x)
{
    if(f==-1)
        f=r=0;
    else 
        r++;
    q[r]=x;
}
void deq()
{
    if(f==-1)
        printf("invalid\n");
    else if(f==r)
        f=r=-1;
    else 
        f++;
}
void front()
{
    if(f==-1)
        printf("invalid\n");
    else 
        printf("%d\n",q[f]);
}
void rear()
{
    if(f==-1)
        printf("invalid\n");
    else 
        printf("%d\n",q[r]);
}

int main() 
{
    q=(int*)malloc(sizeof(int)*100);
    int t,ch,x;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&ch);
        if(ch==1)
        {
           scanf("%d",&x);
            enq(x);
        }
        else if(ch==2)
            deq();
        else if(ch==3)
            front();
        else if(ch==4)
            rear();
        else 
            isempty();
    }
   
    return 0;
}

