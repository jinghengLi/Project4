#define _CRT_SECURE_NO_WARNINGS
#include "config.h"
#include "code.h"


int main()
{
	srand((unsigned int)time(NULL));
	SetConsoleOutputCP(CP_UTF8);
	int lines = getFileLines("config.txt");
	printf("%d\n", lines);
	//文件解析放到数组中，malloc(sizeof(struct ConfigInfp)*5)
	struct ConfigInfo* configinfo = NULL;
	//文件解析放到数组中
	parseFile("config.txt", lines, &configinfo);
	//根据key获取对应value
	printf("ID= %s\n", getValueByKey("hero", configinfo, lines));
	printf("NAME = %s\n", getValueByKey("heroName", configinfo, lines));
	printf("ATTACK = %s\n", getValueByKey("heroAtk", configinfo, lines));
	printf("DEFENDER = %s\n", getValueByKey("heroDef", configinfo, lines));
	printf("INFO = %s\n", getValueByKey("heroInfo", configinfo, lines));
	//加密
	codeFile("config.txt", "加密文件.txt");
	decodeFile("加密文件.txt", "解密文件.txt");
	//释放内存 
	free(configinfo);
	configinfo = NULL;
	system("pause");
	return EXIT_SUCCESS;
}