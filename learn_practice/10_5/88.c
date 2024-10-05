// 判断上三角矩阵
#include <stdio.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    int arr[n][n];
    int i = 0;
    int j = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    int ret = 1;
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (arr[i][j] != 0)
            {
                ret = 0;
                // 可以goto
            }
        }
    }
    if (ret == 1)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}