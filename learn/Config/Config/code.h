#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <errno.h>
#include <Windows.h>

//加密文件
void codeFile(char* sourceFile, char* destFile);

//解密文件
void decodeFile(char* sourceFile, char* destFile);