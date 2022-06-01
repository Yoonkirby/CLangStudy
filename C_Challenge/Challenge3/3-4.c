// 두개의 주사위를 던졌을 때의 결과를 출력
#include <stdio.h>
#include <stdlib.h> // rand 함수
#include <time.h>   // time 함수

int main(void)
{
    srand(time(NULL));
    printf("Dice 1 : %d\n", rand()%6+1);
    printf("Dice 2 : %d\n", rand()%6+1);

    return 0;
}