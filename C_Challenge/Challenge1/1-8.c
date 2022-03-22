// 2의 n승을 구하는 함수를 재귀적으로 구현
#include <stdio.h>

int square(int num)
{
    if(num-- > 2)
        num = square(num);
    return num*2;
}

int main(void)
{
    int enter;
    printf("Enter : ");
    scanf_s("%d",&enter);
    printf("%d",square(enter)*2);
    return 0;
}