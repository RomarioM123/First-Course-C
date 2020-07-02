#define N 5
#include <cstdlib>
int main()
{
	int mas[N], i, temp, pr;

	for (i = 0; i < N; i++)                               //генерируем массив
		mas[i] = rand() % 9;

	if (N % 2 == 0)                                       //проверяем количество чисел в массиве
		{
			do {                                          //сортируем первую половину массива
				pr = 0;
				for (i = 0; i < (N / 2) - 1; i++)
					if (mas[i] > mas[i + 1])
						{
							temp = mas[i];
							mas[i] = mas[i + 1];
							mas[i + 1] = temp;
							pr = 1;
						}


			} while (pr == 1);

			do {                                          //сортируем вторую половину массива
				pr = 0;
				for (i = N / 2; i < N - 1; i++)
					if (mas[i] < mas[i + 1])
						{
							temp = mas[i];
							mas[i] = mas[i + 1];
							mas[i + 1] = temp;
							pr = 1;
						}


			} while (pr == 1);
		}
	else                                                  //количество чисел в массиве нечетное
		{
			do {                                          //сортируем первую половину массива
				pr = 0;
				for (i = 0; i < (N / 2) - 1.5; i++)
					if (mas[i] > mas[i + 1])
						{
							temp = mas[i];
							mas[i] = mas[i + 1];
							mas[i + 1] = temp;
							pr = 1;
						}	


			} while (pr == 1);

			do {                                          //сортируем вторую половину массива
				pr = 0;
				for (i = (N / 2) + 0.5; i < N - 1; i++)
					if (mas[i] < mas[i + 1])
						{
							temp = mas[i];
							mas[i] = mas[i + 1];
							mas[i + 1] = temp;
							pr = 1;
						}


		} while (pr == 1);
	}

}


