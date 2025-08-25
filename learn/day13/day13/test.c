#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//静态链表
typedef struct Node {
	int data;
	struct Node* next;
} Node;
void test01() {
	//节点的创建
	Node node1 = { 10,NULL };
	Node node2 = { 20,NULL };
	Node node3 = { 30,NULL };
	Node node4 = { 40,NULL };
	Node node5 = { 50,NULL };

	//建立节点的关系
	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;

	//遍历链表
	Node* pCurrent = &node1;
	while (pCurrent != NULL) {
		printf("%d\n", pCurrent->data);
		pCurrent = pCurrent->next;

	}
}

//动态链表
void test02() {
    // 给每个节点分配内存并检查是否成功
    Node* node1 = malloc(sizeof(Node));
    Node* node2 = malloc(sizeof(Node));
    Node* node3 = malloc(sizeof(Node));
    Node* node4 = malloc(sizeof(Node));
    Node* node5 = malloc(sizeof(Node));

    // 检查内存分配是否成功
    if (!node1 || !node2 || !node3 || !node4 || !node5) {
        fprintf(stderr, "Memory allocation failed\n");
        free(node1); free(node2); free(node3); free(node4); free(node5);
        return;
    }

    // 正确建立节点关系和赋值
    node1->data = 10;
    node1->next = node2;

    node2->data = 20;
    node2->next = node3;  

    node3->data = 30;
    node3->next = node4; 

    node4->data = 40;
    node4->next = node5;  

    node5->data = 50;
    node5->next = NULL;

    // 遍历链表：使用当前节点的数据
    Node* pCurrent = node1;
    while (pCurrent != NULL) {
        printf("%d\n", pCurrent->data);  
        pCurrent = pCurrent->next;
    }

    // 释放内存
    pCurrent = node1;
    while (pCurrent != NULL) {
        Node* temp = pCurrent;
        pCurrent = pCurrent->next;
        free(temp);
    }
}



int main()
{

	test01();
	test02();
	system("pause");
	return EXIT_SUCCESS;
}