#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

typedef struct Player {
	char name[20]; //姓名
	int level; //等级
	int exep; //经验
} Player;


//初始化游戏             参数一：人物指针，参数二：任务姓名
void Init_GAME_Company1(char** player, char* name);

//核心战斗，如果战斗结束返回1，否则返回0
int FIGHT_GAME_Company1(void* player, int gameDiff);

//查看玩家信息
void PRINT_GAME_Company1(void* player);

//离开游戏
void EXIT_GAME_Company1(void* player);

//判断是否升级
int isLevelUp(int WinRate, int diff_level);