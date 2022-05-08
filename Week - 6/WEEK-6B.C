//DSOE 6B: Queue using Linked List
/*
Note: All operations should be performed in O(1) time complexity.

Input Format

First line an integer N
Next N lines each line contain one operation each:1 X denotes insert X value to queue, 2 denotes delete the first element,3 denotes print first element, 4 denotes print last element,5 denotes check the queue is empty or not.
Constraints

1 <= N < = 25

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
struct node 
{
    int data;
    struct node *next;
}*f,*r;
void isempty()
{
    if(f==NULL)
        printf("1\n");
    else 
        printf("0\n");
}
void enq(int x)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=NULL;
    if(f==NULL)
        f=r=newnode;
    else
    {
        r->next=newnode;
        r=newnode;
    }
}
void deq()
{
    if(f==NULL)
        printf("invalid\n");
    else if(f==r)
        f=r=NULL;
    else 
    { //printf("%d",f->data);
        f=f->next;
    }
}
void front()
{
    if(f==NULL)
        printf("invalid\n");
    else 
        printf("%d\n",f->data);
}
void rear()
{
    if(f==NULL)
        printf("invalid\n");
    else 
        printf("%d\n",r->data);
}

int main() 
{
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

