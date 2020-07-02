//Лабораторна робота 5
//Iндивiдуальне завдання: відсортувати масив символів за абеткою.
//Автор: Момот Роман

#include <cstdlib>
#define N 5
int main()
{
	char mas[N], i, temp, pr;                      //оголошуємо масив

	for (i = 0; i < N; i++)
		mas[i] = (char)(rand() % 26 + 97);         //заповнюємо масив

	do {                                           //сортуємо масив
		pr = 0;
		for (i = 0; i < N - 1; i++)
			if (mas[i] > mas[i + 1])
			{
				temp = mas[i];
				mas[i] = mas[i + 1];
				mas[i + 1] = mas[i];
				mas[i + 1] = temp;
				pr = 1;
			}


	} while (pr == 1);

}