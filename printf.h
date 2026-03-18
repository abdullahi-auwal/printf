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
	void (*func)(va_list);
};

int _printf(const char *format, ...);
void cp(va_list args);
void strp(va_list args);
void intp(va_list args);

#endif /*PRINTF*/
