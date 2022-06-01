// 0 이상 99 이하의 난수를 총 5개 생성
#include <stdio.h>

int main(void)
{
    for(int i = 0; i < 5; i++)
    {
        printf("Random Number %d : %d\n", i+1, rand()%100);
    }
    return 0;
}