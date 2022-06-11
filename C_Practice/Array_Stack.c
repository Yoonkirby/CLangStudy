#include <stdio.h>
#include <stdlib.h>

#define STACK_MAX 10

void stack_push();
int stack_pop();
void stack_print();

int main(void){
    int stack[STACK_MAX];
    int cnt = -1;
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
                printf("Enter Data : ");
                scanf("%d", &enter);
                stack_push(stack, &cnt, enter);
                break;
            case 2:
                stack_pop(stack, &cnt);
                break;
            case 3:
                stack_print(stack, &cnt);
                break;
            case 4:
                exit(0);
            default:
                printf("Please Re-Enter(1~4)\n\n");
        }
    }

    return 0;
}

void stack_push(int * stack, int * cnt, int data){
    if((*cnt) + 1 >= STACK_MAX){
        printf("Stack is Full\n");
        return;
    }
    *(stack + (++(*cnt))) = data;
}

int stack_pop(int * stack, int * cnt){
    if((*cnt) <= -1 ){
        printf("Stack is Empty\n");
    }
    else{
        int pop;
        pop = *(stack + (*cnt));
        *(stack + ((*cnt)--)) = 0;
        return pop;
    }
}

void stack_print(int * stack, int * cnt){
    if((*cnt) <= -1 ){
        printf("Stack is Empty\n");
    }
    printf("{ ");
    for(int i = 0; i < (*cnt); i++)
    {
        printf("%d, ", *(stack + i));
    }
    printf("%d }\n",*(stack + (*cnt)));
}