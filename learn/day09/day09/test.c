#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct S1
{
	char c1;
	int i;
	char c2;
};

struct S2
{
	int i;
	char c1;
	char c2;
};

int main() {
	
	printf("%d\n", sizeof(struct S1));
	printf("%d\n", sizeof(struct S2));
	return 0;
}
