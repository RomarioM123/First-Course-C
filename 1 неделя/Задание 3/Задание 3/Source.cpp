#include <cmath>
#include <stdlib.h>
int main()
{
	double x = 2,y, B = tan(x);
	double A = (x * x + sqrt(pow(x, 4) + x)) / (0.05 * x);
	char err;

	if (x == 0)
		err = 'e';
	else
		y = ((pow(sin(pow(A, 3)), 2)) - (log2(fabs(B)))) / (sqrt(0.01 + abs(A)));
}