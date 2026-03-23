#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/**
 * struct flag - Maps a format specifier to a function
 * @c: Format specifier character
 * @func: Pointer to function that handles the specifier
 *
 * Associates each format specifier with
 * its corresponding handler function
 */
struct flag
{
	char c;
	void (*func)(va_list, int *ptr);
};

int _printf(const char *format, ...);
void cp(va_list args, int *count);
void strp(va_list args, int *count);
void intp(va_list args, int *count);
void _handleformatspec(const char *format, int *n, int *count, va_list args);
void _printnormalchar(const char *format, int *n, int *i, int *count);

#endif /* MAIN_H */
