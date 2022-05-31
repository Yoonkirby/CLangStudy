// 버블정렬
// 배열에 저장되어 있는 요소들을 내림차순으로 정렬하는 함수 DesSort 정의 및 호출하는 예제
// 길이가 7인 int형 배열에 사용자로부터 7개의 정수를 입력받고 DesSort 함수를 호출하여 내림차순으로 정렬
// 마지막으로 확인을 위해 배열의 요소들을 순서대로 출력
#include <stdio.h>

int len = 7;

void DesSort(int * arr)
{
    int tmp = 0;
    for(int i = len-1; i > 0; i--)
    {
        for(int j = 0; j < i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}

int main(void)
{
    int arr[len];
    for(int i = 0; i < len; i++)
    {
        printf("Enter %d : ", i+1);
        scanf("%d",&arr[i]);
    }

    DesSort(arr);

    for(int i = 0; i < len; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");

    return 0;
}