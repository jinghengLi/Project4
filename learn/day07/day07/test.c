#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void num_trans(int x) {
	if (x > 9)
		num_trans(x);
	printf("%d", ((x % 10) % 2 == 0) ? 0 : 1);
}

int main() {
	int a = 0;
	scanf("%d", &a);
	num_trans(a);
	return 0;
}