#include<stdio.h>
int minRank(char input[], int length);//function calculating the required minrank
int factorial(int);
int permutation(int *,int *);
main()
{
	char input[9], ch;
	int result, length = 0;
	puts("Enter number and press return");
	scanf("%c", &ch);
	//getting input and checking for non numbers or each input
	while (ch != 10)
	{
		if (ch< 48 || ch> 57)
		{
			puts("Non number entered");
			exit(1);
		}
		input[length++] = ch;
		scanf("%c", &ch);
	}
	result = minRank(input, length);
	getch();
}

int minRank(char input[], int length)
{
	int repetition[10] = { 0 };//stores the number of occurrences of each digit int its repective index
	int permutate[10] = { 0 };
	int flag, flag1, result = 0;
	int number = 0;//number of numbers less than the number at ith index
	for (flag1 = 0;flag1 < 10;flag1++)
	{
		++repetition[input[flag1] - '0'];
	}
	for (flag1 = 0;flag1 < 10;flag1++, number = 0)
		printf("%d", repetition[flag1]);
	permutation(repetition, permutate, length - 1);
	for (flag1 = 0;flag1<length;flag1++, number = 0)
	{
		for (flag = flag1 + 1;flag<length;flag++)//checks for the numbers less than the number at 'flag1' index
		{
			if (input[flag1]>input[flag])
			{
				result += permutation(repetition, length - flag1 - 1);
			}
		}
		--repetition[input[flag1] - '0'];
	}
	return(result);
}
int factorial(int num)
{
	if (num == 0 || num == 1)
		return 1;
	else
		return(num*factorial(num - 1));
}

int permutation(int *repetion,int index)//Returns the number of permutations possible for the given number
{
	int flag1, mult = 1;
	for (flag1 = 0;flag1 < 10;flag1++)
	{
			mult *= factorial(repetion[flag1]);
	}
	return(factorial(index) / mult);
}

/*
Example:
input[]=3421
in the minrank function, first loop obtains number =2 i.e. 3 is in the 2nd index amongst the sorted numbers..
so there are 3*factorial(3) permutations above it. i.e 12(0-11)
so requied index is from 12-17... and so on
*/
