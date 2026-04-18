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


int	convert_octal_bits(int bit1, int bit2, int bit3) {
	if (bit1 == 0 && bit2 == 0 && bit3 == 0)
		return(0);
	if (bit1 == 0 && bit2 == 0 && bit3 == 1)
		return(1);
	if (bit1 == 0 && bit2 == 1 && bit3 == 0)
		return(2);
	if (bit1 == 0 && bit2 == 1 && bit3 == 1)
		return(3);
	if (bit1 == 1 && bit2 == 0 && bit3 == 0)
		return(4);
	if (bit1 == 1 && bit2 == 0 && bit3 == 1)
		return(5);
	if (bit1 == 1 && bit2 == 1 && bit3 == 0)
		return(6);
	if (bit1 == 1 && bit2 == 1 && bit3 == 1)
		return(7);
	return (0);
}

void	put_8bit_octal(unsigned int num) {
	int bits[8];
	int j;
	int i;
	int value;

	i = 7;
	j = 0;
	value = 0;
	//printf("\nnum: %d\n", num);
	while (i > -1) {
		bits[j] = (num >> i) & 1;
		//printf("%d", bits[j]);
		i--;
		j++;
	}
	value += convert_octal_bits(0, bits[0], bits[1]) * 100;
	value += convert_octal_bits(bits[2], bits[3], bits[4]) * 10;
	value += convert_octal_bits(bits[5], bits[6], bits[7]);
	ft_putnbr(value);
}

void	put_8bit(unsigned int num, int s) {
	int bits[8];
	int j;
	int i;
	int value;

	i = 7;
	j = 0;
//	ft_putnbr(num);
//	ft_putchar('\n');
	value = 0;
	while (i > -1) {
		bits[j] = (num >> i) & 1;
		i--;
		j++;	
	}
 //   	ft_putchar('\n');

	i = 7;
	j = 0;
	while (i > -1) {
//		ft_putnbr(bits[j]);
//		ft_putstr(" -> ");
//		ft_putnbr(i);
//		ft_putchar('\n');

		switch(i) {
			case 7:
				if (bits[j] == 1) {
					if (s)
						value -= 128;
					else
						value += 128;
				}
				break;
			case 6:
				if (bits[j] == 1)
					value += 64;
				break;
			case 5:
				if(bits[j] == 1)
					value += 32;
				break;
			case 4:
				if(bits[j] == 1)
					value += 16;
				break;
			case 3:
				if(bits[j] == 1)
					value += 8;
				break;
			case 2:
				if(bits[j] == 1)
					value += 4;
				break;
			case 1:
				if(bits[j] == 1)
					value += 2;
				break;
			case 0:
				if (bits[j] == 1)
					value += 1;
				break;

		}
		i--;
		j++;
	}
	
	//ft_putchar('\n');
	ft_putnbr(value);


	// 1 = 2^0 = 1
	// 2 = 2^1 = 2
	// 3 = 2^2 = 4
	// 4 = 2^3 = 8
	
	// 5 = 2^4 = 16
	// 6 = 2^5 = 32
	// 7 = 2^6 = 64
	// 8 = 2^7 = 128
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
		else if (str[i] == 'o')
			count += put_number(va_arg(list, unsigned int), 8, 0);
		else if (str[i] == 'h' && str[i + 1] == 'h') {
			if (str[i + 2] == 'u')
				put_8bit(va_arg(list, unsigned int), 0);
			else if (str[i + 2] == 'd')
				put_8bit(va_arg(list, int), 1);
			else if (str[i + 2] == 'i')
				put_8bit(va_arg(list, int), 1);
			else if (str[i + 2] == 'o')
				put_8bit_octal(va_arg(list, unsigned int));
			i += 2;
		}	
		i++;
	}
	return(count);
}
