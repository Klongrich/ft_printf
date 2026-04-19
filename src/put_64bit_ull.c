#include "../inc/ft_printf.h"


void	ft_putnbr_ull(unsigned long long n)
{
	unsigned long long num;

	num = n;
	if (num < 0)
	{
		ft_putchar('-');
		num *= -1;
	}
	if (num > 9)
		ft_putnbr_ull(num / 10);
	ft_putchar((num % 10) + 48);
}


unsigned long long	get_value(int i) {
	unsigned long long value;

	value = 1;
	while (i > 0) {
		value *= 2;
		i--;	
	}
	return (value);
}

void	put_64bit_ull(unsigned long long num) {
	int bits[64];
	int j;
	int i;
	unsigned long long value;

	i = 63;
	j = 0;
	value = 0;
	while (i > -1) {
		bits[j] = (num >> i) & 1;	
		i--;
		j++;	
	}
	i = 63;
	j = 0;
	while (i > -1) {		
		if (bits[j] == 1) {
			value += get_value(i);
		}
		i--;
		j++;
	}
	ft_putnbr_ull(value);
}

