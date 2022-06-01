// 달팽이 배열을 만들어서 이를 출력하는 프로그램
// 달팽이 배열 ex)
// 1   2   3
// 8   9   4
// 7   6   5
// 숫자 n을 입력 받아서 n*n의 길이에 해당하는 달팽이 배열을 출력
#include <stdio.h>

int main(void)
{
    int enter, i, j, x = 0, y = 0, cnt = 1, pm = 1;
    printf("Enter : ");
    scanf_s("%d", &enter);
    int arr[enter][enter];
    
    for(y = 0; y < enter; y++)
    {
        arr[x][y] = cnt++;
    }
    y--;

    for(i = enter-1; i >= 1; i--)
    {
        if(pm == 1)
        {
            for(j = 0; j < i; j++)
            {
                arr[++x][y] = cnt++;
            }
            for(j = 0; j < i; j++)
            {
                arr[x][--y] = cnt++;
            }
            pm *= -1;
        }
        else if(pm == -1)
        {
            for(j = 0; j < i; j++)
            {
                arr[--x][y] = cnt++;
            }
            for(j = 0; j < i; j++)
            {
                arr[x][++y] = cnt++;
            }
            pm *= -1;
        }
    }
    
    for(i = 0; i < enter; i++)
    {
        for(j = 0; j < enter; j++)
        {
            printf("\t%d",arr[i][j]);
        }
        printf("\n\n");
    }

    return 0;
}