#include<stdio.h>

void swap(int *x,int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int partition(int arr[],int left,int right)
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
	return i+1;
}

void quickSort(int arr[],int left,int right)
{
	if(left < right)//Base case
	{
		int pi = partition(arr,left,right);
		quickSort(arr,left,pi-1);//Sorting left part of pivot
		quickSort(arr,pi+1,right);//Sorting right part of pivot
	}
}

int main()
{
	int arr[9] = {1,5,9,3,8,6,7,4,2}, i;
	quickSort(arr,0,8);
	for(i=0;i<9;i++)
		printf("%d ",arr[i]);
}
