#include "my.h"		/**- Підключення заголовочного файлу. */

NotebookElSp* Init() {
	struct NotebookElSp* p = (struct NotebookElSp*)malloc(sizeof(NotebookElSp)); /**- Виділення пам'яті на наступний елемент списка. */
	return p;					/**- Повернення покажчика. */
}
FILE* OpenFile() {
	FILE* TEXT = fopen("notebook.txt", "r");	/**- Відкриття файлу. */
	if (!TEXT) return NULL;						/**- Перевірка на існування файлу. */
	return TEXT;								/**- Повернення даних з файлу. */
}
void InitSpisok(NotebookElSp* h, NotebookElSp* t) {
	h->next = t;		/**- Переміщення покажчиків. */
	h->prev = NULL;
	t->next = NULL;
	t->prev = h;
}
NotebookElSp* Choise(NotebookElSp* h, NotebookElSp* t, FILE* text) {
	int choise;			/**- Оголошуємо змінну вибору вариіанту заповнення списку. */
	printf("Заполнять список с хвоста(0) или с головы(1): ");
	scanf("%i", &choise);	/**- Введення вибору. */
	if (choise == 0) {		/**Якщо користувач вибрав заповнення з хвоста: */
		CreateSpT(t, text);	/**- Виклик функції заповнення з хвоста. */
		return 0;			/**- Закінчення роботи функції. */
	}
	if (choise == 1) {		/**Якщо користувач вибрав заповнення з голови: */
		CreateSpH(h, text);	/**- Виклик функції заповлення з голови. */
		return 0;			/**- Завершення роботи функції. */
	}
	else					/**Якщо користувач вибрав неправильний символ: */
	{
		printf("Вы ввели неправильный символ. Повторите попытку.\n");
		return Choise(h, t, text);	/**- Повторний виклик функції вибору заповнення списку. */
	}
}
void CreateSpH(NotebookElSp* h, FILE* text) {
	struct NotebookElSp* p;	/**- Оголошення покажчика.*/
	while (!feof(text))		/**- Цикл, який працює поки не буде кінець файлу. */
	{
		p = (NotebookElSp*)malloc(sizeof(NotebookElSp));	/**- Виділення пам'яті для елементу списку. */
		fscanf(text, "%f%s%s%s", &p->info.ScrDiagonal, p->info.Company, p->info.Model, p->info.Bluetooth);
		fscanf(text, "%i%f%s", &p->info.Keys, &p->info.Price, p->info.System);	/**- Запис даних у структуру. */
		p->next = h->next;	/**- Переміщення покажчиків. */
		p->next->prev = p;
		p->prev = h;
		h->next = p;
	}
	fclose(text);			/**- Закриття файлу. */
}
void CreateSpT(NotebookElSp* t, FILE* text) {
	struct NotebookElSp* p;	/**- Оголошення покажчика.*/
	while (!feof(text))		/**- Цикл, який працює поки не буде кінець файлу. */
	{
		p = (NotebookElSp*)malloc(sizeof(NotebookElSp));	/**- Виділення пам'яті на елемент списку. */
		fscanf(text, "%f%s%s%s", &p->info.ScrDiagonal, p->info.Company, p->info.Model, p->info.Bluetooth);
		fscanf(text, "%i%f%s", &p->info.Keys, &p->info.Price, p->info.System);	/**- Запис даних у структуру. */
		p->prev = t->prev;	/**- Переміщення покажчика на наступні дані. */
		p->prev->next = p;
		p->next = t;
		t->prev = p;
	}
	fclose(text);			/**- Закриття файлу. */
}
void Menu(NotebookElSp* head, NotebookElSp* tail) {
	int choise, choise2;    /**- Оголошення змінних вибору дій користувача. */
	printf("\n=================\nВыбор действий:\n1)Вывести на экран\n");
	printf("2)Удалить определенный ноутбук\n3)Найти среднюю диагональ ноутбуков\n");
	printf("4)Отсортировать ноутбуки по диагонали\n5)Записать новый ноутбук\n");
	printf("6)Поменять два элемента местами\n----------------\n");
	printf("7)Сохранить в текстовый файл\n8)Сохранить в бинарный файл\n");
	printf("9)Чтение из бинарного файла\n10)Завершить работу программы\n");
	printf("================\n");
	printf("Что надо сделать? ");
	scanf("%i", &choise);		/**- Вибор дії користувачем. */

	if (head->next == tail && choise != 5 && choise != 10)	/**Якщо у структурі нема елементів: */
	{
		printf("Список пуст. Хотите добавить элемент(1) или завершить программу(0)? ");
		scanf("%i", &choise2);	/**- Введення дії користувачем. */
		if (choise2 == 0)		/**- Користувач вибрав закінчення програми: */
		{
			printf("Завершение программы.\n");
			FreeSpisok(head);		/**- Виклик функції очищення списку. */

			if (_CrtDumpMemoryLeaks())	/**- Перевірка на існування витоків пам'яті.*/
				printf("\nУтечка памяти обнаружена.");	//Витоків немає
			else
				printf("\nУтечка памяти отсутствует.");	//Витоки є
			return;				/**- Закінчення роботи програми.*/
		}
		if (choise2 == 1)		/**- Користувач вибрав додавання нових елементів: */
		{
			NewNotebook(head, tail);	/**- Виклик функції додавання нового ноутбука у список. */
			return Menu(head, tail);	/**- Виклик функції меню. */
		}
		else					/**- Користувач написав неправильний символ: */
		{
			printf("Вы выбрали что-то не так. Введите что вы хотите сделать повторно:\n");
			return Menu(head, tail);	/**- Виклик функції меню. */
		}
	}
	if (choise == 1)			/**Якщо користувач вибрав виведення списку у консоль: */
	{
		printf("Выводить список с головы(1) или с хвоста(0)? ");
		scanf("%i", &choise2);	/**- Введення варіанту виведення списку у консоль*/
		if (choise2 == 1)		/**Якщо користувач вибрав виведення з голови списку:*/
		{
			OutputScrH(head);	/**- Виклик функції виведення списку у консоль з голови. */
			return Menu(head, tail);	/**- Виклик функції меню.*/
		}

		if (choise2 == 0)		/**Якщо користувач вибрав виведення з хвоста списку:*/
		{
			OutputScrT(tail);	/**- Виклик функції виведення списку у консоль з хвоста. */
			return Menu(head, tail);	/**- Виклик функції меню. */
		}
		else printf("\nОшибка. Неверный символ.");	/**- Якщо неправильний символ: */
		return Menu(head, tail);		/**- Виклик функції меню. */
	}
	else if (choise == 2)		/**Якщо користувач вибрав виалення ноутбука зі списку: */
		DeleteNotebook(head);	/**- Виклик функції видалення ноутбуку зі списку. */
	else if (choise == 3)		/**Якщо користувач вибрав знаходження середньої диагоналі ноутбуків: */
		AverageScreen(head);	/**- Виклик функції знаходження середньої диагоналі ноутбуків. */
	else if (choise == 4)		/**Якщо користувач вибрав сортування списку: */
		SortScreen(head, tail);	/**- Виклик функції сортування списку. */
	else if (choise == 5)		/**Якщо користувач вибрав додавання нового ноутбуку у список: */
		NewNotebook(head, tail);/**- Виклик функції додавання нового елементу. */
	else if (choise == 6)		/**Якщо користувач вибрав переставлення двух елементів списку: */
		Swap(head, tail);		/**- Виклик функції переставлення двох елементів списку. */
	else if (choise == 7)		/**Якщо користувач вибрав збереження списку у текстовий файл: */
	{
		char ResultName[15] = "result.txt";
		FILE* RESULT = fopen(ResultName, "w");	/**- Відкриття текстового файлу. */
		OutputFile(head, RESULT);				/**- Виклик функції збереження списку у текстовий файл. */
		printf("Данные сохранены в файл.\n");
	}
	else if (choise == 8)		/**Якщо користувач вибрав збереження списку в бінарний файл: */
		OutputFileBinary(head);	/**- Виклик функції збереження списку у бінарний файл. */
	else if (choise == 9)		/**Якщо користувач вибрав читання даних з бінарного файлу: */
		InputFileBinary(head);	/**- Виклик функції читання даних з бінарного файлу. */
	else if (choise == 10)		/**Якщо користувач вибрав завершення програми: */
	{
		printf("Завершение программы.\n");
		FreeSpisok(head);		/**- Виклик функції очищення списку. */

		if (_CrtDumpMemoryLeaks())	/**- Перевірка на існування витоків пам'яті.*/
			printf("\nУтечка памяти обнаружена.");	//Витоків немає
		else
			printf("\nУтечка памяти отсутствует.");	//Витоки є
		return;
	}
	else						/**Якщо користувач вибрав неправильний символ: */
	{
		printf("Вы выбрали что-то не так. Введите что вы хотите сделать повторно:\n");
		return Menu(head, tail);/**- Виклик функції меню. */
	}
	return Menu(head, tail);	/**Виклик функції меню. */
}
void OutputScrH(NotebookElSp* h) {
	struct NotebookElSp* p = h->next;	/**- Оголошення покажчика на перший елемент списку. */
	printf("\nСписок:\n");
	printf("Company     Model  Screen Diagonal   Bluetooth  Keys       Price     System\n");
	int i = 1;			/**- Оголошення змінної нумерації списку. */

	while (p->next)		/**- Цикл, який працює поки не буде кінець списку. */
	{
		printf("%2i) %-7s %-12s %-9.1f", i, p->info.Company, p->info.Model, p->info.ScrDiagonal);	/**- Виведення даних у консоль. */
		printf("%8s %8i %12.2f %10s\n", p->info.Bluetooth, p->info.Keys, p->info.Price, p->info.System);
		p = p->next;	/**- Переміщення покажчика на наступний елемент. */
		i++;			/**- Збільшення змінної нумерації списку. */
	}
}
void OutputScrT(NotebookElSp* t) {
	struct NotebookElSp* p = t->prev;	/**- Оголошення покажчика на перший елемент. */
	printf("Список:\n");
	printf("Company     Model  Screen Diagonal   Bluetooth  Keys       Price     System\n");
	int i = 1;			/**- Оголошення змінної нумерації списку. */

	while (p->prev)		/**- Цикл, який працює поки не буде кінець списку. */
	{
		printf("%2i) %-7s %-12s %-9.1f", i, p->info.Company, p->info.Model, p->info.ScrDiagonal);	/**- Виведення даних у консоль. */
		printf("%8s %8i %12.2f %10s\n", p->info.Bluetooth, p->info.Keys, p->info.Price, p->info.System);
		p = p->prev;	/**- Переміщення покажчика на наступний елемент. */
		i++;			/**- Збільшення змінної нумерації списку. */
	}
}
void DeleteNotebook(NotebookElSp* h) {
	struct NotebookElSp* p = h->next;	/**- Оголошення покажчика на перший елемент. */
	int value;							/**- Оголошення змінної вибору номеру списку, який треба видалити. */
	int size = Size(h);					/**- Виклик функції знаходження розміру структури. */
	printf("Введите  номер ноутбука которой надо удалить: ");
	scanf("%i", &value);				/**- Введення змінної, яка вказує, який ноутбук потрібно видалити. */

	if (value <= 0 || value > size)		/**Якщо користувач вибрав номер, який не існує: */
	{
		printf("Ошибка. Неверный номер списка.\n");
		DeleteNotebook(h);				/**- Виклик функції видалення ноутбука. */
	}
	printf("\nНоутбук, который будет удалён: \n");
	printf("Company    Model  Screen Diagonal   Bluetooth  Keys     Price       System\n");

	for (int i = 1; i < value; i++)		/**- Цикл, який переміщує покажчик до потрібного місця. */
		p = p->next;
	printf("%-9s %-7s %9.1f %14s", p->info.Company, p->info.Model, p->info.ScrDiagonal, p->info.Bluetooth);
	printf("%8i %12.2f %10s\n", p->info.Keys, p->info.Price, p->info.System);	/**Виведення даних у консоль. */
	p->next->prev = p->prev;			/**- Переміщення покажчиків сусідніх елементів. */
	p->prev->next = p->next;
	free(p);							/**- Видалення потрібного елементу. */
}
void AverageScreen(NotebookElSp* h) {
	struct NotebookElSp* p = h->next;	/**- Оголошення покажчика на перший елемент даних. */
	float value = 0;					/**- Оголошення змінної суми діагоналей. */
	int count = 0;						/**- Оголошення змінної кількості ноутбуків. */
	while (p->next)						/**- Цикл, який працює до кінця списку. */
	{
		value += p->info.ScrDiagonal;	/**- Суммуємо диагоналі. */
		count++;						/**- Знаходимо кількість ноутбуків. */
		p = p->next;					/**- Переміщуємо покажчик на наступний елемент. */
	}

	float AvValue = value / count;		/**- Знаходимо середню диагональ. */
	printf("\nСредняя диагональ ноутбуков: %.2f", AvValue);	/**- Виведення середньої диагоналі у консоль. */
}
void SortScreen(NotebookElSp* h, NotebookElSp* t) {
	bool pr = false;					/**- Оголошення змінної, потрібної для сортування. */
	struct NotebookElSp* p = h->next;	/**- Оголошення покажчика на перший елемент списку. */

	do {								/**- Цикл, який виконує сортування. */
		pr = false;
		p = h->next;					/**- Перміщення покажчика у початок списку. */
		while (p->next)					/**- Цикл, який працює до кінця списку. */
		{
			if (p->info.ScrDiagonal > p->next->info.ScrDiagonal && p->next != t)	/**- Якщо перший елемент більше наступного: */
			{
				p->next->prev = p->prev;	/**- Переміщення покажчиків. */
				p->next->next->prev = p;
				p->prev = p->next;
				p->next = p->next->next;
				p->prev->next = p;
				p->prev->prev->next = p->prev;
				pr = true;
			}
			p = p->next;				/**- Переміщення покажчика на наступний елемент. */
		}
	} while (pr == true);
	printf("Список отсортирован.");
}
void NewNotebook(NotebookElSp* h, NotebookElSp* t) {
	int choise;						/**- Оголошуємо змінну вибору місця вставлення ноутбуку. */
	int size = Size(h);				/**- Виклик функції знаходження розміру списку. */
	struct NotebookElSp* NewNotebook = (NotebookElSp*)malloc(sizeof(NotebookElSp));	/**- Виділення пам'яті на новий елемент списку. */

	NewStroka(NewNotebook);			/**- Виклик функції запису введення даних нового ноутбуку. */

	if (h->next == t)				/**Якщо список пуст: */
	{
		printf("\nСписок пуст. Запись в первый номер списка.\n");
		NewNotebook->next = t;		/**- Переміщення покажчиків. */
		NewNotebook->prev = h;
		h->next = NewNotebook;
		t->prev = NewNotebook;
		return;						/**- Закінчення роботи функції. */
	}

	printf("После какого ноутбука записать новую строку: ");
	scanf("%i", &choise);			/**- Вибір місця, куди потрібно записати ноутбук. */

	struct NotebookElSp* p = h->next;	/**- Оголошуємо покажчик на перший елемент списку. */

	if (choise <= 0)				/**Якщо треба вставити на перше місце: */
	{
		printf("\nНоутбук будет вставлен на первую позицию.");
		NewNotebook->next = h->next;	/**- Переміщення покажчиків. */
		NewNotebook->prev = h;
		h->next->prev = NewNotebook;
		h->next = NewNotebook;
		return;						/**- Закінчення роботи функції. */
	}
	if (choise > size)				/**Якщо треба записати у кінець списку: */
	{
		p = t->prev;				/**- Переміщення покажчика на  потрібний елемент. */
		NewNotebook->next = t;		/**- Переміщення покажчиків. */
		NewNotebook->prev = p;
		p->next = NewNotebook;
		t->prev = NewNotebook;
		return;						/**- Закінчення роботи функції. */
	}
	else							/**Якщо треба записати у середину списку: */
	{
		for (int i = 0; i < choise - 1; i++)	/**- Цикл, який знаходить місце, куди потрібно записати ноутбук */
			p = p->next;			/**- Переміщення покажчиків. */
		NewNotebook->next = p->next;
		p->next->prev = NewNotebook;
		p->next = NewNotebook;
		NewNotebook->prev = p;
	}

}
NotebookElSp* NewStroka(NotebookElSp* p) {
	printf("\nВведите новый новый ноутбук с характеристиками в  столбик(!!!): \n");
	printf("Компания, модель, диагональ экрана, наличие Bluetooth, количество клавиш, цена, операционная система\n");
	scanf("%s \n%s \n%f \n%s \n", p->info.Company, p->info.Model, &p->info.ScrDiagonal, p->info.Bluetooth);
	scanf("%i \n%f \n%s", &p->info.Keys, &p->info.Price, p->info.System); /**- Запис нових даних з консолі */
	p->next = NULL;		/**- Ставимо покажчик на наступний елемент на NULL.*/
	p->prev = NULL;		/**- Ставимо покажчик на попередній елемент на NULL.*/

	return p;			/**- Повертаємо новий елемент для запису у список. */
}
void Swap(NotebookElSp* h, NotebookElSp* t) {
	struct NotebookElSp* p = h->next, * f;	/**- Оголошення покажчиків на елементи, які треба поміняти місцями.*/
	int number1, number2, temp;				/**- Оголошення змінних вибору елементів.*/
	int i = 0, j = 0, size = Size(h);		/**- Оголошення змінних, необхідних для роботи програми.*/
	OutputScrH(h);							/**- Виклик функції виведення списку у консоль.*/
	if (h->next->next == t)					/**Якщо у списку тільки 1 елемент: */
	{
		printf("В списке только 1 элемент. Возвращение функции.\n");
		return;								/**- Закінченя роботи функції.*/
	}
	printf("Введите 2 элемента через пробел, которые надо поменять местами: ");
	scanf("%i %i", &number1, &number2);		/**- Введення номерів елементів, які треба поміняти місцями.*/

	if (number1 > size || number2 > size || number1 < 1 || number2 < 1) {	/**Якщо користувач ввів помилкові символи:*/
		printf("Ошибка. Неверные номера символов. Завершение программы");
		return Swap(h, t);					/**- Виклик функції зміни місцями двух елементів.*/
	}

	if (number1 == number2) {				/**Якщо користувач ввів однакові елементи: */
		printf("Ошибка. Вы ввели 2 одинаковых символа.");
		return Swap(h, t);					/**- Виклик функції зміни місцями двух елементів.*/
	}

	if (number1 > number2) {				/**Якщо перший номер елементу більше другого: */
		temp = number1;						/**- Змінюємо змінні номерів елементів.*/
		number1 = number2;
		number2 = temp;
	}

	while (i < number1-1) {					/**- Цикл переміщення першого покажчика.*/
		p = p->next;						/**- Переміщення першого покажчика на наступний елемент.*/
		i++;
	}
	f = p;
	while (j < number2 - number1) {			/**- Цикл переміщення другого покажчика.*/
		f = f->next;						/**- Переміщення другого покажчика на наступний елемент.*/
		j++;
	}

	if (p->next == f)						/**Якщо треба поміняти місцями два сусідніх елемента:*/
	{
		p->next = f->next;					/**- Переміщення покажчиків.*/
		f->next = p;
		p->next->prev = p;
		f->prev = p->prev;
		p->prev->next = f;
		p->prev = f;
	}
	else									/**Якщо треба поміняти місцями не сусідні елементи: */
	{
		p->next->prev = f;					/**- Переміщення покажчиків.*/
		f->next->prev = p;
		p->prev->next = f;
		f->prev->next = p;
		f = p->next;
		p->next = p->prev->next->next;
		p->prev->next->next = f;
		f = p->prev;
		p->prev = f->next->prev;
		p = f->next;
		p->prev = f;
	}
}
void OutputFile(NotebookElSp* h, FILE* text) {
	struct NotebookElSp* p = h->next;	/**- Оголошення покажчика на перший елемент. */
	int i = 1;							/**- Оголошення змінної нумерації списку. */
	fprintf(text, "  Company    Model  Screen Diagonal   Bluetooth  Keys     Price       System\n");
	while (p->next)						/**- Цикл, який працює до кінця списку. */
	{
		fprintf(text, "%2i) %-7s %-12s %-10.1f", i, p->info.Company, p->info.Model, p->info.ScrDiagonal);  /**- Виведення елементів у файл. */
		fprintf(text, "%8s %8i %12.2f %10s\n", p->info.Bluetooth, p->info.Keys, p->info.Price, p->info.System);
		p = p->next;					/**- Переміщення покажчина на наступний елемент. */
		i++;							/**- Збільшення змінної нумерації списку. */
	}
	fclose(text);						/**- Закриття файлу. */
}
void OutputFileBinary(NotebookElSp* h) {
	struct NotebookElSp* p = h->next;	/**- Оголошення покажчика на перший елемент списку.*/
	FILE* RESULTBINARY = fopen("resultbinary.bin", "w+b");	/**- Відкриття бінарного файлу.*/

	while (p->next) {					/**- Цикл, який записує дані у бінарний файл.*/
		fwrite(&p->info, sizeof(Notebook), 1, RESULTBINARY);/**- Запис у бінарний файл.*/
		p = p->next;					/**- Переміщення покажчика на наступний елемент.*/
	}
	fclose(RESULTBINARY);				/**- Закриття бінарного файлу.*/
	printf("Данные сохранены в бинарный файл");
}
void InputFileBinary(NotebookElSp* h) {
	struct NotebookElSp* p = h->next;	/**- Оголошення покажчика на перший елемент списку.*/
	FILE* ResultBinary = fopen("resultbinary.bin", "r+b");	/**- Відкриття бінарного файлу.*/
	if (!ResultBinary)		/**- Перевірка на існування файлу.*/
	{
		printf("Файл не существует. Чтение невозможно.\n");
		return;
	}
	while (p->next) {		/**- Цикл, який записує дані З файлу.*/
		fread(&p->info, sizeof(Notebook), 1, ResultBinary);	/**- Запис даних у список.*/
		p = p->next;		/**- Переміщення покажчика на наступний елемент.*/
	}
	fclose(ResultBinary);	/**- Закриття файлу.*/
}
int Size(NotebookElSp* h) {
	struct NotebookElSp* p = h->next;	/**- Оголошення покажчика на перший елемент. */
	int size = 0;						/**- Оголошення змінної розміру списку.*/

	while (p->next)						/**- Цикл, який працює до кінця списку.*/
	{
		size++;							/**- Збільшення змінної розміру списку.*/
		p = p->next;					/**- Переміщення покажчика на наступний елемент.*/
	}

	return size;						/**- Поверення змінної розміру списку.*/
}
void FreeSpisok(NotebookElSp* h) {
	struct NotebookElSp* p = h;		/**- Оголошення покажчика. */

	while (p)					/**- Цикл, який працює до кінця списку. */
	{
		h = p;
		p = p->next;			/**- Переміщення покажчика на наступний елемент. */
		free(h);				/**- Видалення елементу. */
	}
}



