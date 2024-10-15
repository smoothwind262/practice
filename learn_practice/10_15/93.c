#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int ElemType;

// ������
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *Linklist;

// ��ʼ��
void InitList(Linklist *L)
{
    (*L) = (LNode *)malloc(sizeof(LNode));
    if ((*L) == NULL)
    {
        printf("ͷ����ڴ����ʧ��!\n");
        exit(0);
    }
    (*L)->next = NULL;
}

// ͷ��
//  void List_HeadInsert(Linklist *L)
//  {
//      assert(L);
//      int n = 0;
//      int i = 0;
//      printf("��������ĸ���:>");
//      scanf("%d", &n);
//      for (i = 0; i < n; i++)
//      {
//          LNode *s = (LNode *)malloc(sizeof(LNode));
//          if (!s)
//          {
//              printf("��㴴���ڴ����ʧ��!\n");
//              exit(0);
//          }
//          printf("�������������:>");
//          scanf("%d", &s->data);
//          s->next = (*L)->next;
//          (*L)->next = s;
//      }
//      printf("�������!\n");
//  }

// β��
void List_TailInsert(Linklist *L)
{
    assert(L);
    int n = 0;
    int i = 0;
    LNode *r = *L;
    printf("��������ĸ���:>");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        LNode *s = (LNode *)malloc(sizeof(LNode));
        if (s == NULL)
        {
            printf("��㴴���ڴ����ʧ��!\n");
            exit(0);
        }
        printf("�������������:>");
        scanf("%d", &s->data);
        r->next = s;
        r = s;
    }
    printf("�������!\n");
}

// ��λ�����
int GetElem(const Linklist L)
{
    int i = 0;
    int j = 0;
    LNode *p = L;
    printf("����ҵĽ��:>");
    scanf("%d", &i);
    for (j = 0; j < i; j++)
    {
        p = p->next;
    }
    return p->data;
}

// ���
int Length(const Linklist L)
{
    int length = 0;
    LNode *p = L->next;
    while (p)
    {
        p = p->next;
        length++;
    }
    return length;
}

// ����
void ListInsert(Linklist *L)
{

    int i = 0;
    int j = 0;
    LNode *p = (*L);
    printf("������������λ��:>");
    scanf("%d", &i);
    // ����
    for (j = 0; j < i - 1; j++)
    {
        p = p->next;
    }
    if (!p || i < 1 || i > Length((*L)))
    {
        printf("���벻�Ϸ�!\n");
        exit(0);
    }
    // ����
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (!s)
    {
        printf("��㴴���ڴ����ʧ��!\n");
        exit(0);
    }
    printf("�������������:>");
    scanf("%d", &s->data);
    s->next = p->next;
    p->next = s;
}

// ɾ��
void ListDelete(Linklist *L)
{
    if ((*L)->next == NULL)
    {
        printf("�ձ��޷�ɾ��!\n");
        exit(0);
    }
    int i = 0;
    int j = 0;
    LNode *p = (*L);
    printf("������ɾ������λ��:>");
    scanf("%d", &i);
    // ����
    for (j = 0; j < i - 1; j++)
    {
        p = p->next;
    }
    if (!p || i < 1 || i > Length((*L)))
    {
        printf("ɾ�����Ϸ�!\n");
        exit(0);
    }
    // ɾ��
    LNode *q = p->next;
    p->next = q->next;
    free(q);
}

// ��ӡ��
void PrintList(const Linklist L)
{
    LNode *p = L->next;
    if (p == NULL)
    {
        printf("����һ��������!\n");
    }
    while (p)
    {
        printf("->%d", p->data);
        p = p->next;
    }
}

// ���ٱ�
void DestoryList(Linklist *L)
{
    assert(*L);
    LNode *p = (*L)->next;
    while (p)
    {
        LNode *q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;
}

// ������
int main()
{
    printf("����һ��������\n");
    Linklist L;

    // ͷ���ĳ�ʼ��
    InitList(&L);

    // ͷ�巨����������
    // List_HeadInsert(&L);

    // β�巨����������
    List_TailInsert(&L);

    // ��λ�����
    int ret = GetElem(L);
    printf("Ҫ���ҵĽ��Ϊ:%d\n", ret);

    // ���
    int len = Length(L);
    printf("��Ϊ:%d\n", len);

    // ����
    ListInsert(&L);

    // ɾ��
    ListDelete(&L);

    // ��ӡ����
    PrintList(L);

    // ��������
    DestoryList(&L);

    return 0;
}