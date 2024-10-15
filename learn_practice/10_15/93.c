#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int ElemType;

// 单链表
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *Linklist;

// 初始化
void InitList(Linklist *L)
{
    (*L) = (LNode *)malloc(sizeof(LNode));
    if ((*L) == NULL)
    {
        printf("头结点内存分配失败!\n");
        exit(0);
    }
    (*L)->next = NULL;
}

// 头插
//  void List_HeadInsert(Linklist *L)
//  {
//      assert(L);
//      int n = 0;
//      int i = 0;
//      printf("请输入结点的个数:>");
//      scanf("%d", &n);
//      for (i = 0; i < n; i++)
//      {
//          LNode *s = (LNode *)malloc(sizeof(LNode));
//          if (!s)
//          {
//              printf("结点创建内存分配失败!\n");
//              exit(0);
//          }
//          printf("请输入结点的数据:>");
//          scanf("%d", &s->data);
//          s->next = (*L)->next;
//          (*L)->next = s;
//      }
//      printf("创建完成!\n");
//  }

// 尾插
void List_TailInsert(Linklist *L)
{
    assert(L);
    int n = 0;
    int i = 0;
    LNode *r = *L;
    printf("请输入结点的个数:>");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        LNode *s = (LNode *)malloc(sizeof(LNode));
        if (s == NULL)
        {
            printf("结点创建内存分配失败!\n");
            exit(0);
        }
        printf("请输入结点的数据:>");
        scanf("%d", &s->data);
        r->next = s;
        r = s;
    }
    printf("创建完成!\n");
}

// 按位序查找
int GetElem(const Linklist L)
{
    int i = 0;
    int j = 0;
    LNode *p = L;
    printf("请查找的结点:>");
    scanf("%d", &i);
    for (j = 0; j < i; j++)
    {
        p = p->next;
    }
    return p->data;
}

// 求表长
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

// 插入
void ListInsert(Linklist *L)
{

    int i = 0;
    int j = 0;
    LNode *p = (*L);
    printf("请输入插入结点的位序:>");
    scanf("%d", &i);
    // 查找
    for (j = 0; j < i - 1; j++)
    {
        p = p->next;
    }
    if (!p || i < 1 || i > Length((*L)))
    {
        printf("插入不合法!\n");
        exit(0);
    }
    // 插入
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (!s)
    {
        printf("结点创建内存分配失败!\n");
        exit(0);
    }
    printf("请输入结点的数据:>");
    scanf("%d", &s->data);
    s->next = p->next;
    p->next = s;
}

// 删除
void ListDelete(Linklist *L)
{
    if ((*L)->next == NULL)
    {
        printf("空表无法删除!\n");
        exit(0);
    }
    int i = 0;
    int j = 0;
    LNode *p = (*L);
    printf("请输入删除结点的位序:>");
    scanf("%d", &i);
    // 查找
    for (j = 0; j < i - 1; j++)
    {
        p = p->next;
    }
    if (!p || i < 1 || i > Length((*L)))
    {
        printf("删除不合法!\n");
        exit(0);
    }
    // 删除
    LNode *q = p->next;
    p->next = q->next;
    free(q);
}

// 打印表
void PrintList(const Linklist L)
{
    LNode *p = L->next;
    if (p == NULL)
    {
        printf("这是一个空链表!\n");
    }
    while (p)
    {
        printf("->%d", p->data);
        p = p->next;
    }
}

// 销毁表
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

// 主函数
int main()
{
    printf("这是一个单链表\n");
    Linklist L;

    // 头结点的初始化
    InitList(&L);

    // 头插法创建单链表
    // List_HeadInsert(&L);

    // 尾插法创建单链表
    List_TailInsert(&L);

    // 按位序查找
    int ret = GetElem(L);
    printf("要查找的结点为:%d\n", ret);

    // 求表长
    int len = Length(L);
    printf("表长为:%d\n", len);

    // 插入
    ListInsert(&L);

    // 删除
    ListDelete(&L);

    // 打印链表
    PrintList(L);

    // 销毁链表
    DestoryList(&L);

    return 0;
}