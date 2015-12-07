/*
Program: To check if given number is divisible by 11
A number is divisible by 11 if difference of sum digits in odd and even places
in the number is 11 or 0
Example: let input=7172
odd=7+7=14
even=1+2=3
odd-even = 14-3=11
So 7172 is divisible by 11
*/
#include<stdio.h>
int divisible_by_11(char *, int);
main()
{
	int length = 50, flag = 0, result;
	char *input = malloc(length), ch;
	puts("Enter number and press return");
	scanf("%c", &ch);
	//getting input and checking for non numbers on each input
	while (ch != 10)
	{
		if (ch< 48 || ch> 57)
		{
			puts("Non number entered");
			exit(1);
		}
		input[flag++] = ch;
		if (flag == length)
		{
			length += 20;
			input = realloc(input, length);
		}
		scanf("%c", &ch);
	}
	length = flag;
	result = divisible_by_11(input, length);
	(result == 0 || result % 11 == 0) ? puts("Divisible by 11") : puts("Not Divisible by 11");
	//free(input);
	getch();
}
int divisible_by_11(char *input, int length)
{
	int flag;
	int odd = 0, even = 0;//stores the sum of numbers at odd and even positions of the number
	for (flag = 0;flag < length;flag += 2)//calculating sum of numbers at odd positions
	{
		odd += input[flag] - '0';
	}
	for (flag = 1;flag < length;flag += 2)//calculating sum of numbers at even positions
	{
		even += input[flag] - '0';
	}
	return(odd - even);
}
