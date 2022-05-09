#include <stdio.h>
int main()
{
    int r1,c1;
    scanf("%d %d",&r1,&c1);
    int arr[r1][c1], i, j;
    for(i=0;i<r1;i++)
        for(j=0;j<c1;j++)
            scanf("%d",&arr[i][j]);

    int r2,c2;
    scanf("%d %d",&r2,&c2);
    int brr[r2][c2];
    for(i=0;i<r2;i++)
        for(j=0;j<c2;j++)
            scanf("%d",&brr[i][j]);

    if(r1==r2 && c1==c2)
    {
        for(i=0;i<r1;i++)
        {
            for(j=0;j<c1;j++)
                printf("%d ",arr[i][j]+brr[i][j]);
            printf("\n");
        }
    }
    else
        printf("-1");
    return 0;
}
