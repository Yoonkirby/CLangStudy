#include <stdio.h>
#include <stdlib.h>

#define ARR_MAX 5

typedef struct{
    int arr[ARR_MAX];
    int size;
}SQ;

void stack_push(SQ * st, int data);
int stack_pop(SQ * st);
void enqueue(SQ * q, int data);
int dequeue(SQ * q);
void print_stack(SQ * st);
void print_queue(SQ * q);

int main(void)
{
    SQ Q = {{0,},0};
    SQ S = {{0,},0};
    
    stack_push(&S, 1);
    stack_push(&S, 2);
    stack_push(&S, 3);
    stack_push(&S, 4);
    stack_push(&S, 5);
    print_stack(&S);

    printf("pop : %d\n", stack_pop(&S));
    printf("pop : %d\n", stack_pop(&S));
    printf("pop : %d\n", stack_pop(&S));
    print_stack(&S);

    printf("\n");

    enqueue(&Q, 1);
    enqueue(&Q, 2);
    enqueue(&Q, 3);
    print_queue(&Q);
    printf("dequeue : %d\n", dequeue(&Q));
    print_queue(&Q);
    printf("dequeue : %d\n", dequeue(&Q));
    print_queue(&Q);
    enqueue(&Q, 4);
    enqueue(&Q, 5);
    print_queue(&Q);
    return 0;
}

void stack_push(SQ * st, int data)
{
    if(st->size >= ARR_MAX){
        printf("Stack is Full\n");
        return;
    }
    st->arr[st->size++] = data;
}

int stack_pop(SQ * st)
{
    if(st->size >= 0){
        int tmp;
        tmp = st->arr[st->size-1];
        st->arr[st->size-1] = 0;
        st->size--;
        return tmp;
    }
    printf("Stack is Empty\n");
}

void enqueue(SQ * q, int data)
{
    if(q->size >= ARR_MAX){
        printf("Queue is Full\n");
        return;
    }
    q->arr[q->size++] = data;
}

int dequeue(SQ * q)
{
    if(q->size >= 0){
        int tmp;
        tmp = q->arr[0];
        q->size--;
        for(int i = 0; i < q->size; i++){
            q->arr[i] = q->arr[i+1];
        }
        q->arr[q->size] = 0;
        return tmp;
    }
    printf("Queue is Empty\n");
}

void print_stack(SQ * st)
{
    for(int i = 0; i < st->size; i++){
        printf("%d ",st->arr[i]);
    }
    printf(" Top\n");
}

void print_queue(SQ * q)
{
    printf("Back ");
    for(int i = q->size - 1; i >= 0; i--){
        printf("%d ", q->arr[i]);
    }
    printf(" Front\n");
}