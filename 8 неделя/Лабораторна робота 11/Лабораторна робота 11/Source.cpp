/**
 * @mainpage
 * <b> Лабораторна робота № 11. Файли </b>
 * <br/><b>Мета роботи:</b>: Придбати практичні навички щодо розроблення програм із використанням файлів для завантаження та збереження даних. <br/>
 * <b>Індивідуальне завдання:</b>
 * Визначити % символів, що попарно збіглися, у вхідних текстах (кількість символів, що збіглися, до загальної кількості символів). <br/>
 * <b>Типи обєктів та їх поля: </b>
 * @author Momot R.
 * @date 18-nov-2019
 * @version 1.3
 */
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#define CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, FILE, __LINE)
#define new DEBUG_NEW

#include <stdlib.h>			  /**- Підключення бібліотеки <stdlib.h>. */ 
#include <stdio.h>		      /**- Підключення бібліотеки <stdio.h>. */   
#define N 200				  /**- Оголошення максимального розміру масиву. */

bool ReadFile(char [], char []);			
int Size(char*);							
int Comparison(char*, char*, int, int);		
float Percent(int, int, int);					
void OutputFile(char [], char*, float, int, int, int);	

int main()
{
	char str1[N], str2[N];				/**- Оголошення масивів для текстів. */
	char* text1;						/**- Оголошення покажчика для текста 1. */
	char* text2;					    /**- Оголошення покажчика для текста 2. */
	text1 = str1;
	text2 = str2;

	ReadFile(str1, str2);				/**- Виклик функції читання з файлу. */
	if (ReadFile == false)				/**- Перевірка існування файлів з текстами. */
		return 0;

	int size1 = Size(text1);			/**- Виклик функції знаходження розміру першого тексту. */
	int size2 = Size(text2);			/**- Виклик функції знаходження розміру другого тексту. */

	int i = 0;
	char* copystr2 = (char*)malloc(sizeof(char) * size2 + 1);			   /**- Виділяємо пам'ять для копії масива 2. */
	for (i = 0; i < size2; i++)											   /**- Цикл, який знаходить символ, який треба записати. */
		*(copystr2 + i) = str2[i];										   /**- Записуємо символ масива 2 у копію. */
	*(copystr2 + i) = '\0';												   /**- Записуэмо у кінець масива символ кінця. */

	int MatchedNumber = Comparison(text1, text2, size1, size2);            /**- Виклик функції порівняння текстів. */
	printf("\nNumber of matched symbols in texts: %i", MatchedNumber);     /**- Виведення кількості символів які збіглися консоль. */
	float PercentMatched = Percent(MatchedNumber, size1, size2);           /**- Виклик функції знаходження відсотка збігів. */

	printf("\nAmount of symbols: %i", size1 + size2);                      /**- Виведення кількості символів у консоль. */
	printf("\nPercent of matched symbols: %.2f\n", PercentMatched);		   /**- Виведення відсотка збігів у консоль. */

	OutputFile(str1, copystr2, PercentMatched, MatchedNumber, size1, size2); /**- Виклик функції запису результатів у файли. */

	free(copystr2);
	if (_CrtDumpMemoryLeaks())					/**- Перевірка витоків пам'яті. */
		printf("\nMemory leak detected.");		/**- Ввиденення у консоль тексту про відсутність витоків. */
	else
		printf("\nThere is no memory leak.");	/**- Ввиденення у консоль тексту про наявність витоків. */

	return 0;
}

bool ReadFile(char arr1[], char arr2[])
{
	FILE* Text1;
	Text1 = fopen("text1.txt", "r");					    /**- Відкриття першого файлу. */
	if (Text1 == NULL)									    /**- Перевірка на існування файлу з текстом. */
		return false;
	fgets(arr1, N, Text1);								    /**- Запис з першого файлу у масив 1. */
	fclose(Text1);											/**- Закриття першого файлу. */

	FILE* Text2;
	Text2 = fopen("text2.txt", "r");						/**- Відкриття другого файлу. */
	if (Text2 == NULL)										/**- Перевірка на існування файлу з текстом. */
		return false;
	fgets(arr2, N, Text2);									/**- Запис з другого файлу у масив 2. */
	fclose(Text2);											/**- Закриття другого файлу. */

	printf("Text 1: \n");
	printf("%s\n", arr1);									/**- Виведення першого тексту у консоль. */
	printf("\nText 2: \n");
	printf("%s\n", arr2);									/**- Виведення другого тексту у консоль. */

}

int Size(char* text)
{
	int size = 0, i = 0;               /**- Змінні, необхідна для знаходження розміру масиву. */

	do {
		size++;                        /**- Збільшення змінної розміру тексту на 1. */
		i++;						   /**- Збільшення змінної елементів тексту на 1. */
	} while (*(text + i) != '\0');     /**- Цикл, який визначає розмір масиву. */

	return size;					   /**- Повернення результату роботи функції. */
}

int Comparison(char* text1, char* text2, int size1, int size2)
{
	int num = 0;								/**- Змінна, необхідна для роботи функції. */

	for (int i = 0; i < size1; i++)             /**- Цикл, який знаходить елемент першого тексту. */
		for (int j = 0; j < size2; j++)			/**- Цикл, який знаходить елемент другого тексту. */
			if (*(text1 + i) == *(text2 + j) && *(text1 + i) != ' ') /**- Оператор, який перевіряє збіг елементів текстів. */
			{
				num++;							/**- Збільшення змінної збігів елементів на 1. */
				*(text2 + j) = '+';				/**- Заміна символу у тексті 2 для уникнення повторних збігів. */
				j = j + size2;                  /**- Закінчення порівняння з елементом тексту 1. */
			}

	return num;                                 /**- Повернення змінної збігів елементів. */
}

float Percent(int MatchedNumber, int size1, int size2)
{
	float result = 100 / ((size1 + size2) / MatchedNumber);   /**- Оголошення змінної відсотка збігів символів та її знаходження. */
	return result;											  /**- Повернення змінної. */
}

void OutputFile(char arr1[], char* arr2, float Percent, int matches, int size1, int size2)
{
	FILE* RESULT = fopen("result.txt", "w");					/**- Відкриття текстового файлу результатів. */
	fprintf(RESULT, "Value of matched symbols: %i (%%%.2f)", matches, Percent); /**- Запис у результатів роботи у текстовий файл. */
	fclose(RESULT);												/**- Закриття текстового файлу результатів. */

	FILE* Text1Binary = fopen("text1binary.bin", "w+b");		/**- Відкриття 1 бінарного файлу. */
	fwrite(arr1, size1, 1, Text1Binary);						/**- Запис текста 1 у бінарний файл. */
	fclose(Text1Binary);										/**- Закриття 1 бінарного файлу. */

	FILE* Text2Binary = fopen("text2binary.bin", "w+b");		/**- Відкриття 2 бінарного файлу. */
	fwrite(arr2, size2, 1, Text2Binary);						/**- Запис текста 2 у бінарний файл. */
	fclose(Text2Binary);										/**- Закриття 2 бінарного файлу. */
}