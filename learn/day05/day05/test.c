#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	
#include <string.h>
int main() {
	char a[] = { 'a','b','c','d','e','f' };
	char b[] = "abcdef"; //等同于{ 'a','b','c','d','e','f','\0'};
	char* p	= "abcdef";

	//printf("%d\n", sizeof(a));   // 5
	//printf("%d\n", strlen(a));  //  a为随机值
	//printf("%d\n", sizeof(b));  //  7  sizeof中单独放数组名，这⾥的数组名表⽰整个数组，计算的是整个数组的⼤⼩
	//printf("%d\n", strlen(b));  //  6
	//printf("%d\n", sizeof(p));  // 4或8
	//printf("%d\n", strlen(p)); //6

	//printf("%d\n", sizeof(a + 0)); // 4或8
	//printf("%d\n", strlen(a + 0)); //  a为随机值
	//printf("%d\n", sizeof(b + 0)); // 4或8 表示计算首元素地址的占用内存空间
	//printf("%d\n", strlen(b + 0)); //  6
	//printf("%d\n", sizeof(p + 0)); // 4或8
	//printf("%d\n", strlen(p + 0));//6

	//printf("%d\n", sizeof(*a));  // 1
	//printf("%d\n", strlen(*a));   // 非法访问内存空间， strlen('a')=strlen(97),内存开辟未给97内存空间，地址无效
	//printf("%d\n", sizeof(*b));   // 1  解引用为a的首元素
	//printf("%d\n", strlen(*b));   // 不合法 strlen('a')=strlen(97) 
	//printf("%d\n", sizeof(*p));  //1
	//printf("%d\n", strlen(*p)); //

	//printf("%d\n", sizeof(a + 1));  // 4或8
	//printf("%d\n", strlen(a + 1));  // 随机值，比a小1
	//printf("%d\n", sizeof(b + 1));  // 4或8，第二个元素的地址
	//printf("%d\n", strlen(b + 1));  // 5 从第二个元素b到结尾
	//printf("%d\n", sizeof(p + 1));
	//printf("%d\n", strlen(p + 1));

	//printf("%zd\n", sizeof(a[0]));  //1 b的第二个元素
	//printf("%zd\n", strlen(a[0]));  // 不合法 strlen('a')=strlen(97) 
	//printf("%zd\n", sizeof(b[0]));  // 1 b的第二个元素
	//printf("%zd\n", strlen(b[0]));  // 不合法 strlen('a')=strlen(97) 
	//printf("%zd\n", sizeof(p[0]));  //
	//printf("%zd\n", strlen(p[0]));

	//printf("%d\n", sizeof(&a));  //4或8
	//printf("%d\n", strlen(&a));  // 随机值
	//printf("%d\n", sizeof(&b));  // 4或8
	//printf("%d\n", strlen(&b));  // 6
	//printf("%d\n", sizeof(&p));
	//printf("%d\n", strlen(&p));

	//printf("%d\n", sizeof(*&b));  // 6
	//printf("%d\n", strlen(*&a));  // 随机值
	//printf("%d\n", sizeof(*&b));  // 7  等同于b,得到b元素的个数
	//printf("%d\n", strlen(*&b));  // 6  等同于b,得到b元素的长度
	//printf("%d\n", sizeof(*&p));
	//printf("%d\n", strlen(*&p));

	//printf("%d\n", sizeof(&a + 1)); //4或8
	//printf("%d\n", strlen(&a + 1)); // 随机值,比a小6，因为会跳过数组a的部分
	//printf("%d\n", sizeof(&b + 1)); // 4或8
	//printf("%d\n", strlen(&b + 1)); // 随机值，跳过数组或字符串b的\0到下一个\0
	//printf("%d\n", sizeof(&p + 1));
	//printf("%d\n", strlen(&p + 1));

	//printf("%d\n", sizeof(&a[0]));  //4或8
	//printf("%d\n", strlen(&a[0]));  // 随机值
	//printf("%d\n", sizeof(&b[0]));  // 4或8
	//printf("%d\n", strlen(&b[0]));  // 6 从第一个元素到结尾
	//printf("%d\n", sizeof(&p[0]));
	//printf("%d\n", strlen(&p[0]));

	//printf("%d\n", sizeof(&a[0] + 1));  //4或8
	//printf("%d\n", strlen(&a[0] + 1));  // 随机值, 比a小1，因为会跳过数组a[0]的部分
	//printf("%d\n", sizeof(&b[0] + 1));  // 4或8
	//printf("%d\n", strlen(&b[0] + 1));  // 5  从第2个元素到结尾
	//printf("%d\n", sizeof(&p[0] + 1));
	//printf("%d\n", strlen(&p[0] + 1));

	return 0;
}