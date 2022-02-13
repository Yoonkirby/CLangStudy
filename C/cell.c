#include <stdio.h>
#include <time.h> //?‚œ?ˆ˜?ƒ?„±?‹œ ?•„?š”?•œ ?—¤?”

int main(void)
{
	/*char name[256];
	printf("?´ë¦„ì´ ë­ì—?š”? ");
	scanf_s("%s", name, sizeof(name));

	int age;
	printf("ëª‡ì‚´?´?—?š”? ");
	scanf_s("%d", &age);

	float weight;
	printf("ëª¸ë¬´ê²ŒëŠ” ëª? kg ?´?—?š”? ");
	scanf_s("%f", &weight);

	double height;
	printf("?‚¤?Š” ëª? cm ?´?—?š”? ");
	scanf_s("%lf", &height);

	char what[256];
	printf("ë¬´ìŠ¨ ë²”ì£„ë¥? ???ì§ˆë???–´?š”? ");
	scanf_s("%s", what, sizeof(what));

	printf("\n\n==== ë²”ì£„? ? •ë³? ====\n\n");
	printf(" ?´ë¦?      : %s\n", name);
	printf(" ?‚˜?´      : %d\n", age);
	printf(" ëª¸ë¬´ê²?    : %.2fkg\n", weight);
	printf(" ?‚¤        : %.2lfcm\n", height);
	printf(" ë²”ì£„ëª?    : %s\n", what);*/
	
	//?”¼?¼ë¯¸ë“œë¥? ?Œ“?•„?¼ - ?”„ë¡œì ?Š¸
	/*int floor;
	printf("ëª? ì¸µìœ¼ë¡? ?Œ“ê² ëŠ?ƒ?");
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

	//srand(time(NULL)); // ?‚œ?ˆ˜ ì´ˆê¸°?™”
	//int num = rand() % 3 +1; // 1 ~ 3

	/*printf("?‚œ?ˆ˜ ì´ˆê¸°?™” ?´? „\n");
	for (int i = 0; i < 10; i++)
		printf("%d ", rand() % 10);

	srand(time(NULL));// ?‚œ?ˆ˜ ì´ˆê¸°?™”
	printf("\n\n?‚œ?ˆ˜ ì´ˆê¸°?™” ?´?›„\n");
	for (int i = 0; i < 10; i++)
		printf("%d ", rand() % 10);*/

	//ê°??œ„ 0 ë°”ìœ„ 1 ë³? 2
	/*srand(time(NULL));
	int i = rand() % 3; // 0 ~ 2 ë°˜í™˜
	switch (i) {
	case 0:printf("ê°??œ„\n"); break;
	case 1:printf("ë°”ìœ„\n"); break;
	case 2:printf("ë³?\n"); break;
	default:printf("ëª°ë¼?š”\n"); break;
	}*/
	
	/*int age = 15;
	switch (age) {
	case 8:
	case 9:
	case 10:
	case 11:
	case 12:
	case 13:printf("ì´ˆë“±?•™?ƒ ?…?‹ˆ?‹¤\n"); break;
	case 14:
	case 15:
	case 16:printf("ì¤‘í•™?ƒ ?…?‹ˆ?‹¤.\n"); break;
	case 17:
	case 18:
	case 19:printf("ê³ ë“±?•™?ƒ ?…?‹ˆ?‹¤\n"); break;
	default : printf("?•™?ƒ?´ ?•„?‹ˆ?‹­?‹ˆ?‹¤\n"); break;
	}*/

	

	return 0;
}