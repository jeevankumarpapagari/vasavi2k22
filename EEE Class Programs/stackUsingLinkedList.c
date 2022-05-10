#include<stdlib.h>
struct stackNode
{
	int data;
	struct stackNode *next;
}*top = NULL;
typedef struct stackNode SN;

SN* push(SN *top,int value)
{
	SN *newNode = (SN*) malloc(sizeof(SN));
	newNode->data = value;
	newNode->next = top;
	return newNode;
}

SN* pop(SN *top)
{
	if(top == NULL)//In case stack is empty
		return NULL;
	if(top->next == NULL)//In case stack contain only top
	{
		free(top);
		return NULL;
	}
	//In case stack contains more elements
	SN *temp = top;
	top = top->next;
	free(temp);
	return top;

	//return (top==NULL || top->next==NULL) ? NULL : top->next;
}

int main()
{
	top = push(top,10);
	top = push(top,20);
	top = push(top,30);
	
	top = pop(top);
	
	return 0;
}
