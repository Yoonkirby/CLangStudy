#include <stdio.h>
#include <time.h> //?��?��?��?��?�� ?��?��?�� ?��?��

int main(void)
{
	/*char name[256];
	printf("?��름이 뭐에?��? ");
	scanf_s("%s", name, sizeof(name));

	int age;
	printf("몇살?��?��?��? ");
	scanf_s("%d", &age);

	float weight;
	printf("몸무게는 �? kg ?��?��?��? ");
	scanf_s("%f", &weight);

	double height;
	printf("?��?�� �? cm ?��?��?��? ");
	scanf_s("%lf", &height);

	char what[256];
	printf("무슨 범죄�? ???질�???��?��? ");
	scanf_s("%s", what, sizeof(what));

	printf("\n\n==== 범죄?�� ?���? ====\n\n");
	printf(" ?���?      : %s\n", name);
	printf(" ?��?��      : %d\n", age);
	printf(" 몸무�?    : %.2fkg\n", weight);
	printf(" ?��        : %.2lfcm\n", height);
	printf(" 범죄�?    : %s\n", what);*/
	
	//?��?��미드�? ?��?��?�� - ?��로젝?��
	/*int floor;
	printf("�? 층으�? ?��겠느?��?");
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

	//srand(time(NULL)); // ?��?�� 초기?��
	//int num = rand() % 3 +1; // 1 ~ 3

	/*printf("?��?�� 초기?�� ?��?��\n");
	for (int i = 0; i < 10; i++)
		printf("%d ", rand() % 10);

	srand(time(NULL));// ?��?�� 초기?��
	printf("\n\n?��?�� 초기?�� ?��?��\n");
	for (int i = 0; i < 10; i++)
		printf("%d ", rand() % 10);*/

	//�??�� 0 바위 1 �? 2
	/*srand(time(NULL));
	int i = rand() % 3; // 0 ~ 2 반환
	switch (i) {
	case 0:printf("�??��\n"); break;
	case 1:printf("바위\n"); break;
	case 2:printf("�?\n"); break;
	default:printf("몰라?��\n"); break;
	}*/
	
	/*int age = 15;
	switch (age) {
	case 8:
	case 9:
	case 10:
	case 11:
	case 12:
	case 13:printf("초등?��?�� ?��?��?��\n"); break;
	case 14:
	case 15:
	case 16:printf("중학?�� ?��?��?��.\n"); break;
	case 17:
	case 18:
	case 19:printf("고등?��?�� ?��?��?��\n"); break;
	default : printf("?��?��?�� ?��?��?��?��?��\n"); break;
	}*/

	

	return 0;
}