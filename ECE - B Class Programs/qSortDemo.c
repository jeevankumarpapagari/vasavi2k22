#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int*)x - *(int*)y;
}

int main()
{
	int arr[9] = {1,5,9,3,7,6,2,4,8}, i;
	qsort(arr,9,sizeof(int),compare);
	for(i=0;i<9;i++)
		printf("%d ",arr[i]);
	return 0;
}
