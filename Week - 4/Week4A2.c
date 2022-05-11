#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct doubleLinkedListNode
{
    struct doubleLinkedListNode *prev;
    int data;
    struct doubleLinkedListNode *next;
}*head = NULL, *tail = NULL;

typedef struct doubleLinkedListNode DLLNode;

DLLNode* insertAtBegin(DLLNode *head,int value)
{
    DLLNode *newNode = (DLLNode*) malloc(sizeof(DLLNode));
    newNode->prev = NULL;
    newNode->data = value;
    newNode->next = head;
    if(head == NULL)
        tail = newNode;
    else
        head->prev = newNode;
    return newNode;
}

DLLNode* insertAtEnd(DLLNode *tail,int value)
{
    DLLNode *newNode = (DLLNode*) malloc(sizeof(DLLNode));
    newNode->data = value;
    newNode->next = NULL;
    if(tail == NULL)
    {
        newNode->prev = NULL;
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    return tail;
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

DLLNode* deleteFromEnding(DLLNode *head)
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
    DLLNode *temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    free(temp);
    return head;
}

DLLNode* insertAtPosition(DLLNode *head,int value,int pos)
{
    if(pos < 1 || (head==NULL && pos>1))
    {
        printf("Invalid\n");
        return head;
    }
    if(pos == 1)
        return insertAtBegin(head,value);

    DLLNode *newNode = (DLLNode*) malloc(sizeof(DLLNode)), *ptr = head;;
    newNode->data = value;
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
    newNode->next = ptr->next;
    if(ptr->next != NULL)
        ptr->next->prev = newNode;
    newNode->prev = ptr;
    ptr->next = newNode;
    return head;
}

void display(DLLNode *head)
{
    if(head == NULL)
        printf("Empty\n");
    else
    {
        DLLNode *ptr = head;
        while(ptr!=tail)
        {
            printf("%d<==>",ptr->data);
            ptr = ptr->next;
        }
        printf("%d\n",tail->data);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int choice, element, pos;
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: scanf("%d",&element);
                    head = insertAtBegin(head,element);
                    break;
            case 2: scanf("%d",&element);
                    tail = insertAtEnd(tail,element);
                    break;
            case 3: head = deleteFromBeginning(head);
                    break;
            case 4: head = deleteFromEnding(head); break;
            case 5: scanf("%d %d",&pos,&element);
                    head = insertAtPosition(head,element,pos);
                    break;
            case 6: display(head); break;
        }
    }
    return 0;
}
