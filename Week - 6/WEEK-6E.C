//DSOE 6E: Design Circular Queue using array
/*
Input Format

First line an integer N, size of Queue
Second line an integer Q, number of operations on circular queue
Next Q lines each line contain one operation each:1 X denotes insert X value to queue, 2 denotes delete the first element,3 denotes print first element, 4 denotes print last element,5 denotes check the queue is empty or not
Constraints

1 <= N < = 10 1 <= Q < = 100

Output Format

Every answer should be in new line according to the problem statement

Sample Input 0

5
13
1 10
1 20
1 30
1 40
1 50
1 60
2
1 60
1 70
2
3
4
5
Sample Output 0

Queue is Full
Queue is Full
30
60
0
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int f=-1,r=-1;
int *q,qsize;
void isempty()
{
    if(f==-1)
        printf("1\n");
    else 
        printf("0\n");
}
void enq(int x)
{
    if( (f==0 && r==qsize-1) || (f==r+1) )
    {
        printf("Queue is Full\n");
        return;
    }
    if(f==-1)
        f=r=0;
    else 
        r=(r+1)%qsize;
    q[r]=x;
}
void deq()
{
    if(f==-1)
        printf("Queue is Empty\n");
    else if(f==r)
        f=r=-1;
    else 
        f=(f+1)%qsize;
}
void front()
{
    if(f==-1)
        printf("Queue is Empty\n");
    else 
        printf("%d\n",q[f]);
}
void rear()
{
    if(f==-1)
        printf("Queue is Empty\n");
    else 
        printf("%d\n",q[r]);
}

int main() 
{
    scanf("%d",&qsize);
    q=(int*)malloc(sizeof(int)*qsize);
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

