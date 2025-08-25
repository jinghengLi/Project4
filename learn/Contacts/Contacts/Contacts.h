#pragma once
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#define MAX 200
#define DEFAULT_SZ 3
#define INC_SZ 2

typedef struct PerInfo {            //������ϵ����Ϣ�ṹ��
	char name[20];
	int age;
	char gender[10];
	char tel[20];
	char relat[10];
	char addr[30];
} PerInfo;

//��̬�汾
//typedef struct Contact {       //ͨѶ¼�ṹ��
//	PerInfo data[MAX];   //�����ϵ����Ϣ
//	int count;        //��¼��ǰͨѶ¼��ʵ������
//} Contact;

//��̬�汾
typedef struct Contact {       //ͨѶ¼�ṹ��
	PerInfo* data;      //�����ϵ����Ϣ
	int count;        //��¼��ǰͨѶ¼��ʵ������
	int capacity;
} Contact;


//��ʼ��ͨѶ¼
int InitContact(Contact* pc);

void AddContact(Contact* pc);
//��ʾȫ����ϵ��
void ShowContact(const Contact* pc);

//ɾ����ϵ��
void DelContact(Contact* pc);

//������ϵ��
void SearchContact(Contact* pc);

//�޸���ϵ��
void ModifyContact(Contact* pc);


//������ϵ��
void SortContact(Contact* pc);

//����ͨѶ¼
void SaveContact(const Contact* pc);

//����ͨѶ¼
void DestroyContact(Contact* pc);

//������Ϣ��ͨѶ¼
void LoadContact(Contact* pc);