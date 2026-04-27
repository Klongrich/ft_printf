#include "../inc/ft_printf.h"

void	put_8bit(unsigned int num, int s, t_flags flags) {
	int bits[8];
	int j;
	int i;
	int value;
	int num_len;

	i = 7;
	j = 0;
	value = 0;
	while (i > -1) {
		bits[j] = (num >> i) & 1;
		i--;
		j++;	
	}
	i = 7;
	j = 0;
	while (i > -1) {
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

	num_len = ft_numlen(value) + 1;
	if (s)
		put_formatting_from_flags(value, 10, flags, 1);
	else
		put_formatting_from_flags(value, 10, flags, 0);
	if (flags.left && flags.padding != 0) {
		if (value < 0) {
			ft_putchar('-');
		}
		if (value >= 0 && flags.plus) {
			ft_putchar('+');
			num_len++;
		}
	}	
	ft_putnbr_f(value);
	if (flags.padding != 0 && flags.left) {
		while (i < flags.padding - num_len) {
			ft_putchar(' ');
			i++;
		}	
	}
}
