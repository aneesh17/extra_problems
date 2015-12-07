#include<stdio.h>
int modulo(int, int, int);
main()
{
	int base, exponent, mod, result;
	puts("Enter values for base exponent and mod respectively");
	scanf("%d%d%d", &base, &exponent, &mod);
	printf("(base^exponent) %% mod=%d", modulo(base, exponent, mod));		
	getch();
}
int modulo(int base, int exponent, int mod)
{
	int result = 1;
	while (exponent > 0)
	{
		if (exponent % 2 == 1)
		{
			result = (result*base) % mod;
			exponent -= 1;
		}
		else
		{
			base = (base*base) % mod;
			exponent /= 2;
		}
	}
	return(result);
}