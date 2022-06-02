#include<stdio.h>
int main()
{
	int n;
	printf("Enter value of n: ");
	scanf("%d",&n);//Reading total number of elements of list
	
	int arr[n], i;
	printf("Enter value into list: ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);//Reading elements into list
		
	//print elements before sorting
	printf("\nElements before sorting:\n");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
		
	//Insertion sort procedure
	int count = 0;
	for(i=1;i<n;i++)
	{
		int key = arr[i], j = i-1;
		while(j>=0 && arr[j]>key)
		{
			arr[j+1] = arr[j];
			j--;
			count++;
		}
		arr[j+1] = key;
	}
	
	//print elements after sorting
	printf("\nElements after sorting:\n");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\nTotal operations: %d\n",count);
	return 0;
}
