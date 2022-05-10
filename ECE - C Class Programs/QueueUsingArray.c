/*
				Queue
	1. Queue is a linear data structure
	2. Queue works based on a principle FIFO
		[First In First Out] or LILO [Last In
		Last Out]
	3. The position where insertion can be done will
		be known as rear position
	4. The position where deletion can takes place
		will be known as front position
	5. Operations:
		1. Enqueue => Insertion
		2. Dequeue => Deletion
		3. rearOperation => Last inserted element
		4. frontOperation => First element to be delete
		5. isEmpty => Checking Queue is empty
		6. isFull => Checking Queue is full
		7. Size => Total number of elements
	6. Implementation ways:
		1. Using an Array
		2. Using a Linked list
*/

//Target: Every operation should be done with O(1)
#define SIZE 10
int queue[SIZE], front = 0, rear = -1;

void enQueue(int ele)
{
	if(rear == SIZE-1)      printf("Queue is full");
	else                    queue[++rear] = ele;
}

void deQueue()
{
	if(front > rear)        printf("Queue is Empty");
	else
	{
		front++;
		if(front > rear)
		{
			front = 0;
			rear = -1;
		}
	}
}

int size()
{
	return rear-front+1;
}

bool isEmpty()
{
	return front>rear ? true : false;
}

bool isFull()
{
	return rear == SIZE-1;
}

void frontElement()
{
	isEmpty() ? printf("Queue is empty") : printf("%d",queue[front]);
}

void rearElement()
{
	isEmpty() ? printf("Queue is empty") : printf("%d",queue[rear]);
}

int main()
{
	enQueue(147);
	enQueue(10);
	enQueue(52);enQueue(98);enQueue(45);
	enQueue(96);enQueue(9);enQueue(12);
	deQueue();
	printf("Total elements are: %d",size());
	printf("Is Queue is empty? %d",isEmpty());
}
