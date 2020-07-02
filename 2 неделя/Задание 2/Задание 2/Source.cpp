#include <math.h>
int main()
{
	double in, F, ik = 6, x, sum = 0, A = 4; //объ€вл€ем первый и последний элементы р€да (in, ik), число в синусе (x), факториал числа (F)
	in = F = x = 1;

	for (int d = 1; sum <= A; in++)
	{
		F *= in;
		x *= d;
		sum += F / sin(x);
	}
	return sum;
}
