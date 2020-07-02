#include <stdlib.h>
#define N 5
int main()
{
	int mas[N], i, min;

	for (i = 0; i < N; i++)
		mas[i] = rand() % 9 - rand() % 9;
	
	min = mas[0];
	
	for (i = 0; i < N; i++)
		if (mas[i] < min)
			min = mas[i];
}

