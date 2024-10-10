#include "contacts.h"

// 初始化
// 静态
// void InitContacts(Contacts *pc)
// {
//     assert(pc);
//     pc->count = 0;
//     memset(pc->data, 0, sizeof(pc->data));
// }

// 动态
int InitContacts(Contacts *pc)
{
    assert(pc);
    pc->count = 0;
    pc->data = (PeoInfo *)calloc(INIT_CAP, sizeof(PeoInfo));
    if (pc->data == NULL)
    {
        printf("%s\n", strerror(errno));
        return 1;
    }
    pc->capacity = INIT_CAP;
    return 0;
}

// 按名字查找
static int Find_By_Name(Contacts *pc, char *nam)
{
    assert(pc);
    int i = 0;
    for (i = 0; i < pc->count; i++)
    {
        if (0 == strcmp(pc->data[i].name, nam))
        {
            return i;
        };
    }
    return -1;
}

// 排序函数
int Cmp_By_Name(const void *p1, const void *p2)
{
    return strcmp(((PeoInfo *)p1)->name, ((PeoInfo *)p2)->name);
}

// 扩容
void Add_Capacity(Contacts *pc)
{
    if (pc->count == pc->capacity)
    {
        PeoInfo *pst = (PeoInfo *)realloc(pc->data, (pc->capacity + ADD_CAP) * sizeof(PeoInfo));
        if (pst == NULL)
        {
            printf("%s\n", strerror(errno));
        }
        else
        {
            pc->data = pst;
            pc->capacity += ADD_CAP;
            printf("扩容成功！\n");
        }
    }
}

// 1.添加联系人

// 静态
// void Add_Contacts(Contacts *pc)
// {
//     assert(pc);
//     if (pc->count == MAX_SIZE)
//     {
//         printf("通讯录已满，无法继续添加！\n");
//     }
//     else
//     {
//         printf("请输入联系人的姓名:>");
//         scanf("%s", pc->data[pc->count].name);
//         printf("请输入联系人的年龄:>");
//         scanf("%d", &(pc->data[pc->count].age));
//         printf("请输入联系人的性别:>");
//         scanf("%s", pc->data[pc->count].sex);
//         printf("请输入联系人的电话:>");
//         scanf("%s", pc->data[pc->count].tele);
//         printf("请输入联系人的地址:>");
//         scanf("%s", pc->data[pc->count].addr);
//         pc->count++;
//         printf("添加成功！\n");
//     }
// }

// 动态
void Add_Contacts(Contacts *pc)
{
    assert(pc);
    Add_Capacity(pc);
    printf("请输入联系人的姓名:>");
    scanf("%s", pc->data[pc->count].name);
    printf("请输入联系人的年龄:>");
    scanf("%d", &(pc->data[pc->count].age));
    printf("请输入联系人的性别:>");
    scanf("%s", pc->data[pc->count].sex);
    printf("请输入联系人的电话:>");
    scanf("%s", pc->data[pc->count].tele);
    printf("请输入联系人的地址:>");
    scanf("%s", pc->data[pc->count].addr);
    pc->count++;
    printf("添加成功！\n");
}

// 2.按姓名查找对应联系人并打印
void Search_Contacts(Contacts *pc)
{
    assert(pc);
    char nam[MAX_NAME] = {0};
    printf("请输入要查找的联系人的姓名:>");
    scanf("%s", nam);
    // 遍历查找
    int ret = Find_By_Name(pc, nam);
    // 打印
    if (ret == -1)
    {
        printf("该联系人不存在！\n");
    }
    else
    {
        printf("%-20s\t%-5s\t%-5s\t%-12s\t%-40s\n", "姓名", "年龄", "性别", "电话", "地址");
        printf("%-20s\t%-5d\t%-5s\t%-12s\t%-40s\n",
               pc->data[ret].name,
               pc->data[ret].age,
               pc->data[ret].sex,
               pc->data[ret].tele,
               pc->data[ret].addr);
    }
}

// 3.联系人信息的修改
void Mofidy_Contacts(Contacts *pc)
{
    assert(pc);
    char nam[MAX_NAME] = {0};
    printf("请输入要修改的联系人的姓名:>");
    scanf("%s", nam);
    // 遍历查找
    int ret = Find_By_Name(pc, nam);
    // 修改
    if (ret == -1)
    {
        printf("该联系人不存在,无法修改！\n");
    }
    else
    {
        printf("请输入联系人的姓名:>");
        scanf("%s", pc->data[ret].name);
        printf("请输入联系人的年龄:>");
        scanf("%d", &(pc->data[ret].age));
        printf("请输入联系人的性别:>");
        scanf("%s", pc->data[ret].sex);
        printf("请输入联系人的电话:>");
        scanf("%s", pc->data[ret].tele);
        printf("请输入联系人的地址:>");
        scanf("%s", pc->data[ret].addr);
        printf("修改成功！\n");
    }
}

// 4.显示所育信息
void Show_Contacts(const Contacts *pc)
{
    assert(pc);
    int i = 0;
    printf("%-20s\t%-5s\t%-5s\t%-12s\t%-40s\n", "姓名", "年龄", "性别", "电话", "地址");
    for (i = 0; i < pc->count; i++)
    {
        printf("%-20s\t%-5d\t%-5s\t%-12s\t%-40s\n",
               pc->data[i].name,
               pc->data[i].age,
               pc->data[i].sex,
               pc->data[i].tele,
               pc->data[i].addr);
    }
}

// 5.删除联系人
void Del_Contacts(Contacts *pc)
{
    if (pc->count == 0)
    {
        printf("通讯录为空，无法删除！\n");
        return;
    }
    char nam[MAX_NAME] = {0};
    printf("请输入要查找的联系人的姓名:>");
    scanf("%s", nam);
    int i = 0;
    // 遍历查找
    int ret = Find_By_Name(pc, nam);
    // 删除
    if (ret == -1)
    {
        printf("该联系人不存在,无法删除！\n");
    }
    else
    {
        for (i = ret; i < pc->count - 1; i++)
        {
            pc->data[i] = pc->data[i + 1];
        }
        pc->count--;
        printf("删除成功！\n");
    }
}

// 6.按名字排序联系人
void Sort_Contacts(Contacts *pc)
{
    assert(&pc);
    qsort(pc->data, pc->count, sizeof(PeoInfo), Cmp_By_Name);
    printf("排序成功！\n");
}
