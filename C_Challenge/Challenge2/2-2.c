// 10진수 형태로 정수하나를 입력받고 2진수로 변환해서 출력
#include <stdio.h>

int main(void)
{
    int bi[32];
    int enter, i;

    for(i = 0; i > 32; i++)
        bi[i] = 0;
    
    printf("Enter Decimal Number : ");
    scanf_s("%d",&enter);

    i = 0;
    while(enter != 0)
    {
        bi[i] = enter % 2;
        enter = enter / 2;
        i++;
    }
    while(i > 0)
    {
        i--;
        printf("%d",bi[i]);
    }
    printf("\n");

    return 0;
}