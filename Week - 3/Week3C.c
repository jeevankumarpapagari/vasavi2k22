#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct singleLinkedListNode
{
    int data;
    struct singleLinkedListNode *next;
}*head = NULL;

typedef struct singleLinkedListNode SLLNode;

SLLNode* insertAtBegining(SLLNode *head,int value)
{
    SLLNode *newNode = (SLLNode*) malloc(sizeof(SLLNode));
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

void display(SLLNode *head)
{
    if(head)
    {
        printf("%d ",head->data);
        display(head->next);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int element;
        scanf("%d",&element);
        head = insertAtBegining(head,element);
    }
    display(head);
    return 0;
}
