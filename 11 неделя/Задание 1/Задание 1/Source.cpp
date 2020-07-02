#define _CRT_SECURE_NO_WARNINGS
#define CRTDBG_MAP_ALLOC
#define DEBUG_NEW new(_NORMAL_BLOCK, FILE, __LINE)
#define new DEBUG_NEW
#include <string.h> 
#include <crtdbg.h> 

#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

struct TElSp {
	int info;
	struct TElSp* next;
	struct TElSp* prev;
};

struct TElSp* Init();
void InitSp(TElSp*, TElSp*);
FILE* OpenFile();
void PrintH(TElSp*);
int AddT(TElSp*, FILE*);
void Swap(TElSp*, int);
void FreeSpisok(TElSp*);

int main() 
{
	setlocale(LC_ALL, "Rus");
	struct TElSp* h = Init();
	struct TElSp* t = Init();
	
	FILE* text = OpenFile();
	if (text == NULL) {
		printf("Файл не может быть открыт. Завершение работы");
		FreeSpisok(h);
		return 0;
	}
	
	InitSp(h, t);
	int size = AddT(t, text);
	PrintH(h);
	Swap(h, size);
	PrintH(h);
	FreeSpisok(h);

	if (_CrtDumpMemoryLeaks())
		printf("\nУтечка памяти обнаружена.");
	else
		printf("\nУтечка памяти отсутствует.");
	return 0;
}

struct TElSp* Init() {
	struct TElSp* p = (struct TElSp*)malloc(sizeof(TElSp));
	return p;
}
FILE* OpenFile() {
	FILE* text = fopen("Text.txt", "r");
	if (!text) return NULL;
	return text;
}
void InitSp(TElSp* h, TElSp* t) {
	h->next = t;
	h->prev = NULL;
	t->next = NULL;
	t->prev = h;
}
int AddT(struct TElSp* t, FILE* text) {
	struct TElSp* Add;
	int size = 0;

	while (!feof(text)) {
		Add = (TElSp*)malloc(sizeof(TElSp));
		fscanf(text, "%i", &Add->info);
		Add->prev = t->prev;
		Add->prev->next = Add;
		Add->next = t;
		t->prev = Add;
		size++;
	}
	fclose(text);
	return size;
}
void PrintH(struct TElSp* h) {
	struct TElSp* p = h->next;

	while (p->next) {
		printf("%-3i", p->info);
		p = p->next;
	}

}
void Swap(TElSp* h, int size) {
	struct TElSp* p = h->next, * f;
	int number1, number2, temp;
	int i = 0, j = 0;

	printf("\nВведите 2 элемента через пробел, которые надо поменять местами: ");
	scanf("%i %i", &number1, &number2);

	if (number1 > size || number2 > size || number1 < 1 || number2 < 1) {
		printf("Ошибка. Неверные номера символов. Завершение программы");
		return Swap(h, size);
	}

	if (number1 == number2) {
		printf("Ошибка. Вы ввели 2 одинаковых символа.");
		return Swap(h, size);
	}

	if (number1 > number2) {
		temp = number1;
		number1 = number2;
		number2 = temp;
	}

	while (i < number1-1) {
		p = p->next;
		i++;
	}
	f = p;
	while (j < number2 - number1) {
		f = f->next;
		j++;
	}

	if (p->next == f)
	{
		p->next = f->next;
		f->next = p;
		p->next->prev = p;
		f->prev = p->prev;
		p->prev->next = f;
		p->prev = f;
	}
	else
	{
		p->next->prev = f;
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
void FreeSpisok(TElSp* h) {
	struct TElSp* p = h;

	while (p){
		h = p;
		p = p->next;
		free(h);
	}
}