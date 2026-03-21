#include "../main.h"
#include <stddef.h>

int main(void)
{
	int n = _printf("%s%c%c%c%s%%%s%c", "Loading ", '.', '.', '.', "99", " Please wait", '\n');
	_printf("%d\n", n);
	
	return (0);
}
