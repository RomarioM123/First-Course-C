#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#define CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, FILE, __LINE)
#define new DEBUG_NEW

#include <locale.h>	    /**- Підключення бібліотеки для локалізації консолі. */ 
#include <stdio.h>      /**- Підключення бібліотеки для вводу та виводу інформації. */ 
#include <stdlib.h>     /**- Підключення бібліотеки для виділення динамічної пам'яті. */ 
#define N 200           /**- Оголошення максимального розміру масиву. */

#include <time.h>						/**- Підключення бібліотеки <time.h> */
#define Date printf("Дата: %s\n", __DATE__);	/**- Оголошення макросу виведення поточної дати. */
#define Time printf("Время: %s\n", __TIME__);	/**- Оголошення макросу виведення поточного часу. */
#define FunctionName printf("\nНазвание функции: %s\n", __func__);	/**- Оголошення макросу виведення назви функції. */
#define TimeOfWork printf("\nВремя работы программы: %lf\n", (double)time / CLOCKS_PER_SEC);	/**- Оголошення макросу виведення часу роботи програми. */
#define start clock_t time = clock();	/**- Оголошення макросу засікання часу роботи програми. */
#define fin time = clock() - time;		/**- Оголошення макросу кінця засікання часу роботи програми. */

int Size(char[]);						/**- Оголошення функції знаходження розміру тексту. */
float Percent(float, float, float);		/**- Оголошення функції знаходження відсотка збігів символів.*/
bool ReadFile(char*, char*);			/**- Оголошення функції читання даних з файлу. */
int Comparison(char*, char*, int, int);	/**- Оголошення функції порівняння текстів.*/
bool Test_Size();						/**- Оголошення функції тестування функції Size.*/
bool Test_Percent();					/**- Оголошення функції тестування функції Percent.*/

