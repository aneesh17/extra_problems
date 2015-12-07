#include<stdio.h>
int input(char*);
int *adder(char*, int, char*, int);
main()
{
	int length_for_num1 = 30, length_for_num2 = 30,flag;
	char* number1 = malloc(length_for_num1);
	char* number2 = malloc(length_for_num2);
	puts("Enter first number");
	length_for_num1 = input(number1);
	puts("Enter second number");
	length_for_num2 = input(number2);	
	int length = (length_for_num1 >= length_for_num2) ? (length_for_num1 + 1) : (length_for_num2 + 1);
	int *result = malloc(length*sizeof(int));
	result = adder(number1, length_for_num1 - 1, number2, length_for_num2 - 1);
	for (flag = 0;flag < length;flag++)
		printf("%d", result[flag]);
	free(number1);
	free(number2);
	free(result);
	getch();
}

int input(char* input)
{
	int flag = 0, length = 30;
	scanf("%c", &input[flag]);
	while (input[flag] != 10)
	{
		if (flag == length - 1)
		{
			length += 20;
			realloc(input, length);
		}
		scanf("%c", &input[++flag]);
	}
	return(flag);
}

 int* adder(char* number1,int length_for_num1, char* number2, int length_for_num2)
{
	int length = (length_for_num1 >= length_for_num2) ? (length_for_num1+2) : (length_for_num2+2);
	int flag, carry = 0, temp_for_add;
	int *result = malloc(length*sizeof(int));
	for (flag = length - 1;length_for_num1 >= 0 && length_for_num2 >= 0;)
	{
		temp_for_add = number1[length_for_num1] - '0' + number2[length_for_num2] - '0';
		result[flag] = carry + temp_for_add % 10;
		carry = temp_for_add / 10;
		--flag;
		--length_for_num1;
		--length_for_num2;
	}
	if (length_for_num1 < 0)
	{
		while (length_for_num2 >= 0)
		{
			temp_for_add = carry + number2[length_for_num2] - '0';
			result[flag] = temp_for_add % 10;
			carry = temp_for_add / 10;
			flag--;
			length_for_num2--;
		}
	}
	else
	{
		while (length_for_num1 >= 0)
		{
			temp_for_add = carry + number1[length_for_num1] - '0';
			result[flag] = temp_for_add % 10;
			carry = temp_for_add / 10;
			flag--;
			length_for_num1--;
		}
	}
	result[flag] = carry;
	return(result);
}
