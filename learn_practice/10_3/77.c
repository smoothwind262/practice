#include <stdio.h>
#include <string.h>
#include <errno.h>

// strerror函数
// C语言中库函数执行失败时都会设置错误码，类似 0,1,2,3,4,5······
int main()
{
    FILE *pf = fopen("test.txt", "r");
    if (pf == NULL)
    {
        // errno C语言中的一个全局变量，用来存放错误码
        printf("%s\n", strerror(errno));
        return 1;
    }

    return 0;
}