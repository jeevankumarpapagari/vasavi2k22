#include<stdio.h>

void merge(int arr[],int left,int middle,int right)
{
	int leftLength = middle-left+1;//Calc number of elements in left array
	int rightLength = right-middle;//Calc number of elements int right array
	
	int leftArray[leftLength], rightArray[rightLength];
	int i, j , k = left;
	
	for(i=0;i<lefLength;i++)//Copying arr elements into left
		leftArray[i] = arr[left+i];
	for(j=0;j<rightLength;j++)//Copying arr elements into right
		rightArray[j] = arr[middle+1+j];
	
}

void mergeSort(int arr[],int left,int right)
{
	if(left < right)//Base case
	{
		int middle = (left+right)/2;
		mergeSort(arr,left,middle);
		mergeSort(arr,middle+1,right);
		merge(arr,left,middle,right);
	}
}

int main()
{
	int arr[9] = {1,9,5,3,7,6,4,2,8}, i;
	mergeSort(arr,0,8);
	for(i=0;i<9;i++)
		printf("%d ",arr[i]);
	return 0;
}
