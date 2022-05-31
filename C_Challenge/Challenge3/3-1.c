// 길이가 4*4인 int형 2차원 배열을 선언
// 1~16의 값으로 차례대로 배열을 초기화
// 배열의 요소들을 오른쪽 방향으로 90도씩 이동시켜 그 결과를 출력
#include <stdio.h>

int main(void)
{
    int arr[4][4] = {{1, 2, 3, 4}, 
                     {5, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16}};
    int tmp[4][4];
    int i, j;

    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
        {
            tmp[j][3-i] = arr[i][j];
        }
    }

    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
        {
            arr[i][j] = tmp[i][j];
        }
    }

    for(int i = 0; i < 4; i++)
    {
        printf("\n");
        for(int j = 0; j < 4; j++)
        {
            printf("%d\t", arr[i][j]);
        }
    }
    printf("\n");

    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
        {
            tmp[j][3-i] = arr[i][j];
        }
    }

    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
        {
            arr[i][j] = tmp[i][j];
        }
    }

    for(int i = 0; i < 4; i++)
    {
        printf("\n");
        for(int j = 0; j < 4; j++)
        {
            printf("%d\t", arr[i][j]);
        }
    }
    printf("\n");

    return 0;
}