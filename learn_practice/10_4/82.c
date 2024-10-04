#include <stdio.h>

int main()
{
    float money = 0.0;
    int month = 0;
    int day = 0;
    int dis = 0;
    scanf("%f %d %d %d", &money, &month, &day, &dis);
    if (month == 11 && day == 11)
    {
        money = money * 0.7 - dis * 50;
    }
    else if (month == 12 && day == 12)
    {
        money = money * 0.8 - dis * 50;
    }

    if (money < 0.0)
    {
        money = 0.0;
    }
    printf("%.2f\n", money);
    return 0;
}