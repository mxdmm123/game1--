
#include "wegame.h"

void game()
{
	char ret = 0; //判断输赢变量

	//定义一个数组

	char board[ROW][COL] = { 0 };
	//初始化棋盘

	initboard(board, ROW, COL);

	//显示棋盘

	displayboard(board, ROW, COL);

	//下棋
	//玩家1下棋,使用#
	//玩家2下棋，使用*
	while (1) {
		//玩家1下棋
		player1move(board, ROW, COL);
		displayboard(board, ROW, COL);
		ret = iswin(board, ROW, COL);
		if (ret != 'C') {
			break;
		}
		//玩家2下棋
		player2move(board, ROW, COL);
		displayboard(board, ROW, COL);
		ret = iswin(board, ROW, COL);
		if (ret != 'C') {
			break;
		}
	}
	if (ret == '#') {
		printf("玩家1赢\n");
	}
	else if (ret == '*') {
		printf("玩家2赢\n");
	}
	else if (ret == 'Q') {
		printf("平局\n");
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
		printf("玩游戏：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出\n");
			break;
		}
	} while (input);
}


int main()
{
	test();
	return 0;
}