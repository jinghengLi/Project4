#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//void my_reverse(char* str, int left, int right);
//
//int main() {
//	char arr[] = "abcdefghijklmnopqrstuvwxyz";
//	int left = 0;
//	int right = strlen(arr)-1;
//	my_reverse(arr,left,right);
//	printf("%s\n", arr);
//	return 0;
//}
//
//void my_reverse(char* str, int left,int right) {
//	int temp = str[left];
//	str[left] = str[right];
//	str[right] = temp;
//
//	if (left < right) {
//		my_reverse(str, left+1,right-1);
//	}
//	
//}

//�ݹ�ʵ���ַ�����ת
void reverse(char* str) {
	char temp = *str;   // �����һ���ַ�
	int len = my_strlen(str);
	*(str) = str[len - 1]; // �����һ���ַ��ŵ���һ��λ�û��� *str = *(str + len - 1);
	*(str + len - 1) = '\0'; // �����һ���ַ�λ������Ϊ�ַ���������
	if (my_strlen(str + 1) >= 2)   // ���ʣ�ಿ���Ƿ�������������ַ�
		reverse(str + 1); // �ݹ���ã�����ʣ�ಿ��
	*(str + len - 1) = temp; // ������ĵ�һ���ַ��ŵ����һ��λ��
}

int my_strlen(const char* str) {
	int len = 0;
	while (*str++) {
		len++;
	}
	return len;
}

int main() {
	char arr[] = "abcdefghijklmnopqrstuvwxyz";
	reverse(arr);
	printf("%s\n", arr);
	return 0;
}