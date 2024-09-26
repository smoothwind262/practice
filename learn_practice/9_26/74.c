// 字符串函数
#include <stdio.h>
#include <string.h>
#include <assert.h>

// 模拟实现strlen函数

//  1.循环
size_t my_strlen(const char *str)
{
    assert(str);
    size_t count = 0;
    while (*str)
    {
        count++;
        str++;
    }
    return count;
}

// // 2.指针 - 指针
// size_t my_strlen(const char *str)
// {
//     assert(str);
//     char *ret = str;
//     while (*str)
//     {
//         str++;
//     }
//     return str - ret;
// }

// // 3.递归
// size_t my_strlen(const char *str)
// {
//     assert(str);
//     if (*str == '\0')
//     {
//         return 0;
//     }
//     else
//     {
//         return my_strlen(str + 1) + 1;
//     }
// }

// 模拟实现strcpy函数
char *my_strcpy(char *des, const char *sou)
{
    assert(des && sou);
    char *ret = des;
    while (*des++ = *sou++)
        ;
    *des = *sou;
    return ret;
}

// 模拟实现strcat函数
char *my_strcat(char *des, const char *sou)
{
    assert(des && sou);
    char *ret = des;
    // 找到'\0'
    while (*des != '\0')
    {
        des++;
    }

    // 拷贝
    while (*des++ = *sou++)
        ;
    return ret;
}

// 模拟实现strcmp函数
int my_strcmp(const char *arr2, const char *arr)
{
    assert(arr2 && arr);
    while (*arr2++ == *arr++)
    {
        if (*arr2 == '\0')
        {
            return 0;
        }
    }
    if (*arr2 > *arr)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
int main()
{
    char arr1[20] = {0};
    char arr2[20] = "xxxx";
    char arr[] = "abcdef";
    // my_strlen函数
    int len = my_strlen(arr);
    printf("%d\n", len);

    // my_strcpy函数
    my_strcpy(arr1, arr);
    printf("%s\n", arr1);

    // my_strcat函数
    my_strcat(arr2, arr);
    printf("%s\n", arr2);

    // my_strcmp函数
    int n = my_strcmp(arr, arr1);
    if (n > 0)
    {
        printf(">\n");
    }
    else if (n == 0)
    {
        printf("=\n");
    }
    else
    {
        printf("<\n");
    }

    return 0;
}