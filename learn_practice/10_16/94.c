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

// 初始化
void InitList(DLinkList *L)
{
    (*L) = (DNode *)malloc(sizeof(DNode));
    if ((*L) == NULL)
    {
        printf("头结点内存分配失败!\n");
        exit(0);
    }
    (*L)->prior = NULL;
    (*L)->next = NULL;
}

// 创建双链表
void CreateList(DLinkList *L)
{
    assert(*L);
    int i = 0;
    int n = 0;
    printf("请输入结点的个数:>");
    scanf("%d", &n);
    DNode *p = (*L);
    for (i = 0; i < n; i++)
    {
        DNode *s = (DNode *)malloc(sizeof(DNode));
        if (s == NULL)
        {
            printf("结点内存分配失败!\n");
            exit(0);
        }
        printf("请输入结点的数据:>");
        scanf("%d", &s->data);
        p->next = s;
        s->prior = p;
        s->next = NULL;
        p = p->next;
    }
}

// 求表长
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

// 插入
void ListInsert(DLinkList *L, int *len)
{
    assert(*L);
    int i = 0;
    int j = 0;
    DNode *p = (*L);
    printf("请输入插入结点的位序:>");
    scanf("%d", &i);
    // 查找
    for (j = 0; j < i; j++)
    {
        p = p->next;
    }
    if (p == NULL || i < 0 || i > *len)
    {
        printf("插入不合法!\n");
        exit(0);
    }
    // 插入
    DNode *s = (DNode *)malloc(sizeof(DNode));
    if (s == NULL)
    {
        printf("结点创建内存分配失败!\n");
        exit(0);
    }
    printf("请输入结点的数据:>");
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

// 删除
void ListDelete(DLinkList *L, int *len)
{
    assert(*L);
    if ((*L)->next == NULL)
    {
        printf("空表无法删除!\n");
        exit(0);
    }
    int i = 0;
    int j = 0;
    DNode *p = (*L);
    printf("请输入删除结点的位序:>");
    scanf("%d", &i);
    // 查找
    for (j = 0; j < i - 1; j++)
    {
        p = p->next;
    }
    if (p == NULL || i < 1 || i > *len + 1)
    {
        printf("删除不合法!\n");
        exit(0);
    }
    // 删除
    DNode *q = p->next;
    p->next = q->next;
    free(q);
}

// 打印表
void PrintList(const DLinkList L)
{
    assert(L);
    DNode *p = L->next;
    if (p == NULL)
    {
        printf("这是一个空链表!\n");
    }
    while (p)
    {
        printf("<->%d", p->data);
        p = p->next;
    }
}

// 销毁表
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
    printf("这是一个双链表!\n");
    DLinkList L;

    // 初始化
    InitList(&L);

    // 创建双链表
    CreateList(&L);

    // 求表长
    int len = Length(L);
    printf("表长为:%d\n", len);

    // 插入
    ListInsert(&L, &len);

    // 删除
    ListDelete(&L, &len);

    // 打印链表
    PrintList(L);
    printf("\n");
    // printf("表长为:%d\n", len);

    // 销毁链表
    DestoryList(&L);

    return 0;
}