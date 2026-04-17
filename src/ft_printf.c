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

int	put_number(long n, int base, int is_uppercase) {
	int		count;
	char	*symbols;

	count = 0;
	if (!is_uppercase)
		symbols = "0123456789abcdef";
	else
		symbols = "0123456789ABCDEF";
	if (n == 0)
		return (ft_putchar('0'));
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		count = 11;
		return (count);
	}
	else if (n < 0)
	{
		ft_putchar ('-');
		n = -n;
		count++;
	}
	if (n >= base)
		count += put_number(n / base, base, is_uppercase);
	count += ft_putchar(symbols[n % base]);
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
			count += put_number(va_arg(list, int), 10, 0);
		else if (str[i] == 's')
			ft_putstr(va_arg(list, char*));
		else if (str[i] == 'p')
			count += put_pointer(va_arg(list, void*));
		else if (str[i] == 'u')
			count += putunit_max(va_arg(list, unsigned int), 10);
		else if (str[i] == 'x')
			count += put_number(va_arg(list, unsigned int), 16, 0);
		else if (str[i] == 'X')
			count += put_number(va_arg(list, unsigned int), 16, 1);	
		str++;
	}
	return(count);
}
