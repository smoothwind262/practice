#include <stdio.h>
#include <string.h>
#include <assert.h>

// memcpy实现
void *my_memcpy(void *dest, const void *scr, size_t n)
{
    assert(dest && scr);
    void *ret = dest;
    while (n--)
    {
        *(char *)dest = *(char *)scr;
        //(强制类型转换)优先级不如单目操作符
        dest = (char *)dest + 1;
        scr = (char *)scr + 1;
    }
    return ret;
}

int main()
{
    int arr1[] = {0, 1, 2, 3, 4, 5, 6};
    int arr2[30] = {0};
    my_memcpy(arr2, arr1, 28);
    // memcpy(arr1 + 2, arr1, 12);
    int i = 0;
    for (i = 0; i < 7; i++)
    {
        printf("%d\n", arr2[i]);
        // printf("%d\n", arr1[i]);
    }

    return 0;
}
