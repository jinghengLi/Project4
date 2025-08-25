#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main() {
    char s[501] = "";
    while (fgets(s, sizeof(s), stdin) != NULL) {
        s[strcspn(s, "\n")] = '\0';
        int len = strlen(s);
        int count = 0;
        char arr[501];
        for (int i = 0; i < len; i++) {
            arr[s[i]] = 1;

        }

        for (int i = 0; i < 128; i++) {
            if (arr[i] == 1)
                count += 1;
        }
        printf("%d", count);



    }




    return 0;
}