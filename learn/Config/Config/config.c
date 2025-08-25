#define _CRT_SECURE_NO_WARNINGS
#include "config.h"


//�жϴ���������Ƿ���Ч
int isvalidLines(char* str) {
	if (str[0] == '\0' || strchr(str, ':') == NULL) {
		return 0;
	}
	return 1;
}

//��ȡ�ļ���Ч����
int getFileLines(const char* filePath) {
	FILE* file = fopen(filePath, "rb+");
	if (file == NULL) {
		perror("fopen");
		return EXIT_FAILURE;
	}
	char buf[1024] = { 0 };
	int lines = 0;
	while (fgets(buf, 1024, file) != NULL) {
		if (isvalidLines(buf)) {
			lines++;
		}
	}
	return lines;
	fclose(file);
}




//�ļ������ŵ�������
void parseFile(const char* filePath, int lines, struct ConfigInfo** configinfo) {
	struct ConfigInfo* config = malloc(sizeof(struct ConfigInfo) * lines);
	if (config == NULL) {
		perror("parseFile");
		return EXIT_FAILURE;
	}
	FILE* file = fopen(filePath, "r");
	if (file == NULL) {
		perror("fopen");
		return EXIT_FAILURE;
	}
	int index = 0;
	char buf[1024] = { 0 };  //��ÿ�����ݷŵ�buf��
	while (fgets(buf, 1024, file) != NULL) {
		if (isvalidLines(buf	)) {
			memset(config[index].key, 0, 64);   //�������
			memset(config[index].value, 0, 64);
			char* pos = strchr(buf,':');
			strncpy(config[index].key, buf, pos-buf);   //posΪ':'λ��
			strncpy(config[index].value, pos+1, strlen(pos + 1) - 1);  //-1��ȥ�����з���pos+1Ϊvalue��ʼλ��
			index++;
			}
		memset(buf, 0, 1024);
	}
	*configinfo = config;
}

//����key��ȡ��Ӧvalue
char* getValueByKey(char* key, struct ConfigInfo* configInfo, int lines) {
	for (int i = 0; i < lines; i++) {
		if (strcmp(configInfo[i].key, key) == 0) {
			return configInfo[i].value;
			}
		}
	return NULL;
}

//�ͷ��ڴ�
void freeSpace(struct ConfigInfo* configinfo) {
	if (configinfo == NULL) {
		perror("fopen");
		return EXIT_FAILURE;
		}
	free(configinfo);
	configinfo = NULL;
}