#ifndef PRINTF_H
#define PRINTF_H

#include <stdarg.h>

/**
 * struct flag - structure that allows me to call the appropriate func
 * @c: format specifier
 * @func: appropriate function pointer
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
int checker(char c);

#endif /*PRINTF*/
