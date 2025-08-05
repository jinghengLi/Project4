#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void Initboard(char board[ROW][COL], int row, int col) {


	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			board[i][j] = ' ';
		}
	}
}

void Printboard(char board[ROW][COL], int row, int col) {
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf(" %c ", board[i][j]);
			if (j < col - 1) {
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1) {
			for (j = 0; j < col; j++) {
				printf("---");
				if (j < col - 1) {
					printf("+");
				}
			}
			printf("\n");
		}
	}
}

void Playmove(char board[ROW][COL], int row, int col) {

	int x = 0;
	int y = 0;
	while (1) {
		printf("玩家下棋，请输入坐标（行 列）：");
		scanf("%d %d", &x, &y);
		if (x < 0 || x >= row || y < 0 || y >= col || board[x][y] != ' ') {
			printf("输入错误，请重新输入！\n");
			continue;
		}
		board[x][y] = 'X'; // 玩家用 'X' 下棋
		break;
	}

}


void Commove(char board[ROW][COL], int row, int col) {
	int x = 0;
	int y = 0;
	while (1) {
		x = rand() % row; // 随机生成行坐标
		y = rand() % col; // 随机生成列坐标
		if (board[x][y] == ' ') { // 如果该位置为空
			board[x][y] = 'O'; // 电脑用 '#' 下棋
			printf("电脑下棋，坐标为：%d %d\n", x, y);
			break;
		}
	}

}

int IsWin(char board[ROW][COL], int row, int col) {
	// 检查行
	for (int i = 0; i < row; i++) {
		for (int j = 0; j <= col - 5; j++) {
			if (board[i][j] != ' ' && board[i][j] == board[i][j + 1] && 
				board[i][j] == board[i][j + 2] && board[i][j] == board[i][j + 3] && 
				board[i][j] == board[i][j + 4]) {
				return board[i][j]; // 有玩家获胜
			}
		}
	}
	// 检查列
	for (int j = 0; j < col; j++) {
		for (int i = 0; i <= row - 5; i++) {
			if (board[i][j] != ' ' && board[i][j] == board[i + 1][j] && 
				board[i][j] == board[i + 2][j] && board[i][j] == board[i + 3][j] && 
				board[i][j] == board[i + 4][j]) {
				return board[i][j]; // 有玩家获胜
			}
		}
	}
	// 检查主对角线
	for (int i = 0; i <= row - 5; i++) {
		for (int j = 0; j <= col - 5; j++) {
			if (board[i][j] != ' ' && board[i][j] == board[i + 1][j + 1] && 
				board[i][j] == board[i + 2][j + 2] && board[i][j] == board[i + 3][j + 3] && 
				board[i][j] == board[i + 4][j + 4]) {
				return board[i][j]; // 有玩家获胜
			}
		}
	}
	// 检查副对角线
	for (int i = 0; i <= row - 5; i++) {
		for (int j = 4; j < col; j++) {
			if (board[i][j] != ' ' && board[i][j] == board[i + 1][j - 1] && 
				board[i][j] == board[i + 2][j - 2] && board[i][j] == board[i + 3][j - 3] && 
				board[i][j] == board[i + 4][j - 4]) {
				return board[i][j]; // 有玩家获胜
			}
		}
	}
	
	// 检查是否平局
	if (IsFull(board, row, col)) {
		return 'Q'; // 平局
	}
	return 'C'; // 游戏继续进行
}

int IsFull(char board[ROW][COL], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (board[i][j] == ' ') {
				return 0; // 棋盘未满
			}
		}
	}
	return 1; // 棋盘已满
}