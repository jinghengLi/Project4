#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int num_trans(int x) {
	printf("%d", (x / 10 % 2 == 0) ? 0 : 1);
}

int main() {
	int a = 0;
	scanf("%d", &a);


	return 0;
}