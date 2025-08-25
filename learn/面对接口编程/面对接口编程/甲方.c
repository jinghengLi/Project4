#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "gameCompany1.h"

//��ʼ����Ϸ             ����һ������ָ�룬����������������
typedef void(*Init_GAME)(char** player, char* name);

//����ս�������ս����������1�����򷵻�0
typedef int(*FIGHT_GAME)(void* player, int gameDiff);

//�鿴�����Ϣ
typedef void(*PRINT_GAME)(void* player);

//�뿪��Ϸ
typedef void(*EXIT_GAME)(void* player);

//�׷�����ʵ��
void playGame(Init_GAME init, FIGHT_GAME fightGame, PRINT_GAME printGame, EXIT_GAME exitGame) {
	//��ʼ��
	void* player = NULL;
	printf("��������Ľ�ɫ���ƣ�\n");
	char name[20];
	scanf("%s", name);
	init(&player, name);
	int gameDiff = -1;

	while (1) {
		getchar(); //�Ե��س�
		system("cls");
		printf("��ѡ����Ϸ�Ѷȣ�1.�� 2.��ͨ 3.����\n");

		scanf("%d", &gameDiff);
		getchar(); //�Ե��س�
		int ret = fightGame(player, gameDiff);
		if (ret == 1) {
			printf("��ϲ�㣬��ս�ɹ���\n");
			printf("��ǰ��ɫ��Ϣ���£�\n");
			printGame(player);
		}
		else {
			printf("��սʧ�ܣ���Ϸ������\n");
			break;
		}
	}
	//�˳���Ϸ
	exitGame(player);
}




//����Ϸ

int main() {
	srand((unsigned int)time(NULL)); //�������������
	playGame(Init_GAME_Company1, FIGHT_GAME_Company1, PRINT_GAME_Company1, EXIT_GAME_Company1);
	system("pause");
	return EXIT_SUCCESS;	
}