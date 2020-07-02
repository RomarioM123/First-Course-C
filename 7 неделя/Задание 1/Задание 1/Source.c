#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, FILE, __LINE__)
#define new DEBUG_NEW

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define N 3    //строки
#define M 4    //столбцы
int** Memory();
int EvenCount(int**);
int* ArrEven(int**, int);
int main()
{	
	setlocale(LC_ALL, "Rus");
	int** pArr = Memory();
	
	printf("Введите массив целых чисел: \n");
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf_s("%i", &*(*(pArr + i) + j));
	
	int size = EvenCount(pArr);            //считаем кол-во четных элементов
	int* pEven = ArrEven(pArr, size);      //формируем массив четных эл-ов
	
	printf("\nЧетные числа: \n");
	for (int i = 0; i < size; i++)
		printf("%i ", *(pEven + i));
	
	for (int i = 0; i < N; i++)           //освобождаем память
		free(pArr[i]);
	free(pArr);
	free(pEven);
	
	char b;
	int a = _CrtDumpMemoryLeaks();        //проверяем утечку памяти
	if (a == 1)
		printf("\n\nЕсть утечка памяти.");
	else
		printf("\n\nНет утечки памяти.");
 	return 0;
}

int** Memory()
{
	int** pArr = (int**)malloc(sizeof(int*) * N);
	
	for (int i = 0; i < N; i++)
		* (pArr + i) = (int*)malloc(sizeof(int) * M);
	
	return pArr;
}

int EvenCount(int** pArr)
{
	int size = 0;
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (*(*(pArr + i) + j) % 2 == 0)
				size++;      //находим кол-во четных чисел
	
	return size;
}

int* ArrEven(int** pArr, int size)
{
	int* pEven = (int*)malloc(sizeof(int) * size);
	
	for (int i = 0, l = 0; i < N; i++)
		for(int j = 0; j < M ; j++)
			if (*(*(pArr + i) + j) % 2 == 0)
			{
				*(pEven + l) = *(*(pArr + i) + j);
				l++;
			}
				
	return pEven;
}