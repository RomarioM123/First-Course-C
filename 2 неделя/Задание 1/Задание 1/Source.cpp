#include <math.h>
int main()
{
	int in, F, ik = 2, x; //объ€вл€ем первый и последний элементы р€да (in, ik), число в синусе (x), факториал числа (F)
	double sum = 0;
	in = F = x = 1;
	
	for (int d = 1; in <= ik; in++)
	{
		F *= in;
		x *= d;
		sum += F / sin(x);
	}
	return sum;
}
