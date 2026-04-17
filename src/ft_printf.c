#include "ft_printf.h"
#include "ft_printf.h"


void	ft_printf(char *str, ...) {
	va_list list;
	int	i;

	i = 0;
	va_start(list, str);
	while (str[i]) {
		while (str[i] != '%' && str[i]) {
			ft_putchar(str[i]);
			i++;
		}
		if (!str[i])
			break ;
		i++;
		if (str[i] == 'd')
			ft_putnbr(va_arg(list, int));
		else if (str[i] == 's')
			ft_putstr(va_arg(list, char*));
		str++;
	}
}
