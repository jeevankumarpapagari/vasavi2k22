#include <stdio.h>

void swap(int *x,int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int arr[],int left,int right)
{
    int i = left-1, j;
    for(j=left;j<right;j++)
    {
        if(arr[j] <= arr[right])
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[right]);
    return i+1;
}

void quickSort(int arr[],int left,int right)
{
    if(left < right)
    {
        int pi = partition(arr,left,right);
        quickSort(arr,left,pi-1);
        quickSort(arr,pi+1,right);
    }
}

int main()
{
    int tc;
    scanf("%d",&tc);

    while(tc--)
    {
        int n;
        scanf("%d",&n);

        int arr[n], i;
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);

        quickSort(arr,0,n-1);

        for(i=0;i<n;i++)
            printf("%d ",arr[i]);
        printf("\n");
    }
    return 0;
}
