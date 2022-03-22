// 10진수 정수를 입력 받아 16진수로 출력하는 프로그램을 작성
// 서식문자의 활용에 대한 문제
#include <stdio.h>

int main(void)
{
    int num = 0;
    printf("Enter : ");
    scanf("%d",&num);
    printf("result : %x\n",num);
    return 0;
}