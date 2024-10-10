#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main()
{
    // ·ÖÅä
    int *p = (int *)malloc(40);
    // int *p = calloc(10,4);
    if (p == NULL)
    {
        printf("%s\n", strerror(errno));
        return 1;
    }

    // ²Ù×÷
    int *pst = (int *)realloc(p, 80);
    int i = 0;
    for (i = 0; i <= 10; i++)
    {
        pst[i] = i;
    }
    for (i = 0; i <= 10; i++)
    {
        printf("%d ", pst[i]);
    }

    // ÊÍ·Å
    free(pst);
    p = NULL;
    pst = NULL;

    return 0;
}