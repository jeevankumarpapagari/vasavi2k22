#include <stdio.h>

void merge(int arr[],int left,int middle,int right)
{
    int len1 = middle-left+1, len2 = right-middle;
    int leftArr[len1], rightArr[len2], i;
    for(i=0;i<len1;i++)
        leftArr[i] = arr[left+i];
    for(i=0;i<len2;i++)
        rightArr[i] = arr[middle+i+1];
    int j=0, k = left; i = 0;
    while(i<len1 && j<len2)
        arr[k++] = leftArr[i] <= rightArr[j] ? leftArr[i++] : rightArr[j++];
    while(i<len1)
        arr[k++] = leftArr[i++];
    while(j<len2)
        arr[k++] = rightArr[j++];
}

void mergeSort(int arr[],int left,int right)
{
    if(left < right)
    {
        int mi = (left+right)/2;
        mergeSort(arr,left,mi);
        mergeSort(arr,mi+1,right);
        merge(arr,left,mi,right);
    }
}

int main()
{
    int n;
    scanf("%d",&n);

    int arr[n],i;
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    mergeSort(arr,0,n-1);

    for(i=0;i<n;i++)
        printf("%d ",arr[i]);

    return 0;
}
