#include<stdio.h>

int main()
{
	int n;
	printf("Enter n value: ");
	scanf("%d",&n);//Reading n value into program
	
	int arr[n], i;
	printf("Enter elements into list: ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);//Read elements into list
	int count = 0;
	for(i=1;i<n;i++)
	{
		count++;
		int key = arr[i], j = i-1;
		while(j>=0 && arr[j]>key)
		{
			arr[j+1] = arr[j];
			j--;
			count++;
		}
		arr[j+1] = key;
	}
	
	printf("\nElements of list after sorting: ");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
	printf("\nTotal operations: %d",count);
	return 0;
}
