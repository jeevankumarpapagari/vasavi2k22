#include<stdio.h>

void swap(int *x,int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void partition(int arr[],int left,int right)
{
	int pivot = arr[right],i=left-1,j;
	for(j=left;j<right;j++)
	{
		if(arr[j] <= pivot)
		{
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[right]);
}

int main()
{
	int arr[6] = {1,5,9,3,8,6}, i;
	partition(arr,0,5);
	for(i=0;i<6;i++)
		printf("%d ",arr[i]);
}
