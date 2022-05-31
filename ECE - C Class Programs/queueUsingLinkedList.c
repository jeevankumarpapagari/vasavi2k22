#include<stdio.h>
#include<stdlib.h>

struct queueNode
{
	int data;
	struct queueNode *next;
}*front = NULL, *rear = NULL;
typedef struct queueNode QN;

void enQueue(int ele)
{
	QN *nn = (QN*) malloc(sizeof(QN));
	nn->data = ele;
	nn->next = NULL;
	if(rear == NULL)
		front = rear = nn;
	else
	{
		rear->next = nn;
		rear = nn;
		//rear = rear->next = nn;
	}
}

void deQueue()
{
	if(front == NULL)
		printf("Queue is empty, Not possible to delete\n");
	else if(front->next == NULL)
	{
		printf("Element to be deleted is: %d\n",front->data);
		free(front);
		front = rear = NULL;
	}
	else
	{
		QN *temp = front;
		front = front->next;
		printf("Element to be deleted is: %d\n",temp->data);
		free(temp);
	}
}

void display()
{
	if(front==NULL)
	{
		printf("There are no elements to display\n");
		return;
	}
	QN *ptr = front;
	while(ptr->next)
	{
		printf("%d -> ",ptr->data);
		ptr = ptr->next;
	}
	printf("%d\n",ptr->data);
}

int main()
{
	display();
	deQueue();
	enQueue(100);//rear = NULL
	enQueue(150);//rear -> pointing towards already memory location
	enQueue(200);
	display();
	enQueue(250);
	enQueue(300);
	display();
	deQueue();
	display();
	enQueue(350);
	enQueue(400);
	display();
	deQueue();
	display();
	return 0;
}
