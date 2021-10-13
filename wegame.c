
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
		//打印一行
		int j = 0;
		for (j = 0; j < col; j++) {
			//打印分割线
			printf(" %c ", board[i][j]);
			//打印竖线
			if (j < col - 1) {
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1) {
			//打印下半部分
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
	printf("玩家1下棋：");
	while (1) {
		scanf("%d %d", &x, &y);
		if (x>=1 && x<=ROW && y>=1 && y<=COL) {
			if (board[x - 1][y - 1] != '*' && board[x-1][y-1] ==' ') {
				board[x - 1][y - 1] = '#';
				break;
			}
			else
			{
				printf("该坐标已经被占用\n");
			}
		}
		else
		{
			printf("输入非法坐标,请重新输入");
		}
	}
}

void player2move(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	printf("玩家2下棋：");
	while (1) {
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= ROW && y >= 1 && y <= COL) {
			if (board[x - 1][y - 1] != '#' && board[x - 1][y - 1] == ' ') {
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该坐标已经被占用\n");
			}
		}
		else
		{
			printf("非法坐标,请重新输入：");
		}
	}
}
//满了返回1，没满返回0
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
	//横三行
	for (i = 0; i < row; i++)
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
			return board[i][0];
		}
	//竖三列
	for (i = 0; i < col; i++) {
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] !=' ') {
			return board[0][i];
		}
	}
	//两个对角线
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
	//判断是否满了
	if (1 == isfull(board,row,col)) {
		return 'Q';
	}
	else
	{
		return 'C';
	}
}