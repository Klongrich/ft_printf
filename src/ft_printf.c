#include "ft_printf.h"

int	putunit_max(unsigned long num, int base) {
	char	*hex;
	char	buffer[50];
	int	i;
	int	count;

	hex = "0123456789abcdef";
	i = 49;
	count = 0;
	buffer[i] = '\0';
	if (num == 0)
		buffer[--i] = '0';
	while (num > 0) {
		buffer[--i] = hex[num % base];
		num /= base;
	}
	while (buffer[i]) {
		write(1, &buffer[i], 1);
		count++;
		i++;
	}
	return (count);
}


int	put_pointer(void *pointer) {
	unsigned long long	address;
	int			count;

	count = 0;
	address = (unsigned long long) pointer;
	if (pointer == NULL)
		ft_putstr("(nil)");
	ft_putstr("0x");
	count += putunit_max(address, 16);
	return(count);
}

int	ft_printf(char *str, ...) {
	va_list list;
	int	i;
	int 	count;
	

	i = 0;
	count = 0;
	va_start(list, str);
	while (str[i]) {
		while (str[i] != '%' && str[i]) {
			count += ft_putchar(str[i]);
			i++;
		}
		if (!str[i])
			break ;
		i++;
		if (str[i] == 'c') 
			count += ft_putchar(va_arg(list, int));
		if (str[i] == 'd' || str[i] == 'i')
			ft_putnbr(va_arg(list, int));
		else if (str[i] == 's')
			ft_putstr(va_arg(list, char*));
		else if (str[i] == 'p')
			put_pointer(va_arg(list, void*));
		else if (str[i] == 'u')
			putunit_max(va_arg(list, unsigned int), 10);
		else if (str[i] == 'x')
			putunit_max(va_arg(list, unsigned int), 16);	
		str++;
	}
	return(count);
}
