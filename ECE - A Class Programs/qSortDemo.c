#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int*)x - *(int*)y;
}

int main()
{
	int n;
	printf("Enter n value: ");
	scanf("%d",&n);
	
	int arr[n], i;
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	printf("\nElements before sorting:\n");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);

	qsort(arr,n,sizeof(int),compare);

	printf("\nElements after sorting:\n");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);

	return 0;
}
