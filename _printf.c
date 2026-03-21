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
		{'0', NULL}
	};

	int i, k, n, j, r, count, n_start;
	va_list args;
	char *n_buff;

	n = 0;
	count = 0;
	va_start(args, format);
	if (format == NULL)
		return (-1);
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
			if (format[n] == '%')
			{
				write(1, "%", 1);
				count = count + 1;
			}
			while (spec[k].c != '0')
			{
				if (format[n] == spec[k].c)
					spec[k].func(args, &count);
				k++;
			}
			if (!((format[n] == '%') && (format[n - 1] == '%')))
				r = checker(*format);
		}
		if (r == - 1)
			break;
		if (format[n] == '\0')
			break;
		n++;
	}
	va_end(args);
	return (count);
}

/**
 * checker - checks if we have valid format specifier
 * @c: the format specifier
 *
 * Return: -1 if not valid
 */
int checker(char c)
{
	if ((c != 'c') && (c != 's') && (c != 'd') && (c != 'i'))
		return (-1);
	else
		return (0);
}

/**
 * cp - write a character to the terminal
 * @args: pointer to the variadic argument (character)
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


