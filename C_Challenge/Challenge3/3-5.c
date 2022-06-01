// 가위 바위 보 게임
// 사용자로부터 가위 바위 보 중에서 하나를 입력 받음
// 컴퓨터는 난수 생성을 통해서 가위 바위 보 중에서 하나를 선택하게 함
// 이 둘을 비교해서 승자와 패자를 가려주는 프로그램
// 단 프로그램의 진행은 사용자가 질 때까지 계속 되어야 하고 마지막에 가서는 게임의 결과(ex. 4승 3무)까지 출력
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int enter, pc, win = 0, draw = 0;
    srand(time(NULL));
    while(1)
    {
        pc = rand() % 3 + 1;
        printf("Rock = 1, Scissors = 2, Paper = 3\nEnter : ");
        scanf_s("%d", &enter);
        if(enter < 1 || enter > 3)
        {
            printf("ReEnter 1 ~ 3\n");
            continue;
        }
        if(enter - pc == 0)
        {
            printf("Draw!\n");
            draw++;
        }
        else if(enter - pc == -1 || enter - pc == 2)
        {
            printf("You Win!\n");
            win++;
        }
        else if(enter - pc == 1 || enter - pc == -2)
        {
            printf("You Lose...\n");
            break;
        }
    }
    printf("Win %d, Draw %d\n", win, draw);

    return 0;
}