#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//��̬����
typedef struct Node {
	int data;
	struct Node* next;
} Node;
void test01() {
	//�ڵ�Ĵ���
	Node node1 = { 10,NULL };
	Node node2 = { 20,NULL };
	Node node3 = { 30,NULL };
	Node node4 = { 40,NULL };
	Node node5 = { 50,NULL };

	//�����ڵ�Ĺ�ϵ
	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;

	//��������
	Node* pCurrent = &node1;
	while (pCurrent != NULL) {
		printf("%d\n", pCurrent->data);
		pCurrent = pCurrent->next;

	}
}

//��̬����
void test02() {
    // ��ÿ���ڵ�����ڴ沢����Ƿ�ɹ�
    Node* node1 = malloc(sizeof(Node));
    Node* node2 = malloc(sizeof(Node));
    Node* node3 = malloc(sizeof(Node));
    Node* node4 = malloc(sizeof(Node));
    Node* node5 = malloc(sizeof(Node));

    // ����ڴ�����Ƿ�ɹ�
    if (!node1 || !node2 || !node3 || !node4 || !node5) {
        fprintf(stderr, "Memory allocation failed\n");
        free(node1); free(node2); free(node3); free(node4); free(node5);
        return;
    }

    // ��ȷ�����ڵ��ϵ�͸�ֵ
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

    // ��������ʹ�õ�ǰ�ڵ������
    Node* pCurrent = node1;
    while (pCurrent != NULL) {
        printf("%d\n", pCurrent->data);  
        pCurrent = pCurrent->next;
    }

    // �ͷ��ڴ�
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