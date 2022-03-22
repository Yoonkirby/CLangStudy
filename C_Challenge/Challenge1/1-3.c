// 두 개의 정수를 입력 받아 최대 공약수(GCD)를 구하는 프로그램을 작성
// 유클리드 호제법
#include <stdio.h>

int GCD(int num1, int num2) //큰숫자가 왼쪽으로 감
{
    int r;
    r = num1 % num2;
    if(r >= 0 && r < num2)
    {
        while(r!=0)
        {
            num1 = num2;
            num2 = r;
            r = num1 % num2;
            
        }
    }
    else
    {
        exit(1);
    }
    return num2;
}

int main(void)
{
    int ent1 = 0, ent2 = 0, temp = 0;
    printf("Enter 1 : ");
    scanf("%d",&ent1);
    printf("Enter 2 : ");
    scanf("%d",&ent2);

    if(ent1 < ent2)
    {
        temp = ent2;
        ent2 = ent1;
        ent1 = temp;
    }
    printf("Result : %d\n",GCD(ent1,ent2));
    return 0;
}