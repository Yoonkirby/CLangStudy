#include <stdio.h>
#include <time.h> //���� ������ �ʿ�
//������ ���� ctrl + alt + S
//������ exe ���� ctrl + alt + R
int main(void)
{
	//�Ƕ�̵� �ױ�
	/*int floor;
	printf("������ �װڽ��ϱ�?");
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


	//srand(time(NULL)); //���� �ʱ�ȭ
	//int num = rand() % 3 +1; // 1 ~ 3

	/*printf("���� �ʱ�ȭ ����\n");
	forint i = 0; i < 10; i++)
		printf("%d ", rand() % 10);

	srand(time(NULL)); //���� �ʱ�ȭ
	printf("���� �ʱ�ȭ ����\n");
	for (int i = 0; i < 10; i++)
		printf("%d ", rand() % 10);*/


	//���� ���� ��
	/*srand(time(NULL));
	int i = rand() % 3; // 0 ~ 2 ��ȯ
	switch (i) {
	case 0:printf("����\n"); break; //break ������ �� case ���� �� ����
	case 1:printf("����\n"); break;
	case 2:printf("��\n"); break;
	default:printf("�����\n"); break;
	}*/

	
	/*int age = 15;
	switch (age)
	{
	case 8:
	case 9:
	case 10:
	case 11:
	case 12:
	case 13:printf("�ʵ��л� �Դϴ�.\n"); break;
	case 14:
	case 15:
	case 16:printf("���л� �Դϴ�.\n"); break;
	case 17:
	case 18:
	case 19:printf("����л� �Դϴ�.\n"); break;
	default : printf("�л��� �ƴϽʴϴ�.\n"); break;
	}*/

	

	return 0;
}