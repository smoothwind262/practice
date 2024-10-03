#include <stdio.h>
#include <string.h>

// strtokº¯Êý
int main()
{
    char arr1[] = "relievedchao@gmail.com";
    char a[40] = {0};
    strcpy(a, arr1);
    char arr2[] = "@.";
    char *ret = NULL;

    // if (ret != NULL)
    // {
    //     printf("%s\n", ret);
    // }
    // ret = strtok(NULL, arr2);
    // if (ret != NULL)
    // {
    //     printf("%s\n", ret);
    // }
    // ret = strtok(NULL, arr2);
    // if (ret != NULL)
    // {
    //     printf("%s\n", ret);
    // }

    for (ret = strtok(a, arr2); ret != NULL; ret = strtok(NULL, arr2))
    {
        printf("%s\n", ret);
    }

    return 0;
}
