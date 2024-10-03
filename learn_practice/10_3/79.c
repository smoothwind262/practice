#include <stdio.h>
#include <string.h>
#include <assert.h>

// memmove ʵ��
void *my_memmove(void *dest, const void *scr, size_t n)
{
    assert(dest && scr);
    void *ret = dest;
    if (dest < scr)
    {
        // ǰ -> ��
        while (n--)
        {
            *(char *)dest = *(char *)scr;
            dest = (char *)dest + 1;
            scr = (char *)scr + 1;
        }
    }
    else
    {
        // �� -> ǰ
        while (n--)
        {
            *((char *)dest + n) = *((char *)scr + n);
        }
    }
    return ret;
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int sz = sizeof(arr1) / sizeof(arr1[0]);
    my_memmove(arr1 + 2, arr1, 20);
    int i = 0;
    for (i = 0; i < sz; i++)
    {
        printf("%d ", arr1[i]);
    }
    return 0;
}