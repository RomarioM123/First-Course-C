#define _CRT_SECURE_NO_WARNINGS
#define CRTDBG_MAP_ALLOC
#define DEBUG_NEW new(_NORMAL_BLOCK, FILE, __LINE)
#define new DEBUG_NEW
#include <string.h>      /**- Підключення бібліотеки <string.h>. */
#include <crtdbg.h>      /**- Підключення бібліотеки <crtdbg.h>. */  
#include <stdio.h>       /**- Підключення бібліотеки <stdio.h>. */
#include <stdlib.h>      /**- Підключення бібліотеки <stdlib.h>. */ 
#include <locale.h>      /**- Підключення бібліотеки <locale.h>. */  

struct Notebook {			/**- Оголошення структури Notebook. */
	float ScrDiagonal;      /**- Діагональ екрану. */
	char Company[10];		/**- Назва компанії. */
	char Model[10];			/**- Модель. */
	char Bluetooth[3];		/**- Наявність Bluetooth. */
	int Keys;				/**- Кількість клавіш. */
	float Price;			/**- Назва компанії. */
	char System[10];		/**- Система. */
};
struct NotebookElSp {
	Notebook info;			/**- Оголошення покажчика на інформацію Notebook. */
	NotebookElSp* next, * prev;	/**- Оголошення покажчиків на попередній та наступний елемент списку.*/
};

NotebookElSp* Init();				/**- Оголошення функції ініціалізації структури Notebook. */
FILE* OpenFile();							/**- Оголошення функції відкриття файлу.*/
void InitSpisok(NotebookElSp*, NotebookElSp*);	/**- Оголошення функції переміщення покажчиків голови та хвоста списку. */
void CreateSpH(NotebookElSp*, FILE*);		/**- Оголошення функії заповнення списку з файлу з голови. */
void CreateSpT(NotebookElSp*, FILE*);		/**- Оголошення функії заповнення списку з файлу з хвоста. */
void OutputScrH(NotebookElSp*);				/**- Оголошення функції виведення списку у консоль з голови.*/
void OutputScrT(NotebookElSp*);				/**- Оголошення функції виведення списку у консоль з хвоста.*/
void FreeSpisok(NotebookElSp*);				/**- Оголошення функції видалення списку.*/
NotebookElSp* Choise(NotebookElSp*, NotebookElSp*, FILE*);	/**- Оголошення функції вибору варіанту заповнення списку.*/
void Menu(NotebookElSp*, NotebookElSp*);	/**- Оголошення функції вибору дій зі списком.*/
void AverageScreen(NotebookElSp*);			/**- Оголошення функції знаходження середньої диагоналі.*/
void OutputFile(NotebookElSp*, FILE*);		/**- Оголошення функції виведення списку у файл.*/
int Size(NotebookElSp*);					/**- Оголошення функції знаходження розміру списку.*/
void OutputFileBinary(NotebookElSp*);		/**- Оголошення функції запису списку в бінарний файл.*/
void InputFileBinary(NotebookElSp*);		/**- Оголошення функції читання списку з бінарного файлу.*/
void SortScreen(NotebookElSp*, NotebookElSp*);	/**- Оголошення функції сортування списку за діагоналлю екрана.*/
void NewNotebook(NotebookElSp*, NotebookElSp*);	/**- Оголошення функції вставки нового ноутбука у список.*/
void DeleteNotebook(NotebookElSp*);			/**- Оголошення функції видалення строки зі списку.*/
NotebookElSp* NewStroka(NotebookElSp*);		/**- Оголошення функції запису нового ноутбука з консолі.*/
void Swap(NotebookElSp*, NotebookElSp*);	/**- Оголошення функції зміни місцями 2 елементів списку.*/


