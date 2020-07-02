int main()
{
	int n = 8, d = 1;

	if (n % 2 == 0)
	{
		for (int i = 2; i <= n; i += 2)
			d *= i;
	}
	else
	{
		for (int i = 1; i <= n; i += 2)
			d *= i;
	}
}