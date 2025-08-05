#pragma once
#include <stdio.h>
#define ROW 10
#define COL 10

// 初始化五子棋棋盘
void Initboard(char board[ROW ][COL ], int row, int col);
// 打印五子棋棋盘
void Printboard(char board[ROW][COL], int row, int col);
// 五子棋玩家下棋
void Playmove(char board[ROW][COL], int row, int col);
// 五子棋电脑下棋
void Commove(char board[ROW][COL], int row, int col);
//五子棋判断输赢
int IsWin(char board[ROW][COL], int row, int col);
// 五子棋判断平局
int IsFull(char board[ROW][COL], int row, int col);