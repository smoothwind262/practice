#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define INIT_CAP 3
#define ADD_CAP 2
#define MAX_SIZE 100
#define MAX_NAME 20
#define MAX_SEX 8
#define MAX_TELE 12
#define MAX_ADDR 40

typedef struct PeoInfo
{
    char name[MAX_NAME];
    int age;
    char sex[MAX_SEX];
    char tele[MAX_TELE];
    char addr[MAX_ADDR];
} PeoInfo;

// ��̬�汾
//  typedef struct Contacts
//  {
//      PeoInfo data[MAX_SIZE];
//      int count;
//  } Contacts;

// ��̬�汾
typedef struct Contacts
{
    PeoInfo *data;
    int count;    // ��ϵ�˵ĸ���
    int capacity; // �����Ĵ�С
} Contacts;

// ��ʼ��
int InitContacts(Contacts *pc);

// ADD
void Add_Contacts(Contacts *pc);

// SEARCH
void Search_Contacts(Contacts *pc);

// MODIFY
void Mofidy_Contacts(Contacts *pc);

// SHOW
void Show_Contacts(const Contacts *pc);

// DEL
void Del_Contacts(Contacts *pc);

// SORT
void Sort_Contacts(Contacts *pc);
