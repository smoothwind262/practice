// ÑîÊÏ¾ØÕó
#include <stdio.h>

int Find_num(int arr[3][3], int *px, int *py, int n)
{
    int i = 0;
    int j = *py - 1;
    while (i <= *px && j >= 0)
    {
        if (n > arr[i][j])
        {
            i++;
        }
        else if (n < arr[i][j])
        {
            j--;
        }
        else
        {
            *px = i;
            *py = j;
            return 1;
        }
    }
    return 0;
}

int main()
{
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int n = 0;
    while (scanf("%d", &n) == 1)
    {
        int row = 3;
        int col = 3;
        int ret = Find_num(arr, &row, &col, n);
        if (ret == 1)
        {
            printf("%d %d\n", row, col);
        }
        else
        {
            printf("ÕÒ²»µ½\n");
        }
    }

    return 0;
}