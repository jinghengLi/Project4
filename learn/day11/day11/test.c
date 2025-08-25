#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdio.h>

int main() {
    int a = 0;
    char arr[1001] = { 0 };
    scanf("%d", &a);
    for (int i = 0; i < a; i++) {
        scanf("%s", arr[i]);
    }
    return 0;
}