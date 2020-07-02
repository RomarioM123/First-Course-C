//Сформировать массив вещественных чисел из N элементов и отсортировать первую половину по возрастанию, а вторую - по убыванию
//Задание 1
#include <stdlib.h>
#define N 10
float form(float mas[], int i);                           //оголошуємо функцію формування масива
float sort(float mas[], int k, int ni, int ogranichenie); //оголошуємо функцію сортировки
int main()
{
	int i = 0;

	float mas[N];
	form(mas, 0);
	sort(mas, 1, 0, ((N / 2)-1));
	sort(mas, -1, ((N / 2)-1), N);
}

float form(float mas[], int i)
{
	for (i = 0; i < N; i++)
		mas[i] = (float)(rand() % 20 + (-9.99));         //генеруємо масив

	return mas[i];
}

float sort(float mas[], int k, int ni, int ogranichenie)
{
	int pr;
	float temp;

	do {
			pr = 0;
			for (int i = ni; i < ogranichenie; i++)
				if (k * mas[i] > k * mas[i + 1])
				{
					temp = mas[i];
					mas[i] = mas[i + 1];
					mas[i + 1] = temp;
					pr = 1;
				}
		} while (pr == 1);

	return mas[N];
}