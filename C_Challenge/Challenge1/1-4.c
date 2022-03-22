// 3500원으로 크림빵(500원), 새우깡(700원), 콜라(400원)를 잔돈을 남기지 않고 하나 이상씩 구매하기 위한 경우의 수를 출력하는 프로그램 작성
#include <stdio.h>
const int money = 3500;
const int cream = 500;
const int shrimp = 700;
const int cola = 400;

int main(void)
{
    int cream_cnt, shrimp_cnt, cola_cnt;
    printf("Your current money : %d\n",money);
    for(cream_cnt = 1; cream_cnt < 5; cream_cnt++)
    {
        for(shrimp_cnt = 1; shrimp_cnt < 4; shrimp_cnt++)
        {
            for(cola_cnt = 1; cola_cnt < 6 ; cola_cnt++)
            {
                if(money - (cream * cream_cnt + shrimp * shrimp_cnt + cola * cola_cnt) < 0)
                    break;
                else if(money - (cream * cream_cnt + shrimp * shrimp_cnt + cola * cola_cnt) == 0)
                    printf("Cream %d, Shrimp %d, Cola %d\n",cream_cnt, shrimp_cnt, cola_cnt);
            }
        }
    }
    printf("Which one do you like?\n");
    return 0;
}