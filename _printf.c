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
	int i, n, count;
	va_list args;

	n = 0;
	count = 0;
	va_start(args, format);
	if (format == NULL)
		return (0);
	while (format[n] != '\0')
	{
		for (i = n; (format[i] != '%') && (format[i] != '\0'); i++)
			;
		if (i > n)
		{
			_printnormalchar(format, &n, &i, &count);
		}
		if (format[n] == '%')
		{
			_handleformatspec(format, &n, &count, args);
		}
		if (format[n] == '\0')
			break;
		n++;
	}
	va_end(args);
	return (count);
}

/**
 * _printnormalchar - print normal chars in the format
 * @format: ptr to the format string
 * @n: index to the chars in the format string
 * @i: index to the buffer chars
 * @count: ptr to count
 */
void _printnormalchar(const char *format, int *n, int *i, int *count)
{
	int j = 0;
	char *n_buff;
	int n_start = 0;

	n_buff = malloc(sizeof(char) * (*i - *n));
	if (n_buff == NULL)
		return;
	n_start = *i - *n;
	while (*i != *n)
	{
		n_buff[j] = format[*n];
		(*n)++;
		j++;
	}
	write(1, n_buff, n_start);
	*count = *count + n_start;
	free(n_buff);
}

/**
 * _handleformatspec - handle chars after %
 * @format: ptr to the format string
 * @n: ptr to the index to format chars
 * @count: the ptr to the count
 * @args: the ptr to the variadic arguments
 */
void _handleformatspec(const char *format, int *n, int *count, va_list args)
{
	char str[2];
	struct flag spec[] = {
		{'c', cp},
		{'s', strp},
		{'d', intp},
		{'i', intp},
		{'\0', NULL}
	};
	int k = 0;

	(*n)++;
	if ((format[*n] != 'c') && (format[*n] != 's') &&
			(format[*n] != 'd') && (format[*n] != 'i'))
	{
		if (format[*n] == '\0')
		{
			exit(*count);
		}
		if (format[*n] != '%')
		{
			str[0] = '%';
			str[1] = format[*n];
			write(1, str, 2);
			*count = *count + 2;
		}
		if (format[*n] == '%')
		{
			write(1, "%", 1);
			*count = *count + 1;
		}
	}
	else
	{
		while (spec[k].c != '\0')
		{
			if (format[*n] == spec[k].c)
				spec[k].func(args, count);
			k++;
		}
	}
}

/**
 * cp - write a character to the terminal
 * @args: pointer to the variadic argument (character)
 * @count: keep count of characters printed
 */
void cp(va_list args, int *count)
{
	char c = va_arg(args, int);

	write(1, &c, 1);
	*count = *count + 1;
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


