#include<stdio.h>

void merge(int arr[],int left,int middle,int right)
{
	int len1 = middle-left+1;//Calculating of left array length
	int len2 = right-middle;//Calculating right array length
	
	int leftArray[len1], rightArray[len2], i, j, k = left;
	
	for(i=0;i<len1;i++)//Preparing left array
		leftArray[i] = arr[left+i];
	for(j=0;j<len2;j++)//Preparing right array
		rightArray[j] = arr[middle+j+1];

	i = 0; j = 0;
	while(i<len1 && j<len2)//Preparation of final array
		arr[k++] = leftArray[i] <= rightArray[j] ? leftArray[i++] : rightArray[j++];
	while(i<len1)//Copying leftover elements of left array
		arr[k++] = leftArray[i++];
	while(j<len2)//Copying leftover elements of right array
		arr[k++] = rightArray[j++];
}

void mergeSort(int arr[],int left,int right)
{
	if(left < right)//Base case
	{
		int middle = (left + right) / 2;
		mergeSort(arr,left,middle);
		mergeSort(arr,middle+1,right);
		merge(arr,left,middle,right);
	}
}

int main()
{
	int arr[9] = {1,5,9,3,7,6,4,2,8}, i;
	
	printf("Elements before sorting: ");
	for(i=0;i<9;i++)
		printf("%d ",arr[i]);

	mergeSort(arr,0,8);

	printf("\n\nElements after sorting: ");
	for(i=0;i<9;i++)
		printf("%d ",arr[i]);
	
	return 0;
}
