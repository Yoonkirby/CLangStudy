// 두 개의 정수를 입력 받아 구구단을 출력하는 프로그램을 작성
// ex) 3과 5를 입력하면 3단, 4단, 5단 출력
// + 조건 : 두 개의 숫자를 입력 할 때 입력 순서가 자유로워야 한다. 즉 3과 5를 입력하던 5와 3을 입력하던 같은 결과를 출력해야함
#include <stdio.h>

int main(void)
{
    int ent1 = 0, ent2 = 0, temp = 0;
    printf("Enter 1 : ");
    scanf("%d",&ent1);
    printf("Enter 2 : ");
    scanf("%d",&ent2);

    if(ent1 > ent2)
    {
        temp = ent2;
        ent2 = ent1;
        ent1 = temp;
    }

    for(int i = ent1; i <= ent2; i++)
    {
        for(int j = 1; j < 10; j++)
        {
            printf("%d X %d = %d\n", i, j, i*j);
        }
    }
    return 0;
}