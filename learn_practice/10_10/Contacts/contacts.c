#include "contacts.h"

// ��ʼ��
// ��̬
// void InitContacts(Contacts *pc)
// {
//     assert(pc);
//     pc->count = 0;
//     memset(pc->data, 0, sizeof(pc->data));
// }

// ��̬
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

// �����ֲ���
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

// ������
int Cmp_By_Name(const void *p1, const void *p2)
{
    return strcmp(((PeoInfo *)p1)->name, ((PeoInfo *)p2)->name);
}

// ����
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
            printf("���ݳɹ���\n");
        }
    }
}

// 1.�����ϵ��

// ��̬
// void Add_Contacts(Contacts *pc)
// {
//     assert(pc);
//     if (pc->count == MAX_SIZE)
//     {
//         printf("ͨѶ¼�������޷�������ӣ�\n");
//     }
//     else
//     {
//         printf("��������ϵ�˵�����:>");
//         scanf("%s", pc->data[pc->count].name);
//         printf("��������ϵ�˵�����:>");
//         scanf("%d", &(pc->data[pc->count].age));
//         printf("��������ϵ�˵��Ա�:>");
//         scanf("%s", pc->data[pc->count].sex);
//         printf("��������ϵ�˵ĵ绰:>");
//         scanf("%s", pc->data[pc->count].tele);
//         printf("��������ϵ�˵ĵ�ַ:>");
//         scanf("%s", pc->data[pc->count].addr);
//         pc->count++;
//         printf("��ӳɹ���\n");
//     }
// }

// ��̬
void Add_Contacts(Contacts *pc)
{
    assert(pc);
    Add_Capacity(pc);
    printf("��������ϵ�˵�����:>");
    scanf("%s", pc->data[pc->count].name);
    printf("��������ϵ�˵�����:>");
    scanf("%d", &(pc->data[pc->count].age));
    printf("��������ϵ�˵��Ա�:>");
    scanf("%s", pc->data[pc->count].sex);
    printf("��������ϵ�˵ĵ绰:>");
    scanf("%s", pc->data[pc->count].tele);
    printf("��������ϵ�˵ĵ�ַ:>");
    scanf("%s", pc->data[pc->count].addr);
    pc->count++;
    printf("��ӳɹ���\n");
}

// 2.���������Ҷ�Ӧ��ϵ�˲���ӡ
void Search_Contacts(Contacts *pc)
{
    assert(pc);
    char nam[MAX_NAME] = {0};
    printf("������Ҫ���ҵ���ϵ�˵�����:>");
    scanf("%s", nam);
    // ��������
    int ret = Find_By_Name(pc, nam);
    // ��ӡ
    if (ret == -1)
    {
        printf("����ϵ�˲����ڣ�\n");
    }
    else
    {
        printf("%-20s\t%-5s\t%-5s\t%-12s\t%-40s\n", "����", "����", "�Ա�", "�绰", "��ַ");
        printf("%-20s\t%-5d\t%-5s\t%-12s\t%-40s\n",
               pc->data[ret].name,
               pc->data[ret].age,
               pc->data[ret].sex,
               pc->data[ret].tele,
               pc->data[ret].addr);
    }
}

// 3.��ϵ����Ϣ���޸�
void Mofidy_Contacts(Contacts *pc)
{
    assert(pc);
    char nam[MAX_NAME] = {0};
    printf("������Ҫ�޸ĵ���ϵ�˵�����:>");
    scanf("%s", nam);
    // ��������
    int ret = Find_By_Name(pc, nam);
    // �޸�
    if (ret == -1)
    {
        printf("����ϵ�˲�����,�޷��޸ģ�\n");
    }
    else
    {
        printf("��������ϵ�˵�����:>");
        scanf("%s", pc->data[ret].name);
        printf("��������ϵ�˵�����:>");
        scanf("%d", &(pc->data[ret].age));
        printf("��������ϵ�˵��Ա�:>");
        scanf("%s", pc->data[ret].sex);
        printf("��������ϵ�˵ĵ绰:>");
        scanf("%s", pc->data[ret].tele);
        printf("��������ϵ�˵ĵ�ַ:>");
        scanf("%s", pc->data[ret].addr);
        printf("�޸ĳɹ���\n");
    }
}

// 4.��ʾ������Ϣ
void Show_Contacts(const Contacts *pc)
{
    assert(pc);
    int i = 0;
    printf("%-20s\t%-5s\t%-5s\t%-12s\t%-40s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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

// 5.ɾ����ϵ��
void Del_Contacts(Contacts *pc)
{
    if (pc->count == 0)
    {
        printf("ͨѶ¼Ϊ�գ��޷�ɾ����\n");
        return;
    }
    char nam[MAX_NAME] = {0};
    printf("������Ҫ���ҵ���ϵ�˵�����:>");
    scanf("%s", nam);
    int i = 0;
    // ��������
    int ret = Find_By_Name(pc, nam);
    // ɾ��
    if (ret == -1)
    {
        printf("����ϵ�˲�����,�޷�ɾ����\n");
    }
    else
    {
        for (i = ret; i < pc->count - 1; i++)
        {
            pc->data[i] = pc->data[i + 1];
        }
        pc->count--;
        printf("ɾ���ɹ���\n");
    }
}

// 6.������������ϵ��
void Sort_Contacts(Contacts *pc)
{
    assert(&pc);
    qsort(pc->data, pc->count, sizeof(PeoInfo), Cmp_By_Name);
    printf("����ɹ���\n");
}
