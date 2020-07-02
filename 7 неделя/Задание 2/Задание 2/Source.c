#define _CRT_SECURE_NO_WARNINGS
#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#include "stdlib.h"
#include "string.h"
#include <stdio.h>
#include <Windows.h>
void Swap(char*, int);
int main(void)
{
	SetConsoleCP(1251);         //поддержка русского языка в консоли
	SetConsoleOutputCP(1251);
	
	char* pText;
	int size = 0;
	
	printf("Введите количество элементов: ");
	scanf(" %i", &size);
	
	pText = (char*)malloc(sizeof(char) * size);

	printf("Введите предложение: ");
	scanf(" %[^\n]s", &*pText);

	Swap(pText, size);

	printf("\nВыходной массив: \n");
	for (int i = 0; i < size; i++)
		printf_s(" %c", *(pText + i));

	return 0;
}

void Swap(char* pArr, int size)
{
	char temp;
	
	for (int i = 0, j = size-1; i <= size / 2; i++, j--)
	{
		temp = *(pArr + j);
		*(pArr + j) = *(pArr + i);
		*(pArr + i) = temp;
	}
}