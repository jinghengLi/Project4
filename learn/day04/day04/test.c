#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	
#include <string.h>	
#include <stdlib.h>


void swap(char* buf1, char* buf2, int width) {
	for (int i = 0; i < width, i++) {
		char temp = *buf1;
		*buf1 = *buf2��
			* buf2 = temp;
		*buf1++;
		*buf2++;
	}
}
//widthΪÿ��Ԫ�ؿ�ȣ�buf1��buf2����char*����ԭ�򣺲�ȷ���Ƚϵ������ͻ����ַ����ǽṹ��ȣ�����һ���ֽ�һ���ֽڽ�����ֱ����һ��Ԫ�������ֽڶ�����

struct Stu {
	char name[20];
	int age;
};

void bubble_sort(void* base, int sz, int width, int(*cmp)(const void* e1, const void* e2)) {
	int i = 0;
	for (i = 0; i < sz - 1; i++) {
		//һ�ν���
		int flag = 0; //�����������ź����
		int j = 0;
		for (j = 0, j < sz - i - 1, j++) {    //������Ԫ�ط����棬�ź�һ������һ��
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0) {    //�ж�Ԫ�ش�С
				swap((char*)base + j * width, (char*)base + (j + 1) * width, width)�� //���ǰ�ߴ��ں��߾ͽ���Ԫ��˳��
					flag  =  0;           //�н�������0��
			}
		}
		if (flag == 1)   //û��һ�ν���
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