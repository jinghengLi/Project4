#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <errno.h>
#include <Windows.h>
#include <time.h>

//配置信息结构体
struct ConfigInfo {
	char key[64];
	char value[64];
};



//获取文件有效行数
int getFileLines(const char* filePath);

//判断传入的数据是否有效
int isvalidLines(char* str);

//文件解析放到数组中
void parseFile(const char* filePath, int lines, struct ConfigInfo** configinfo);

//根据key获取对应value
char* getValueByKey(char* key, struct ConfigInfo* configInfo, int lines);

//释放内存
void freeSpace(struct ConfigInfo* configinfo);