#define _CRT_SECURE_NO_WARNINGS
#include "linklist.h"

//初始化链表
//函数返回值的 创建好的链表的头文件
Node* init_Linklist() {
	Node* pHeader = malloc(sizeof(Node));
	if (pHeader == NULL) {
		return;
	}
	//头节点不维护数据域
	pHeader->data = -1;
	pHeader->next = NULL;

	//创建尾节点指针，用于记录当前的链表尾部的节点位置，方便做尾插
	Node* pTail = pHeader;
	int val = -1;
	while (1) {
		printf("请插入数据，输入-1代表结束");
		scanf("%d", &val);
		if (val == -1) {
			break;
		}
		//创建新节点
		Node* newNode = malloc(sizeof(Node));
		if (newNode == NULL) {
			// 处理分配失败，例如打印错误并退出循环
			printf("内存分配失败！\n");
			break;
		}
		newNode->data = val;
		newNode->next = NULL;

		//更新节点指向
		pTail->next = newNode;
		pTail = newNode;
	}
	//返回给用户
	return pHeader;
}

//遍历列表
void foreach_Linklist(Node* pHeader) {
	if (pHeader == NULL) {
		return;
		}
	//当前节点，指向第一个有真实数据的节点
	Node* pCurrent = pHeader->next;
	while (pCurrent != NULL) {
		printf("%d\n", pCurrent->data);
		pCurrent = pCurrent->next;
	}
}  

//插入节点功能
void insert_Linklist(Node* pHeader, int oldVal, int newVal) {
	if (pHeader == NULL) {
		return;
	}
	//创建两个临时的指针，来实现节点的插入
	Node* pPrev = pHeader;
	Node* pCurrent = pHeader->next;
	while (pCurrent != NULL) {
		if (pCurrent->data == oldVal) {
			break;
		}
		//两个辅助指针向后移动
		pPrev = pCurrent;
		pCurrent = pCurrent->next;
	}
		//创建新节点
	Node* newNode = malloc(sizeof(Node));
	newNode->data = newVal;
	newNode->next = NULL;
		//更改指针时间
	newNode->next = pCurrent;
	pPrev->next = newNode;
}

//删除节点功能，不删除头文件，加入节点
void delete_Linklist(Node* pHeader, int delVal) {
	if (pHeader == NULL) {
		perror("delete_Linklist");
		return EXIT_FAILURE;
	}
	//创建两个临时的指针，pHeader为要删除的节点
	Node* pPrev = pHeader;
	Node* pCurrent = pHeader->next;
	while (pCurrent != NULL) {
		if (pCurrent->data == delVal) {
			break;
		}
		//两个辅助指针向后移动
		pPrev = pCurrent;
		pCurrent = pCurrent->next;
	}
	if (pCurrent == NULL) {  //没有找到目标节点
		printf("没有找到目标为%d的节点\n", delVal);
		return EXIT_FAILURE;
	}
	//找到了，更改指针指针指向，到下一个节点
	pPrev->next = pCurrent->next;
	//删除节点
	free(pCurrent);
	pCurrent = NULL;

}

//清空链表,包括删除头文件，删除后不能加入节点
void clear_Linklist(Node* pHeader) {
	if (pHeader == NULL) {
		perror("delete_Linklist");
		return EXIT_FAILURE;
	}
	//创建临时节点
	Node* pCurrent = pHeader->next;
	while (pCurrent != NULL) {
		//先记录下一个节点的位置
		Node* nextNode = pCurrent->next;
		//释放当前位置的节点
		free(pCurrent);
		//移动到下一个节点位置
		pCurrent = nextNode;
	}
	//清空完带有数据的节点后，头节点nex置空
	pHeader->next = NULL;
}

//销毁列表
void destory_Linklist(Node* pHeader) {
	if (pHeader == NULL) {
		perror("delete_Linklist");
		return EXIT_FAILURE;
	}
	//先清空列表
	clear_Linklist(pHeader);
	free(pHeader);
	pHeader = NULL;

}	


//反转链表
void reverse_Linklist(Node* pHeader) {
		if (pHeader == NULL) {
		perror("reverse_Linklist");
		return EXIT_FAILURE;
	}
	//创建三个临时节点
	Node* pPrev = NULL;
	Node* pCurrent = pHeader->next;
	Node* pNext = NULL;
	while (pCurrent != NULL) {
		//先记录下一个节点的位置
		pNext = pCurrent->next;
		//更改当前节点的指针域
		pCurrent->next = pPrev;
		//三个指针向后移动
		pPrev = pCurrent;
		pCurrent = pNext;
	}
	//循环结束后，pPrev指向最后一个节点
	pHeader->next = pPrev;
}



//统计链表节点个数
int count_Linklist(Node* pHeader){
	if (pHeader == NULL) {
		perror("count_Linklist");
		return EXIT_FAILURE;
	}
	int count = 0;
	//当前节点，指向第一个有真实数据的节点
	Node* pCurrent = pHeader->next;
	while (pCurrent != NULL) {
		count++;
		pCurrent = pCurrent->next;
	}
	return count;
}