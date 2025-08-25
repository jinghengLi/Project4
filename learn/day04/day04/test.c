#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	
#include <string.h>	
#include <stdlib.h>


void swap(char* buf1, char* buf2, int width) {
	for (int i = 0; i < width, i++) {
		char temp = *buf1;
		*buf1 = *buf2；
			* buf2 = temp;
		*buf1++;
		*buf2++;
	}
}
//width为每个元素宽度，buf1、buf2设置char*类型原因：不确定比较的是整型还是字符还是结构体等，所以一个字节一个字节交换，直到把一个元素所有字节都传完

struct Stu {
	char name[20];
	int age;
};

void bubble_sort(void* base, int sz, int width, int(*cmp)(const void* e1, const void* e2)) {
	int i = 0;
	for (i = 0; i < sz - 1; i++) {
		//一次交换
		int flag = 0; //假设数组是排好序的
		int j = 0;
		for (j = 0, j < sz - i - 1, j++) {    //把最大的元素房后面，排好一个就少一个
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0) {    //判断元素大小
				swap((char*)base + j * width, (char*)base + (j + 1) * width, width)； //如果前者大于后者就交换元素顺序
					flag  =  0;           //有交换就置0；
			}
		}
		if (flag == 1)   //没有一次交换
		{
			break;
		}
	}
}

int cmp_stu_by_age(const void* e1, const void* e2) {
	return ((struct Stu*)e2)->age - ((struct Stu*)e1)->age;
}
void test() {
	struct Stu s[] = { {"lisi",12},{"wanger",18},{"zhaowu",20} };
	int sz = sizeof(s) / sizeof(s[0]);
	bubble_sort(s, sz, sizeof(s[0]), cmp_stu_by_age);
	for (int i = 0; i < sz; i++) {
		printf("%s %d\n", s[i].name, s[i].age);
	}
}


int main() {
	test();
	return 0;
}