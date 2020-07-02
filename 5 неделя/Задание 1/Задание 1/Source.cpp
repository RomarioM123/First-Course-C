//Сформировать массив веществ. чисел N строк, M столбцов. Каждую строку отдельно сортировать по возрастанию
#include <stdlib.h>
#define N 4          //кол-во строк
#define M 5       //кол-во столбцов
float Form(float mas[], int size);
float Sort(float mas[], int ni, int size);
float Vec(float mas[], int stroka, int stolbec, float vec[N][M]);
int main()
{
	float mas[N * M], vec[N][M];
	int j = 0, f = -5, k = 1, ogranichenie;

	Form(mas, N * M);
	for (j = 0; j < N; j++, k++)
	{
		f += M;
		ogranichenie = (M * k) - 1;
		Sort(mas, f, ogranichenie);
	}
	Vec(mas, N, M, vec);
}

float Form(float mas[], int size)
{
	int i = 0;

	for (i = 0; i < size; i++)
		mas[i] = (float)(rand() % 20 + (-9.99));

	return mas[i];
}

float Sort(float mas[], int ni, int size)
{
	int pr, l = 0;
	float temp, vec[N][M];

	do {
		pr = 0;
		for (int i = ni; i < size; i++)
			if (mas[i] > mas[i + 1])
			{
				temp = mas[i];
				mas[i] = mas[i + 1];
				mas[i + 1] = temp;
				pr = 1;
			}
	} while (pr == 1);

	return mas[l];
}

float Vec(float mas[], int stroka, int stolbec, float vec[N][M])
{
	int i, j, l;

	for (i = 0, l = 0; i < stroka; i++)
		for (j = 0; j < stolbec; j++)
			vec[i][j] = mas[l++];
	return mas[l];
}