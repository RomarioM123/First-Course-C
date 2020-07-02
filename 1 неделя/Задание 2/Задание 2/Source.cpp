int main()
{
	char a = 'x';
	int r = 6;
	double pi = 3.14, S, V, l;

	if (a == 'S')
			S = pi * r * r;
	else if (a == 'V')
			V = (4 * pi * r * r * r) / 3;
	else if (a == 'l')
			l = 2 * pi * r;
	else
			(r = 'e');
}