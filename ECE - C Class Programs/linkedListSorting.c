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
		printf("\nList is Empty\n");
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

void sortedInsert(int value)
{
	struct Node *nn = (struct Node*) malloc(sizeof(struct Node));
	nn->data = value;
	
	if(sortedHead == NULL || sortedHead->data >= value)
	{
		nn->next = sortedHead;
		sortedHead = nn;
	}
	else
	{
		struct Node *current = sortedHead;
		while(current->next != NULL && current->next->data < value)
			current = current->next;
		nn->next = current->next;
		current->next = nn;
	}
}

void sort()
{
	struct Node *current = head, *nextNode;
	while(current != NULL)
	{
		nextNode = current->next;
		sortedInsert(current->data);
		current = nextNode;
	}
	head = sortedHead;
}

int main()
{
	insertAtBeginning(10);
	insertAtBeginning(30);
	insertAtBeginning(25);
	insertAtBeginning(63);
	insertAtBeginning(85);
	insertAtBeginning(5);

	display();

	sort();

	display();

	return 0;
}
