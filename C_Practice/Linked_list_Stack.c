#include <stdio.h>
#include <stdlib.h>

#define STACK_MAX 10

typedef struct node{
    int data;
    struct node * next;
}NODE;

typedef struct linked_list{
    int cnt;
    NODE * top;
    NODE * bottom;
}LL;

LL* make_ll();
NODE* make_node(int data);
void stack_push(LL * ll);
int stack_pop(LL * ll);
void stack_print(LL * ll);
void stack_clear(LL * ll);

int main(void){
    LL * ll = make_ll();
    int enter;
    while(1){
        printf("=== STACK ===\n");
        printf(" 1. PUSH\n");
        printf(" 2. POP\n");
        printf(" 3. PRINT\n");
        printf(" 4. EXIT\n");
        printf("=============\n");
        printf("Enter(1~4) : ");
        scanf("%d", &enter);
        switch(enter){
            case 1:
                stack_push(ll);
                break;
            case 2:
                stack_pop(ll);
                break;
            case 3:
                stack_print(ll);
                break;
            case 4:
                stack_clear(ll);
                exit(0);
            default:
                printf("Please Re-Enter(1~4)\n\n");
        }
    }
    return 0;
}

LL* make_ll(){
    LL * ll = (LL*)malloc(sizeof(LL));
    ll->cnt = 0;
    ll->top = NULL;
    ll->bottom = NULL;
    return ll;
}

NODE* make_node(int data){
    NODE * node = (NODE*)malloc(sizeof(NODE));
    node->data = data;
    node->next = NULL;
    return node;
}

void stack_push(LL * ll){
    if(ll->cnt >= STACK_MAX){
        printf("Stack is Full\n\n");
        return;
    }
    int enter;
    printf("Enter Data : ");
    scanf("%d", &enter);
    NODE * node = make_node(enter);
    if(ll->cnt == 0){
        ll->top = node;
        ll->bottom = node;
    }
    else{
        ll->top->next = node;
        ll->top = node;
    }
    ll->cnt++;
    printf("Push Success\n\n");
}

int stack_pop(LL * ll){
    if(ll->cnt == 0){
        printf("There's Nothing\n\n");
    }
    else if(ll->cnt == 1){
        int pop = ll->top->data;
        free(ll->top);
        ll->top = NULL;
        ll->bottom = NULL;
        ll->cnt--;
        return pop;
    }
    else{
        NODE * idx = ll->bottom;
        for(int i = 1; i < ll->cnt - 1; i++){
            idx = idx->next;
        }
        idx->next = NULL;
        int pop = ll->top->data;
        free(ll->top);
        ll->top = idx;
        ll->cnt--;
        printf("Pop Success\n\n");
        return pop;
    }
}

void stack_print(LL * ll){
    if(ll->cnt == 0){
        printf("Stack is empty\n\n");
        return;
    }
    NODE * tmp = ll->bottom;
    printf("\n");
    while(tmp != NULL){
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n\n");
}

void stack_clear(LL * ll){
    if(ll->cnt > 0){
        ll->top = ll->bottom;
        while(ll->bottom != NULL){
            ll->top = ll->top->next;
            free(ll->bottom);
            ll->bottom = ll->top;
        }
    }
    free(ll);
    printf("Exit...\n");
}