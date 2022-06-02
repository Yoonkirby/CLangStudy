// 4-1에서 구현한 프로그램에서 변경을 가함
// 구조체 배열을 선언하는 것이 아니라, 구조체 포인터 배열을 선언하고 구조체 변수를 동적으로 할당하는 형태로 프로그램을 재 구현
// 4-1에서 구현한 방법보다 4-2에서 구현한 방법이 지니는 장점이 무엇인지도 생각해보자
#include <stdio.h>
#include <stdlib.h> // malloc()
#include <string.h>

typedef struct Book
{
    char * title;
    char * author;
    int * page;
}BOOK;

int main(void)
{
    BOOK * book[3];
    int i, temp[3];
    char tmp[100];
    printf("Enter Book Information\n");
    for(i = 0; i < 3; i++)
    {
        printf("Enter Author : ");
        scanf_s("%s", tmp);
        temp[i] = strlen(tmp)+1;
        book[i]->author = (char *)malloc(sizeof(char)*temp[i]);
        printf("Author : %s\n", book[i]->author);
        strcpy(book[i]->author, tmp);
        
        printf("Enter Title : ");
        scanf_s("%s", tmp);
        temp[i] = strlen(tmp)+1;
        book[i]->title = (char *)malloc(sizeof(char)*temp[i]);
        strcpy(book[i]->title, tmp);
        
        printf("Enter Pages : ");
        scanf_s("%d", temp);
        book[i]->page = (int *)malloc(sizeof(int));
        book[i]->page = &temp[i];
        
        if(book[i]->author == NULL || book[i]->title == NULL || book[i]->page == NULL)
        {
            exit(1);
        }
    }
    printf("\nPrint Book Information\n");
    for(i = 0; i < 3; i++)
    {
        printf("Book %d\n", i+1);
        printf("Author : %s\n", book[i]->author);
        printf("Title : %s\n", book[i]->title);
        printf("Pages : %d\n", book[i]->page);
        free(book[i]->author);
        free(book[i]->title);
        free(book[i]->page);
    }
    return 0;
}