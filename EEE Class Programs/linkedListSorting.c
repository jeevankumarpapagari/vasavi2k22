#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*head = NULL, *sortedHead = NULL;

void insertAtBeginning(int value)
{
	struct Node *nn = (struct Node*) malloc(sizeof(struct Node));
	nn->data = value;
	nn->next = head;
	head = nn;
}

void display()
{
	if(head == NULL)
		printf("\nList is empty\n");
	else
	{
		struct Node *ptr = head;
		while(ptr != NULL)
		{
			printf("%d => ",ptr->data);
			ptr = ptr->next;
		}
		printf("NULL\n");
	}
}

void sortedInsert(struct Node *ptr)
{
	if(sortedHead == NULL || sortedHead->data >= ptr->data)
	{
		ptr->next = sortedHead;
		sortedHead = ptr;
	}
	else
	{
		struct Node *current = sortedHead;
		while(current->next != NULL && current->next->data < ptr->data)
			current = current->next;
		ptr->next = current->next;
		current->next = ptr;
	}
}

void sort()
{
	struct Node *current = head;
	while(current != NULL)
	{
		struct Node *nextNode = current->next;
		sortedInsert(current);
		current = nextNode;
	}
	head = sortedHead;
}

int main()
{
	insertAtBeginning(15);
	insertAtBeginning(10);
	insertAtBeginning(5);
	insertAtBeginning(19);
	insertAtBeginning(35);
	insertAtBeginning(30);
	
	display();
	
	sort();
	
	display();
	
	return 0;
}
