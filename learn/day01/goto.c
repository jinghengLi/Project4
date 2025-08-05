//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//int main()
//{
//	printf("hehe\n");
//	goto again;//next可以是其他标识符，也可以是数字常量
//	printf("haha\n");
//	goto next;
//next:
//	printf("跳过了haha的打印\n");
//	printf("程序继续执行\n");
//again:
//	printf("程序结束\n");
//	return 0;
//}
//
////程序的执行流程如下：
////打印 “hehe”。
////goto again; 使程序跳转到 again : 标签处。
////执行 again : 标签下的 printf("程序结束\n"); ，输出 “程序结束”。
////程序结束。
////因此，goto again; 之后的所有代码都不会执行，因为程序已经跳转到 again : 标签并在此结束。