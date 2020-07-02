//Сформировать массив веществ. чисел. Вывести сумму элементов массива, Значение максимального элемента, сколько элементов находятся в интервале
//Задание 3
#include <stdlib.h>
#define N 5
float Form(float mas[], int, int);
float Sum(float mas[], int, int);
float Max(float mas[], int);
int Interval(float mas[], float, float, int, int, int);

int main()
{
	float mas[N], sum, max;
	int Int = 0;

	Form(mas, N, 0);
	sum = Sum(mas, N, 0);
	max = Max(mas, N);
	Int = Interval(mas, sum, max, N, 0, 0);
	
}

float Form(float mas[],int size, int i)
{
	for (i = 0; i < size; i++)
		mas[i] = rand() % 20 + (-9.99);        

	return mas[i];
}

float Sum(float mas[], int size, int i)
{
	float sum = 0;
	
	for (i = 0; i < size; i++)
		sum += mas[i];
	
	return sum;
}

float Max(float mas[], int size)
{
	float max;

	max = mas[0];

	for (int i = 1; i < size; i++)
		if (max < mas[i])
			max = mas[i];

	return max;
}

int Interval(float mas[], float sum, float max, int size, int i, int Int)
{

	for (i = 0; i < size; i++)
		if (sum <= mas[i] && mas[i] <= max)
			Int++;
	
	return Int;
}