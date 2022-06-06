#include<stdio.h>
int main()
{
	//int arr[9] = {9,8,7,6,5,4,3,2,1};
	int arr[9] = {1,2,3,4,5,6,7,8,9};
	int i,j,key,c = 0;
	for(i=1;i<9;i++)
	{
		j = i-1;
		key = arr[i];
		while(j>=0 && arr[j]>key)
		{
			arr[j+1] = arr[j];
			j--;
			c++;
		}
		arr[j+1] = key;
	}
	
	for(i=0;i<9;i++)
		printf("%d ",arr[i]);
	printf("\nTotal operations: %d",c);
	return 0;
}
