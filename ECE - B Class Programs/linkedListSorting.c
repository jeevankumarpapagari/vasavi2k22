#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;
}*head = NULL, *sorted = NULL;

void insertAtBeginning(int newValue)
{
	struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
	newNode->data = newValue;
	newNode->next = head;
	head = newNode;
}

void display()
{
	if(head == NULL)
		printf("\nList is empty");
	else
	{
		struct Node *ptr = head;
		while(ptr)
		{
			printf("%d => ",ptr->data);
			ptr = ptr->next;
		}
		printf("NULL");
	}
}

void sortedInsert(struct Node *ptr)
{
	if(sorted == NULL || sorted->data >= ptr->data)
	{
		ptr->next = sorted;
		sorted = ptr;
	}
	else
	{
		struct Node *current = sorted;
		while(current->next && current->next->data < ptr->data)
			current = current->next;
		ptr->next = current->next;
		current->next = ptr;
	}
}

void sort()
{
	struct Node *current = head;
	while(current)//current != NULL
	{
		struct Node *nextNode = current->next;
		sortedInsert(current);
		current = nextNode;
	}
	head = sorted;
}

int main()
{
	insertAtBeginning(10);
	insertAtBeginning(5);
	insertAtBeginning(15);
	insertAtBeginning(12);
	insertAtBeginning(30);
	insertAtBeginning(22);
	
	display();
	
	sort();
	
	display();
	
	return 0;
}
