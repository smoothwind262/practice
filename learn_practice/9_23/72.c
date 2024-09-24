// 函数指针的使用 （计算器）
#include <stdio.h>

// 打印菜单
void manu()
{
    printf("******************************\n");
    printf("******** 1.add  2.sub ********\n");
    printf("******** 3.mul  4.div ********\n");
    printf("********    0.exit    ********\n");
    printf("******************************\n");
}

// 函数加减乘除
int add(int x, int y)
{
    return x + y;
}

int sub(int x, int y)
{
    return x - y;
}

int mul(int x, int y)
{
    return x * y;
}

int div(int x, int y)
{
    return x / y;
}

int calc(int (*pr)(int, int))
{
    int x = 0;
    int y = 0;
    printf("请输入两个数:>");
    scanf("%d %d", &x, &y);
    return pr(x, y);
}

int main()
{
    int input = 0;

    do
    {
        manu();

        printf("请选择:>");
        scanf("%d", &input);

        // 函数指针数组
        int (*parr[5])(int, int) = {0, add, sub, mul, div};
        if (input >= 1 && input <= 4)
        {
            printf("%d\n", calc(parr[input]));
        }
        else if (input == 0)
        {
            printf("退出计算器\n");
        }
        else
        {
            printf("输入错误\n");
        }

        // switch (input)
        // {
        // case 1:
        //     printf("%d\n", calc(add));
        //     break;
        // case 2:
        //     printf("%d\n", calc(sub));
        //     break;
        // case 3:
        //     printf("%d\n", calc(mul));
        //     break;
        // case 4:
        //     printf("%d\n", calc(div));
        //     break;
        // case 0:
        //     printf("退出计算器\n");
        //     break;

        // default:
        //     printf("输入错误\n");
        //     break;
        // }
    } while (input);

    return 0;
}