#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

typedef struct Player {
	char name[20]; //����
	int level; //�ȼ�
	int exep; //����
} Player;


//��ʼ����Ϸ             ����һ������ָ�룬����������������
void Init_GAME_Company1(char** player, char* name);

//����ս�������ս����������1�����򷵻�0
int FIGHT_GAME_Company1(void* player, int gameDiff);

//�鿴�����Ϣ
void PRINT_GAME_Company1(void* player);

//�뿪��Ϸ
void EXIT_GAME_Company1(void* player);

//�ж��Ƿ�����
int isLevelUp(int WinRate, int diff_level);