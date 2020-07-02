#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#define CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, FILE, __LINE)
#define new DEBUG_NEW

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 3

struct Products {
	char name[15];
	float amount;
	float PurchasePrice;
	float SellingPrice;
};

bool ReadFile(Products list[]);
void OutputScreen(Products list[], float*);
void Sort(Products list[]);
void BenefitFind(Products list[], float*);

int main() {
	setlocale(LC_ALL, "Rus");
	Products list[SIZE];
	float benefit[SIZE];
	float* pBenefit;
	pBenefit = benefit;
	
	ReadFile(list);
	if (ReadFile == false) return 0;
	Sort(list);
	BenefitFind(list, pBenefit);
	OutputScreen(list, pBenefit);

	if (_CrtDumpMemoryLeaks())
		printf("\nУтечка памяти обнаружена.");
	else
		printf("\nНет утечки памяти.");
}

bool ReadFile(Products list[]) {
	FILE* TEXT = fopen("Text.txt", "r");
	if (!TEXT) return false;
	
	for (int i = 0; i < SIZE; i++)
	{
		fscanf(TEXT, "%s%f", &list[i].name, &list[i].amount);
		fscanf(TEXT, "%f %f", &list[i].PurchasePrice, &list[i].SellingPrice);
	}
		
	fclose(TEXT);
	return true;
}
void OutputScreen(Products list[], float* benefit) {
	printf("Список товаров: \n");
	printf("Название товара  Количество   Цена Покупки   Цена Продажи       Выгода\n");
	for (int i = 0; i < SIZE; i++)
	{
		printf("%2i) %-13s %-15.2f ", i + 1, list[i].name, list[i].amount);
		printf("%-15.2f %-15.2f", list[i].PurchasePrice, list[i].SellingPrice);
		printf("%.2f\n", *(benefit + i));
	}
		
}
void Sort(Products list[]) {
	bool pr;
	struct Products temp;

	do {
		pr = false;
		for(int i = 0; i < SIZE - 1; i++)
			if (strcmp(list[i].name,list[i + 1].name) > 0)
			{
				temp = list[i];
				list[i] = list[i + 1];
				list[i + 1] = temp;
				pr = true;
			}
	} while (pr == true);

	printf("Список отсортирован по названию\n");
}
void BenefitFind(Products list[], float* benefit) {
	for (int i = 0; i < SIZE; i++)
		* (benefit + i) = list[i].PurchasePrice - list[i].SellingPrice;
}