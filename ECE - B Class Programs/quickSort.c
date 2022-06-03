#include<stdio.h>

void swap(int *x,int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int partition(int arr[],int leftIndex,int rightIndex)
{
	int pivot = arr[rightIndex],i = leftIndex-1,j;
	for(j=leftIndex;j<rightIndex;j++)
	{
		if(arr[j] <= pivot)
		{
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[rightIndex]);
	return i+1;
}

void quickSort(int arr[],int left,int right)
{
	if(left < right)//Base case
	{
		int pi = partition(arr,left,right);
		quickSort(arr,left,pi-1);
		quickSort(arr,pi+1,right);
	}
}

int main()
{
	int arr[9] = {1,7,3,9,8,2,5,6,4}, i;
	quickSort(arr,0,8);//0->LeftIndex, 4->RightIndex
	for(i=0;i<9;i++)
		printf("%d ",arr[i]);
}
