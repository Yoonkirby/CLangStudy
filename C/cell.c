#include <stdio.h>
#include <time.h> //????±? ??? ?€?

int main(void)
{
	/*char name[256];
	printf("?΄λ¦μ΄ λ­μ?? ");
	scanf_s("%s", name, sizeof(name));

	int age;
	printf("λͺμ΄?΄??? ");
	scanf_s("%d", &age);

	float weight;
	printf("λͺΈλ¬΄κ²λ λͺ? kg ?΄??? ");
	scanf_s("%f", &weight);

	double height;
	printf("?€? λͺ? cm ?΄??? ");
	scanf_s("%lf", &height);

	char what[256];
	printf("λ¬΄μ¨ λ²μ£λ₯? ???μ§λ???΄?? ");
	scanf_s("%s", what, sizeof(what));

	printf("\n\n==== λ²μ£? ? λ³? ====\n\n");
	printf(" ?΄λ¦?      : %s\n", name);
	printf(" ??΄      : %d\n", age);
	printf(" λͺΈλ¬΄κ²?    : %.2fkg\n", weight);
	printf(" ?€        : %.2lfcm\n", height);
	printf(" λ²μ£λͺ?    : %s\n", what);*/
	
	//?Ό?Όλ―Έλλ₯? ???Ό - ?λ‘μ ?Έ
	/*int floor;
	printf("λͺ? μΈ΅μΌλ‘? ?κ² λ??");
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

	//srand(time(NULL)); // ?? μ΄κΈ°?
	//int num = rand() % 3 +1; // 1 ~ 3

	/*printf("?? μ΄κΈ°? ?΄? \n");
	for (int i = 0; i < 10; i++)
		printf("%d ", rand() % 10);

	srand(time(NULL));// ?? μ΄κΈ°?
	printf("\n\n?? μ΄κΈ°? ?΄?\n");
	for (int i = 0; i < 10; i++)
		printf("%d ", rand() % 10);*/

	//κ°?? 0 λ°μ 1 λ³? 2
	/*srand(time(NULL));
	int i = rand() % 3; // 0 ~ 2 λ°ν
	switch (i) {
	case 0:printf("κ°??\n"); break;
	case 1:printf("λ°μ\n"); break;
	case 2:printf("λ³?\n"); break;
	default:printf("λͺ°λΌ?\n"); break;
	}*/
	
	/*int age = 15;
	switch (age) {
	case 8:
	case 9:
	case 10:
	case 11:
	case 12:
	case 13:printf("μ΄λ±?? ???€\n"); break;
	case 14:
	case 15:
	case 16:printf("μ€ν? ???€.\n"); break;
	case 17:
	case 18:
	case 19:printf("κ³ λ±?? ???€\n"); break;
	default : printf("???΄ ???­??€\n"); break;
	}*/

	

	return 0;
}