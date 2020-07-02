//Iндивiдуальне завдання: За допомогою цикла, визначити, скiльки значень може приймати тип short.
//Автор: Момот Роман

int main()
{
	short maxfor = -1, x = 1;             //оголошуємо ідент. для максимального значення short (for)
	short MinDoWhile = 0, MinWhile = 0;   //оголошуємо ідент. для мінімального значення short (do while)

	for (int i = -1; maxfor <= 0; )       //знаходимо верхнє обмеження short через for
		maxfor -= x;

	do {                                  //знаходимо нижнє обмеження short через do while
		MinDoWhile += x;
	} while (MinDoWhile >= 0);

	while (MinWhile >= 0)                 //знаходимо нижнє обмеження short через while
		MinWhile += x;

}