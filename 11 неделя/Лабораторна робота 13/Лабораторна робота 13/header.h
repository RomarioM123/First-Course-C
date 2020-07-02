#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#define CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, FILE, __LINE)
#define new DEBUG_NEW

#include <locale.h>		/**- Підключення бібліотеки для локалізації консолі. */ 
#include <stdio.h>		/**- Підключення бібліотеки для вводу та виводу інформації. */ 
#include <stdlib.h>     /**- Підключення бібліотеки для виділення динамічної пам'яті. */ 
#define N 200           /**- Оголошення максимального розміру масиву. */

int Size(char []);						/**- Оголошення функції знаходження розміру тексту. */	
float Percent(float, float, float);		/**- Оголошення функції знаходження відсотка збігів символів.*/
bool ReadFile(char*, char*);			/**- Оголошення функції читання даних з файлу. */
int Comparison(char*, char*, int, int);	/**- Оголошення функції порівняння текстів.*/
bool Test_Size();						/**- Оголошення функції тестування функції Size.*/
bool Test_Percent();					/**- Оголошення функції тестування функції Percent.*/

