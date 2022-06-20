#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node * next;
}NODE;

typedef struct stack{
    int size;
    NODE * top;
    NODE * bottom;
}STACK;

typedef struct queue{
    int size;
    NODE * front;
    NODE * back;
}QUEUE;

STACK* stack_init(int data);
void stack_push(STACK * stack, int data);
int stack_pop(STACK * stack);
void print_stack(STACK * stack);
void free_stack(STACK * stack);
QUEUE* queue_init(int data);
void enqueue(QUEUE * q, int data);
int dequeue(QUEUE * q);
void print_queue(QUEUE * q);
void free_queue(QUEUE * q);

int main(void)
{
    STACK * stack = stack_init(1);
    QUEUE * queue = queue_init(1);

    stack_push(stack, 2);
    stack_push(stack, 3);
    stack_push(stack, 4);
    stack_push(stack, 5);
    print_stack(stack);

    printf("pop : %d\n", stack_pop(stack));
    print_stack(stack);
    printf("pop : %d\n", stack_pop(stack));
    print_stack(stack);

    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    print_queue(queue);

    printf("pop : %d\n", dequeue(queue));
    print_queue(queue);
    printf("pop : %d\n", dequeue(queue));
    print_queue(queue);

    free_stack(stack);
    free_queue(queue);
    return 0;
}

STACK* stack_init(int data)
{
    STACK * stack = (STACK*)malloc(sizeof(STACK));
    NODE * node = (NODE*)malloc(sizeof(NODE));
    node->data = data;
    node->next = NULL;
    stack->size = 1;
    stack->top = node;
    stack->bottom = node;
    return stack;
}

void stack_push(STACK * stack, int data)
{
    NODE * node = (NODE*)malloc(sizeof(NODE));
    node->data = data;
    node->next = stack->top;
    stack->top = node;
    stack->size++;
}

int stack_pop(STACK * stack)
{
    int tmp = stack->top->data;
    NODE * temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    stack->size--;
    return tmp;
}

void print_stack(STACK * stack)
{
    NODE * tmp = stack->top;
    printf("Top ");
    for(int i = 0; i < stack->size; i++){
        printf("%d ",tmp->data);
        tmp = tmp->next;
    }
    printf(" Bottom\n");
}

void free_stack(STACK * stack)
{
    NODE * tmp = stack->top;
    for(int i = 0; i < stack->size; i++){
        tmp = tmp->next;
        free(stack->top);
        stack->top = tmp;
    }
    free(stack);
}

QUEUE* queue_init(int data)
{
    QUEUE * q = (QUEUE*)malloc(sizeof(QUEUE));
    NODE * node = (NODE*)malloc(sizeof(NODE));
    node->data = data;
    node->next = NULL;
    q->size = 1;
    q->front = node;
    q->back = node;
    return q;
}

void enqueue(QUEUE * q, int data)
{
    NODE * node = (NODE*)malloc(sizeof(NODE));
    node->data = data;
    node->next = NULL;
    q->back->next = node;
    q->back = node;
    q->size++;
}

int dequeue(QUEUE * q)
{
    int tmp = q->front->data;
    NODE * temp = q->front;
    q->front = q->front->next;
    free(temp);
    q->size--;
    return tmp;
}

void print_queue(QUEUE * q)
{
    NODE * tmp = q->front;
    printf("Front ");
    for(int i = 0; i < q->size; i++){
        printf("%d ",tmp->data);
        tmp = tmp->next;
    }
    printf(" Back\n");
}

void free_queue(QUEUE * q)
{
    NODE * tmp = q->front;
    for(int i = 0; i < q->size; i++){
        tmp = tmp->next;
        free(q->front);
        q->front = tmp;
    }
    free(q);
}