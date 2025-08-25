#define _CRT_SECURE_NO_WARNINGS
#include "code.h"



void codeFile(char* sourceFile, char* destFile) {
	FILE* fp1 = fopen(sourceFile, "r");
	FILE* fp2 = fopen(destFile, "w");
	if (!fp1 || !fp2) {
		return 0;
	}
	char ch;
	while ((ch = fgetc(fp1)) != EOF) {
		short tmp = (short)ch;
		tmp <<= 4;
		tmp |= 0x8000;
		tmp = tmp + rand() % 16;
		fprintf(fp2, "%hd\n", tmp);
		printf("%d\n", tmp);
	}
	fclose(fp1);
	fclose(fp2);
}

void decodeFile(char* sourceFile, char*destFile ) {
	FILE* fp1 = fopen(sourceFile, "r");
	FILE* fp2 = fopen(destFile, "w");
	if (!fp1 || !fp2) {
		return;
	}
	short tmp;
	while ( !feof(fp1) ) {
		
		fscanf(fp1, "%hd", &tmp);
		tmp <<= 1;
		tmp >>= 5;
		char ch = (char)tmp;
		fputc(ch, fp2);
		printf("%d\n", tmp);
	}

	fclose(fp1);
	fclose(fp2);
}

