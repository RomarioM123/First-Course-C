//Сформировать массив веществ. чисел N строк M столбцов. В каждом столбце найти минимальный элемент, записать в одномерный массив, отсортировать по возрастанию
#include <stdlib.h>
#define N 4                               //кол-во строк
#define M 3			                      //кол-во столбцов
float Form(float mas[]);
void MasMinEl(float mas[], float MasMin[]);
float Sort(float mas[]);
int main()
{
	float mas[N * M], MasMin[M];

	Form(mas);
	MasMinEl(mas, MasMin);
	Sort(MasMin);
}

float Form(float mas[])
{
	int i = 0;

	for (i = 0; i < N * M; i++)
		mas[i] = (float)(rand() % 20 + (-9.99));

	return mas[i];
}

void MasMinEl(float mas[], float MasMin[])
{
	int l, i, j, min;
	float vec[N][M];

	for (i = 0, l = 0; i < N; i++)
		for (j = 0; j < M; j++)
			vec[i][j] = mas[l++];

	for (j = 0; j < M; j++)
	{
		min = 0;
		for (i = 0; i < N; i++)
			if (vec[min][j] > vec[i][j])
				min = i;
		
		MasMin[j] = vec[min][j];
	}
}

float Sort(float mas[])
{
	int temp, pr, i;

	do
	{
		pr = 0;
		for (i = 0; i < M - 1; i++)
			if (mas[i] > mas[i + 1])
			{
				temp = mas[i];
				mas[i] = mas[i + 1];
				mas[i + 1] = temp;
				pr = 1;
			}
	} while (pr == 1);

	return mas[i];
}