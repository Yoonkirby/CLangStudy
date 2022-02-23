#include <stdio.h>
#include <stdlib.h>
void ll_insert(), ll_delete(), ll_update(), ll_print(), ll_exit();

typedef struct NODE
{
    int data;
    struct NODE *next;
}node;

typedef struct ll
{
    int index;
    node *head;
    node *tail;
}linked_list;

linked_list *ll_make()
{
    linked_list *Link = (linked_list *)malloc(sizeof(linked_list));
    Link->index = 0;
    Link->head = NULL;
    Link->tail = NULL;
    return Link;
}

linked_list *node_make(int data)
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
    enter = 0;
    while(1)
    {
        printf("Enter [ (1) Insert, (2) Delete, (3) Update, (4) Print, (5) Exit ] : ");
        scanf_s("%d",&enter);
        if(enter == 1)
            ll_insert;
        else if(enter == 2)
            ll_delete;
        else if(enter == 3)
            ll_update;
        else if(enter == 4)
            ll_print;
        else if(enter == 5)
        {
            ll_exit();
            exit(1);
        }
        else
            printf("Enter Again (1 ~ 5)\n");
    }
    return 0;
}

void ll_insert()
{
     
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