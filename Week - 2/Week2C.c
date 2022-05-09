#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);

    int arr[n][n], i, j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&arr[i][j]);

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            i>=j ? printf("%d ",arr[i][j]) : printf("0 ");
        printf("\n");
    }
    return 0;
}
