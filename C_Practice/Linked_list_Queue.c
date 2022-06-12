#include <stdio.h>
#include <stdlib.h>

#define QUEUE_MAX 10

typedef struct node
{
    int data;
    struct node * next;
}Q_NODE;

typedef struct linked_list
{
    Q_NODE * front;
    Q_NODE * back;
    int size;
}Q_LIST;

Q_LIST* make_Qlist()
{
    Q_LIST * list = (Q_LIST*)malloc(sizeof(Q_LIST));
    list->front = NULL;
    list->back = NULL;
    list->size = 0;
    return list;
}

Q_NODE* make_Qnode(int data)
{
    Q_NODE * node = (Q_NODE*)malloc(sizeof(Q_NODE));
    node->data = data;
    node->next = NULL;
    return node;
}

void enqueue();
int dequeue();
void queue_print();
void queue_exit();

int main(void)
{
    Q_LIST * Qlist = make_Qlist();
    int enter;

    while(1){
        printf("=== Queue ===\n");
        printf(" 1. EnQueue\n");
        printf(" 2. DeQueue\n");
        printf(" 3. PRINT\n");
        printf(" 4. EXIT\n");
        printf("=============\n");
        printf("Enter(1~4) : ");
        scanf("%d", &enter);
        switch(enter){
            case 1:
                enqueue(Qlist);
                break;
            case 2:
                enter = dequeue(Qlist);
                if(enter != 0){
                    printf("\n%d\n\n", enter);
                }
                break;
            case 3:
                queue_print(Qlist);
                break;
            case 4:
                queue_exit(Qlist);
            default:
                printf("Please Re-Enter(1~4)\n\n");
        }
    }
    return 0;
}

void enqueue(Q_LIST * list)
{
    if(list->size >= QUEUE_MAX){    // 큐가 꽉찼을때
        printf("\nQueue is Full\n\n");
        return;
    }
    int enter;
    printf("Enter Data : ");
    scanf("%d", &enter);
    Q_NODE * node = make_Qnode(enter);
    if(list->size == 0){
        list->front = node;
    }
    else{
        node->next = list->back;
    }
    list->back = node;
    list->size++;
}

int dequeue(Q_LIST * list)
{
    if(list->size <= 0){
        printf("\nQueue is Empty\n\n");
        return 0;
    }
    int dq;
    dq = list->front->data;
    if(list->size == 1){
        free(list->front);
        list->front = NULL;
        list->back = NULL;
    }
    else{
        Q_NODE * tmp = list->back;
        for(int i = 1; i < list->size - 1; i++){
            tmp = tmp->next;
        }
        tmp->next = NULL;
        free(list->front);
        list->front = tmp;
    }
    list->size--;
    return dq;
}

void queue_print(Q_LIST * list)
{
    if(list->size <= 0){
        printf("\nQueue is Empty\n\n");
        return;
    }
    Q_NODE * tmp = list->back;
    printf("\n");
    for(int i = 1; i <= list->size; i++){
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n\n");
}

void queue_exit(Q_LIST * list)
{
    if(list->size != 0){
        Q_NODE * tmp = list->back;
        for(int i = 1; i <= list->size; i++){
            tmp = tmp->next;
            free(list->back);
            list->back = tmp;
        }
    }
    free(list);
    exit(0);
}