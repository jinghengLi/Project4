#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <errno.h>

//节点结构体
typedef struct Node {
	int data;
	struct Node* next;
} Node;

//初始化链表
//函数返回值的 创建好的链表的头文件
Node* init_Linklist();

//遍历列表
void foreach_Linklist(Node* pHeader);

//插入节点功能
void insert_Linklist(Node* pHeader,int oldVal,int newVal);  //在旧节点前加入新节点

//删除节点功能
void delete_Linklist(Node* pHeader, int delVal);

//清空链表,包括删除头文件，删除后不能加入节点
void clear_Linklist(Node* pHeader);

//销毁列表
void destory_Linklist(Node* pHeader);

//反转链表
void reverse_Linklist(Node* pHeader);

//统计链表节点个数
int count_Linklist(Node* pHeader);