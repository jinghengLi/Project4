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

//递归实现字符串反转
void reverse(char* str) {
	char temp = *str;   // 保存第一个字符
	int len = my_strlen(str);
	*(str) = str[len - 1]; // 将最后一个字符放到第一个位置或者 *str = *(str + len - 1);
	*(str + len - 1) = '\0'; // 将最后一个字符位置设置为字符串结束符
	if (my_strlen(str + 1) >= 2)   // 检查剩余部分是否有两个或更多字符
		reverse(str + 1); // 递归调用，处理剩余部分
	*(str + len - 1) = temp; // 将保存的第一个字符放到最后一个位置
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