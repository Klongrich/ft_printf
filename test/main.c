#include "ft_printf.h"

int	main() {
	char *str;
	int num;

	str = "testing";
	num = 42;
	ft_printf("Testing STR\n");
	ft_printf("%s\n", str);
	ft_printf("testing str ->: %s\n", str);
	ft_printf("%d\n", num);
	ft_printf("%i\n", num);
	return(0);
}
