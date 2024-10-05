// 判断是否是旋转字符串
#include <stdio.h>
#include <string.h>

int is_left_revolve(char s1[], char s2[])
{
    // 0.1
    // int len = strlen(s1);
    // int i = 0;
    // for (i = 0; i < len; i++)
    // {
    //     char tmp = s1[0];
    //     int j = 0;
    //     for (j = 0; j < len - 1; j++)
    //     {
    //         s1[j] = s1[j + 1];
    //     }
    //     s1[j] = tmp;
    //     if (strcmp(s1, s2) == 0)
    //     {
    //         return 1;
    //     }
    // }
    // return 0;

    // 0.2
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if (len1 != len2)
    {
        return 0;
    }
    strncat(s1, s1, len1);
    // strcat(s1, s1);   // 会死循环
    if (strstr(s1, s2) == NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    char s1[30] = "abcdef";
    char s2[] = "cdefab";
    int ret = is_left_revolve(s1, s2);
    printf("%d\n", ret);

    return 0;
}