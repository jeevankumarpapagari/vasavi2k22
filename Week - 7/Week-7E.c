#include <stdio.h>

int main()
{
    int len1;
    scanf("%d",&len1);

    int leftArr[len1], i;
    for(i=0;i<len1;i++)
        scanf("%d",&leftArr[i]);

    int len2;
    scanf("%d",&len2);

    int rightArr[len2], j;
    for(j=0;j<len2;j++)
        scanf("%d",&rightArr[j]);

    for(i=0,j=0;i<len1&&j<len2;)
        leftArr[i] <= rightArr[j] ? printf("%d ",leftArr[i++]) : printf("%d ",rightArr[j++]);

    while(i<len1)
        printf("%d ",leftArr[i++]);

    while(j<len2)
        printf("%d ",rightArr[j++]);

    return 0;
}
