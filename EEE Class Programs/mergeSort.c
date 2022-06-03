#include<stdio.h>

void merge(int arr[],int li,int mi,int ri)
{
	int len1 = mi-li+1;//Identifying the length of left array
	int len2 = ri-mi;//Identifying the length of right array
	
	int leftArr[len1], rightArr[len2],i,j;
	for(i=0;i<len1;i++)
		leftArr[i] = arr[li+i];//Copying elements into left array
	for(j=0;j<len2;j++)
		rightArr[j] = arr[mi+j+1];//Copying elements into right array
	int k = li;
	i = 0; j = 0;
	while(i<len1 && j<len2)//Merging array in sorted order
		arr[k++] = leftArr[i] <= rightArr[j] ? leftArr[i++] : rightArr[j++];
	while(i<len1) //Copying remaining elements of left array
		arr[k++] = leftArr[i++];
	while(j<len2) //Copying remaining elements of right array
		arr[k++] = rightArr[j++];
}

void mergeSort(int arr[],int li,int ri)
{
	if(li < ri)
	{
		int mi = (li+ri)/2;
		mergeSort(arr,li,mi);
		mergeSort(arr,mi+1,ri);
		merge(arr,li,mi,ri);
	}
}

int main()
{
	int n;
	printf("Enter n value: ");
	scanf("%d",&n);//Reading n value into program

	int arr[n], i;
	printf("Enter elements into list: ");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);//Read elements into list

	printf("\nElements of list before sorting: ");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);

	mergeSort(arr,0,n-1);

	printf("\nElements of list after sorting: ");
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);

	return 0;
}
