#include "header.h"
int main()
{
	setlocale(LC_ALL, "Russian");   /**- Русіфікація консолі. */
	char str1[N], str2[N];          /**- Оголошення масивів для текстів. */
	char* text1;					/**- Оголошення покажчика для текста 1. */
	char* text2;				
	text1 = str1;
	text2 = str2;

	ReadFile(text1, text2);			/**- Виклик функції читання з файлу. */
	if (ReadFile == false)			/**- Перевірка існування файлів з текстами. */
		return 0;

	int size1 = Size(text1);		/**- Виклик функції знаходження розміру першого тексту. */
	int size2 = Size(text2);		/**- Виклик функції знаходження розміру другого тексту. */

	printf("Text 1: \n");
	printf("%s\n", str1);			/**- Виведення першого тексту у консоль. */
	printf("\nText 2: \n");
	printf("%s\n", str2);			/**- Виведення другого тексту у консоль. */

	int MatchedNumber = Comparison(text1, text2, size1, size2);        /**- Виклик функції порівняння текстів. */
	printf("\nNumber of matched symbols in texts: %i", MatchedNumber); /**- Виведення кількості символів які збіглися консоль. */
	float PercentMatched = Percent(MatchedNumber, size1, size2);       /**- Виклик функції знаходження відсотка збігів. */

	printf("\nAmount of symbols: %i", size1 + size2);				   /**- Виведення кількості символів у консоль. */
	printf("\nPercent of matched symbols: %.2f\n", PercentMatched);    /**- Виведення відсотка збігів у консоль. */

	if (_CrtDumpMemoryLeaks())					/**- Перевірка витоків пам'яті. */
		printf("\nMemory leak detected.");		/**- Ввиденення у консоль тексту про відсутність витоків. */
	else
		printf("\nThere is no memory leak.");	/**- Ввиденення у консоль тексту про наявність витоків. */

	return 0;
}
