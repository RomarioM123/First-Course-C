#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define N 3                                                   //строки
#define M 4                                                   //столбцы
float** MasGen(float**);
void FormMas(float**);
int Neg(float**);
float* FormMasNeg(float**, int);
void Sort(float*, int);
int main()
{	
	float** pm;
	MasGen(pm);
	FormMas(pm);
	int sumNeg = Neg(pm);
	float* MasNeg = FormMasNeg(pm, sumNeg);
	
	float* pm2 = (float*)malloc(sizeof(float) * sumNeg);
	pm2 = MasNeg;
	
	Sort(pm2, sumNeg);

	for (int i = 0; i < N; i++)
		free(pm[i]);
	free(*pm);
	free(pm2);

	char b;
	int a = _CrtDumpMemoryLeaks();            //проверяем утечку памяти
	if (a == 1)
		b = 'e';  //есть утечка
	else
		b = 'g';  //нет утечки

	return 0;
}
float** MasGen(float** pm)
{
	pm = (float**)malloc(sizeof(float*) * N);  
	for (int i = 0; i < N; i++)
		*(pm++) = (float*)malloc(sizeof(float) * M);  
	return pm;
}

void FormMas(float** pm)                                  //заполняем массивы вещественных чисел
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			**pm++ = (float)(rand() % 20 + (-9.99));
}

int Neg(float** pm)                                       //находим кол-во отриц. эл-ов массива
{
	int sumNeg = 0;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (**pm++ < 0)
				sumNeg++;
	return sumNeg;
}

float* FormMasNeg(float** pm, int size)                  //формируем массив отриц. эл-ов
{
	float* MasPoint = (float*)malloc(sizeof(float) * size);

	for (int i = 0, l = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (**pm++ < 0)
				*MasPoint++ = **pm;
	return MasPoint;
}

void Sort(float* pm, int size)                           //Сортируем массив отриц. эл-ов
{
	int pr;
	float temp;
	

	do {
		pr = 0;
		for (int i = 0; i < size - 1; i++)
			if (*pm > *(pm+i))
			{
				temp = *pm;
				*pm = *(pm+i);
				*(pm + i) = temp;
				pr = 1;
			}

	} while (pr == 1);
}
