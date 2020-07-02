#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#define CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, FILE, __LINE)
#define new DEBUG_NEW
 
#include <stdio.h>
#include <stdlib.h>
#define SIZE 5        //макс. кол-во товаров

struct Products
{
	char name[20];     //название товара
	float price;       //цена товара
};

void ReadFile(Products list[]);
void MaxPrice(Products list[]);
void SumPrice(Products list[]);

int main()
{
	Products goods[SIZE];
	
	ReadFile(goods);
	MaxPrice(goods);
	SumPrice(goods);

	if (_CrtDumpMemoryLeaks())	
		printf("\nMemory leak detected.");
	else
		printf("\nNo memory leak.");
}

void ReadFile(Products list[])
{
	FILE* TEXT = fopen("text.txt", "r");
	if (!TEXT)
		return;

	for (int i = 0; i < SIZE; i++)
	{
		fscanf(TEXT, "%s", list[i].name);

		if (list[i].name[0] < ((int)'A') || list[i].name[0] > ((int)'z'))
		{
			fclose(TEXT);
			return;
		}

		printf("Name of product: %s\n", list[i].name);
		printf("Price:");
		fscanf(TEXT, "%f", &list[i].price);
		printf(" %.3f\n\n", list[i].price);
	}
	fclose(TEXT);
}
void MaxPrice(Products list[])
{
	float Max = list[0].price;
	int i = 0, number;
	
	for (i = 1; i < SIZE; i++)
	{
		if (list[i].name[0] < ((int)'A') || list[i].name[0] > ((int)'z'))
			break;
		
		if (Max < list[i].price)
		{
			Max = list[i].price;
			number = i;
		}
			
	}
	printf("Most expensive product: %s\n", list[number].name);
}
void SumPrice(Products list[])
{
	float sum = 0;

	for (int i = 0; i < SIZE; i++)
	{
		if (list[i].name[0] < ((int)'A') || list[i].name[0] > ((int)'z'))
			break;
		sum += list[i].price;
	}
		
	printf("Price of all products: %.2f\n", sum);
}

