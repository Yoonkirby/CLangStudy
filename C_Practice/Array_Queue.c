#include <stdio.h>
#include <stdlib.h>

#define QUEUE_MAX 10

typedef struct queue{
    int data[QUEUE_MAX];
    int front;
    int back;
    int size;
}Queue;

void enqueue();
int dequeue();
void queue_print();

int main(void)
{
    Queue Q = {.front = 0, .back = 0, .size = 0};
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
                enqueue(&Q);
                break;
            case 2:
                enter = dequeue(&Q);
                if(enter != 0){
                    printf("\n%d\n\n", enter);
                }
                break;
            case 3:
                queue_print(&Q);
                break;
            case 4:
                exit(0);
            default:
                printf("Please Re-Enter(1~4)\n\n");
        }
    }
    return 0;
}

void enqueue(Queue * Q)
{
    if(Q->size >= QUEUE_MAX){    // 큐가 꽉찼을때
        printf("Queue is Full\n\n");
        return;
    }
    int enter;
    printf("Enter Data : ");
    scanf("%d", &enter);
    if(Q->size > 0){
        Q->back = (Q->back + 1) % QUEUE_MAX;
    }
    Q->data[Q->back] = enter;
    Q->size++;
}

int dequeue(Queue * Q)
{
    if(Q->size <= 0){
        printf("Queue is Empty\n\n");
        return 0;
    }
    int dq;
    dq = Q->data[Q->front];
    Q->data[Q->front] = 0;
    Q->front = (Q->front + 1) % QUEUE_MAX;
    Q->size--;
    return dq;
}

void queue_print(Queue * Q)
{
    int tmp = Q->back;
    printf("\n");
    for(int i = 0; i < Q->size; i++){
        printf("%d ", Q->data[tmp--]);
        if(tmp == -1){
            tmp = QUEUE_MAX - 1;
        }
    }
    printf("\n\n");
}