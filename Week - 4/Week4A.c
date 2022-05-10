#include <stdio.h>
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
        while(ptr->next != NULL)
            ptr = ptr->next;
        ptr->next = newNode;
        newNode->prev = ptr;
    }
    return head;
}

void display()
{
    DLLNode *ptr = head;
    while(ptr->next != NULL)
    {
        printf("%d<==>",ptr->data);
        ptr = ptr->next;
    }
    printf("%d",ptr->data);
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
    display();
    return 0;
}
