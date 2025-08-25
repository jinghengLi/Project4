#define _CRT_SECURE_NO_WARNINGS
#include "linklist.h"

//��ʼ������
//��������ֵ�� �����õ������ͷ�ļ�
Node* init_Linklist() {
	Node* pHeader = malloc(sizeof(Node));
	if (pHeader == NULL) {
		return;
	}
	//ͷ�ڵ㲻ά��������
	pHeader->data = -1;
	pHeader->next = NULL;

	//����β�ڵ�ָ�룬���ڼ�¼��ǰ������β���Ľڵ�λ�ã�������β��
	Node* pTail = pHeader;
	int val = -1;
	while (1) {
		printf("��������ݣ�����-1�������");
		scanf("%d", &val);
		if (val == -1) {
			break;
		}
		//�����½ڵ�
		Node* newNode = malloc(sizeof(Node));
		if (newNode == NULL) {
			// �������ʧ�ܣ������ӡ�����˳�ѭ��
			printf("�ڴ����ʧ�ܣ�\n");
			break;
		}
		newNode->data = val;
		newNode->next = NULL;

		//���½ڵ�ָ��
		pTail->next = newNode;
		pTail = newNode;
	}
	//���ظ��û�
	return pHeader;
}

//�����б�
void foreach_Linklist(Node* pHeader) {
	if (pHeader == NULL) {
		return;
		}
	//��ǰ�ڵ㣬ָ���һ������ʵ���ݵĽڵ�
	Node* pCurrent = pHeader->next;
	while (pCurrent != NULL) {
		printf("%d\n", pCurrent->data);
		pCurrent = pCurrent->next;
	}
}  

//����ڵ㹦��
void insert_Linklist(Node* pHeader, int oldVal, int newVal) {
	if (pHeader == NULL) {
		return;
	}
	//����������ʱ��ָ�룬��ʵ�ֽڵ�Ĳ���
	Node* pPrev = pHeader;
	Node* pCurrent = pHeader->next;
	while (pCurrent != NULL) {
		if (pCurrent->data == oldVal) {
			break;
		}
		//��������ָ������ƶ�
		pPrev = pCurrent;
		pCurrent = pCurrent->next;
	}
		//�����½ڵ�
	Node* newNode = malloc(sizeof(Node));
	newNode->data = newVal;
	newNode->next = NULL;
		//����ָ��ʱ��
	newNode->next = pCurrent;
	pPrev->next = newNode;
}

//ɾ���ڵ㹦�ܣ���ɾ��ͷ�ļ�������ڵ�
void delete_Linklist(Node* pHeader, int delVal) {
	if (pHeader == NULL) {
		perror("delete_Linklist");
		return EXIT_FAILURE;
	}
	//����������ʱ��ָ�룬pHeaderΪҪɾ���Ľڵ�
	Node* pPrev = pHeader;
	Node* pCurrent = pHeader->next;
	while (pCurrent != NULL) {
		if (pCurrent->data == delVal) {
			break;
		}
		//��������ָ������ƶ�
		pPrev = pCurrent;
		pCurrent = pCurrent->next;
	}
	if (pCurrent == NULL) {  //û���ҵ�Ŀ��ڵ�
		printf("û���ҵ�Ŀ��Ϊ%d�Ľڵ�\n", delVal);
		return EXIT_FAILURE;
	}
	//�ҵ��ˣ�����ָ��ָ��ָ�򣬵���һ���ڵ�
	pPrev->next = pCurrent->next;
	//ɾ���ڵ�
	free(pCurrent);
	pCurrent = NULL;

}

//�������,����ɾ��ͷ�ļ���ɾ�����ܼ���ڵ�
void clear_Linklist(Node* pHeader) {
	if (pHeader == NULL) {
		perror("delete_Linklist");
		return EXIT_FAILURE;
	}
	//������ʱ�ڵ�
	Node* pCurrent = pHeader->next;
	while (pCurrent != NULL) {
		//�ȼ�¼��һ���ڵ��λ��
		Node* nextNode = pCurrent->next;
		//�ͷŵ�ǰλ�õĽڵ�
		free(pCurrent);
		//�ƶ�����һ���ڵ�λ��
		pCurrent = nextNode;
	}
	//�����������ݵĽڵ��ͷ�ڵ�nex�ÿ�
	pHeader->next = NULL;
}

//�����б�
void destory_Linklist(Node* pHeader) {
	if (pHeader == NULL) {
		perror("delete_Linklist");
		return EXIT_FAILURE;
	}
	//������б�
	clear_Linklist(pHeader);
	free(pHeader);
	pHeader = NULL;

}	


//��ת����
void reverse_Linklist(Node* pHeader) {
		if (pHeader == NULL) {
		perror("reverse_Linklist");
		return EXIT_FAILURE;
	}
	//����������ʱ�ڵ�
	Node* pPrev = NULL;
	Node* pCurrent = pHeader->next;
	Node* pNext = NULL;
	while (pCurrent != NULL) {
		//�ȼ�¼��һ���ڵ��λ��
		pNext = pCurrent->next;
		//���ĵ�ǰ�ڵ��ָ����
		pCurrent->next = pPrev;
		//����ָ������ƶ�
		pPrev = pCurrent;
		pCurrent = pNext;
	}
	//ѭ��������pPrevָ�����һ���ڵ�
	pHeader->next = pPrev;
}



//ͳ������ڵ����
int count_Linklist(Node* pHeader){
	if (pHeader == NULL) {
		perror("count_Linklist");
		return EXIT_FAILURE;
	}
	int count = 0;
	//��ǰ�ڵ㣬ָ���һ������ʵ���ݵĽڵ�
	Node* pCurrent = pHeader->next;
	while (pCurrent != NULL) {
		count++;
		pCurrent = pCurrent->next;
	}
	return count;
}