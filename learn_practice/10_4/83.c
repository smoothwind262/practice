#include <stdio.h>

int main()
{
    int arr[10][10] = {0};
    int i = 0;
    int j = 0;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j <= i; j++)
        {
            if ((i == j) || (j == 0))
            {
                arr[i][j] = 1;
            }

            if (i >= 2 && j >= 1)
            {
                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
            }
        }
    }

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j <= i; j++)
        {
            printf("%3d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
