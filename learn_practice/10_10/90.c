#include <stdio.h>

// �ṹ
struct Stu
{
    char name;
    int age;
    double sorce;
} Stu;

// ö��
enum DAY
{
    // ö�ٳ���
    MON = 1,
    TUE,
    WEN,
    THUR,
    FRI,
    SAT,
    SON,
} day; // ö�ٱ���

// ����
union PRT
{
    int a;
    char b;
    char arr[5];
} prt;

int main()
{
    // �ṹ���С
    printf("%u\n", sizeof(Stu));

    // ö��
    printf("%d\n", MON);

    // �������С
    printf("%u\n", sizeof(prt));
    //  �������жϴ�С��
    prt.a = 1;
    if (prt.b == 1)
    {
        printf("С��\n");
    }
    else
    {
        printf("���\n");
    }

    return 0;
}