#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


int* is_Rotate(const char* str1, const char* str2) {
	int sz = strlen(str1);
    char* start = str2;
    for (int i = 0; i < sz; i++) {
        char* p = start;
        while (*(p + 1)) {
            char tmp = *p;
            *p = *(p + 1);
            *(p + 1) = tmp;
            p++;
        }
        if (strcmp(str1, str2 == 0)) {
            return 1;
        }
        else
            return 0;
    }
}


int main() {
    char s1 = "AABCD";
    char s2 = "ABCDA";
    int ret = is_Rotate(s1, s2);
    printf("%d\n", ret);
	return 0;
}
