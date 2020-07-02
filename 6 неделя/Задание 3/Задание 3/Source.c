#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define N 3                                                   //строки
#define M 4                                                   //столбцы
void FormMas(float**);
float* MasMax(float**, int);
float* FormMas2(float**, float*);
int main()
{
	float** pm,** copypm;
	
	pm = (float**)malloc(sizeof(float*) * N);    //выделяем память на массив указателей
	for (int i = 0; i < N; i++)
		*(pm++) = (float*)malloc(sizeof(float) * M);    //выделяем память на остальную часть

	FormMas(pm);
	float* Max = MasMax(pm, N);
	float* MasMax = FormMas2(pm, Max);

	
	for (int i = 0; i < N; i++)
		free(*pm++);
	free(pm);
	free(Max);
	free(MasMax);

	char b;
	int a = _CrtDumpMemoryLeaks();      //проверяем утечку памяти
	if (a == 1)
		b = 'e';  //есть утечка
	else
		b = 'g';  //нет утечки

	return 0;
}


void FormMas(float** pm)           //заполняем массивы вещественных чисел
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			**pm++ = (float)(rand() % 20 + (-9.99));
}

float* MasMax(float** pm, int size)           //находим макс. элемент первой строки
{
	float* Max = (float*)malloc(sizeof(float));

	for (int j = 0; j < M; j++)
		if (*(pm+size++) > Max)
			Max = *(pm + size);
	return Max;
}

float* FormMas2(float** pm, float* Max)
{
	int count = 0, l = 0;
	float** copypm;
	copypm = pm;


	for (int i = 1; i < N; i++)
		for (int j = 0; j < M; j++)
			if (**pm++ > *Max)
				count++;           //находим кол-во элементов больше эл-та 1 строки

	float* MasMax = (float*)malloc(sizeof(float) * count);  //выделяем память для массива элементов

	for (int i = 1; i < N; i++)
		for (int j = 0; j < M; j++)
			if (*pm++ > Max)
				*MasMax++ = **pm++;
	
	return MasMax; 
}
