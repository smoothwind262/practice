#include <stdio.h>
#include <string.h>
#include <errno.h>

// strerror����
// C�����п⺯��ִ��ʧ��ʱ�������ô����룬���� 0,1,2,3,4,5������������
int main()
{
    FILE *pf = fopen("test.txt", "r");
    if (pf == NULL)
    {
        // errno C�����е�һ��ȫ�ֱ�����������Ŵ�����
        printf("%s\n", strerror(errno));
        return 1;
    }

    return 0;
}