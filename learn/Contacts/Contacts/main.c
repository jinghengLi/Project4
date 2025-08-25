#define _CRT_SECURE_NO_WARNINGS
#include "Contacts.h"
void menu() {
	printf("***********************************************\n");
	printf("************    1.添加联系人     **************\n");
	printf("************    2.删除联系人     **************\n");
	printf("************    3.查找联系人     **************\n");
	printf("************    4.修改联系人     **************\n");
	printf("************    5.查看联系人     **************\n");
	printf("************    6.排序联系人     **************\n");
	printf("************    0.退出通讯录     **************\n");
	printf("***********************************************\n");
}



int main() {
	int input = 0;
	char name[] = { 0 };
	Contact con;     //创建通讯录（包含联系人信息和记录）
	InitContact(&con);   //初始化通讯录
	do {
		menu();
		printf("请输入你的选择:>");
		scanf("%d", &input);
		switch (input) {
		case 1:
			AddContact(&con);
			break;
		case 2:
			DelContact(&con);
			break;
		case 3:
			SearchContact(&con);
			break;
		case 4:
			ModifyContact(&con);
			break;
		case 5:
			ShowContact(&con);
			break;
		case 6:
			SortContact(&con);
			break;
		case 0:
			SaveContact(&con);
			DestroyContact(&con);
			printf("正在退出通讯录");
			break;
		default:
			printf("输入错误，请重新输入");
			break;
		}
	} while (input);
	return 0;
}