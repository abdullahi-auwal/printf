#include "../main.h"
#include <stddef.h>

int main(void)
{
	int n = _printf("%c", '\0');
	_printf("%d\n", n);
	
	return (0);
}
