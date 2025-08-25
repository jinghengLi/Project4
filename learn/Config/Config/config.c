#define _CRT_SECURE_NO_WARNINGS
#include "config.h"


//判断传入的数据是否有效
int isvalidLines(char* str) {
	if (str[0] == '\0' || strchr(str, ':') == NULL) {
		return 0;
	}
	return 1;
}

//获取文件有效行数
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




//文件解析放到数组中
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
	char buf[1024] = { 0 };  //将每行数据放到buf中
	while (fgets(buf, 1024, file) != NULL) {
		if (isvalidLines(buf	)) {
			memset(config[index].key, 0, 64);   //清空数据
			memset(config[index].value, 0, 64);
			char* pos = strchr(buf,':');
			strncpy(config[index].key, buf, pos-buf);   //pos为':'位置
			strncpy(config[index].value, pos+1, strlen(pos + 1) - 1);  //-1是去除换行符，pos+1为value起始位置
			index++;
			}
		memset(buf, 0, 1024);
	}
	*configinfo = config;
}

//根据key获取对应value
char* getValueByKey(char* key, struct ConfigInfo* configInfo, int lines) {
	for (int i = 0; i < lines; i++) {
		if (strcmp(configInfo[i].key, key) == 0) {
			return configInfo[i].value;
			}
		}
	return NULL;
}

//释放内存
void freeSpace(struct ConfigInfo* configinfo) {
	if (configinfo == NULL) {
		perror("fopen");
		return EXIT_FAILURE;
		}
	free(configinfo);
	configinfo = NULL;
}