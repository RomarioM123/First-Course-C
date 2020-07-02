#define _CRT_SECURE_NO_WARNINGS
#define CRTDBG_MAP_ALLOC                          
#include <crtdbg.h>				    /**< Підключення бібліотеки відстеження витоку пам'яті. */
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE, LINE)
#define new DEBUG_NEW
#include <stdio.h>		 /**< Підключення бібліотеки для вводу та виводу інформації. */   
#define N 200
char Count(char*);
int main()
{
	FILE *text;
	text = fopen("text.txt", "r");
	int choise;
	char str[N];

	if (text == NULL)
		return 0;
		
	fgets(str, N, text);
	fclose(text);
	
	char* pStr;
	pStr = str;

	int count = Count(pStr);
	printf("Your sentence:\n %s", pStr);
	printf("\nNumber of words: %i", count);
	return 0;
}

char Count(char* text)
{
	int size = -1, i = 0, count = 0;

	do {
		size++;
		i++;
	} while (*(text+i) != '\0');

	for (i = 0; i < size; i++)
		if (*(text + i) != ' ' && (*(text + i + 1) == ' ' || *(text + i + 1) == '\n' || *(text + i + 1) == '?' || * (text + i + 1) == '!'))
			count++;
	return count;
}
