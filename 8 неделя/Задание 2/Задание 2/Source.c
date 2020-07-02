#define _CRT_SECURE_NO_WARNINGS
#define CRTDBG_MAP_ALLOC                          
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE, LINE)
#define new DEBUG_NEW
#include <stdio.h>  
#include <stdlib.h>
#define N 200
int Size(char*);
char Count(char*, int);
char CountWords(char*, int, int*, int);
int BiggestSentence(int*, int);
int main()
{
	FILE* text;
	text = fopen("text.txt", "r");
	char str[N];

	if (text == NULL)
		return 0;

	fgets(str, N, text);
	fclose(text);

	char* pStr;
	pStr = str;

	int size = Size(pStr);
	int count = Count(pStr, size);

	printf("Your sentence:\n%s\n", pStr);
	printf("\nNumber of sentences: %i\n", count);
	
	int* pSenArr = (int*)malloc(sizeof(int) * count);

	int a = 0;
	int* copypSenArr;
	copypSenArr = pSenArr;

	for (int i = 1; i <= count; i++)
	{
		int WordCount = CountWords(pStr, size, pSenArr, a);
		printf("\nNumber of words in sentence %i: %i", i, *pSenArr);
		pSenArr++;
		a = a + WordCount + 2;
	}
	pSenArr = copypSenArr;
	int i = 0;
	int Max = BiggestSentence(pSenArr, count);
	printf("\nBiggest sentence: %i (%i words)", Max, *(pSenArr+Max-1));
	
	if (_CrtDumpMemoryLeaks == 1)
		printf("\nThere is a memory leak.");				
	else
		printf("\n\nNo memory leak.");
	return 0;
}
int Size(char* text)
{
	int size = 0, i = 0;
	
	do {
		size++;
		i++;
	} while (*(text + i) != '\0');
	
	return size-1;
}
char Count(char* text, int size)
{
	int i = 0, count = 0;

	for (i = 0; i < size; i++)
		if (*(text + i) != '.' && (*(text + i + 1) == '.' || *(text + i + 1) == '\n'))
			count++;
	return count;
}
char CountWords(char* text, int size, int* pSenArr, int a)
{
	int WordCount = 0, i = 0;
	
	for (i = a; i < size; i++)
	{
		if (*(text + i) != ' ' && (*(text + i + 1) == ' ' || *(text + i + 1) == '.' || *(text + i + 1) == '!' || *(text + i + 1) == '?' || *(text + i + 1) == '\n'))
			WordCount++;
		if (*(text + i+1) == '.' || *(text + i+1) == '?' || *(text + i + 1) == '!' || *(text + i + 1) == '\n')
		{
			*pSenArr = WordCount;
			return i;
		}
	}
}
int BiggestSentence(int* pSenArr, int count)
{
	int Max = *pSenArr;
	for (int i = 0; i < count; i++)
		if (Max < &*pSenArr++)
			Max = i;
	return Max;
}
