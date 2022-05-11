#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct doubleLinkedListNode
{
    struct doubleLinkedListNode *prev;
    int data;
    struct doubleLinkedListNode *next;
}*head = NULL;

typedef struct doubleLinkedListNode DLLNode;

DLLNode* insertAtEnd(DLLNode *head,int value)
{
    DLLNode *newNode = (DLLNode*) malloc(sizeof(DLLNode));
    newNode->data = value;
    newNode->next = NULL;
    if(head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
    }
    else
    {
        DLLNode *ptr = head;
        while(ptr->next)
            ptr = ptr->next;
        ptr->next = newNode;
        newNode->prev = ptr;
    }
    return head;
}

DLLNode* deleteFromBeginning(DLLNode *head)
{
    if(head == NULL)
    {
        printf("Invalid\n");
        return NULL;
    }
    if(head->next == NULL)
    {
        free(head);
        return NULL;
    }
    DLLNode *temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);
    return head;
}

DLLNode* deleteFromPosition(DLLNode *head,int pos)
{
    if(pos < 1 || (head==NULL && pos >= 1))
    {
        printf("Invalid\n");
        return NULL;
    }

    if(pos == 1)
        return deleteFromBeginning(head);

    DLLNode *ptr = head;
    for(int i=1;i<=pos-2;i++)
    {
        if(ptr!=NULL)
            ptr = ptr->next;
        else
        {
            printf("Invalid\n");
            return head;
        }
    }
    DLLNode *temp = ptr->next;
    DLLNode *ptr1 = temp->next;
    ptr->next = ptr1;
    if(ptr1 != NULL)
        ptr1->prev = ptr;
    free(temp);
    return head;
}

void display(DLLNode *head)
{
    if(head == NULL)
        printf("Empty\n");
    else
    {
        DLLNode *ptr = head;
        while(ptr->next)
        {
            printf("%d<=>",ptr->data);
            ptr = ptr->next;
        }
        printf("%d\n",ptr->data);
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
        head = insertAtEnd(head,element);
    }
    scanf("%d",&n);
    while(n--)
    {
        int pos;
        scanf("%d",&pos);
        head = deleteFromPosition(head,pos);
    }
    display(head);
    return 0;
}
