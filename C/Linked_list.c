#include <stdio.h>
#include <stdlib.h>
void ll_insert(), ll_delete(), ll_update(), ll_print(), ll_exit();

typedef struct NODE //노드 구조체
{
    int data;
    struct NODE *next;
}node;

typedef struct ll   //링크드리스트 구조체
{
    int cnt;
    node *head;
    node *tail;
    node *cur;
}linked_list;

linked_list *ll_make()  //링크드리스트 생성 함수
{
    linked_list *Link = (linked_list *)malloc(sizeof(linked_list));
    Link->cnt = 0;
    Link->head = NULL;  //초기화
    Link->tail = NULL;
    Link->cur = NULL;
    return Link;
}

linked_list *node_make(int data)    //노드 생성 함수
{
    node *Node = (node *)malloc(sizeof(node));
    Node->data = data;
    Node->next = NULL;
    return Node;
}

int main(void)
{
    int enter;
    linked_list *List = ll_make();  //링크드 리스트 생성
    printf("Set the initial Value : ");
    scanf_s("%d",&enter); //첫번째 노드의 값을 입력받음
    node *Node = node_make(enter);  //첫번째 노드 생성
    List->cnt++;    //카운트 갯수 증가
    List->head = Node;  //헤드, 테일과 커서를 첫번째 노드에 연결
    List->tail = Node;
    List->cur = Node;
    enter = 0;
    while(1)
    {
        printf("Enter [ (1) Insert, (2) Delete, (3) Update, (4) Print, (5) Exit ] : ");
        scanf_s("%d",&enter);
        if(enter == 1)
            ll_insert(List);
        else if(enter == 2)
            ll_delete();
        else if(enter == 3)
            ll_update();
        else if(enter == 4)
            ll_print();
        else if(enter == 5)
        {
            ll_exit();
            exit(1);
        }
        else
            printf("Enter Again [ 1 ~ 5 ]\n");
    }
    return 0;
}

void ll_insert(linked_list *LL)
{
    node *tmp = (node *)malloc(sizeof(node));
    int i = 0, index = 0, fb = 0, value = 0;
    
    if(LL->head == NULL || LL->tail == NULL)
    {
        printf("error!\n");
        exit(1);
    }
    else if(LL->head != LL->tail)    //첫노드가 아닐 경우
    {
        printf("Which node do you want to insert?\n");
        while(1)
        {
            printf("Enter [ 1 ~ %d ] : ",LL->cnt);
            scanf_s("%d",&index);
            if(index >= 1 && index <= LL->cnt)
                break;
            else
                printf("Error! Enter Again [ 1 ~ %d ]\n",LL->cnt);
        }
    }
    else    //첫노드일 경우
    {
        printf("What do you want put it in the front or the back of the first node?\n");
    }

    while(1)
    {
        printf("Enter [ (1) front, (2) back ] : "); //앞에 넣을지 뒤에 넣을지 입력 받음
        scanf_s("%d",&fb);
        if(fb == 1 || fb == 2)
        {
            break;
        }
        printf("Enter Again [ 1 or 2 ]\n");
    }
    printf("Input the data value : ");  //새로운 노드에 넣을 값를 입력받음
    sacnf_s("%d",&value);
    tmp->data = value;

    if(fb == 1) //앞에 넣을 경우
    {
        if(index == 1)  //헤드의 앞에 넣을 경우
        {
            tmp->next = LL->head;
            LL->head = tmp;
            LL->cnt++;
            exit(1);
        }
        for(i = 1; i < index - 1; i++)
        {
            LL->cur = LL->cur->next;
        }
        tmp->next = LL->cur->next;
        LL->cur->next = tmp;
        LL->cnt++;
        exit(1);
    }
    else if(fb == 2)    //뒤에 넣을 경우
    {
        for(i = 1; i < index; i++)
        {
            LL->cur = LL->cur->next;
        }
        if(index == LL->cnt)    //테일의 뒤에 넣을 경우
        {
            tmp->next = NULL;
            LL->cur->next = tmp;
            LL->tail = tmp;
            LL->cnt++;
            exit(1);
        }
        tmp->next = LL->cur->next;
        LL->cur->next = tmp;
        LL->cnt++;
    }
}

void ll_delete()
{

}

void ll_update()
{

}

void ll_print()
{

}

void ll_exit()
{

}