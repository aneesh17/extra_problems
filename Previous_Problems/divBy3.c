/*
Program: To check if the given number is divisible by 3
A number is divisible by 3 if the sum of all its digits is divisible by 3
Example: let input= 2358
sum=2+3+5+8=18 which is divisible by 3
So 2358 is divisible by 3
A number N if divisible by a number D,even if repeated R times will still 
be divisible by D. In case of 3, it is so because the sum of digits after
repetition will be a multiple of the number before repetition
So it is enough to check if the entered number is divisible or not
*/
#include<stdio.h>
int divisible_by_3(char *, int);
main()
{
	int length = 50, flag = 0, repetitions, result;
	char *input = malloc(length), ch;
	puts("Enter number and press return");
	scanf("%c", &ch);
	puts("Enter number of repetitions");
	scanf("%d", &repetitions);
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
	result = divisible_by_3(input, length);
	(result % 3 == 0) ? puts("Divisible by 3") : puts("Not Divisible by 3");
	//free(input);
	getch();
}
int divisible_by_3(char *input, int length)
{
	int flag, sum = 0;
	for (flag = 0;flag < length;flag ++)//calculating sum of digits to check if it is divisible by 3
	{
		sum += input[flag] - '0';
	}	
	return(sum);
}
