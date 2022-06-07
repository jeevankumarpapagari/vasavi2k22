#include<stdio.h>

void merge(int arr[],int leftIndex,int middleIndex,int rightIndex)
{
	int leftArrayLength = middleIndex-leftIndex+1;//Calculating left array length
	int rightArrayLength = rightIndex-middleIndex;//Calculating right array length
	
	int leftArray[leftArrayLength],rightArray[rightArrayLength], i, j, k = leftIndex;
	for(i=0;i<leftArrayLength;i++)//Copying main array elements into left Array
		leftArray[i] = arr[leftIndex+i];
	for(j=0;j<rightArrayLength;j++)//Copying main array elements into right Array
		rightArray[j] = arr[middleIndex+j+1];

	i = 0; j = 0;
	while(i<leftArrayLength && j<rightArrayLength)//Preparing final list
		arr[k++] = leftArray[i] <= rightArray[j] ? leftArray[i++] : rightArray[j++];
		
	while(i < leftArrayLength)//Copying left over elements into main array
		arr[k++] = leftArray[i++];
	while(j < rightArrayLength)//Copying left over elements into main array
		arr[k++] = rightArray[j++];
}

void mergeSort(int arr[],int leftIndex,int rightIndex)
{
	if(leftIndex < rightIndex)
	{
		int middleIndex = (leftIndex + rightIndex) / 2;
		mergeSort(arr,leftIndex,middleIndex);
		mergeSort(arr,middleIndex+1,rightIndex);
		merge(arr,leftIndex,middleIndex,rightIndex);
	}
}

int main()
{
	int arr[9] = {1,5,9,3,7,6,2,4,8};
	mergeSort(arr,0,8);
	int i;
	for(i=0;i<9;i++)
		printf("%d ",arr[i]);
	
	return 0;
}
