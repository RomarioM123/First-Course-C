//Сформировать 2 массива из N и M элементов. Определить во сколько раз значение максимального элемента 1 массива больше 2 массива
//Задание 2
#include <stdlib.h>
#define N 5
#define M 7
int form(int mas[], int, int);        //оголошуємо функцію генерації масивів
int max(int mas[], int, int);         //оголошуємо функцію знаходження максимального єлемента масиву
int sravnenie(int, int);
int main()
{
	int mas[N], mas2[M];
	int max1, max2;
	int i = 0, u;

	form(mas, N, i);                  //виклик генерації масива 1
	form(mas2, M, i);                 //виклик генерації масива 2

	max1 = max(mas, N, i);            //знаходження найбільшого єлемента 1 масива
	max2 = max(mas2, M, i);           //знаходження найбільшого єлемента 2 масива

	u = sravnenie(max1, max2);        //виклик функції для порівняння максимальних єлементів масивів
}

int form(int mas[],int size, int i)
{
	for (i = 0; i < size; i++)
			mas[i] = rand() % 71 + (-20);    //генеруємо масив (-20 - 50)
	
	return mas[i];
}

int max(int mas[],int size, int i)
{
	int max = mas[0];

	for (i = 1; i < size; i++)
		if (max < mas[i])
			max = mas[i];

	return max;
}

int sravnenie(int a, int b)
{
	int u = a / b;

	return u;
}