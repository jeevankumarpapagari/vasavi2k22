#define SIZE 5
int cQueue[SIZE], rear = -1, front = -1;

void enQueue(int ele)
{
	if((front==0 && rear==SIZE-1) || rear+1==front)
		printf("Circular Queue is FULL");
	else if(rear == -1)
		rear = front = 0;
	else
	    rear = (rear+1)%SIZE;
	cQueue[rear] = ele;
}

void deQueue()
{
	if(front==-1)
		printf("Circular Queue is empty");
	else if(front == rear)
		front = rear = -1;
	else
	    front = (front+1)%SIZE;
}
int size()
{
	if(front==-1)
		return 0;
	else
	{
		int i, count = 0;
		for(i=front;i!=rear;i=(i+1)%SIZE)
			count++;
		return count+1;
	}
}
int main()
{
	enQueue(5);//0
	enQueue(9);//1
	enQueue(4);//2
	enQueue(8);//3
	enQueue(6);//4
	enQueue(10);//0->Invalid
	deQueue();//Deletes from 0 index
	deQueue();//Deletes from 1 index
	deQueue();//Deletes from 2 index
	deQueue();//Deletes from 3 index
	deQueue();//Deletes from 4 index
	deQueue();//Deletes from 0 index
	printf("Total elements: ",size());
}
