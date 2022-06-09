// 전화번호 관리 프로그램을 작성 p.606
// 그런대 링크드리스트를 버무린

//scanf를 gets로 바꿔야할듯? 런타임에러뜸
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_MAX 30
#define NUMBER_MAX 15
enum{insert = 1, delete, search, printall, exitprogram};

typedef struct phone    // 이름, 전화번호를 저장하는 노드 구조체
{
    char * name;
    char * number;
    struct phone * next;
}PHONE;

typedef struct linked_list  // 링크드 리스트 관리 구조체
{
    int cnt;
    PHONE * head;
    PHONE * tail;
}LL;

LL* linked_list_Make()  // 링크드 리스트 초기 생성 함수
{
    LL * link = (LL*)malloc(sizeof(LL));
    if(link == NULL)
    {
        printf("Dynamic Allocation Failed\n");
        exit(1);
    }
    link->cnt = 0;
    link->head = NULL;
    link->tail = NULL;
    return link;
}

PHONE * Phone_Make(char * name, char * number, PHONE * next)    // 노드 생성
{
    PHONE * phone = (PHONE*)malloc(sizeof(PHONE));
    phone->name = (char*)malloc(sizeof(name)+1);
    phone->number = (char*)malloc(sizeof(number)+1);
    if(phone == NULL || phone->name == NULL || phone->number == NULL)
    {
        printf("Dynamic Allocation Failed\n");
        exit(1);
    }
    strcpy(phone->name, name);
    strcpy(phone->number, number);
    phone->next = next;
    return phone;
}

int Phone_Index(LL * link, char * name) // 동일한 이름이 몇번째 노드에 있는지 찾는 함수
{
    PHONE * tmp = link->head;
    for(int i = 1; i <= link->cnt; i++)
    {
        if(tmp->name == name)
        {
            return i;
        }
        tmp = tmp->next;
    }
    printf("Name not found!\n");
    return 0;
}

void Phone_PrintMenu();
void Phone_Insert();
void Phone_Delete();
void Phone_Search();
void Phone_PrintAll();
void Phone_Exit();

int main(void)
{
    LL * link = linked_list_Make();
    int enter;
    while(1)
    {
        Phone_PrintMenu();
        printf("Choose the item : ");
        scanf("%d", &enter);
        switch(enter)
        {
            case insert:
                Phone_Insert(link);
                break;
            case delete:
                Phone_Delete(link);
                break;
            case search:
                Phone_Search(link);
                break;
            case printall:
                Phone_PrintAll(link);
                break;
            case exitprogram:
                Phone_Exit(link);
                exit(0);
            default:
                printf("Please Re-Enter\n\n");
        }
    }
    return 0;
}

void Phone_PrintMenu()
{
    printf("***** MENU *****\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Search\n");
    printf("4. Print All\n");
    printf("5. Exit\n");
}

void Phone_Insert(LL * link)
{
    char name[NAME_MAX];
    char number[NUMBER_MAX];

    printf("Input Name : ");
    scanf("%s", name);
    printf("Input Tel Number : ");
    scanf("%s", number);
    
    PHONE * node = Phone_Make(name, number, NULL);

    if(link->cnt == 0)
    {
        link->head = node;
    }
    else
    {
        link->tail->next = node;
    }
    link->tail = node;
    link->cnt++;
    printf("\tData Inserted\n\n");
}

void Phone_Delete(LL * link)
{
    if(link->cnt == 0)  // 삭제할 노드자체가 존재하지 않을 경우
    {
        printf("Nothing more to delete!\n");
        return;
    }

    PHONE * tmp = link->head;
    PHONE * index;
    int idx;
    char idxname[NAME_MAX];

    printf("Input Name : ");
    scanf("%s", idxname);
    idx = Phone_Index(link, idxname);   // 동일이름이 몇번째 노드에 있는지 찾음
    if(idx != 0)    // 동일이름이 없지 않을 경우
    {
        if(link->cnt == 1)   // 노드가 하나일 경우
        {
            free(tmp->name);
            free(tmp->number);
            free(tmp);
            link->head = NULL;
            link->tail = NULL;
            link->cnt--;
            return;
        }

        if(link->cnt >= 2)  // 노드가 2개 이상일 경우
        {
            for(int i = 1; i < idx - 1; i++)
                tmp = tmp->next;
            index = tmp->next;
            if(idx != link->cnt)        // 삭제할 노드가 꼬리가 아닐 경우
            {
                tmp->next = index->next;
                index->next = NULL;
                free(index->name);
                free(index->number);
                free(index);
                link->cnt--;
                return;
            }
            else                        // 삭제할 노드가 꼬리일 경우
            {
                link->tail = tmp;
                tmp->next = NULL;
                free(index->name);
                free(index->number);
                free(index);
                link->cnt--;
                return;
            }
        }
    }
}

void Phone_Search(LL * link)
{
    if(link->cnt == 0)  // 검색할 노드가 없는 경우
    {
        printf("Nothing to search for!\n\n");
        return;
    }

    PHONE * tmp = link->head;
    int idx;
    char idxname[NAME_MAX];

    printf("Input Name : ");
    scanf("%s", idxname);
    idx = Phone_Index(link, idxname);
    if(idx != 0)
    {
        for(int i = 1; i < idx; i++)
        {
            tmp = tmp->next;
        }
        printf("Name : %s\tTel : %s\n", tmp->name, tmp->number);
    }
}

void Phone_PrintAll(LL * link)
{
    if(link->cnt == 0)
    {
        printf("Nothing to print!\n\n");
        return;
    }
    PHONE * tmp = link->head;
    printf("[ Print All Data ]\n");
    while(tmp != NULL)
    {
        printf("Name : %s\tTel : %s\n", tmp->name, tmp->number);
        tmp = tmp->next;
    }
}

void Phone_Exit(LL * link)
{
    PHONE * tmp = link->head;
    PHONE * clear;
    while(tmp != NULL)
    {
        clear = tmp;
        tmp = tmp->next;
        free(clear->name);
        free(clear->number);
        free(clear);
    }
    free(link);
}