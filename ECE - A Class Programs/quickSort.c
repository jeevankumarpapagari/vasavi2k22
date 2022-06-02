#include<stdio.h>

void swap(int *x,int *y)//call be reference
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int partition(int arr[],int left,int right)
{
	int pivot = arr[right], i = left-1, j;
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
	if(left < right)
	{
		int pi = partition(arr,left,right);
		quickSort(arr,left,pi-1);
		quickSort(arr,pi+1,right);
	}
}

int main()
{
	int n;
	printf("Enter n value: ");
	scanf("%d",&n);//Reading total number of elements of list
	
	int arr[n], i;
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);//Reading elements into list

	printf("\nElements before sorting:\n");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);

	quickSort(arr,0,n-1);

	printf("\nElements after sorting:\n");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);

	return 0;
}
