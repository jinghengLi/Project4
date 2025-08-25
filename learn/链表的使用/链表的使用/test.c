#define _CRT_SECURE_NO_WARNINGS
#include "linklist.h"


void test01() {
	//初始化链表
	Node* pHeader = init_Linklist();
	//遍历的结果
	printf("遍历的结果为：\n");
	foreach_Linklist(pHeader);
	//测试插入数据 20 21
	insert_Linklist(pHeader, 20,100);
	insert_Linklist(pHeader, 21, 200);
	//插入节点
	printf("插入节点后，遍历的结果为：\n");
	//100 20 200 21
	foreach_Linklist(pHeader);
	//删除节点
	delete_Linklist(pHeader, 2000);
	delete_Linklist(pHeader, 200);
	printf("删除节点后，遍历的结果为：\n");
	// 20 21
	foreach_Linklist(pHeader);
	//清空链表
	clear_Linklist(pHeader);
	printf("删除节点后，遍历的结果为：\n");
	foreach_Linklist(pHeader);
	//重新插入节点
	insert_Linklist(pHeader, 100, 100);
	insert_Linklist(pHeader, 200, 200);
	printf("重新插入节点后，遍历的结果为：\n");
	foreach_Linklist(pHeader);
	//销毁链表
	destory_Linklist(pHeader);
	printf("重新插入节点\n");
	insert_Linklist(pHeader, 100, 100);
	insert_Linklist(pHeader, 200, 200);
	printf("销毁链表后，遍历的结果为：\n");
	foreach_Linklist(pHeader);

}

void test02() {
	//初始化链表
	Node* pHeader = init_Linklist();
	//遍历的结果
	printf("链表反转前结果为：\n");
	foreach_Linklist(pHeader);
	//反转链表
	reverse_Linklist(pHeader);
	printf("反转链表后，遍历的结果为：\n");
	foreach_Linklist(pHeader);
	//销毁链表
	/*destory_Linklist(pHeader);*/
	//当前链表的节点个数
	int count = count_Linklist(pHeader);
	printf("当前链表的节点个数为：%d\n", count);
}


int main()
{
	/*test01();*/
	test02();
	system("pause");
	return EXIT_SUCCESS;
}


