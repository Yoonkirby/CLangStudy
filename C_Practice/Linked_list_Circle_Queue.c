#include <stdio.h>
#include <stdlib.h>

#define Q_MAX 10

typedef struct Node{
    int data;
    struct Node * next;
}NODE;

typedef struct Circle_Queue{
    unsigned int size;
    NODE * front;
    NODE * back;
}CQUEUE;

NODE* make_node(int data);
void enqueue(CQUEUE * q, int data);
int dequeue(CQUEUE * q);

int main(void)
{
    CQUEUE Q;
    Q.size = 0;
    Q.front = NULL;
    Q.back = NULL;

    for(int i = 1; i <= 5; i++){
        enqueue(&Q, i);
    }
    for(int i = 1; i <= 5; i++){
        printf("%d\n", dequeue(&Q));
    }
    return 0;
}

NODE* make_node( int data)
{
    NODE * node = (NODE*)malloc(sizeof(NODE));
    node->data = data;
    node->next = NULL;
    return node;
}

void enqueue(CQUEUE * q, int data)
{
    if(q->size >= Q_MAX){
        printf("Queue is Full\n");
        return;
    }

    NODE * node = make_node(data);
    if(q->size == 0){
        q->front = node;
        q->back = node;
    }
    else{
        node->next = q->front;
        q->back->next = node;
        q->back = node;
    }
    q->size++;
}

int dequeue(CQUEUE * q)
{
    int data;
    if(q->size == 1){
        data = q->front->data;
        free(q->front);
        q->front = NULL;
        q->back = NULL;
        q->size--;
        return data;
    }
    else if(q->size > 1){
        NODE * node = q->front;
        data = q->front->data;
        q->front = q->front->next;
        q->back->next = q->front;
        free(node);
        return data;
    }
    printf("Queue is empty\n");
}
