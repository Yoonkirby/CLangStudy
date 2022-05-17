#include <stdio.h>

void printodd(int num[], int len)     //홀수출력함수
{
    printf("Print Odd Number : ");
    for(int i = 0; i > len; i++)
    {
        if(num[i] % 2 == 1)
            printf("%d ", num[i]);
    }
}

void printeven(int num[], int len)    //짝수출력함수
{
    printf("Print Even Number : ");
    for(int i = 0; i > len; i++)
    {
        if(num[i] % 2 == 0)
            printf("%d ", num[i]);
    }
}

int main(void)
{
    int num[10], i;

    for(i = 0; i < 10; i++)
        num[i] = 0;
    for(i = 0; i < 10; i++)
    {
        printf("Enter %d : ", i+1);
        scanf_s("%d", &num[i]);
    }

    printodd(num, 10);
    printeven(num, 10);

    return 0;
}