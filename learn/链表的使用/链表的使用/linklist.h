#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <errno.h>

//�ڵ�ṹ��
typedef struct Node {
	int data;
	struct Node* next;
} Node;

//��ʼ������
//��������ֵ�� �����õ������ͷ�ļ�
Node* init_Linklist();

//�����б�
void foreach_Linklist(Node* pHeader);

//����ڵ㹦��
void insert_Linklist(Node* pHeader,int oldVal,int newVal);  //�ھɽڵ�ǰ�����½ڵ�

//ɾ���ڵ㹦��
void delete_Linklist(Node* pHeader, int delVal);

//�������,����ɾ��ͷ�ļ���ɾ�����ܼ���ڵ�
void clear_Linklist(Node* pHeader);

//�����б�
void destory_Linklist(Node* pHeader);

//��ת����
void reverse_Linklist(Node* pHeader);

//ͳ������ڵ����
int count_Linklist(Node* pHeader);