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

t_flags init() {
	t_flags flags;

	flags.zero = 0;
	flags.left = 0;
	flags.padding = 0;
	flags.pound = 0;
	flags.space = 0;
	flags.plus = 0;
	return (flags);
}

void	parse_flags(char *buffer, t_flags *flags) {
	int i;
	int j;
	char buff[1024];
	
	i = 0;
	j = 0;
	buff[0] = '\0';
	while (buffer[i] == '#' || buffer[i] == '0' || buffer[i] == '-' || buffer[i] == '+' || buffer[i] == ' ') {
		if (buffer[i] == '#')
			flags->pound = 1;
		else if (buffer[i] == '0')
			flags->zero = 1;
		else if (buffer[i] == '-')
			flags->left = 1;
		else if (buffer[i] == '+')
			flags->plus = 1;
		else if (buffer[i] == ' ')
			flags->space = 1;
		i++;
	}

	while (buffer[i]) {
		buff[j] = buffer[i];	
		i++;
		j++;
	}
	if (buff[j]) {
		flags->padding = ft_atoi(buff);
	}
}

int	put_number(long n, int base, int is_uppercase, char *buffer) {
	int	count;
	char	*symbols;
	
	count = 0;
	if (!is_uppercase)
		symbols = "0123456789abcdef";
	else
		symbols = "0123456789ABCDEF";
	if (n == 0)
		return (ft_putchar('0'));
	else if (n < 0) {
		//ft_putchar ('-');
		n = -n;
		//count++;
	}
	if (n >= base)
		count += put_number(n / base, base, is_uppercase, buffer);
	count += ft_putchar(symbols[n % base]);
	return (count);
}

int     put_numbers_args(long n, int base, int is_uppercase, t_flags flags) { 
	int i;
	int num_len;

	i = 0;
	num_len = ft_numlen(n);
	if (flags.zero) {
		if (base == 16) {
			if (flags.pound) {
				ft_putchar('0');
				ft_putchar('x');
				num_len += 2;
			}
		} else {
			if (n > 0 && flags.plus) {
				ft_putchar('+');
				num_len++;
			}
			else if (n < 0)
				ft_putchar('-');
		}
	}
	if (flags.padding != 0 && !flags.left) {
		if (flags.zero) {
			while (i < flags.padding - num_len ) {
				ft_putchar('0');
				i++;
			}
		} else {
			if (base == 16) {
				if (flags.pound)
					num_len += 2;
			} else {
				if (flags.plus) {
					if (n > 0)
						num_len++;
				}
			}
			while (i < flags.padding - num_len) {
				ft_putchar(' ');
				i++;
			}

			if (base == 16) {
				if (flags.pound)  {
					ft_putchar('0');
					ft_putchar('x');
				}
			} else {
				if (flags.plus) {
					if (n > 0) {
						ft_putchar('+');
					} else if (n < 0)
						ft_putchar('-');
				}
			}
		}	
	}
	if (n < 0 && !flags.zero)
		ft_putchar('-');
	put_number(n, base, is_uppercase, "holder");
	if (flags.padding != 0 && flags.left) {
		while (i < flags.padding - num_len) {
			ft_putchar(' ');
			i++;
		}	
	}
	return (0);
}


int	put_number_ll(long long n, int base, int is_uppercase) {
	int	count;
	char	*symbols;

	count = 0;
	if (!is_uppercase)
		symbols = "0123456789abcdef";
	else
		symbols = "0123456789ABCDEF";
	if (n == 0)
		return (ft_putchar('0'));
	else if (n < 0) {
		ft_putchar ('-');
		n = -n;
		count++;
	}
	if (n >= base)
		count += put_number_ll(n / base, base, is_uppercase);
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


int	convert_hex_bits(int bit1, int bit2, int bit3, int bit4) {
	if (bit1 == 0 && bit2 == 0 && bit3 == 0 && bit4 == 0)
		return (0);
	if (bit1 == 0 && bit2 == 0 && bit3 == 0 && bit4 == 1)
		return (1);
	if (bit1 == 0 && bit2 == 0 && bit3 == 1 && bit4 == 0)
		return (2);
	if (bit1 == 0 && bit2 == 0 && bit3 == 1 && bit4 == 1)
		return (3);
	if (bit1 == 0 && bit2 == 1 && bit3 == 0 && bit4 == 0)
		return(4);
	if (bit1 == 0 && bit2 == 1 && bit3 == 0 && bit4 == 1)
		return (5);
	if (bit1 == 0 && bit2 == 1 && bit3 == 1 && bit4 == 0)
		return (6);
	if (bit1 == 0 && bit2 == 1 && bit3 == 1 && bit4 == 1)
		return (7);
	if (bit1 == 1 && bit2 == 0 && bit3 == 0 && bit4 == 0)
		return (8);
	if (bit1 == 1 && bit2 == 0 && bit3 == 0 && bit4 == 1)
		return (9);
	if (bit1 == 1 && bit2 == 0 && bit3 == 1 && bit4 == 0)
		return (10);
	if (bit1 == 1 && bit2 == 0 && bit3 == 1 && bit4 == 1)
		return (11);
	if (bit1 == 1 && bit2 == 1 && bit3 == 0 && bit4 == 0)
		return (12);
	if (bit1 == 1 && bit2 == 1 && bit3 == 0 && bit4 == 1)
		return (13);
	if (bit1 == 1 && bit2 == 1 && bit3 == 1 && bit4 == 0)
		return (14);
	if (bit1 == 1 && bit2 == 1 && bit3 == 1 && bit4 == 1)
		return (15);
	return (0);
}


char	get_hex_char(int num) {
	if (num == 0)
		return ('0');
	if (num == 1)
		return ('1');
	if (num == 2)
		return ('2');
	if (num == 3)
		return ('3');
	if (num == 4)
		return ('4');
	if (num == 5)
		return ('5');
	if (num == 6)
		return ('6');
	if (num == 7)
		return ('7');
	if (num == 8)
		return ('8');
	if (num == 9)
		return ('9');
	if (num == 10)
		return ('a');
	if (num == 11)
		return ('b');
	if (num == 12)
		return ('c');
	if (num == 13)
		return ('d');
	if (num == 14)
		return ('e');
	if (num == 15)
		return ('f');
	return ('0');

}

char	get_hex_char_uppercase(int num) {
	if (num == 0)
		return ('0');
	if (num == 1)
		return ('1');
	if (num == 2)
		return ('2');
	if (num == 3)
		return ('3');
	if (num == 4)
		return ('4');
	if (num == 5)
		return ('5');
	if (num == 6)
		return ('6');
	if (num == 7)
		return ('7');
	if (num == 8)
		return ('8');
	if (num == 9)
		return ('9');
	if (num == 10)
		return ('A');
	if (num == 11)
		return ('B');
	if (num == 12)
		return ('C');
	if (num == 13)
		return ('D');
	if (num == 14)
		return ('E');
	if (num == 15)
		return ('F');
	return ('0');

}

void	put_8bit_hex(unsigned int num, int uppercase, int pound_passed) {
	int bits[8];
	int j;
	int i;
	char value[2];

	i = 7;
	j = 0;
	while (i > -1) {
		bits[j] = (num >> i) & 1;
		i--;
		j++;
	}

	if (!uppercase) {
		value[0] = get_hex_char(convert_hex_bits(bits[0], bits[1], bits[2], bits[3]));
		value[1] = get_hex_char(convert_hex_bits(bits[4], bits[5], bits[6], bits[7]));
	} else {
		value[0] = get_hex_char_uppercase(convert_hex_bits(bits[0], bits[1], bits[2], bits[3]));
		value[1] = get_hex_char_uppercase(convert_hex_bits(bits[4], bits[5], bits[6], bits[7]));
	}
	if (pound_passed)
		if (num != 0)
			ft_putstr("0x");
	ft_putchar(value[0]);
	ft_putchar(value[1]);
}

void	put_16bit_hex(unsigned int num, int uppercase) {
	int bits[16];
	int j;
	int i;
	char value[4];

	i = 15;
	j = 0;
	while (i > -1) {
		bits[j] = (num >> i) & 1;
		i--;
		j++;
	}

	if (!uppercase) {
		value[0] = get_hex_char(convert_hex_bits(bits[0], bits[1], bits[2], bits[3]));
		value[1] = get_hex_char(convert_hex_bits(bits[4], bits[5], bits[6], bits[7]));
		value[2] = get_hex_char(convert_hex_bits(bits[8], bits[9], bits[10], bits[11]));
		value[3] = get_hex_char(convert_hex_bits(bits[12], bits[13], bits[14], bits[15]));
	} else {
		value[0] = get_hex_char_uppercase(convert_hex_bits(bits[0], bits[1], bits[2], bits[3]));
		value[1] = get_hex_char_uppercase(convert_hex_bits(bits[4], bits[5], bits[6], bits[7]));
		value[2] = get_hex_char_uppercase(convert_hex_bits(bits[8], bits[9], bits[10], bits[11]));
		value[3] = get_hex_char_uppercase(convert_hex_bits(bits[12], bits[13], bits[14], bits[15]));
	}
	ft_putchar(value[0]);
	ft_putchar(value[1]);
	ft_putchar(value[2]);
	ft_putchar(value[3]);
}


void	put_8bit_octal(unsigned int num) {
	int bits[8];
	int j;
	int i;
	int value;

	i = 7;
	j = 0;
	value = 0;
	while (i > -1) {
		bits[j] = (num >> i) & 1;
		i--;
		j++;
	}
	value += convert_octal_bits(0, bits[0], bits[1]) * 100;
	value += convert_octal_bits(bits[2], bits[3], bits[4]) * 10;
	value += convert_octal_bits(bits[5], bits[6], bits[7]);
	ft_putnbr(value);
}


void	put_16bit_octal(unsigned int num) {
	int bits[16];
	int j;
	int i;
	int value;

	i = 15;
	j = 0;
	value = 0;
	while (i > -1) {
		bits[j] = (num >> i) & 1;
		i--;
		j++;
	}
	value += convert_octal_bits(0, 0, bits[0]) * 100000;
	value += convert_octal_bits(bits[1], bits[2], bits[3]) * 10000;
	value += convert_octal_bits(bits[4], bits[5], bits[6]) * 1000;
	value += convert_octal_bits(bits[7], bits[8], bits[9]) * 100;
	value += convert_octal_bits(bits[10], bits[11], bits[12]) * 10;
	value += convert_octal_bits(bits[13], bits[14], bits[15]);
	ft_putnbr(value);
}


void	put_8bit(unsigned int num, int s) {
	int bits[8];
	int j;
	int i;
	int value;

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
	ft_putnbr(value);
}

void	put_16bit(unsigned int num, int s) {
	int bits[16];
	int j;
	int i;
	int value;

	i = 15;
	j = 0;
	value = 0;
	while (i > -1) {
		bits[j] = (num >> i) & 1;
		i--;
		j++;	
	}
	i = 15;
	j = 0;
	while (i > -1) {
		switch(i) {
			case 15:
				if (bits[j] == 1) {
					if (s) {
						value -= 32728;
					} else {
						value += 32768;
					}
				}
			case 14:
				if (bits[j] == 1)
					value +=  16384;
				break;
			case 13:
				if (bits[j] == 1)
					value += 8192;
				break;
			case 12:
				if (bits[j] == 1)
					value += 4096;
				break;
			case 11:
				if (bits[j] == 1)
					value += 2048;
				break;
			case 10:
				if(bits[j] == 1)
					value += 1024;
				break;
			case 9:
				if(bits[j] == 1)
					value += 512;
				break;
			case 8:
				if (bits[j] == 1)
					value += 256;
				break;
			case 7:
				if (bits[j] == 1) 
					value += 128;
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
	ft_putnbr(value);
}

void	put_64bit(long long num) {
	int bits[16];
	int j;
	int i;
	long long value;

	i = 15;
	j = 0;
	value = 0;
	while (i > -1) {
		bits[j] = (num >> i) & 1;
		i--;
		j++;	
	}
	i = 15;
	j = 0;
	while (i > -1) {
		switch(i) {
			case 31:
				if (bits[j] == 1)
					value += 32768;
				break;
			case 30:
				if (bits[j] == 1)
					value +=  16384;
				break;
			case 29:
				if (bits[j] == 1)
					value += 8192;
				break;
			case 28:
				if (bits[j] == 1)
					value += 4096;
				break;
			case 27:
				if (bits[j] == 1)
					value += 2048;
				break;
			case 26:
				if(bits[j] == 1)
					value += 1024;
				break;
			case 25:
				if(bits[j] == 1)
					value += 512;
				break;
			case 24:
				if (bits[j] == 1)
					value += 256;
				break;
			case 23:
				if (bits[j] == 1) 
					value += 128;
				break;
			case 22:
				if (bits[j] == 1)
					value += 64;
				break;
			case 21:
				if(bits[j] == 1)
					value += 32;
				break;
			case 20:
				if(bits[j] == 1)
					value += 16;
				break;
			case 19:
				if(bits[j] == 1)
					value += 8;
				break;
			case 18:
				if(bits[j] == 1)
					value += 4;
				break;
			case 17:
				if(bits[j] == 1)
					value += 2;
				break;
			case 16:
				if (bits[j] == 1)
					value += 1;
				break;
			case 15:
				if (bits[j] == 1)
					value += 32768;
				break; 
			case 14:
				if (bits[j] == 1)
					value +=  16384;
				break;
			case 13:
				if (bits[j] == 1)
					value += 8192;
				break;
			case 12:
				if (bits[j] == 1)
					value += 4096;
				break;
			case 11:
				if (bits[j] == 1)
					value += 2048;
				break;
			case 10:
				if(bits[j] == 1)
					value += 1024;
				break;
			case 9:
				if(bits[j] == 1)
					value += 512;
				break;
			case 8:
				if (bits[j] == 1)
					value += 256;
				break;
			case 7:
				if (bits[j] == 1) 
					value += 128;
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
	ft_putnbr(value);
}


int put_float(double f) {
	//32-bit 6 to 9 digits
	//64-bit 15 to 17 digits
	int precision;
	int count;
	long int_part;
	double fraction;
	int digit;
	char c;

	count = 0;
	int_part = (long)f;
	precision = 6;
	if (f < 0) {
		count += ft_putchar('-');
		f = -f;
	}
    	ft_putnbr(int_part);
    	write(1, ".", 1);
    	fraction = f - (double)int_part;
    	while (precision--) {
        	fraction *= 10;
        	digit = (int)fraction;
        	c = digit + '0';
        	count += ft_putchar(c);
       		fraction -= digit;
    	}
	return (count);
}


/*

void	print_flags(t_args flags) {
	printf("pound: %d\n", flags.pound);
	printf("zero: %d\n", flags.zero);
	printf("plus: %d\n", flags.plus);
	printf("left: %d\n", flags.left);
	printf("space: %d\n", flags.space);
	printf("ll: %d\n", flags.ll);
	printf("l: %d\n", flags.l);
	printf("h: %d\n", flags.h);
	printf("hh: %d\n", flags.hh);
}

t_args	init() {
	t_args v;

	v.pound = 0;
	v.zero = 0;
	v.plus = 0;
	v.left = 0;
	v.space = 0;
	v.ll = 0;
	v.l = 0;
	v.h = 0;
	v.hh = 0;

	return (v);
}

*/

int	check_c(char c) {
	if (c == 'c')
		return (1);
	if (c == 'd')
		return (1);
	if (c == 'i')
		return (1);
	if (c == 's')
		return (1);
	if (c == 'p')
		return (1);
	if (c == 'u')
		return (1);
	if (c == 'x')
		return (1);
	if (c == 'X')
		return (1);
	if (c == 'o')
		return (1);
	if (c == 'f')
		return (1);
	if (c == 'h')
		return (1);
	if (c == 'l')
		return (1);
	return (0);
}


int	ft_printf(char *str, ...) {
	va_list list;
	int	i;
	int	j;
	int 	count;
	char	buffer[1024];
	t_flags flags;

	i = 0;
	j = 0;
	count = 0;
	flags = init();
	buffer[0] = '\0';
	va_start(list, str);
	while (str[i]) {
		while (str[i] != '%' && str[i]) {
			count += ft_putchar(str[i]);
			i++;
		}
		if (!str[i])
			break ;
		i++;
		while (!check_c(str[i])) {
			buffer[j] = str[i];
			i++;
			j++;
		}
		buffer[j] = '\0';
		parse_flags(buffer, &flags);
		if (str[i] == 'c') 
			count += ft_putchar(va_arg(list, int));
		if (str[i] == 'd' || str[i] == 'i')
			count += put_numbers_args(va_arg(list, int), 10, 0, flags);
		else if (str[i] == 's')
			ft_putstr(va_arg(list, char*));
		else if (str[i] == 'p')
			count += put_pointer(va_arg(list, void*));
		else if (str[i] == 'u')
			count += putunit_max(va_arg(list, unsigned int), 10);
		else if (str[i] == 'x')
			count += put_numbers_args(va_arg(list, unsigned int), 16, 0, flags);
		else if (str[i] == 'X')
			count += put_number(va_arg(list, unsigned int), 16, 1, buffer);
		else if (str[i] == 'o')
			count += put_number(va_arg(list, unsigned int), 8, 0, buffer);
		else if (str[i] == 'f')
			count += put_float(va_arg(list, double));			
		else if (str[i] == 'h' && str[i + 1] == 'h') {
			if (str[i + 2] == 'u')
				put_8bit(va_arg(list, unsigned int), 0);
			else if (str[i + 2] == 'd')
				put_8bit(va_arg(list, int), 1);
			else if (str[i + 2] == 'i')
				put_8bit(va_arg(list, int), 1);
			else if (str[i + 2] == 'o')
				put_8bit_octal(va_arg(list, unsigned int));
			else if (str[i + 2] == 'x')
				put_8bit_hex(va_arg(list, unsigned int), 0, 0);
			else if (str[i + 2] == 'X')
				put_8bit_hex(va_arg(list, unsigned int), 1, 0);
			i += 2;
		}
		else if (str[i] == 'h') {
			if(str[i + 1] == 'u')
				put_16bit(va_arg(list, unsigned int), 0);
			else if (str[i + 1] == 'd')
				put_16bit(va_arg(list, int), 1);
			else if (str[i + 1] == 'i')
				put_16bit(va_arg(list, int), 1);
			else if(str[i + 1] == 'o')
				put_16bit_octal(va_arg(list, unsigned int));
			else if(str[i + 1] == 'x')
				put_16bit_hex(va_arg(list, unsigned int), 0);
			else if (str[i + 1] == 'X')
				put_16bit_hex(va_arg(list, unsigned int), 1);
			i += 1;
		}
		else if (str[i] == 'l' && str[i + 1] == 'l') {
			if (str[i + 2] == 'u')
				put_64bit_ull(va_arg(list, unsigned long long));
			else if (str[i + 2] == 'd')
				put_64bit(va_arg(list, long long));
			else if (str[i + 2] == 'i')
				put_number_ll(va_arg(list, long long), 10, 0);
			else if (str[i + 2] == 'o')
				put_number_ll(va_arg(list, long long), 8, 0);
			else if (str[i + 2] == 'x')
				put_number_ll(va_arg(list, long long), 16, 0);
			else if (str[i + 2] == 'X')
				put_number_ll(va_arg(list, long long), 16, 1);
			i += 2;
		}
		else if (str[i] == 'l') {
			if (str[i + 1] == 'u')
				put_number(va_arg(list, unsigned long), 10, 0, buffer);
			else if (str[i + 1] == 'd')
				put_number(va_arg(list, long), 10, 0, buffer);
			else if (str[i + 1] == 'i')
				put_number(va_arg(list, long), 10, 0, buffer);
			else if (str[i + 1] == 'o')
				put_number(va_arg(list, long), 8, 0, buffer);
			else if (str[i + 1] == 'x')
				put_number(va_arg(list, long), 16, 0, buffer);
			else if (str[i + 1] == 'X')
				put_number(va_arg(list, long), 16, 1, buffer);
			else if (str[i + 1] == 'f')
				put_float(va_arg(list, double));
			i += 1;
		}
		i++;
	}
	return(count);
}
