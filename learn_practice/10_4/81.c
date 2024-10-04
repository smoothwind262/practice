#include <stdio.h>

int main()
{
    int input = 0;
    int j = input - 1;
    int k = 1;
    while (scanf("%d", &input) == 1)
    {
        int i = 0;
        for (i = 0; i < input; i++)
        {
            for (j = input - 1 - i; j > 0; j--)
            {
                printf("  ");
            }

            for (k = 1 + i; k > 0; k--)
            {
                printf("* ");
            }
            printf("\n");
        }
    }
    return 0;
}