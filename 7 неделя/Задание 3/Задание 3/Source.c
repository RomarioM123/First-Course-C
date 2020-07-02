#define _CRT_SECURE_NO_WARNINGS
#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <windows.h>
char Count(char*, int);
int main()
{
	SetConsoleCP(1251);         //поддержка русского языка в консоли
	SetConsoleOutputCP(1251);
	int size = 0;
	char* pText;
	
	printf("Введите количество элементов: ");
	scanf(" %i", &size);
	
	pText = (char*)malloc(sizeof(char) * size);

	printf("\nВведите текст(до 200 символов): ");
	scanf(" %[^\n]s", &*pText);

	int count = Count(pText, size);

	printf("\nКоличество слов: %i", count);
	
	return 0;
}

char Count(char* text, int size)
{
	int count = 0;

	for (int i = 0; i < size; i++)
		if (*(text + i) != ' ' && (*(text + i + 1) == ' ' || *(text + i + 1) == '\0'))
			count++;
	return count;
}