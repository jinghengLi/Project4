#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <errno.h>
#include <Windows.h>
#include <time.h>

//������Ϣ�ṹ��
struct ConfigInfo {
	char key[64];
	char value[64];
};



//��ȡ�ļ���Ч����
int getFileLines(const char* filePath);

//�жϴ���������Ƿ���Ч
int isvalidLines(char* str);

//�ļ������ŵ�������
void parseFile(const char* filePath, int lines, struct ConfigInfo** configinfo);

//����key��ȡ��Ӧvalue
char* getValueByKey(char* key, struct ConfigInfo* configInfo, int lines);

//�ͷ��ڴ�
void freeSpace(struct ConfigInfo* configinfo);