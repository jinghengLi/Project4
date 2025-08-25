#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	

int main() {
	int n = 0;
	int m = 0;
	int arr1[1001] = { 0 };
	int arr2[1001] = { 0 };
	scanf("%d %d", &n, &m);	
	if (fgets(arr1, sizeof(arr1), stdin) != NULL) {
		arr1[strcspn(arr1, "\n")] = '\0';
	}
	if (fgets(arr2, sizeof(arr2), stdin) != NULL) {
		arr2[strcspn(arr2, "\n")] = '\0';
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", arr1[i]);
	}
	for (int i = 0; i < m; i++) {
		printf("%d ", arr2[i]);
	}
	return 0;
}