// 숫자 n을 입력 받고 다음 공식이 성립하는 k의 최댓값을 출력하는 프로그램 작성
// 2^k <= n
#include <stdio.h>

int main(void)
{
    int n, k = 0, max = 2;
    printf("Enter : ");
    scanf_s("%d",&n);
    while(1)
    {
        if(max > n)
            break;
        max *= 2;
        k++;
    }
    printf("K's Maximum is %d",k);
    return 0;
}