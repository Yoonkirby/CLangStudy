#include <stdio.h>
#include <time.h> //난수생성시 필요한 헤더

int main(void)
{
	/*char name[256];
	printf("이름이 뭐에요? ");
	scanf_s("%s", name, sizeof(name));

	int age;
	printf("몇살이에요? ");
	scanf_s("%d", &age);

	float weight;
	printf("몸무게는 몇 kg 이에요? ");
	scanf_s("%f", &weight);

	double height;
	printf("키는 몇 cm 이에요? ");
	scanf_s("%lf", &height);

	char what[256];
	printf("무슨 범죄를 저질렀어요? ");
	scanf_s("%s", what, sizeof(what));

	printf("\n\n==== 범죄자 정보 ====\n\n");
	printf(" 이름      : %s\n", name);
	printf(" 나이      : %d\n", age);
	printf(" 몸무게    : %.2fkg\n", weight);
	printf(" 키        : %.2lfcm\n", height);
	printf(" 범죄명    : %s\n", what);*/
	
	//피라미드를 쌓아라 - 프로젝트
	/*int floor;
	printf("몇 층으로 쌓겠느냐?");
	scanf_s("%d", &floor);
	int i, j;
	for (i = 1; i <= floor; i++) {
		for (j = floor; i < j; j--)
		{
			printf(" ");
		}
		for (j = 0; j < (i*2-1); j++)
		{
			printf("*");
		}
		printf("\n");
	}*/

	//srand(time(NULL)); // 난수 초기화
	//int num = rand() % 3 +1; // 1 ~ 3

	/*printf("난수 초기화 이전\n");
	for (int i = 0; i < 10; i++)
		printf("%d ", rand() % 10);

	srand(time(NULL));// 난수 초기화
	printf("\n\n난수 초기화 이후\n");
	for (int i = 0; i < 10; i++)
		printf("%d ", rand() % 10);*/

	//가위 0 바위 1 보 2
	/*srand(time(NULL));
	int i = rand() % 3; // 0 ~ 2 반환
	switch (i) {
	case 0:printf("가위\n"); break;
	case 1:printf("바위\n"); break;
	case 2:printf("보\n"); break;
	default:printf("몰라요\n"); break;
	}*/
	
	/*int age = 15;
	switch (age) {
	case 8:
	case 9:
	case 10:
	case 11:
	case 12:
	case 13:printf("초등학생 입니다\n"); break;
	case 14:
	case 15:
	case 16:printf("중학생 입니다.\n"); break;
	case 17:
	case 18:
	case 19:printf("고등학생 입니다\n"); break;
	default : printf("학생이 아니십니다\n"); break;
	}*/

	printf("한글테스트\n");

	return 0;
}