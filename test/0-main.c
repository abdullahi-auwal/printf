#include "../printf.h"

int main(void)
{
	char *str = "World!";
	char c = '!';
	int n = 2840;

	_printf("Hello %s%c x%d\n", str, c, n);
	
	return (0);
}
