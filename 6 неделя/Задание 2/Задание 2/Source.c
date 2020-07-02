#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h> 
#define N 3                                                    //строки
#define M 4                                                    //столбцы
void FormMas(float**);
int Neg(float**);
float* FormMasNeg(float**, int);
float* FormMasPos(float**, int);
int main()
{
	float** pm;
	
	pm = (float**)malloc(sizeof(float*) * N);    //выделяем память на массив указателей
	for (int i = 0; i < N; i++)
		*(pm++) = (float*)malloc(sizeof(float) * M);       //выделяем память на остальные массивы
	
	FormMas(pm);

	int sumNeg = Neg(pm);
	float* pMasPos = FormMasPos(pm, N * M - sumNeg);           //форм. массива пол. эл-ов
	float* pMasNeg = FormMasNeg(pm, sumNeg);                   //форм. массива отр. эл-ов
	
	for (int i = 0; i < N; i++)
		free(*pm++);
	free(pMasNeg);
	free(pMasPos);
	
	char b;
	int a = _CrtDumpMemoryLeaks();                          //проверяем утечку памяти
	if (a == 1)
		b = 'e';  //есть утечка
	else
		b = 'g';  //нет утечки

	return 0;
}

void FormMas(float** FormMas)                                  //заполняем массивы вещественных чисел
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			**FormMas++ = (float)(rand() % 20 + (-9.99));
}

int Neg(float** FormMas)                                       //находим кол-во отриц. эл-ов массива
{
	int sumNeg = 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (**FormMas < 0)
				sumNeg++;
	return sumNeg;
}

float* FormMasPos(float** pm, int size)                       //формируем массив полож. эл-ов
{
	float* pMasPos;
	pMasPos = (float*)malloc(sizeof(float) * size);
	
	
		for (int i = 0, l = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (*pm++ > 0)
				*(pMasPos++) = **pm;
	return pMasPos;
}

float* FormMasNeg(float** pm, int size)                  //формируем массив отриц. эл-ов
{
	float* pMasNeg;
	pMasNeg = (float*)malloc(sizeof(float) * size);

	for (int i = 0, l = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (*pm++ < 0)
				*(pMasNeg++) = **pm;
	return pMasNeg;
}