#define _CRT_SECURE_NO_WARNINGS
#include "linklist.h"


void test01() {
	//��ʼ������
	Node* pHeader = init_Linklist();
	//�����Ľ��
	printf("�����Ľ��Ϊ��\n");
	foreach_Linklist(pHeader);
	//���Բ������� 20 21
	insert_Linklist(pHeader, 20,100);
	insert_Linklist(pHeader, 21, 200);
	//����ڵ�
	printf("����ڵ�󣬱����Ľ��Ϊ��\n");
	//100 20 200 21
	foreach_Linklist(pHeader);
	//ɾ���ڵ�
	delete_Linklist(pHeader, 2000);
	delete_Linklist(pHeader, 200);
	printf("ɾ���ڵ�󣬱����Ľ��Ϊ��\n");
	// 20 21
	foreach_Linklist(pHeader);
	//�������
	clear_Linklist(pHeader);
	printf("ɾ���ڵ�󣬱����Ľ��Ϊ��\n");
	foreach_Linklist(pHeader);
	//���²���ڵ�
	insert_Linklist(pHeader, 100, 100);
	insert_Linklist(pHeader, 200, 200);
	printf("���²���ڵ�󣬱����Ľ��Ϊ��\n");
	foreach_Linklist(pHeader);
	//��������
	destory_Linklist(pHeader);
	printf("���²���ڵ�\n");
	insert_Linklist(pHeader, 100, 100);
	insert_Linklist(pHeader, 200, 200);
	printf("��������󣬱����Ľ��Ϊ��\n");
	foreach_Linklist(pHeader);

}

void test02() {
	//��ʼ������
	Node* pHeader = init_Linklist();
	//�����Ľ��
	printf("����תǰ���Ϊ��\n");
	foreach_Linklist(pHeader);
	//��ת����
	reverse_Linklist(pHeader);
	printf("��ת����󣬱����Ľ��Ϊ��\n");
	foreach_Linklist(pHeader);
	//��������
	/*destory_Linklist(pHeader);*/
	//��ǰ����Ľڵ����
	int count = count_Linklist(pHeader);
	printf("��ǰ����Ľڵ����Ϊ��%d\n", count);
}


int main()
{
	/*test01();*/
	test02();
	system("pause");
	return EXIT_SUCCESS;
}


