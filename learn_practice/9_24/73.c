// 冒泡排序任意类型
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// int比较函数
int cmp_int(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void Swap(char *a, char *b, int width)
{
    int i = 0;
    for (i = 0; i < width; i++)
    {
        char tmp = *a;
        *a = *b;
        *b = tmp;
        a++;
        b++;
    }
}

// 冒泡排序
void bubble_sort(void *base, int num, int width, int (*bubble_cmp)(const void *a, const void *b))
{

    int i = 0;
    // 趟数
    for (i = 0; i < num - 1; i++)
    {
        int flag = 1;
        // 一趟
        int j = 0;
        for (j = 0; j < num - 1 - i; j++)
        {
            if (bubble_cmp((char *)base + j * width, (char *)base + (j + 1) * width) > 0)
            {
                // 交换
                Swap((char *)base + j * width, (char *)base + (j + 1) * width, width);
                flag = 0;
            }
        }
        if (flag == 1)
        {
            break;
        }
    }
}

// 结构体数据
struct Stu
{
    char name[20];
    int age;
};
struct Stu s[] = {{"zhangsan", 20}, {"lisi", 18}, {"wangwu", 23}};
int sz2 = sizeof(s) / sizeof(s[0]);

// char比较函数
int cmp_char(const void *a, const void *b)
{
    return strcmp(((struct Stu *)a)->name, ((struct Stu *)b)->name);
}

int main()
{
    // int型数组
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int sz1 = sizeof(arr) / sizeof(arr[0]);

    // // qsort函数快速排序
    // qsort(arr, sz1, sizeof(arr[0]), cmp_int);
    // qsort(s, sz2, sizeof(s[0]), cmp_char);

    // 类qsort实现冒泡排序
    bubble_sort(arr, sz1, sizeof(arr[0]), cmp_int);
    bubble_sort(s, sz2, sizeof(s[0]), cmp_char);

    // 打印
    int i = 0;
    for (i = 0; i < sz1; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    for (i = 0; i < sz2; i++)
    {
        printf("%s\n", s[i].name);
    }

    return 0;
}