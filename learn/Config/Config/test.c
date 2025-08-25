#define _CRT_SECURE_NO_WARNINGS
#include "config.h"
#include "code.h"


int main()
{
	srand((unsigned int)time(NULL));
	SetConsoleOutputCP(CP_UTF8);
	int lines = getFileLines("config.txt");
	printf("%d\n", lines);
	//�ļ������ŵ������У�malloc(sizeof(struct ConfigInfp)*5)
	struct ConfigInfo* configinfo = NULL;
	//�ļ������ŵ�������
	parseFile("config.txt", lines, &configinfo);
	//����key��ȡ��Ӧvalue
	printf("ID= %s\n", getValueByKey("hero", configinfo, lines));
	printf("NAME = %s\n", getValueByKey("heroName", configinfo, lines));
	printf("ATTACK = %s\n", getValueByKey("heroAtk", configinfo, lines));
	printf("DEFENDER = %s\n", getValueByKey("heroDef", configinfo, lines));
	printf("INFO = %s\n", getValueByKey("heroInfo", configinfo, lines));
	//����
	codeFile("config.txt", "�����ļ�.txt");
	decodeFile("�����ļ�.txt", "�����ļ�.txt");
	//�ͷ��ڴ� 
	free(configinfo);
	configinfo = NULL;
	system("pause");
	return EXIT_SUCCESS;
}