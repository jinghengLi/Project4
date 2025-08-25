#include "gameCompany1.h"

//��ʼ����Ϸ             ����һ������ָ�룬����������������
void Init_GAME_Company1(char** p1, char* name) {
	Player* player = (Player*)malloc(sizeof(Player));
	if(player == NULL) {
		printf("�ڴ����ʧ�ܣ�\n");
		return NULL;
	}
	*p1 = player;
	strcpy(player->name, name);//����
	player->level = 1; //�ȼ�
	player->exep = 0; //����
	printf("��Ϸ��ʼ���ɹ���\n");
}

//�ж��Ƿ�����
int isLevelUp(int WinRate, int diff_level) {
	int randNum = rand() % 100 + 1; //����1-100�������
	if(randNum <= WinRate) {
		return diff_level*10; //����
	} else {
		return 0; //������
	}
}

//����ս�������ս����������1�����򷵻�0
int FIGHT_GAME_Company1(void* p, int gameDiff) {
	Player* player= (Player*)p;
	if(player == NULL) {
		printf("�����ϢΪ�գ��޷�����ս����\n");
		return 0;
	}
	int winExp = 0; //ʤ������
	switch(gameDiff) {
		case 1:
			winExp = isLevelUp(80, 1);
			break;
		case 2:
			winExp = isLevelUp(60, 2);
			break;
		case 3:
			winExp = isLevelUp(40, 3);
			break;
		default:
			printf("��Ч����Ϸ�Ѷȣ�\n");
			break;
	}
	//������ӵ��������
	player->exep += winExp;
	player->level  = player->exep / 10; 
	if (winExp > 0) {
		return 1; //ս��ʤ��
	} else {
		return 0; //ս��ʧ��
	}
}

//�鿴�����Ϣ
void PRINT_GAME_Company1(void* player) {
	Player* p = (Player*)player;
	if(p == NULL) {
		printf("�����ϢΪ�գ��޷��鿴��\n");
		return;
	}
	printf("���������%s\n", p->name);
	printf("��ҵȼ���%d\n", p->level);
	printf("��Ҿ��飺%d\n", p->exep);
}

//�뿪��Ϸ
void EXIT_GAME_Company1(void* player) {
	if(player != NULL) {
		free(player);
		player = NULL;
	}
	printf("�˳���Ϸ���ͷ���Դ�ɹ���\n");

}