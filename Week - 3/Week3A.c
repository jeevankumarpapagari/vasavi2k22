#include <stdio.h>
#include <string.h>

int main()
{
    int n,i;
    scanf("%d",&n);
    char str[n][100];
    for(i=0;i<n;i++)
    {
        gets(str[i]);
        scanf("%[^\n]s",str[i]);
    }
    for(i=0;i<n;i++)
    {

        printf("%s",str[i]);
        if(i!=n-1)
            printf(" ");
    }
    printf(".");
    return 0;
}
