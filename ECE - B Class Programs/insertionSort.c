#include<stdio.h>
int main()
{
	int n;
	printf("Enter n value: ");
	scanf("%d",&n);//Reading total number of elements of list
	
	int arr[n], i;
	printf("Enter elements into list: ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);//Reading elements into list
		
	printf("\nList of elements before sorting:\n");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);

	//Insertion sort process
	for(i=1;i<n;i++)
	{
		int key = arr[i], j = i-1;
		while(j>=0 && arr[j]>key)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
	
	printf("\nList of elements after sorting:\n");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
}
