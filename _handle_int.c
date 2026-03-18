#include "printf.h"
#include <unistd.h>

/**
 * intp - retrieve int value and print it
 * @args: pointer to the int value
 */
void intp(va_list args)
{
	int a, i, remains, last_digit;
	char arr[12];

	int n = va_arg(args, int);

	for (i = 0; i < 13; i++)
		arr[i] = '0';
	i--;
	arr[i] = '\0';
	i--;

	if (n == 0)
	{
		write(1, "0", 1);
		return;
	}
	if (n < 0)
	{
		a = 1;
		n = n * -1;
	}

	remains = n;
	while (remains > 0)
	{
		last_digit = remains % 10;
		remains = remains / 10;

		arr[i] = last_digit + '0';
		i--;
	}
	if (a == 1)
		arr[i] = '-';
	else
		i++;
	write(1, &arr[i], 11 - (i - 1));
}
