
#include "wegame.h"


void initboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++) {
		int j = 0;
		for (j = 0; j < col; j++) {
			board[i][j] = ' ';
		}
	}
}

void displayboard(char board[ROW][COL], int row, int col)
{
	//
	int i = 0;
	for (i = 0; i < row; i++) {
		//��ӡһ��
		int j = 0;
		for (j = 0; j < col; j++) {
			//��ӡ�ָ���
			printf(" %c ", board[i][j]);
			//��ӡ����
			if (j < col - 1) {
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1) {
			//��ӡ�°벿��
			for (j = 0; j < col; j++) {
				//
				printf("---");
				//
				if (j < col - 1) {
					printf("|");
				}
			}
			printf("\n");
		}
	}
}

void player1move(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	printf("���1���壺");
	while (1) {
		scanf("%d %d", &x, &y);
		if (x>=1 && x<=ROW && y>=1 && y<=COL) {
			if (board[x - 1][y - 1] != '*' && board[x-1][y-1] ==' ') {
				board[x - 1][y - 1] = '#';
				break;
			}
			else
			{
				printf("�������Ѿ���ռ��\n");
			}
		}
		else
		{
			printf("����Ƿ�����,����������");
		}
	}
}

void player2move(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	printf("���2���壺");
	while (1) {
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= ROW && y >= 1 && y <= COL) {
			if (board[x - 1][y - 1] != '#' && board[x - 1][y - 1] == ' ') {
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("�������Ѿ���ռ��\n");
			}
		}
		else
		{
			printf("�Ƿ�����,���������룺");
		}
	}
}
//���˷���1��û������0
int isfull(char board[ROW][COL], int row, int col) {
	int i = 0;
	for (i = 0; i < row; i++) {
		int j = 0;
		for (j = 0; j < col; j++) {
			if (board[i][j] == ' ') {
				return 0;
			}
		}
	}
	return 1;
}

char iswin(char board[ROW][COL], int row, int col) {
	int i = 0;
	//������
	for (i = 0; i < row; i++)
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
			return board[i][0];
		}
	//������
	for (i = 0; i < col; i++) {
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] !=' ') {
			return board[0][i];
		}
	}
	//�����Խ���
	for (i = 0; i < 3; i++) {
		if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
			return board[0][0];
		}
	}
	for (i = 0; i < 3; i++) {
		if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[2][0] != ' ') {
			return board[2][0];
		}
	}
	//�ж��Ƿ�����
	if (1 == isfull(board,row,col)) {
		return 'Q';
	}
	else
	{
		return 'C';
	}
}