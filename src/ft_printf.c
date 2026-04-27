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
	char buff[4095];
	
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
	buff[j] = '\0';
	if (j > 0) {
		if (buff[j - 1]) {
			flags->padding = ft_atoi(buff);
		}
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
		n = -n;
	}
	if (n >= base)
		count += put_number(n / base, base, is_uppercase, buffer);
	count += ft_putchar(symbols[n % base]);
	return (count);
}

int             ft_numlen_hex(int n) {
         int i;
 
         i = 0;
         if (n < 0)
         {
                 i++;
                 n *= -1;
         }
         if (n == 0)
                 i++;
         while (n)
         {
                 n /= 16;
                 i++;
         }
         return (i);
}

int	put_formatting_from_flags(long n, int base, t_flags flags, int is_signed) {
	int i;
	int num_len;

	
	i = 0;
	if (is_signed) {
		flags.plus = 0;
	}
	if (base == 17) {
 		num_len = ft_numlen_hex(n);
		base = 16;
	}
	else
		num_len = ft_numlen(n);
	if (flags.zero) {
		if (base == 16) {
			if (flags.pound) {
				if(n != 0) {
					ft_putchar('0');
					ft_putchar('x');
					num_len += 2;
				}
			}
		} else {
			if (n > 0 && flags.plus && base != 8) {
				ft_putchar('+');
				num_len++;
			}
			else if (n < 0)
				ft_putchar('-');
		}
	}
	if (flags.padding == 0 && base != 16) {
			if (flags.plus && n >= 0) {
				ft_putchar('+');
				num_len++;
			}
	}
	if (flags.padding == 0 && flags.space) {
		if (n >= 0 && !flags.plus)
			ft_putchar(' ');
	}
	if (flags.padding != 0 && !flags.left) {
		if (flags.zero) {
			while (i < flags.padding - num_len ) {
				ft_putchar('0');
				i++;
			}
		} else {
			if (base == 16) {
				if (flags.pound) {
					if (n != 0)
						num_len += 2;
				}
			} else {
				if (flags.plus) {
					if (n >= 0 && base != 8) {
						if (!flags.padding)
							ft_putchar('+');
						num_len++;
					}
				}
			}
			while (i < flags.padding - num_len) {
				ft_putchar(' ');
				i++;
			}

			if (base == 16) {
				if (flags.pound)  {
					if (n != 0) {
						ft_putchar('0');
						ft_putchar('x');
					}
				}
			} else {
				if (n < 0 && !flags.plus) {
					ft_putchar('-');
				}
				if (flags.plus) {
					if (n >= 0 && base != 8) {
						ft_putchar('+');
					} else if (n < 0)
						ft_putchar('-');
				}
			}
		}	
	}
	if (n < 0 && !flags.zero && !flags.padding) {
		ft_putchar('-');
	}

	return (0);
}

int	put_formatting_from_flags_ull(unsigned long long n, int base, t_flags flags) {
	int i;
	int num_len;

	i = 0;
	num_len = ft_numlen(n);
	if (flags.zero) {
		if (base == 16) {
			if (flags.pound) {
				if(n != 0) {
					ft_putchar('0');
					ft_putchar('x');
					num_len += 2;
				}
			}
		} else {
			if (n > 0 && flags.plus && base != 8) {
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
				if (flags.pound) {
					if (n != 0)
						num_len += 2;
				}
			} else {
				if (flags.plus) {
					if (n >= 0 && base != 8) {
						ft_putchar('+');
						num_len++;
					}
				}
			}
			while (i < flags.padding - num_len) {
				ft_putchar(' ');
				i++;
			}

			if (base == 16) {
				if (flags.pound)  {
					if (n != 0) {
						ft_putchar('0');
						ft_putchar('x');
					}
				}
			} else {
				if (flags.plus) {
					if (n > 0 && base != 8) {
						ft_putchar('+');
					} else if (n < 0)
						ft_putchar('-');
				}
			}
		}	
	}
	if (n < 0 && !flags.zero)
		ft_putchar('-');

	return (0);
}

int     put_numbers_args(long n, int base, int is_uppercase, t_flags flags) { 
	int i;
	int num_len;

	i = 0;
	num_len = ft_numlen(n);

	if (base == 8 || base == 16)
		put_formatting_from_flags(n, base, flags, 1);
	else
		put_formatting_from_flags(n, base, flags, 0);
	if (base == 17)
		base = 16;
	if (flags.left && flags.plus && base != 8) {
		ft_putchar('+');
		num_len++;
	}
	if (flags.left && flags.pound && base == 16) {
		if (n != 0) {
			ft_putstr("0x");
			num_len++;
		}
	}	
	put_number(n, base, is_uppercase, "holder");
	if (flags.padding != 0 && flags.left) {
		while (i < flags.padding - num_len) {
			ft_putchar(' ');
			i++;
		}	
	}
	return (0);
}

int     put_numbers_args_u(long n, int base, int is_uppercase, t_flags flags) { 
	int i;
	int num_len;

	i = 0;
	num_len = ft_numlen(n);
	put_formatting_from_flags(n, base, flags, 1);
	putunit_max(n, base);
	if (flags.padding != 0 && flags.left) {
		while (i < flags.padding - num_len) {
			ft_putchar(' ');
			i++;
		}	
	}
	return (0);
}

int     put_character_args(char c, t_flags flags) { 
	int i;
	int count;
	int str_len;

	i = 0;
	if (flags.padding != 0 && !flags.left) {
		while (i < flags.padding - 1) {
			count += ft_putchar(' ');
			i++;
		}
	}
	count += ft_putchar(c);
	if (flags.padding != 0 && flags.left) {
		while (i < flags.padding - 1) {
			count += ft_putchar(' ');
			i++;
		}	
	}
	return (count);
}

int     put_string_args(char *str, t_flags flags) { 
	int i;
	int count;
	int str_len;

	i = 0;
	count = 0;
	if (str == NULL)
		str_len = 6;
 	else
		str_len = ft_strlen(str);
	if (flags.padding != 0 && !flags.left) {
		while (i < flags.padding - str_len) {
			count += ft_putchar(' ');
			i++;
		}
	}
	if (str == NULL)
		ft_putstr("(null)");
	else
		ft_putstr(str);
	if (flags.padding != 0 && flags.left) {
		while (i < flags.padding - str_len) {
			count += ft_putchar(' ');
			i++;
		}	
	}
	return (count);
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
		//ft_putchar ('-');
		n = -n;
		count++;
	}
	if (n >= base)
		count += put_number_ll(n / base, base, is_uppercase);
	count += ft_putchar(symbols[n % base]);
	return (count);
}

int	put_number_ull(unsigned long long n, int base, int is_uppercase) {
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
		count++;
	}
	if (n >= base)
		count += put_number_ll(n / base, base, is_uppercase);
	count += ft_putchar(symbols[n % base]);
	return (count);
}

int     put_numbers_args_ll(long long n, int base, int is_uppercase, t_flags flags) { 
	int i;
	int num_len;

	i = 0;
	num_len = ft_numlen_ll(n);
	if (base == 8 || base == 16)
		put_formatting_from_flags(n, base, flags, 1);
	else
		put_formatting_from_flags(n, base, flags, 0);
	if (flags.left && flags.plus && base != 8) {
		ft_putchar('+');
		num_len++;
	}	
	put_number_ll(n, base, is_uppercase);
	if (flags.padding != 0 && flags.left) {
		while (i < flags.padding - num_len) {
			ft_putchar(' ');
			i++;
		}	
	}
	return (0);
}

int     put_numbers_args_ull(unsigned long long n, int base, int is_uppercase, t_flags flags) { 
	int i;
	int num_len;

	i = 0;
	num_len = ft_numlen_ll(n);
	put_formatting_from_flags_ull(n, base, flags);
	if (flags.left && flags.plus && base != 8) {
		ft_putchar('+');
		num_len++;
	}	
	put_number_ull(n, base, is_uppercase);
	if (flags.padding != 0 && flags.left) {
		while (i < flags.padding - num_len) {
			ft_putchar(' ');
			i++;
		}	
	}
	return (0);
}


int	put_pointer(void *pointer, t_flags flags) {
	unsigned long long	address;
	int			count;
	int			num_len;
	int			i;

	i = 0;
	count = 0;
	address = (unsigned long long) pointer;
	num_len = ft_numlen_ll(address);
	num_len--;
	if (flags.padding != 0 && !flags.left) {
		while (i < flags.padding - num_len) {
			count += ft_putchar(' ');
			i++;
		}
	}
	if (pointer == NULL)
		ft_putstr("(nil)");
	ft_putstr("0x");
	count += putunit_max(address, 16);
	if (flags.padding != 0 && flags.left) {
		while (i < flags.padding - num_len) {
			count += ft_putchar(' ');
			i++;
		}
	}
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

void	put_8bit_hex(unsigned int num, int uppercase, t_flags flags) {
	int bits[8];
	int j;
	int i;
	char value[2];
	int num_len;

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

	num_len = 2;
	
	if (value[0] == '0' && value[1] != '0')
		put_formatting_from_flags(1, 16, flags, 1);
	else if (num != 0)
		put_formatting_from_flags(11, 16, flags, 1);
	else
		put_formatting_from_flags(0, 16, flags, 1);
	if (flags.pound && flags.left && !flags.zero && num != 0) {
		ft_putstr("0x");
		num_len++;
		num_len++;
	}
	if (!flags.left && !flags.padding && !flags.zero && flags.pound) {
		if (num != 0) 
			ft_putstr("0x");
	}
	if (num != 0) {	
		if (value[0] == '0' && value[1] == '0')
			ft_putchar('0');
		else {
			if (value[0] != '0')
				ft_putchar(value[0]);
			else
				num_len--;
			ft_putchar(value[1]);
		}
	} else {
		ft_putchar('0');
		num_len--;
	}
	if (flags.padding != 0 && flags.left) {
		while (i < flags.padding - num_len - 1) {
			ft_putchar(' ');
			i++;
		}	
	}
}

void	put_16bit_hex(unsigned int num, int uppercase, t_flags flags) {
	int bits[16];
	int j;
	int i;
	char value[4];
	int num_len;
	int padding_value;

	i = 15;
	j = 0;
	padding_value = 1111;
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

	num_len = 4;
	if (value[0] == '0' && value[1] != '0') {
		padding_value /= 10;
	}
	else if (value[0] == '0' && value[1] == '0' && value[2] != '0') {
		padding_value /= 100;
	}
	else if (value[0] == '0' && value[1] == '0' && value[2] == '0' && value[3] != '0') {
		padding_value /= 1000;
	}
	if (num != 0)
		put_formatting_from_flags(padding_value, 16, flags, 1);
	else
		put_formatting_from_flags(0, 16, flags, 1);
	if (flags.pound && flags.left && !flags.zero && num != 0) {
		ft_putstr("0x");
		num_len++;
		num_len++;
		num_len++;
	}
	if (!flags.left && !flags.padding && !flags.zero && flags.pound) {
		if (num != 0)
			ft_putstr("0x");
	}
	if (num != 0) {
		if (value[0] == '0' && value[1] != '0') {
			ft_putchar(value[1]);
			ft_putchar(value[2]);
			ft_putchar(value[3]);
			num_len--;
		}
		else if (value[0] == '0' && value[1] == '0' && value[2] != '0') {
			ft_putchar(value[2]);
			ft_putchar(value[3]);
			num_len -= 2;
		}
		else if (value[0] == '0' && value[1] == '0' && value[2] == '0' && value[3] != '0') {
			ft_putchar(value[3]);
			num_len -= 3;
		} else {
			ft_putchar(value[0]);
			ft_putchar(value[1]);
			ft_putchar(value[2]);
			ft_putchar(value[3]);
		}
	} else {
		ft_putchar('0');
		num_len -= 3;
	}
	if (flags.padding != 0 && flags.left) {
		while (i < flags.padding - num_len - 1) {
			ft_putchar(' ');
			i++;
		}	
	}
}


void	put_8bit_octal(unsigned int num, t_flags flags) {
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
	value += convert_octal_bits(0, bits[0], bits[1]) * 100;
	value += convert_octal_bits(bits[2], bits[3], bits[4]) * 10;
	value += convert_octal_bits(bits[5], bits[6], bits[7]);
	

	num_len = ft_numlen(value);
	put_formatting_from_flags(value, 8, flags, 1);	
	ft_putnbr_f(value);
	if (flags.padding != 0 && flags.left) {
		//check -1
		while (i < flags.padding - num_len - 1) {
			ft_putchar(' ');
			i++;
		}	
	}
}


void	put_16bit_octal(unsigned int num, t_flags flags) {
	int bits[16];
	int j;
	int i;
	int value;
	int num_len;

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

	num_len = ft_numlen(value);
	put_formatting_from_flags(value, 8, flags, 1);	
	ft_putnbr_f(value);
	if (flags.padding != 0 && flags.left) {
		//check -1
		while (i < flags.padding - num_len - 1) {
			ft_putchar(' ');
			i++;
		}	
	}
}

void	put_16bit(unsigned int num, int s, t_flags flags) {
	int bits[16];
	int j;
	int i;
	int value;
	int num_len;

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
						value -= 32768;
					} else {
						value += 32768;
					}
				}
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
	num_len = ft_numlen(value);
	if (s)
		put_formatting_from_flags(value, 10, flags, 1);
	else
		put_formatting_from_flags(value, 10, flags, 0);	
	ft_putnbr_f(value);
	if (value < 0)
		num_len++;
	if (flags.padding != 0 && flags.left) {
		while (i < flags.padding - num_len) {
			ft_putchar(' ');
			i++;
		}	
	}	
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

int put_float_L(long double f) {
	int precision;
	int count;
	long long int_part;
	long double fraction;
	int digit;
	char c;

	count = 0;
	int_part = (long long)f;

	precision = 6;
	if (f < 0) {
		count += ft_putchar('-');
		f = -f;
	}
    	ft_putnbr_ll(int_part);
    	write(1, ".", 1);
    	fraction = f - (long double)int_part;
    	while (precision--) {
        	fraction *= 10;
        	digit = (int)fraction;
        	c = digit + '0';
        	count += ft_putchar(c);
       		fraction -= digit;
    	}
	return (count);
}

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
	if (c == 'L')
		return (1);
	return (0);
}

int	ft_printf(char *str, ...) {
	va_list list;
	int	i;
	int	j;
	int 	count;
	char	buffer[4095];
	t_flags flags;

	i = 0;
	j = 0;
	count = 0;
	flags = init();
	buffer[0] = '\0';
	va_start(list, str);
	while (str[i]) {
		flags = init();
		j = 0;
		ft_bzero(buffer, ft_strlen(buffer));
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
			count +=  put_character_args(va_arg(list, int), flags);
		if (str[i] == 'd' || str[i] == 'i')
			count += put_numbers_args(va_arg(list, int), 10, 0, flags);
		else if (str[i] == 's')
			count += put_string_args(va_arg(list, char*), flags);
		else if (str[i] == 'p')
			count += put_pointer(va_arg(list, void*), flags);
		else if (str[i] == 'u')
			count += put_numbers_args_u(va_arg(list, unsigned int), 10, 0, flags);
		else if (str[i] == 'x')
			count += put_numbers_args(va_arg(list, unsigned int), 17, 0, flags);
		else if (str[i] == 'X')
			count += put_numbers_args(va_arg(list, unsigned int), 17, 1, flags);
		else if (str[i] == 'o')
			count += put_numbers_args(va_arg(list, unsigned int), 8, 0, flags);
		else if (str[i] == 'f')
			count += put_float(va_arg(list, double));			
		else if (str[i] == 'h' && str[i + 1] == 'h') {
			if (str[i + 2] == 'u')
				put_8bit(va_arg(list, unsigned int), 0, flags);
			else if (str[i + 2] == 'd')
				put_8bit(va_arg(list, int), 1, flags);
			else if (str[i + 2] == 'i')
				put_8bit(va_arg(list, int), 1, flags);
			else if (str[i + 2] == 'o')
				put_8bit_octal(va_arg(list, unsigned int), flags);
			else if (str[i + 2] == 'x')
				put_8bit_hex(va_arg(list, unsigned int), 0, flags);
			else if (str[i + 2] == 'X')
				put_8bit_hex(va_arg(list, unsigned int), 1, flags);
			else if (str[i + 2] == 's')
				count += put_string_args(va_arg(list, char*), flags);
			else if (str[i + 2] == 'c')
				 count +=  put_character_args(va_arg(list, int), flags);
			i += 2;
		}
		else if (str[i] == 'h') {
			if(str[i + 1] == 'u')
				put_16bit(va_arg(list, unsigned int), 0, flags);
			else if (str[i + 1] == 'd')
				put_16bit(va_arg(list, int), 1, flags);
			else if (str[i + 1] == 'i')
				put_16bit(va_arg(list, int), 1, flags);
			else if(str[i + 1] == 'o')
				put_16bit_octal(va_arg(list, unsigned int), flags);
			else if(str[i + 1] == 'x')
				put_16bit_hex(va_arg(list, unsigned int), 0, flags);
			else if (str[i + 1] == 'X')
				put_16bit_hex(va_arg(list, unsigned int), 1, flags);
			i += 1;
		}
		else if (str[i] == 'l' && str[i + 1] == 'l') {
			if (str[i + 2] == 'u')
				put_numbers_args_ull(va_arg(list, unsigned long long), 10, 0, flags);
			else if (str[i + 2] == 'd')
				put_numbers_args_ll(va_arg(list, long long), 10, 0, flags);
			else if (str[i + 2] == 'i')
				put_numbers_args_ll(va_arg(list, long long), 10, 0, flags);
			else if (str[i + 2] == 'o')
				put_numbers_args_ull(va_arg(list, unsigned long long), 8, 0, flags);
			else if (str[i + 2] == 'x')
				put_numbers_args_ull(va_arg(list, unsigned long long), 16, 0, flags);
			else if (str[i + 2] == 'X')
				put_numbers_args_ull(va_arg(list, unsigned long long), 16, 1, flags);
			i += 2;
		}
		else if (str[i] == 'l') {
			if (str[i + 1] == 'u')
				put_numbers_args_ull(va_arg(list, unsigned long), 10, 0, flags);
			else if (str[i + 1] == 'd')
				put_numbers_args_ll(va_arg(list, long), 10, 0, flags);
			else if (str[i + 1] == 'i')
				put_numbers_args_ll(va_arg(list, long), 10, 0, flags);
			else if (str[i + 1] == 'o')
				put_numbers_args_ull(va_arg(list, unsigned long), 8, 0, flags);
			else if (str[i + 1] == 'x')
				put_numbers_args_ull(va_arg(list, unsigned long), 16, 0, flags);
			else if (str[i + 1] == 'X')
				put_numbers_args_ull(va_arg(list, unsigned long), 16, 1, flags);
			else if (str[i + 1] == 'f')
				put_float(va_arg(list, double));
			i += 1;
		} else if (str[i] == 'L') {
			if (str[i + 1] == 'f') {
				put_float_L(va_arg(list, long double));
			}
			i += 1;
		}
		i++;
	}
	return(count);
}
