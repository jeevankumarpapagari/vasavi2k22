#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct circularLinkedListNode
{
    int data;
    struct circularLinkedListNode *next;
}*head = NULL, *tail = NULL;

typedef struct circularLinkedListNode CLLNode;

void insertAtBeginning(int value)
{
    CLLNode *newNode = (CLLNode*) malloc(sizeof(CLLNode));
    newNode->data = value;
    if(head == NULL)
    {
        newNode->next = newNode;
        head = tail = newNode;
    }
    else
    {
        newNode->next = head;
        tail->next = newNode;
        head = newNode;
    }
}

void insertAtEnding(int value)
{
    CLLNode *newNode = (CLLNode*) malloc(sizeof(CLLNode));
    newNode->data = value;
    if(tail == NULL)
    {
        newNode->next = newNode;
        head = tail = newNode;
    }
    else
    {
        newNode->next = head;
        tail->next = newNode;
        tail = newNode;
    }
}

void deleteFromBeginning()
{
    if(head == NULL)
        printf("Invalid\n");
    else if(head->next == head)
    {
        free(head);
        head = tail = NULL;
    }
    else
    {
        CLLNode *temp = head;
        head = head->next;
        tail->next = head;
        free(temp);
    }
}

void deleteFromEnding()
{
    if(head == NULL)
        printf("Invalid\n");
    else if(head->next == head)
    {
        free(head);
        head = tail = NULL;
    }
    else
    {
        CLLNode *ptr = head, *temp = tail;
        while(ptr->next != tail)
            ptr = ptr->next;
        ptr->next = tail->next;
        tail = ptr;
        free(temp);
    }
}

void display()
{
    if(head == NULL)
        printf("Empty\n");
    else
    {
        CLLNode *ptr = head;
        while(ptr!=tail)
        {
            printf("->%d",ptr->data);
            ptr = ptr->next;
        }
        printf("->%d->\n",ptr->data);
    }
}

int main()
{
    int n;
    scanf("%d",&n);

    while(n--)
    {
        int choice,element;
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: scanf("%d",&element);
                    insertAtBeginning(element);
                    break;
            case 2: scanf("%d",&element);
                    insertAtEnding(element);
                    break;
            case 3: deleteFromBeginning(); break;
            case 4: deleteFromEnding(); break;
            case 5: display(); break;
        }
    }
    return 0;
}
