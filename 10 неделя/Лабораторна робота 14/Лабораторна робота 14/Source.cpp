/**
*@mainpage
* <b> Лабораторна робота № 14. Однозв’язні списки </b>
* <br/><b>Мета роботи:</b> придбати практичні навички з розробки динамічних структур даних.Освоїти методи обробки односпрямованих списків у програмах мовою С.<br/>
* <b>Індивідуальне завдання:</b>
* Прикладна галузь «НОУТБУК».Сформувати односпрямований список ноутбуків, у яких кількість клавіш знаходиться у діапазоні від 80 до 101. <br/>
* <b>Типи обєктів та їх поля: </b> НОУТБУК: Розмір діагоналі екрану; назва фірми; назва моделі; Чи є Bluetooth ?; кількість клавіш на клавіатурі; ціна; операційна система.
* @author Momot R.
* @date 26-nov-2019
* @version 2.1
*/

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
	NotebookElSp* next;		/**- Оголошення покажчика на наступний елемент списку. */
};

NotebookElSp* Initialization();				/**- Оголошення функції ініціалізації структури Notebook. */
void Menu(NotebookElSp*);					/**- Оголошення функції вибору дій зі списком.*/
FILE* ReadFile(NotebookElSp*);				/**- Оголошення функції відкриття файлу.*/
void CreateSpisok(NotebookElSp*, FILE*);	/**- Оголошення функції створення списку.*/
void OutputScreen(NotebookElSp*);			/**- Оголошення функції виведення списку у консоль.*/
int DeleteNotebook(NotebookElSp*);			/**- Оголошення функції видалення строки зі списку.*/
void AverageScreen(NotebookElSp*);			/**- Оголошення функції знаходження середньої диагоналі.*/
void SortScreen(NotebookElSp*);				/**- Оголошення функції сортування списку за діагональю екрана.*/
void OutputFile(NotebookElSp*, FILE*);		/**- Оголошення функції виведення списку у файл.*/
void NewNotebook(NotebookElSp*);			/**- Оголошення функції вставки нового ноутбука у список.*/
NotebookElSp* NewStroka(NotebookElSp*);		/**- Оголошення функції запису нового ноутбука.*/
int Size(NotebookElSp*);					/**- Оголошення функції знаходження розміру списку.*/
void OutputFileBinary(NotebookElSp*);		/**- Оголошення функції виводу списку в бінарний файл.*/
void InputFileBinary(NotebookElSp*);		/**- Оголошення функції запису списку з бінарного файлу.*/
void FreeSpisok(NotebookElSp*);				/**- Оголошення функції видалення списку.*/

int main() {
	setlocale(LC_ALL, "Rus");	/**- Русіфікація консолі.*/
	struct NotebookElSp* head = Initialization();	/**- Виклик функції ініціалізації структури Notebook. */
	ReadFile(head);				/**- Виклик функції читання з файлу. */		
	Menu(head);					/**- Виклик функції виклику меню.*/
	return 0;					/**- Завершення роботи програми.*/
}

NotebookElSp* Initialization() {
	struct NotebookElSp* p = (struct NotebookElSp*)malloc(sizeof(NotebookElSp)); /**- Виділення пам'яті на наступний елемент списка. */
	p->next = NULL;				/**- Покажчику на наступний елемент списку присвоюємо NULL. */	
	return p;					/**- Кінець роботи функції. */	
}
void Menu(NotebookElSp* start) {
	int choise, choise2;    /**- Оголошення змінних вибору дій користувача. */	
	printf("\n=================\nВыбор действий: \n1)Вывести на экран\n");
	printf("2)Сохранить данные в файл\n3)Удалить определенный ноутбук\n");
	printf("4)Найти среднюю диагональ ноутбуков\n5)Отсортировать ноутбуки ");
	printf("по диагонали\n6)Записать новый ноутбук\n7)Сохранить в бинарный файл\n");
	printf("8)Чтение из бинарного файла\n9)Завершить программу\n================\n");
	printf("Что надо сделать? ");
	scanf("%i", &choise);		/**- Вибор дії користувачем. */

	if (start->next == NULL && choise != 6)	/**Якщо у структурі нема елементів: */
	{
		printf("Список пуст. Хотите добавить элемент(1) или завершить программу(0)? ");
		scanf("%i", &choise2);	/**- Введення дії користувачем. */
		if (choise2 == 0)		/**- Користувач вибрав закінчення програми: */
		{
			printf("Завершение программы.\n");
			FreeSpisok(start);		/**- Виклик функції очищення списку. */

			if (_CrtDumpMemoryLeaks())	/**- Перевірка на існування витоків пам'яті.*/
				printf("\nУтечка памяти обнаружена.");	//Витоків немає
			else
				printf("\nУтечка памяти отсутствует.");	//Витоки є
			return;
		}
		if (choise2 == 1)		/**- Користувач вибрав додавання нових елементів: */
		{
			NewNotebook(start);	/**- Виклик функції додавання нового ноутбука у список. */
			return Menu(start);	/**- Виклик функції меню. */
		}
		else					/**- Користувач написав неправильний символ: */
		{
			printf("Вы выбрали что-то не так. Введите что вы хотите сделать повторно:\n");
			return Menu(start);	/**- Виклик функції меню. */
		}
	}
	if (choise == 1)			/**Якщо користувач вибрав виведення списку у консоль: */
	{
		printf("Список: \n");
		OutputScreen(start);	/**- Виклик функції виведення списку у консоль. */
	}
	else if (choise == 2)		/**Якщо користувач вибрав збереження списку у файл: */
	{
		char ResultName[15] = "result.txt";
		FILE* RESULT = fopen(ResultName, "w");	/**- Відкриття файлу. */
		OutputFile(start, RESULT);				/**- Виклик функції збереження списку у файл. */
		printf("Данные сохранены в файл.\n");
	}
	else if (choise == 3)		/**Якщо користувач вибрав видалення одного елементу зі списка: */
		DeleteNotebook(start);	/**- Виклик функції видалення одного елементу зі списка. */
	else if (choise == 4)		/**Якщо користувач вибрав знаходження середньої диагоналі: */
		AverageScreen(start);	/**- Виклик функції знаходження середньої диагоналі. */
	else if (choise == 5)		/**Якщо користувач вибрав сортування списку: */
	{
		SortScreen(start);		/**- Виклик функції сортування списку. */
		printf("Список отсортирован.");
	}
	else if (choise == 6)		/**Якщо користувач вибрав додавання нового елементу: */
		NewNotebook(start);		/**- Виклик функції додавання нового елементу. */
	else if (choise == 7)		/**Якщо користувач вибрав збереження списку у бінарний файл: */
	{
		OutputFileBinary(start);/**- Виклик функції збереження списку у бінарний файл. */
		printf("Данные сохранены в бинарный файл");
	}
	else if (choise == 8)		/**Якщо користувач вибрав запис з бінарного файлу у список: */
		InputFileBinary(start);	/**- Виклик функції запису з бінарного файлу у список. */
	else if (choise == 9)		/**Якщо користувач вибрав завершення программи: */
	{
		printf("Завершение программы.\n");
		FreeSpisok(start);		/**- Виклик функції очищення списку. */

		if (_CrtDumpMemoryLeaks())	/**- Перевірка на існування витоків пам'яті.*/
			printf("\nУтечка памяти обнаружена.");	//Витоків немає
		else
			printf("\nУтечка памяти отсутствует.");	//Витоки є
		return;

	}
	else						/**Якщо користувач вибрав неправильний символ: */
	{
		printf("Вы выбрали что-то не так. Введите что вы хотите сделать повторно:\n");
		return Menu(start);		/**- Виклик функції меню. */			
	}
	return Menu(start);			/**Виклик функції меню. */
}
FILE* ReadFile(NotebookElSp* head) {
	FILE* TEXT = fopen("notebook.txt", "r");	/**- Відкриття файлу. */
	if (!TEXT) return 0;						/**- Перевірка на існування файлу. */
	CreateSpisok(head, TEXT);					/**- Виклик функції створення списка. */
}
void CreateSpisok(struct NotebookElSp* h, FILE* text) {
	struct NotebookElSp* p = h;	/**- Оголошення покажчика. */
	while (feof(text) == 0)		/**- Цикл, який працює поки не буде кінець файлу. */
	{
		p->next = (NotebookElSp*)malloc(sizeof(NotebookElSp));	/**- Виділення пам'яті на структуру Notebook. */
		p = p->next;						/**- Переміщення покажчика на наступні дані. */
		fscanf(text, "%f%s%s%s", &p->info.ScrDiagonal, p->info.Company, p->info.Model, p->info.Bluetooth);
		fscanf(text, "%i%f%s", &p->info.Keys, &p->info.Price, p->info.System);	/**- Запис даних у структуру. */
	}
	p->next = NULL;
	fclose(text);				/**- Закриття файлу. */
}
void OutputScreen(NotebookElSp* h) {
	struct NotebookElSp* p = h->next;	/**- Оголошення покажчика. */
	printf("Company     Model  Screen Diagonal   Bluetooth  Keys       Price     System\n");
	int i = 1;			/**- Оголошуємо змінну нумерації списку. */

	while (p)			/**- Цикл, який працює поки не буде кінець списку. */
	{
		printf("%2i) %-7s %-12s %-9.1f", i, p->info.Company, p->info.Model, p->info.ScrDiagonal);	/**- Виведення даних у консоль. */
		printf("%8s %8i %12.2f %10s\n", p->info.Bluetooth, p->info.Keys, p->info.Price, p->info.System);
		p = p->next;	/**- Переміщення покажчика. */
		i++;			/**- Збільшуємо змінну нумерації списку. */
	}
}
int DeleteNotebook(NotebookElSp* h) {
	struct NotebookElSp* t = h->next;	/**- Оголошення покажчика на перший елемент даних. */
	struct NotebookElSp* p = t->next;	/**- Оголошення покажчика на другий елемент даних. */
	struct NotebookElSp* f;		
	int value;
	int size = Size(h);					/**- Виклик функції знаходження розміру структури. */
	printf("Введите  номер ноутбука которой надо удалить: ");
	scanf("%i", &value);				/**- Введення змінної, яка вказує, який ноутбук потрібно видалити. */

	if (value <= 0 || value > size)		/**Якщо користувач вибрав номер, який не існує. */
	{
		printf("Ошибка. Неверный номер списка.");
		return 0;						/**- Завершення роботи програми. */
	}
	printf("\nНоутбук, который будет удалён: \n");
	printf("Company    Model  Screen Diagonal   Bluetooth  Keys     Price       System\n");
	if (value == 1)						/**Якщо користувач вибрав перший ноутбук. */
	{
		p = h->next;					/**Переміщення покажчиків. */
		t = p->next;
		printf("%7s %8s %11.1f %14s", p->info.Company, p->info.Model, p->info.ScrDiagonal, p->info.Bluetooth);
		printf("%8i %12.2f %10s\n", p->info.Keys, p->info.Price, p->info.System);	/**Виведення даних у консоль. */
		h->next = t;					/**Переміщення покажчика головного елемента на другий елемент. */
		free(p);						/**Видалення одного елемента. */
		return 0;						/**- Завершення роботи програми. */
	}
	if (value == size)						/**Якщо користувач вибрав останній ноутбук. */
	{
		t = h->next;						/**- Переміщення покажчиків. */
		for (int i = 0; i < size - 2; i++)	/**- Цикл, який переміщує покажчик до потрібного місця. */
			t = t->next;
		p = t->next;						/**- Переміщення покажчика на елемент, який треба видалити. */
		printf("%7s %7s %11.1f %14s", p->info.Company, p->info.Model, p->info.ScrDiagonal, p->info.Bluetooth);
		printf("%8i %12.2f %10s\n", p->info.Keys, p->info.Price, p->info.System);	/**Виведення даних у консоль. */
		free(p);							/**Видалення елемента. */
		t->next = NULL;
		return 0;							/**- Завершення роботи програми. */
	}
	if (value >= 1 && value <= size - 1)	/**Якщо користувач вибрав списки у середині. */
	{
		t = h->next;						/**- Переміщення покажчика на перший елемент. */
		for (int i = 0; i < value - 2; i++)	/**- Цикл, який переміщує покажчик до потрібного місця. */
			t = t->next;
		p = t->next;						/**- Переміщення другого покажчика на елемент, який треба видалити. */
		f = p->next;						/**- Переміщення третього покажчика на наступний елемент. */
		printf("%7s %7s %11.1f %14s", p->info.Company, p->info.Model, p->info.ScrDiagonal, p->info.Bluetooth);
		printf("%8i %12.2f %10s\n", p->info.Keys, p->info.Price, p->info.System);	/**Виведення даних у консоль. */
		t->next = f;						
		free(p);							/**Видалення елемента. */
		return 0;							/**- Завершення роботи програми. */
	}
	return size;
}
void AverageScreen(NotebookElSp* h) {
	struct NotebookElSp* p = h->next;	/**- Оголошення покажчика на перший елемент даних. */
	float value = 0;					/**- Оголошення змінної суми діагоналей. */
	int count = 0;						/**- Оголошення змінної кількості ноутбуків. */
	while (p)							/**- Цикл, який працює до кінця списку. */		
	{
		value += p->info.ScrDiagonal;	/**- Суммуємо диагоналі. */
		count++;						/**- Знаходимо кількість ноутбуків. */
		p = p->next;					/**- Переміщуємо покажчик на наступний елемент. */
	}

	float AvValue = value / count;		/**- Знаходимо середню диагональ. */
	printf("\nСредняя диагональ ноутбуков: %.2f", AvValue);	/**- Виведення середньої диагоналі у консоль. */
}
void SortScreen(NotebookElSp* h) {
	bool pr = false;
	struct NotebookElSp* temp;				/**Оголошення змінної для для перестановки. */
	struct NotebookElSp* p = h->next;		/**Оголошення змінної на перший елемент. */
	struct NotebookElSp* end = NULL;

	do {							/**Цикл, який робить сортування. */
		pr = false;
		p = h->next;
		while (p->next)
		{
			if (p->info.ScrDiagonal > p->next->info.ScrDiagonal)	/**Якщо перший елемент краще наступного: */
			{
				if (p == h->next)			/**- Перестановка, якщо треба переставити перший елемент. */
				{
					temp = p;
					p = temp->next;
					temp->next = p->next;
					p->next = temp;
					h->next = p;
					pr = true;
				}
				else						/**- Перестановка, якщо треба переставити інші елементи. */
				{
					temp = p;
					p = temp->next;
					temp->next = p->next;
					p->next = temp;
					end->next = p;
					pr = true;
				}
			}
			end = p;
			p = p->next;		/**Переміщуємо покажчик на наступний елемент. */
		}
	} while (pr == true);
}
void FreeSpisok(NotebookElSp* h) {
	struct NotebookElSp* p = h;	/**- Оголошення покажчика. */
	while (p)					/**- Цикл, який працює до кінця списку. */
	{
		h = p;
		p = p->next;			/**- Переміщуємо покажчик. */
		free(h);				/**- Очищуємо елемент. */
	}
}
void OutputFile(NotebookElSp* h, FILE* text) {
	struct NotebookElSp* p = h->next;	/**- Оголошення покажчика на перший елемент. */
	int i = 1;							/**- Оголошуємо змінну нумерації списку. */
	fprintf(text, "  Company    Model  Screen Diagonal   Bluetooth  Keys     Price       System\n");
	while (p)							/**- Цикл, який працює до кінця списку. */
	{
		fprintf(text, "%2i) %-7s %-12s %-10.1f", i, p->info.Company, p->info.Model, p->info.ScrDiagonal);  /**- Виведення елементів у файл. */
		fprintf(text, "%8s %8i %12.2f %10s\n", p->info.Bluetooth, p->info.Keys, p->info.Price, p->info.System);
		p = p->next;					/**- Переміщення покажчина на наступний елемент. */
		i++;							/**- Збільшуємо змінну нумерації списку. */
	}
	fclose(text);						/**- Закриття файлу. */	
}
void NewNotebook(NotebookElSp* h) {
	int choise;						/**- Оголошуємо змінну вибору місця вставлення ноутбуку. */
	int size = Size(h);				/**- Виклик функції знаходження розміру списку. */
	struct NotebookElSp* NewNotebook = (struct NotebookElSp*)malloc(sizeof(NotebookElSp));	/**- Виділення пам'яті на новий елемент списку. */

	NewStroka(NewNotebook);			/**- Виклик функції запису нового ноутбуку. */

	if (h->next == NULL)			/**Якщо список пуст: */
	{
		printf("\nСписок пуст. Запись в первый номер списка.\n");
		h->next = NewNotebook;		/**- Ставимо покажчик головного елементу на новий елемент. */
		return;						/**- Закінчення роботи функції. */
	}

	printf("После какого ноутбука записать новую строку: ");
	scanf("%i", &choise);				/**- Вибір місця, куди потрібно записати ноутбук. */

	struct NotebookElSp* p = h->next;	/**- Оголошуємо покажчик на перший елемент списку. */
	struct NotebookElSp* t = p->next;	/**- Оголошуємо покажчик на другий елемент списку. */

	if (choise <= 0)					/**Якщо треба вставити на перше місце: */
	{
		printf("Ноутбук будет вставлен на первую позицию.");
		NewNotebook->next = p;		/**- Ставимо покажчик нового елементу на перший елемент. */
		h->next = NewNotebook;		/**- Ставимо покажчик головного елементу на новий елемент. */
		return;						/**- Закінчення роботи функції. */
	}
	if (size == 1)					/**- Якщо у списку 1 елемент: */
	{
		NewNotebook->next = t;		/**- Ставимо покажчик нового елементу на другий елемент. */
		p->next = NewNotebook;		/**- Ставимо покажчик першого елементу на новий елемент. */
		return;						/**- Закінчення роботи функції. */
	}
	if (choise > size)				/**Якщо треба записати у кінець списку: */
	{
		while (t) {					/**- Цикл, який працює до кінця списку */
			p = p->next;			/**- Переміщуємо покажчики */
		}
		p->next = NewNotebook;		/**- Ставимо покажчик останнього елементу на новий елемент. */
		return;						/**- Закінчення роботи функції. */
	}
	else							/**Якщо треба записати у середину списку: */
	{
		for (int i = 0; i < choise - 1; i++)	/**- Цикл, який знаходить місце, куди потрібно записати ноутбук */
		{
			p = p->next;			/**- Переміщуємо покажчики: */
			t = t->next;
		}
		NewNotebook->next = t;
		p->next = NewNotebook;
	}

}
NotebookElSp* NewStroka(NotebookElSp* p) {
	printf("\nВведите новый новый ноутбук с характеристиками в  столбик(!!!): \n");
	printf("Компания, модель, диагональ экрана, наличие Bluetooth, количество клавиш, цена, операционная система\n");
	scanf("%s \n%s \n%f \n%s \n", p->info.Company, p->info.Model, &p->info.ScrDiagonal, p->info.Bluetooth);
	scanf("%i \n%f \n%s", &p->info.Keys, &p->info.Price, p->info.System); /**- Запис нових даних з консолі */
	p->next = NULL;						/**- Ставимо покажчик на NULL.*/

	return p;							/**- Повертаємо новий елемент для запису */
}
int Size(NotebookElSp* h) {
	struct NotebookElSp* p = h->next;	/**- Оголошення покажчику на перший елемент. */
	int size = 0;						/**- Оголошення змінної розміру списку.*/

	while (p)							/**- Цикл, який працює до кінця списку.*/
	{
		size++;							/**- Збільшення змінної розміру списку.*/
		p = p->next;					/**- Переміщуємо покажчик на наступний елемент.*/
	}

	return size;						/**- Повертаємо змінну розміру списку.*/
}
void OutputFileBinary(NotebookElSp* h) {
	struct NotebookElSp* p = h->next;	/**- Оголошення покажчика на перший елемент списку.*/
	FILE* RESULTBINARY = fopen("resultbinary.bin", "w+b");	/**- Відкриття бінарного файлу.*/

	while (p) {							/**- Цикл, який записує дані у бінарний файл.*/
		fwrite(&p->info, sizeof(Notebook), 1, RESULTBINARY);/**- Запис у бінарний файл.*/
		p = p->next;					/**- Переміщення покажчика на наступний елемент.*/
	}
	fclose(RESULTBINARY);				/**- Закриття бінарного файлу.*/
}
void InputFileBinary(NotebookElSp* h) {
	struct NotebookElSp* p = h->next;	/**- Оголошення покажчика на перший елемент списку.*/
	FILE* ResultBinary = fopen("resultbinary.bin", "r+b");	/**- Відкриття бінарного файлу.*/
	if (!ResultBinary)	/**- Перевірка на існування файлу.*/
	{
		printf("Файл не существует. Чтение невозможно.\n");
		return;
	}
	while (p) {				/**- Цикл, який записує дані у файлу.*/
		fread(&p->info, sizeof(Notebook), 1, ResultBinary);	/**- Запис даних у список.*/
		p = p->next;		/**- Переміщення покажчика на наступний елемент.*/
	}
	fclose(ResultBinary);	/**- Закриття файлу.*/
}