#include "contacts.h"

void menu()
{
    printf("******************************************\n");
    printf("*******    1.Add       2.Search    *******\n");
    printf("*******    3.Modify    4.Show      *******\n");
    printf("*******    5.Del       6.Sort      *******\n");
    printf("*******          0.Exit            *******\n");
    printf("******************************************\n");
}

enum OPINION
{
    EXIT,
    ADD,
    SEARCH,
    MODIFY,
    SHOW,
    DEL,
    SORT
};

// ͨѶ¼
int main()
{
    int input = 0;
    Contacts con;
    InitContacts(&con);
    do
    {
        menu();
        printf("���������ѡ��:>");
        scanf("%d", &input);
        switch (input)
        {
        case ADD:
            Add_Contacts(&con);
            break;
        case SEARCH:
            Search_Contacts(&con);
            break;
        case MODIFY:
            Mofidy_Contacts(&con);
            break;
        case SHOW:
            Show_Contacts(&con);
            break;
        case DEL:
            Del_Contacts(&con);
            break;
        case SORT:
            Sort_Contacts(&con);
            break;
        default:
            printf("�ر�ͨѶ¼\n");
            break;
        }
    } while (input);

    return 0;
}
