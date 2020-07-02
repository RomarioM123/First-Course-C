#define _CRT_SECURE_NO_WARNINGS
#define CRTDBG_MAP_ALLOC
#define DEBUG_NEW new(_NORMAL_BLOCK, FILE, __LINE)
#define new DEBUG_NEW
#include <string.h> 
#include <crtdbg.h> 

#include <stdio.h> 
#include <stdlib.h> 
#include <locale.h> 

struct Integer {
	int number;
};

struct TElSp {
	Integer info;
	TElSp* next;
};

TElSp* InitSp();
FILE* OpenFile();
void CreateSp(TElSp*, FILE*);
void WriteSp(TElSp*);
void SortSp(TElSp*);
void DeleteSp(TElSp*);
void DeleteEvenSp(TElSp*);

int main() {
	setlocale(LC_ALL, "Rus");
	
	struct TElSp* head = InitSp();
	FILE* f = OpenFile();
	CreateSp(head, f);
	WriteSp(head);
	SortSp(head);
	WriteSp(head);
	DeleteEvenSp(head);
	WriteSp(head);

	DeleteSp(head);
	if (_CrtDumpMemoryLeaks())
		printf("\nУтечка памяти обнаружена.");
	else
		printf("\nУтечка памяти отсутствует.");
}

TElSp* InitSp() {
	struct TElSp* p = (struct TElSp*)malloc(sizeof(TElSp));
	p->next = NULL;
	return p;
}
FILE* OpenFile() {
	FILE* fl = fopen("Text.txt", "r");
	if (!fl) return NULL;
	return fl;
}
void CreateSp(TElSp* h, FILE* f) {
	TElSp* p = h;
	while (!feof(f)) {
		p->next = (TElSp*)malloc(sizeof(TElSp));
		p = p->next;
		fscanf(f, "%i", &p->info);
	}
	p->next = NULL;
	fclose(f);
}
void WriteSp(TElSp* h) {
	TElSp* p = h->next;
	while (p) {
		printf("%i ", p->info);
		p = p->next;
	}
	printf("\n");
}
void SortSp(TElSp* h) {
	bool pr = false;
	struct TElSp* temp;
	struct TElSp* p = h->next;
	struct TElSp* end = NULL;

	do {							/**Цикл, який робить сортування. */
		pr = false;
		p = h->next;
		while (p->next)
		{
			if (p->info.number > p->next->info.number)	/**Якщо перший елемент краще наступного: */
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
	printf("\nЧисла после сортировки: \n");
}
void DeleteSp(TElSp* h) {
	struct TElSp* p = h;
	while (p) {
		h = p;
		p = p->next;
		free(h);
	}
}
void DeleteEvenSp(TElSp* h) {
	struct TElSp* p = h->next;
	struct TElSp* f = p->next;

	while (f) {
		p->next = f->next;
		free(f);
		if (p->next == NULL) break;
		p = p->next;
		f = p->next;
	}
	printf("\nЧисла после удаления чётных элементов: \n");
}