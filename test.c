
#include "wegame.h"

void game()
{
	char ret = 0; //�ж���Ӯ����

	//����һ������

	char board[ROW][COL] = { 0 };
	//��ʼ������

	initboard(board, ROW, COL);

	//��ʾ����

	displayboard(board, ROW, COL);

	//����
	//���1����,ʹ��#
	//���2���壬ʹ��*
	while (1) {
		//���1����
		player1move(board, ROW, COL);
		displayboard(board, ROW, COL);
		ret = iswin(board, ROW, COL);
		if (ret != 'C') {
			break;
		}
		//���2����
		player2move(board, ROW, COL);
		displayboard(board, ROW, COL);
		ret = iswin(board, ROW, COL);
		if (ret != 'C') {
			break;
		}
	}
	if (ret == '#') {
		printf("���1Ӯ\n");
	}
	else if (ret == '*') {
		printf("���2Ӯ\n");
	}
	else if (ret == 'Q') {
		printf("ƽ��\n");
	}
}
void menu() {
	printf("***********************\n");
	printf("**1.play    0.exit*****\n");
	printf("***********************\n");
}


void test()
{
	int input = 0;
	menu();
	do
	{
		printf("����Ϸ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳�\n");
			break;
		}
	} while (input);
}


int main()
{
	test();
	return 0;
}