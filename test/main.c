#include "ft_printf.h"
#include <stdio.h>

int	main() {
	char c;
	char *str;
	int num;

	c = 'k';
	str = "testing";
	num = 42;

	printf("no paramters passed\n");
	ft_printf("Testing STR\n");

	printf("passing s\n");
	ft_printf("%s\n", str);
	ft_printf("testing str ->: %s\n", str);

	ft_printf("tesing character: %c\n", c);
	ft_printf("%d\n", num);
	ft_printf("%i\n", num);
	ft_printf("%p\n", &num);

	printf("\n");
	ft_printf("%u\n", -123);
	printf("%u\n", -123);
	printf("\n");

	printf("%p\n", &num);

	printf("\nchecing hex\n");
	ft_printf("%x\n", 12884083);
	printf("%x\n", 12884083);	



	return(0);
}
