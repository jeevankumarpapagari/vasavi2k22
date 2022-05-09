struct stackNode
{
	int marks;
	float cgpa;
	struct stackNode *next;
}*top = NULL;
typedef struct stackNode SN;

SN* push(SN *top,int m,float c)//Inserting at beginning of SLL
{
	SN *newNode = (SN*) malloc(sizeof(SN));
	newNode->marks = m;
	newNode->cgpa = c;
	newNode->next = top;
	return newNode;
}

SN* pop(SN *top)
{
	/*if(top == NULL)
		return NULL;
	if(top->next == NULL)
		return NULL;*/
	if(top == NULL || top->next == NULL)
		return NULL;
	SN *temp = top;
	top = top->next;
	free(temp);
	return top;
	//return (top==NULL || top->next==NULL) ? NULL : top->next;
}

int main()
{
	top = push(top,500,8.96);
	top = push(top,540,9.56);
	top = push(top,550,9.65);
	return 0;
}
