// ≈–∂œ”––Ú–Ú¡–
#include <stdio.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    int arr[n];
    int i = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Ωµ–Ú
    int flag1 = 0;
    // …˝–Ú
    int flag2 = 0;

    for (i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            flag1 = 1;
        }
        else if (arr[i] < arr[i + 1])
        {
            flag2 = 1;
        }
        else
        {
            ;
        }
    }
    if (flag1 + flag2 <= 1)
    {
        printf("sorted\n");
    }
    else
    {
        printf("unsorted\n");
    }

    return 0;
}