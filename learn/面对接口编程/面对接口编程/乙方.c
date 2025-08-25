#include "gameCompany1.h"

//初始化游戏             参数一：人物指针，参数二：任务姓名
void Init_GAME_Company1(char** p1, char* name) {
	Player* player = (Player*)malloc(sizeof(Player));
	if(player == NULL) {
		printf("内存分配失败！\n");
		return NULL;
	}
	*p1 = player;
	strcpy(player->name, name);//姓名
	player->level = 1; //等级
	player->exep = 0; //经验
	printf("游戏初始化成功！\n");
}

//判断是否升级
int isLevelUp(int WinRate, int diff_level) {
	int randNum = rand() % 100 + 1; //生成1-100的随机数
	if(randNum <= WinRate) {
		return diff_level*10; //升级
	} else {
		return 0; //不升级
	}
}

//核心战斗，如果战斗结束返回1，否则返回0
int FIGHT_GAME_Company1(void* p, int gameDiff) {
	Player* player= (Player*)p;
	if(player == NULL) {
		printf("玩家信息为空，无法进行战斗！\n");
		return 0;
	}
	int winExp = 0; //胜利经验
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
			printf("无效的游戏难度！\n");
			break;
	}
	//将经验加到玩家身上
	player->exep += winExp;
	player->level  = player->exep / 10; 
	if (winExp > 0) {
		return 1; //战斗胜利
	} else {
		return 0; //战斗失败
	}
}

//查看玩家信息
void PRINT_GAME_Company1(void* player) {
	Player* p = (Player*)player;
	if(p == NULL) {
		printf("玩家信息为空，无法查看！\n");
		return;
	}
	printf("玩家姓名：%s\n", p->name);
	printf("玩家等级：%d\n", p->level);
	printf("玩家经验：%d\n", p->exep);
}

//离开游戏
void EXIT_GAME_Company1(void* player) {
	if(player != NULL) {
		free(player);
		player = NULL;
	}
	printf("退出游戏，释放资源成功！\n");

}