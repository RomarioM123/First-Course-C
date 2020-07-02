#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#define CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, FILE, __LINE)
#define new DEBUG_NEW

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#define N_BALL 5    //макс. кол-во баллов
#define N_STUD 5    //макс. кол-во студентов

struct Tstud
{
	char name[20];
	int mark[N_BALL];
	float avMark[N_STUD];
};

void ReadFile(Tstud gr[], int);
void SpisoKStepend(Tstud gr[], int);
void SpisokDolg(Tstud gr[], int);
float srBall(int mas[], int);

int main(){
	Tstud grp[N_STUD];
	
	ReadFile(grp, N_STUD);
	SpisoKStepend(grp, N_STUD);
	SpisokDolg(grp, N_STUD);

	if (_CrtDumpMemoryLeaks())	/**- Перевірка на існування витоків пам'яті.*/
		printf("\nMemory leak detected.");	//Витоків немає
	else
		printf("\nNo memory leak.");	//Витоки є
}

void ReadFile(Tstud gr[], int n){
	FILE* TEXT = fopen("text.txt", "r");
	if (!TEXT)
		return;

	for (int i = 0; i < n; i++){
		fscanf(TEXT, "%s", gr[i].name);

		if (gr[i].name[0] < ((int)'A') || gr[i].name[0] > ((int)'z')){
			fclose(TEXT);
			return;
		}

		printf("Name of the student: %s\n", gr[i].name);
		printf("His marks:");
		
		for (int j = 0; j < N_BALL; j++){
			fscanf(TEXT, "%d", &gr[i].mark[j]);
			printf(" %2d", gr[i].mark[j]);
		}
		
		gr[i].avMark[i] = srBall(gr[i].mark, N_STUD);
		printf("\nHis average mark: %.2f\n\n", gr[i].avMark[i]);

	}
	fclose(TEXT);
}
void SpisoKStepend(Tstud gr[], int n)
{
	int num = 0;
	printf("List of students who will get scholarship");
	for (int i = 0; i < n; i++){
		if (gr[i].name[0] < ((int)'A') || gr[i].name[0] > ((int)'z'))
			return;
		if (gr[i].avMark[i] >= 4.5){
			printf(" \n%d) %s\n", num + 1, gr[i].name);
			num++;
		}
	}
}
float srBall(int mas[], int n)
{
	float sum = 0;
	
	for (int j = 0; j < n; j++)
		sum += mas[j];
	sum /= n;
	
	return sum;
}
void SpisokDolg(Tstud gr[], int n)
{
	printf("\nDeduction list:\n");
	int num = 0;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < N_BALL; j++){
			if (gr[i].name[0] < ((int)'A') || gr[i].name[0] > ((int)'z'))
				return;
			
			if (gr[i].mark[j] < 3){
				printf("%d) %s\n", num + 1, gr[i].name);
				num++;
				break;
			}
		}
}
			