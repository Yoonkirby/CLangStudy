// 도서 관리용 프로그램
// [제목, 저자명, 페이지수]에 대한 정보를 저장할 수 있는 구조체를 정의
// 구조체 배열을 선언해서 도서에 대한 정보를 저장하는 구조로 작성
// main함수에서 사용자로부터 3권의 도서에 대한 정보를 입력 받고, 입력이 끝나면 도서에 대한 내용을 출력
#include <stdio.h>

struct Book
{
    char title[50];
    char author[25];
    int page;
};

int main(void)
{
    struct Book book[3];
    int i;
    printf("Enter Book Information\n");
    for(i = 0; i < 3; i++)
    {
        printf("Enter Author : ");
        scanf_s("%s", book[i].author);
        printf("Enter Title : ");
        scanf_s("%s", book[i].title);
        printf("Enter Pages : ");
        scanf_s("%d", &book[i].page);
    }
    printf("\nPrint Book Information\n");
    for(i = 0; i < 3; i++)
    {
        printf("Book %d\n", i+1);
        printf("Author : %s\n", book[i].author);
        printf("Title : %s\n", book[i].title);
        printf("Pages : %d\n", book[i].page);
    }
    return 0;
}