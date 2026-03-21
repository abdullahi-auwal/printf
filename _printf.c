#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * _printf - custom implementation of printf
 * @format: format string
 *
 * Return: 0 if successful. otherwise if not
 */
int _printf(const char *format, ...)
{
	struct flag spec[] = {
		{'c', cp},
		{'s', strp},
		{'d', intp},
		{'i', intp},
		{'\0', NULL}
	};

	int i, k, n, j, count, n_start;
	va_list args;
	char *n_buff, str[2];

	n = 0;
	count = 0;
	va_start(args, format);
	if (format == NULL)
		return (0);
	while (format[n] != '\0')
	{
		k = 0;
		j = 0;
		for (i = n; (format[i] != '%') && (format[i] != '\0'); i++)
			;
		if (i > n)
		{
			n_buff = malloc(sizeof(char) * (i - n));
			if (n_buff == NULL)
				return (-1);
			n_start = i - n;
			while (i != n)
			{
				n_buff[j] = format[n];
				n++;
				j++;
			}
			write(1, n_buff, n_start);
			count = count + n_start;
			free(n_buff);
		}
		if (format[n] == '%')
		{
			n++;
			if ((format[n] != 'c') && (format[n] != 's') &&
					(format[n] != 'd') && (format[n] != 'i'))
			{
				if (format[n] == '\0')
					return (0);
				str[0] = '%';
				str[1] = format[n];
				write(1, &str, 2);
				count = count + 2;
			}
			else
			{
				while (spec[k].c != '\0')
				{
					if (format[n] == spec[k].c)
						spec[k].func(args, &count);
					k++;
				}
				if (format[n] == '\0')
					write(1, "\0", 2);
			}
		}
		if (format[n] == '\0')
			break;
		n++;
	}
	va_end(args);
	return (count);
}

/**
 * cp - write a character to the terminal
 * @args: pointer to the variadic argument (character)
 * @count: keep count of characters printed
 */
void cp(va_list args, int *count)
{
	int i;
	char *str;
	char arr[2];
	char c = va_arg(args, int);

	arr[0] = c;
	arr[1] = '\0';
	str = arr;

	for (i = 0; str[i] != '\0'; i++)
		;
	write(1, str, i);
	*count = *count + i;
}

/**
 * strp - write a string to the terminal
 * @args: pointer to the variadic argument (string)
 * @count: keep count of characters printed
 */
void strp(va_list args, int *count)
{
	int i;
	char *str = va_arg(args, char *);

	if (str == NULL)
	{
		str = "(null)";
	}

	for (i = 0; str[i] != '\0'; i++)
		;
	write(1, str, i);
	*count = *count + i;
}


