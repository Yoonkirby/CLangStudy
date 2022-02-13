#include <stdio.h>
#include <time.h> //난수 생성시 필요
//컴파일 저장 ctrl + alt + S
//컴파일 exe 실행 ctrl + alt + R
int main(void)
{
	//피라미드 쌓기
	/*int floor;
	printf("몇층을 쌓겠습니까?");
	scanf_s("%d", &floor);
	int i, j;
	for(i = 1; i <= floor; i++) {
		for(j = floor; i < j; j--)
		{
			printf(" ");
		}
		for(j = 0; j <i*2-1; j++)
		{
			printf("*");
		}
		printf("\n");
	}*/


	//srand(time(NULL)); //난수 초기화
	//int num = rand() % 3 +1; // 1 ~ 3

	/*printf("난수 초기화 이전\n");
	forint i = 0; i < 10; i++)
		printf("%d ", rand() % 10);

	srand(time(NULL)); //난수 초기화
	printf("난수 초기화 이전\n");
	for (int i = 0; i < 10; i++)
		printf("%d ", rand() % 10);*/


	//가위 바위 보
	/*srand(time(NULL));
	int i = rand() % 3; // 0 ~ 2 반환
	switch (i) {
	case 0:printf("가위\n"); break; //break 없을시 밑 case 까지 쭉 실행
	case 1:printf("바위\n"); break;
	case 2:printf("보\n"); break;
	default:printf("몰라요\n"); break;
	}*/

	
	/*int age = 15;
	switch (age)
	{
	case 8:
	case 9:
	case 10:
	case 11:
	case 12:
	case 13:printf("초등학생 입니다.\n"); break;
	case 14:
	case 15:
	case 16:printf("중학생 입니다.\n"); break;
	case 17:
	case 18:
	case 19:printf("고등학생 입니다.\n"); break;
	default : printf("학생이 아니십니다.\n"); break;
	}*/

	

	return 0;
}