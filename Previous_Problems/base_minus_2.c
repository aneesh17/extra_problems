/*
Program: To find out the base(-2) of a decimal number.
We repeatedly keep dividing the given decimal number by 2 and print its remainder.
Whenever and odd position occurs(count starting from 0) we add the remainder to the number
and continue.
This is done till the number becomes 0.
*/
#include<stdio.h>
int base10_to_base_minus2(int number, int *result);
struct test
{

};
main()
{
	int number, length = 5;;
	int *baseTwo = malloc(length * sizeof(int));
	puts("Enter number:");
	scanf("%d", &number);
	length = base10_to_base_minus2(number, baseTwo);

	for (number = length - 1;number >= 0;number--)
	{
		printf("%d", baseTwo[number]);
	}
	getch();
}
int base10_to_base_minus2(int number, int* baseTwo)// Function to calculate base(-2)
{
	int index = 0, length = 5;
	for (index = 0;number>0;index++)
	{
		if (index == length)
		{
			length += 5;
			baseTwo = realloc(baseTwo, length*sizeof(int));
		}
		baseTwo[index] = number % 2;//adding the remainder to the result array

		/*In the following statement we check for the index. If it is odd, we divide
		  and add the remainder to the number. This is done in order to account for the
		  negative values like -2,-8 etc.
		*/

		number = (index % 2 == 1) ? (number / 2 + baseTwo[index]) : (number / 2);
	}
	return(index);
}
