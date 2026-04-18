#include "ft_printf.h"
#include <stdio.h>


void	checking(char *str) {
	ft_printf("\nchecking %s:\n", str);
}


int	main() {
	char c;
	char *str;
	int num;

	c = 'k';
	str = "testing";
	num = 42;

	printf("no paramters passed\n");
	ft_printf("Testing STR\n");

	checking("strings");
	ft_printf("%s\n", str);
	ft_printf("testing str ->: %s\n", str);

	checking("characters");
	ft_printf("tesing character: %c\n", c);

	checking("integers");
	ft_printf("%d\n", num);
	ft_printf("%i\n", num);

	checking("pointers");
	ft_printf("%p\n", &num);
	printf("%p\n", &num);

	checking("unsigned integers");
	ft_printf("%u\n", -123);
	printf("%u\n", -123);

	checking("hex");
	ft_printf("%x\n", 12884083);
	printf("%x\n", 12884083);	

	checking("oct");
	printf("%o\n", 7594739);
	ft_printf("%o\n", 7594739);

	checking("hhu");
	printf("%hhu\n", 300);	
	printf("%hhu\n", 750);

	ft_printf("%hhu\n", 300);
	ft_printf("%hhu\n", 750);

	return(0);
}
