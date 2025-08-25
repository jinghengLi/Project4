#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "gameCompany1.h"

//初始化游戏             参数一：人物指针，参数二：任务姓名
typedef void(*Init_GAME)(char** player, char* name);

//核心战斗，如果战斗结束返回1，否则返回0
typedef int(*FIGHT_GAME)(void* player, int gameDiff);

//查看玩家信息
typedef void(*PRINT_GAME)(void* player);

//离开游戏
typedef void(*EXIT_GAME)(void* player);

//甲方功能实现
void playGame(Init_GAME init, FIGHT_GAME fightGame, PRINT_GAME printGame, EXIT_GAME exitGame) {
	//初始化
	void* player = NULL;
	printf("请输入你的角色名称：\n");
	char name[20];
	scanf("%s", name);
	init(&player, name);
	int gameDiff = -1;

	while (1) {
		getchar(); //吃掉回车
		system("cls");
		printf("请选择游戏难度：1.简单 2.普通 3.困难\n");

		scanf("%d", &gameDiff);
		getchar(); //吃掉回车
		int ret = fightGame(player, gameDiff);
		if (ret == 1) {
			printf("恭喜你，挑战成功！\n");
			printf("当前角色信息如下：\n");
			printGame(player);
		}
		else {
			printf("挑战失败，游戏结束！\n");
			break;
		}
	}
	//退出游戏
	exitGame(player);
}




//玩游戏

int main() {
	srand((unsigned int)time(NULL)); //设置随机数种子
	playGame(Init_GAME_Company1, FIGHT_GAME_Company1, PRINT_GAME_Company1, EXIT_GAME_Company1);
	system("pause");
	return EXIT_SUCCESS;	
}