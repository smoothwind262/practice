#include <stdio.h>

// 结构
struct Stu
{
    char name;
    int age;
    double sorce;
} Stu;

// 枚举
enum DAY
{
    // 枚举常量
    MON = 1,
    TUE,
    WEN,
    THUR,
    FRI,
    SAT,
    SON,
} day; // 枚举变量

// 联合
union PRT
{
    int a;
    char b;
    char arr[5];
} prt;

int main()
{
    // 结构体大小
    printf("%u\n", sizeof(Stu));

    // 枚举
    printf("%d\n", MON);

    // 联合体大小
    printf("%u\n", sizeof(prt));
    //  联合体判断大小端
    prt.a = 1;
    if (prt.b == 1)
    {
        printf("小端\n");
    }
    else
    {
        printf("大端\n");
    }

    return 0;
}