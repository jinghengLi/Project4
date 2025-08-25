#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ���� Person �ṹ��
typedef struct {
    char name[20];
    int age;
} Person;

// ѡ�������㷨
void selectSort(void* arr, size_t eveSize, size_t len, int (*cmp)(const void*, const void*)) {
    for (size_t i = 0; i < len - 1; i++) {
        size_t minOrMax = i;
        for (size_t j = i + 1; j < len; j++) {
            char* pJ = (char*)arr + eveSize * j;
            char* pMinOrMax = (char*)arr + eveSize * minOrMax;
            if (cmp(pJ, pMinOrMax)) {
                minOrMax = j;
            }
        }
        if (i != minOrMax) {
            char* pI = (char*)arr + eveSize * i;
            char* pMinOrMax = (char*)arr + eveSize * minOrMax;
            char* tmp = malloc(eveSize);
            if (tmp == NULL) {
                fprintf(stderr, "Memory allocation failed\n");
                return;
            }
            memcpy(tmp, pI, eveSize);
            memcpy(pI, pMinOrMax, eveSize);
            memcpy(pMinOrMax, tmp, eveSize);
            free(tmp);
        }
    }
}

// ������������������ - ������İ汾
int compareByName(const void* data1, const void* data2) {
    const Person* p1 = (const Person*)data1;
    const Person* p2 = (const Person*)data2;
    // ���� p2->name �� p1->name �ıȽϽ����ʵ�ֽ���
    return strcmp(p2->name, p1->name)>0;
}

void test02() {
    Person arr[] = {
        {"zhangsan", 12},
        {"xisi", 23},
        {"yichael", 15}
    };
    int len = sizeof(arr) / sizeof(Person);
    selectSort(arr, sizeof(Person), len, compareByName);
    for (int i = 0; i < len; i++) {
        printf("������%s, ���䣺%d\n", arr[i].name, arr[i].age);
    }
}

int main() {
    test02();
    system("pause");
    return EXIT_SUCCESS;
}