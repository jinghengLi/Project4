#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void menu() {
	printf("***********************************\n");
	printf("*********     1.play   ************\n");
	printf("*********     0.exit     ************\n");
	printf("**********************************\n");

}

void game() {
	char board[ROW][COL];
	// 初始化五子棋棋盘
	Initboard(board, ROW, COL);
	// 打印五子棋棋盘
	while (1) {
		int result = IsWin(board, ROW, COL);  // 用于存储游戏结果
		Printboard(board, ROW, COL);
		// 五子棋玩家下棋
		if (result != 'C') {
			if (result == 'X') {
				printf("玩家获胜！\n");
				break;
			}
			else if (result == 'O') {
				printf("电脑获胜！\n");
				break;
			}
			else if (result == 'Q') {
				printf("平局！\n");
				break;
			}
			break; // 游戏结束
		}
		Playmove(board, ROW, COL);
		// 打印五子棋棋盘
		Printboard(board, ROW, COL);
		//五子棋电脑下棋
		Commove(board, ROW, COL);
	}

}



int  main() {
	int choice = 0;
	srand((unsigned int)time(NULL));  // 初始化随机数种子
	do
	{
		menu();  //打印菜单
		printf("请选择：>");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			game();  //调用游戏函数
			//这里可以调用游戏的函数
			break;
		case 0:
			printf("退出游戏\n");
			return 0;
		default:
			printf("输入错误，请重新选择！\n");
			break;
		}
	} while (choice);
	return 0;
}