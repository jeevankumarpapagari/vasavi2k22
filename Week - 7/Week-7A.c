#include <stdio.h>

void swap(int *x,int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int n;
    scanf("%d",&n);

    int arr[n], i;
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    int k, j;
    scanf("%d",&k);

    for(i=0;i<k;i++)
    {
        int mi = i;
        for(j=i+1;j<n;j++)
            if(arr[j] < arr[mi])
                mi = j;
        swap(&arr[mi],&arr[i]);
    }

    for(i=0;i<n;i++)
        printf("%d ",arr[i]);

    return 0;
}
