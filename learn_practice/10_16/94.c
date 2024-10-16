#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int ElemType;

typedef struct DNode
{
    ElemType data;
    struct DNode *prior, *next;
    // struct DNode *next;
} DNode, *DLinkList;

// ��ʼ��
void InitList(DLinkList *L)
{
    (*L) = (DNode *)malloc(sizeof(DNode));
    if ((*L) == NULL)
    {
        printf("ͷ����ڴ����ʧ��!\n");
        exit(0);
    }
    (*L)->prior = NULL;
    (*L)->next = NULL;
}

// ����˫����
void CreateList(DLinkList *L)
{
    assert(*L);
    int i = 0;
    int n = 0;
    printf("��������ĸ���:>");
    scanf("%d", &n);
    DNode *p = (*L);
    for (i = 0; i < n; i++)
    {
        DNode *s = (DNode *)malloc(sizeof(DNode));
        if (s == NULL)
        {
            printf("����ڴ����ʧ��!\n");
            exit(0);
        }
        printf("�������������:>");
        scanf("%d", &s->data);
        p->next = s;
        s->prior = p;
        s->next = NULL;
        p = p->next;
    }
}

// ���
int Length(const DLinkList L)
{
    assert(L);
    int length = 0;
    DNode *p = L->next;
    while (p)
    {
        length++;
        p = p->next;
    }
    return length;
}

// ����
void ListInsert(DLinkList *L, int *len)
{
    assert(*L);
    int i = 0;
    int j = 0;
    DNode *p = (*L);
    printf("������������λ��:>");
    scanf("%d", &i);
    // ����
    for (j = 0; j < i; j++)
    {
        p = p->next;
    }
    if (p == NULL || i < 0 || i > *len)
    {
        printf("���벻�Ϸ�!\n");
        exit(0);
    }
    // ����
    DNode *s = (DNode *)malloc(sizeof(DNode));
    if (s == NULL)
    {
        printf("��㴴���ڴ����ʧ��!\n");
        exit(0);
    }
    printf("�������������:>");
    scanf("%d", &s->data);
    s->next = p->next;
    if (p->next != NULL)
    {
        p->next->prior = s;
    }
    s->prior = p;
    p->next = s;
    (*len)++;
}

// ɾ��
void ListDelete(DLinkList *L, int *len)
{
    assert(*L);
    if ((*L)->next == NULL)
    {
        printf("�ձ��޷�ɾ��!\n");
        exit(0);
    }
    int i = 0;
    int j = 0;
    DNode *p = (*L);
    printf("������ɾ������λ��:>");
    scanf("%d", &i);
    // ����
    for (j = 0; j < i - 1; j++)
    {
        p = p->next;
    }
    if (p == NULL || i < 1 || i > *len + 1)
    {
        printf("ɾ�����Ϸ�!\n");
        exit(0);
    }
    // ɾ��
    DNode *q = p->next;
    p->next = q->next;
    free(q);
}

// ��ӡ��
void PrintList(const DLinkList L)
{
    assert(L);
    DNode *p = L->next;
    if (p == NULL)
    {
        printf("����һ��������!\n");
    }
    while (p)
    {
        printf("<->%d", p->data);
        p = p->next;
    }
}

// ���ٱ�
void DestoryList(DLinkList *L)
{
    assert(*L);
    DNode *p = (*L);
    while (p)
    {
        DNode *q = p->next;
        free(p);
        p = q;
    }
    (*L) = NULL;
}

int main()
{
    printf("����һ��˫����!\n");
    DLinkList L;

    // ��ʼ��
    InitList(&L);

    // ����˫����
    CreateList(&L);

    // ���
    int len = Length(L);
    printf("��Ϊ:%d\n", len);

    // ����
    ListInsert(&L, &len);

    // ɾ��
    ListDelete(&L, &len);

    // ��ӡ����
    PrintList(L);
    printf("\n");
    // printf("��Ϊ:%d\n", len);

    // ��������
    DestoryList(&L);

    return 0;
}