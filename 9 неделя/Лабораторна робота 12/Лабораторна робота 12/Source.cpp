/**
 * @mainpage
 * <b> Лабораторна робота № 12. Структуровані типи даних </b>
 * <br/><b>Мета роботи:</b> придбати практичні навички щодо розроблення програм із застосуванням масивів структур, сумішей і перерахувань. <br/>
 * <b>Індивідуальне завдання:</b>
 * Прикладна галузь «НОУТБУК». Сформувати список ноутбуків, у яких кількість клавіш знаходиться у діапазоні від 80 до 101. <br/>
 * <b>Типи обєктів та їх поля: </b> НОУТБУК: Розмір діагоналі екрану; назва фірми; назва моделі; Чи є Bluetooth?; кількість клавіш на клавіатурі; ціна; операційна система.
 * @author Momot R.
 * @date 03-nov-2019
 * @version 1.0
 */
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#define CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, FILE, __LINE)
#define new DEBUG_NEW

#include <stdio.h>          /**- Підключення бібліотеки <stdio.h>. */  
#include <stdlib.h>         /**- Підключення бібліотеки <stdlib.h>. */  
#define SIZE 4				/**- Оголошення максимальної кількості елементів структури. */

struct Notebook {			/**- Оголошення структури Notebook. */
	float ScrDiagonal;      /**- Діагональ екрану. */
	char Company[10];		/**- Назва компанії. */
	char Model[10];			/**- Модель. */
	char Bluetooth[3];		/**- Наявність Bluetooth. */
	int Keys;				/**- Кількість клавіш. */
	float Price;			/**- Назва компанії. */
	char System[10];		/**- Система. */
};

bool ReadFile(Notebook list[], int);		/**- Оголошення функції читання з файлу. */
void OutputScreen(Notebook list[], int);	/**- Оголошення функції виведення на екран. */
void Sort(Notebook list[], int);			/**- Оголошення функції сортування структури. */
void OutputFile(Notebook list[], int);		/**- Оголошення функції виводу структури у файл. */
void GenAndOutput(Notebook list[], int);	/**- Оголошення функції генерації членів структури та виведення у файл. */

int main()
{
	Notebook list[SIZE];			/**- Оголошення структури розміром SIZE елементів. */

	ReadFile(list, SIZE);			/**- Виклик функції читання з файлу. */
	if (ReadFile == false)			/**- Перевірка на існування файлу з текстом. */
		return 0;

	OutputScreen(list, SIZE);		/**- Виклик функції виведення структури у консоль. */
	Sort(list, SIZE);				/**- Виклик функції сортування структури. */
	OutputScreen(list, SIZE);		/**- Виклик функції виведення структури у консоль. */
	OutputFile(list, SIZE);			/**- Виклик функції виведення структури у файл. */
	GenAndOutput(list, SIZE);		/**- Виклик функції генерації членів та виведення у файл. */

	if (_CrtDumpMemoryLeaks())					/**- Перевірка витоків пам'яті. */
		printf("\nMemory leak detected.");		/**- Ввиденення у консоль тексту про відсутність витоків. */
	else
		printf("\nThere is no memory leak.");	/**- Ввиденення у консоль тексту про наявність витоків. */
}

bool ReadFile(Notebook list[], int size)			/** Функція читання з файлу. */
{
	FILE* TEXT = fopen("notebook.txt", "r");		/**- Відкриття файлу. */
	if (!TEXT)										/**- Перевірка на існування файлу з текстом. */
		return false;

	printf("List of notebooks: \n");

	for (int i = 0; i < size; i++)					/**- Цикл, який визначає поля структури, які треба заповнити. */
	{
		fscanf(TEXT, "%f", &list[i].ScrDiagonal);	/**- Запис у поле диагоналі екрану. */
		fscanf(TEXT, "%s", &list[i].Company);		/**- Запис у поле назви компанії. */
		fscanf(TEXT, "%s", &list[i].Model);			/**- Запис у поле моделі. */
		fscanf(TEXT, "%s", &list[i].Bluetooth);		/**- Запис у поле наявності Bluetooth. */
		fscanf(TEXT, "%i", &list[i].Keys);			/**- Запис у поле кількості клавіш. */
		fscanf(TEXT, "%f", &list[i].Price);			/**- Запис у поле ціни. */
		fscanf(TEXT, "%s", &list[i].System);		/**- Запис у поле системи. */
	}
	fclose(TEXT);									/**- Закриття файлу. */
}

void Sort(Notebook list[], int size)			/** Функція сортування структури. */
{
	bool pr;									/**- Оголошення змінної, необхідної для сортування. */
	struct Notebook temp;						/**- Оголошення тимчасового поля структури для сортування. */

	do {										/**- Цикл, який виконує сортування. */
		pr = false;								/**- Оголошення змінної, необхідної для сортування. */
		for (int i = 0; i < size - 1; i++)		/**- Цикл, який визначає поля струкрури. */
			if (list[i].ScrDiagonal > list[i + 1].ScrDiagonal)	/**- Оператор, який визначає необхідність переставлення елементів структури. */
			{
				temp = list[i];
				list[i] = list[i + 1];
				list[i + 1] = temp;
				pr = true;
			}
	} while (pr == 1);

	printf("\nList of notebooks after sorting(Screen Diagonal): \n");
}

void OutputScreen(Notebook list[], int size)	/**Функція виведення на екран. */
{
	printf("Company       Model    Screen Diagonal   Bluetooth     Keys       Price      System\n");

	for (int i = 0; i < size; i++)	/**- Цикл, який визначає поля струкрури, які треба вивести у консоль. */
	{
		printf("%2i) %-8s %-14s %-12.1f", i + 1, list[i].Company, list[i].Model, list[i].ScrDiagonal);	/**- Виведення елементів у консоль. */
		printf("%8s %10i %13.2f %10s\n", list[i].Bluetooth, list[i].Keys, list[i].Price, list[i].System);
	}
}

void OutputFile(Notebook list[], int size)				/**Функція виводу структури у файл. */
{
	FILE* RESULT = fopen("result.txt", "w");			/**- Відкриття файлу результату. */

	for (int i = 0; i < size; i++)						/**- Цикл, який визначає поля струкрури, які треба записати у файл. */
		if (list[i].Keys >= 80 && list[i].Keys <= 101)	/**- Оператор, який перевіряє елемент структури за умовою (диапазон від 80 до 101). */
		{
			fprintf(RESULT, "%.1f %s %s %s", list[i].ScrDiagonal, list[i].Company, list[i].Model, list[i].Bluetooth);	/**- Виведення поля у файл. */
			fprintf(RESULT, " %i %.2f %s\n", list[i].Keys, list[i].Price, list[i].System);
		}

	fclose(RESULT);										/**- Закриття файлу результату. */
}

void GenAndOutput(Notebook list[], int size)			/**Функція генерації членів структури та виведення у файл. */
{
	FILE* RESULT2 = fopen("result2.txt", "w");			/**- Відкриття другого файлу результату. */

	char i, j;											/**- Оголошення змінних, необхідних для роботи функції. */

	for (i = 0; i < size; i++)							/**- Цикл, який визначає поля струкрури, які треба згенерувати та записати у файл. */
	{
		list[i].Price = rand() % 142 + 13;				/**- Генерація ціни від 13 до 155. */

		for (j = 0; j < 5; j++)							/**- Цикл, який визначає символ у текстовому елементі структури, який треба сгенерувати. */
			list[i].Model[j] = (char)(rand() % 25 + 'A');	/**- Генерація символу. */
		fprintf(RESULT2, "%.1f %s %s %s", list[i].ScrDiagonal, list[i].Company, list[i].Model, list[i].Bluetooth);	/**- Виведення елементів структури у файл. */
		fprintf(RESULT2, "%i %.2f %s\n", list[i].Keys, list[i].Price, list[i].System);
	}
	fclose(RESULT2);									/**- Закриття файлу результату 2. */
}
