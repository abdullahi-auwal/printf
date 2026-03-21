#include "../printf.h"

int main(void)
{
	/*char *str = "!";
	char c = '!';
	int n = 2840;*/
	int n;
	int a = 78;

	n = _printf("Hello %d\n", a);
	_printf("%d\n", n);
	
	return (0);
}
