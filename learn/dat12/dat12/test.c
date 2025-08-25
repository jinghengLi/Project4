#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void test01() {
	//写文件
	FILE* f_write = fopen("./test1.txt", "w+");
	if (f_write == NULL) {
		perror("fopen");
		printf("%s\n", strerror(errno));
		return;
	}
	char buf[] = "hello world";
	for (int i = 0; i < strlen(buf); i++) {
		fputc(buf[i], f_write);
	}
	fclose(f_write);
	//读文件
	FILE* f_read = fopen("./test1.txt", "r");
	if (f_read == NULL) {
		return;
	}
#if 0
	//判断文件结尾 注意：多输出一个空格
	while (!feof(fp_read)) {
		printf("%c", fgetc(fp_read));
	}
#else
	char ch;
	while ((ch = fgetc(f_read)) != EOF) {
		printf("%c", ch);
	}
#endif
	printf("\n");
	fclose(f_read);


}
int main() {
	test01();
	return 0;
}
