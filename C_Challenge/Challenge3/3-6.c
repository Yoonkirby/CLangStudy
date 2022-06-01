// 숫자 맞추기 게임(야구 게임)
// 컴퓨터는 0에서 9사이의 숫자 중 서로 다른 세 개의 숫자를 고름
// 숫자의 순서까지 정확히 맞춰야 한다
// 단 사용자가 예상한 숫자를 입력할 때마다 컴퓨터는 입력된 숫자와 컴퓨터 자신이 생각한 숫자가 얼마나 비슷한지를 알려줘야한다
// 예를 들어 컴퓨터가 고른 숫자가 1 4 9이고, 사용자가 입력한 숫자가 4 0 9이면, 두개의 숫자 4와 9가 일치한다
// 9는 숫자와 위치까지 일치하지만(1 strike), 4는 숫자만 일치한다(1 ball)
// 이 경우 컴퓨터는 1strike, 1ball 을 출력한다
// 만약 사용자가 1 4 9를 입력했다면 3strike, 0ball이 되어 프로그램은 종료가 된다
// 이 때 몇 번 만에 3strike를 얻어냈는지에 대해서도 출력한다
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));
    int pc[3];
    int enter[3];
    int strike, ball, i, j, cnt = 0;
    for(i = 0; i < 3; i++)
        pc[i] = rand() % 10;
    printf("Start Game!\n");
    while(1)
    {
        printf("Enter : ");
        scanf_s("%d %d %d", &enter[0], &enter[1], &enter[2]);
        strike = 0;
        ball = 0;
        for(i = 0; i < 3; i++)
        {
            if(pc[i] == enter[i])
                strike++;
        }
        for(i = 0; i < 3; i++)
        {
            for(j = 0; j < 3; j++)
            {
                if(i == j)
                    continue;
                else
                {
                    if(pc[i] == enter[j])
                        ball++;
                }
            }
        }
        cnt++;
        printf("Result : %dStrike, %dBall!\n", strike, ball);
        if(strike == 3)
            break;
    }
    printf("You got the answer in %d tries\n");
    printf("End Game\n");
    return 0;
}