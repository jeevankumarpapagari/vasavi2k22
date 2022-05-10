#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    char str[110], ss[110];
    scanf("%[^\n]s",str);
    scanf("%s",ss);

    int result = 0;
    for(int i=0;i<strlen(str)-strlen(ss);i++)
    {
        int j = i, k = 0, flag = 1;
        while(ss[k] != '\0')
        {
            if(str[j] != ss[k])
            {
                flag = 0;
                break;
            }
            j++; k++;
        }
        if(flag)
            result++;
    }
    result == 0 ? printf("-1") : printf("%d",result);
    return 0;
}

