/**
 * @mainpage
 * <b> Лабораторна робота № 10. Рядки типу char* </b>
 * <br/><b>Мета роботи:</b>: придбати практичні навички щодо розроблення програм з використанням рядків на мові С. <br/>
 * <b>Індивідуальне завдання:</b>
 * Визначити % символів, що попарно збіглися, у вхідних текстах (кількість символів, що збіглися, до загальної кількості символів). <br/>
 * @author Momot R.
 * @date 26-oct-2019
 * @version 1.0
 */

#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#define CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, FILE, __LINE)
#define new DEBUG_NEW

#include <locale.h>	    /**- Підключення бібліотеки для локалізації консолі. */ 
#include <stdio.h>      /**- Підключення бібліотеки для вводу та виводу інформації. */ 
#include <stdlib.h      /**- Підключення бібліотеки для виділення динамічної пам'яті. */ 
#define N 20            /**- Оголошення максимального розміру масиву. */

bool ReadFile(char*, char*);				/**- Оголошення функції читання з файлів. */
int Size(char*);							/**- Оголошення функції знаходження розміру текста. */
int Comparison(char*, char*, int, int);		/**- Оголошення функції порівняння текстів. */
float Percent(int, int, int);				/**- Оголошення функції знаходження відсотка збігів. */
void Insert(char*, char*, int, int);		/**- Оголошення функції вставки тексту 2 у текст 1 */

int main()
{
	setlocale(LC_ALL, "Russian");     /**- Русіфікація консолі. */
	char str1[N], str2[N];            /**- Оголошення масивів для текстів. */
	char* text1;                      /**- Оголошення покажчика для текста 1. */
	char* text2;					  /**- Оголошення покажчика для текста 2. */
	text1 = str1;
	text2 = str2;

	ReadFile(text1, text2);           /**- Виклик функції читання з файлу. */
	if (ReadFile == false)			  /**- Перевірка існування файлів з текстами. */
		return 0;

	int size1 = Size(text1);		  /**- Виклик функції знаходження розміру першого тексту. */
	int size2 = Size(text2);		  /**- Виклик функції знаходження розміру другого тексту. */

	printf("Text 1: \n");
	printf("%s\n", str1);			  /**- Виведення першого тексту у консоль. */
	printf("\nText 2: \n");
	printf("%s\n", str2);             /**- Виведення другого тексту у консоль. */

	int MatchedNumber = Comparison(text1, text2, size1, size2);        /**- Виклик функції порівняння текстів. */
	printf("\nNumber of matched symbols in texts: %i", MatchedNumber); /**- Виведення кількості символів які збіглися консоль. */
	float PercentMatched = Percent(MatchedNumber, size1, size2);       /**- Виклик функції знаходження відсотка збігів. */

	printf("\nAmount of symbols: %i", size1 + size2);				  /**- Виведення кількості символів у консоль. */
	printf("\nPercent of matched symbols: %.2f\n", PercentMatched);   /**- Виведення відсотка збігів у консоль. */

	printf("\nAdditional task: розробити функцiю, яка реалiзує вставку в рядок «s» другий рядок «s2» в «i»-у позицiю рядка «s». \nНаприклад, insert(“abrakadabra”, “TEXT2”, 4) повинна створити рядок «abraTEXT2kadabra»\n");
	FILE* Text2;
	Text2 = fopen("text2.txt", "r");	         /**- Відкриття другого файлу. */
	fgets(str2, N, Text2);						 /**- Запис з другого файлу у масив 2. */
	fclose(Text2);	          					 /**- Закриття другого файлу. */

	Insert(text1, text2, size1, size2);			 /**- Виклик функції вставки тексту 2 у текст 1. */

	if (_CrtDumpMemoryLeaks())					 /**- Перевірка витоків пам'яті. */
		printf("\nMemory leak detected.");		 /**- Ввиденення у консоль тексту про відсутність витоків. */
	else
		printf("\nThere is no memory leak.");   /**- Ввиденення у консоль тексту про наявність витоків. */

	return 0;
}

bool ReadFile(char* text1, char* text2)
{
	FILE* Text1;
	Text1 = fopen("text1.txt", "r");    /**- Відкриття першого файлу. */
	if (Text1 == NULL)                  /**- Перевірка на існування файлу з текстом. */
		return false;
	fgets(text1, N, Text1);             /**- Запис з першого файлу у масив 1. */
	fclose(Text1);                      /**- Закриття першого файлу. */

	FILE* Text2;
	Text2 = fopen("text2.txt", "r");    /**- Відкриття другого файлу. */
	if (Text2 == NULL)				    /**- Перевірка на існування файлу з текстом. */
		return false;
	fgets(text2, N, Text2);				/**- Запис з другого файлу у масив 2. */
	fclose(Text2);					    /**- Закриття другого файлу. */

	return true;
}

int Size(char* text)
{
	int size = 0, i = 0;            /**- Змінні, необхідна для знаходження розміру масиву. */

	do {
		size++;                     /**- Збільшення змінної розміру тексту на 1. */
		i++;						/**- Збільшення змінної елементів тексту на 1. */
	} while (*(text + i) != '\0');  /**- Цикл, який визначає розмір масиву. */

	return size - 1;		        /**- Повернення результату роботи функції. */
}

int Comparison(char* text1, char* text2, int size1, int size2)
{
	int num = 0;							/**- Змінна, необхідна для роботи функції. */

	for (int i = 0; i < size1; i++)         /**- Цикл, який знаходить елемент першого тексту. */
		for (int j = 0; j < size2; j++)		/**- Цикл, який знаходить елемент другого тексту. */
			if (*(text1 + i) == *(text2 + j) && *(text1 + i) != ' ') /**- Оператор, який перевіряє збіг елементів текстів. */
			{
				num++;						/**- Збільшення змінної збігів елементів на 1. */
				*(text2 + j) = '+';			/**- Заміна символу у тексті 2 для уникнення повторних збігів. */
				j = j + size2;				/**- Закінчення порівняння з елементом тексту 1. */
			}

	return num;                             /**- Повернення змінної збігів елементів. */
}

float Percent(int MatchedNumber, int size1, int size2)
{
	float result = 100 / ((size1 + size2) / MatchedNumber);   /**- Оголошення змінної відсотка збігів символів та її знаходження. */
	return result;						    /**- Повернення змінної. */
}

void Insert(char* text1, char* text2, int size1, int size2)
{
	int value = 0, i = 0;							 /**- Оголошення змінної, необхідної для роботи функції. */
	printf("\nAfter what element write text 2 in text 1: ");
	scanf("%i\n", &value);							 /**- Вибір символу після якого треба вставити текст 2. */

	char* text3 = (char*)malloc(size1 + size2 + 2);  /**- Виділення динамічної пам'яті для нового масиву текста 3. */
	int NewSize = 0;

	if (value > size1)								 /**- Якщо текст 2 треба вставити пісня тексту 1. */
		value = size1;

	for (i = 0; i < value; i++, NewSize++)				   /**- Цикл, який визначає елемент тексту 1, який треба записати в текст 3. */
		* (text3 + NewSize) = *(text1 + i);
	for (i = 0; *(text2 + i + 1) != '\0'; i++, NewSize++)  /**- Цикл, який визначає елемент тексту 2, який треба записати в текст 3. */
		* (text3 + NewSize) = *(text2 + i);
	for (i = value; *(text1 + i) != '\0'; i++, NewSize++)  /**- Цикл, який визначає елемент тексту 1, який треба записати в текст 3. */
		* (text3 + NewSize) = *(text1 + i);
	*(text3 + NewSize) = '\0';

	printf("\nResult: \n%s\n", text3);			/**- Виведення тексту 3 у консоль. */

	free(text3);			                    /**- Звільнення пам'яті. */
}
