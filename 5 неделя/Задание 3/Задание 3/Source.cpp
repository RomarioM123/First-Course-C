#include <stdlib.h>
#define N 3
#define M N
int Form(int mas[]);
int main()
{
	int mas[N * M];

	Form(mas);
}

int Form(int mas[])
{
	int i = 0;

	for (i = 0; i < N * M; i++)
		mas[i] = rand() % 10;

	return mas[i];
}