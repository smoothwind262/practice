#include <stdio.h>
#include <string.h>
#include <assert.h>

// strstr实现
char *my_strstr(const char *str1, const char *str2)
{
    assert(str1 && str2);
    const char *s1 = str1;
    const char *s2 = str2;
    const char *ps = str1;
    while (*ps)
    {
        s1 = ps;
        s2 = str2;
        while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
        {
            s1++;
            s2++;
        }

        if (*s2 == '\0')
        {
            return (char *)ps;
        }

        ps++;
    }
    return NULL;
}

int main()
{
    char arr1[] = "cNoob";
    char arr2[] = "Noob";
    char *ret = my_strstr(arr1, arr2);
    if (ret == NULL)
    {
        printf("子字符串不存在！\n");
    }
    else
    {
        printf("%s\n", ret);
    }

    return 0;
}