#include <stdio.h>
#include <math.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    int sum = 0;
    int i = 0;
    int b = 0;
    while (n)
    {
        int a = n % 10;
        n = n / 10;
        if (a % 2 == 1)
        {
            b = 1;
        }
        else
        {
            b = 0;
        }
        sum = sum + b * pow(10, i++);
    }
    printf("%d\n", sum);

    return 0;
}