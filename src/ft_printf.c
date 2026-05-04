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
	flags.dot = 0;
	return (flags);
}

void	set_flags(char c, t_flags *flags) {
	if (c == '#')
		flags->pound = 1;
	else if (c == '0')
		flags->zero = 1;
	else if (c == '-')
		flags->left = 1;
	else if (c == '+')
		flags->plus = 1;
	else if (c == ' ')
		flags->space = 1;
	else if (c == '.')
		flags->dot = 1;
}

void	parse_flags(char *buffer, t_flags *flags) {
	int i;
	int j;
	char buff[4095];
	
	i = 0;
	j = 0;
	buff[0] = '\0';
	while (buffer[i] == '#' || buffer[i] == '0' || buffer[i] == '-' || buffer[i] == '+' || buffer[i] == ' ' || buffer[i] == '.') {
		set_flags(buffer[i], flags);
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

int             ft_numlen_hex(unsigned long long n) {
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

int             ft_numlen_oct(unsigned long long n) {
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
                 n /= 8;
                 i++;
         }
         return (i);
}

int	get_numlen(long n, int base) {
	if (base == 17) {
 		return(ft_numlen_hex(n));
	} else if (base == 8) {
		return(ft_numlen_oct(n));
	}  else
		return(ft_numlen_ll(n));
}

int 	put_dot(long n, int num_len, int count, int padding) {
	int i;

	i = 0;
	if (n < 0 ) {
		count += ft_putchar('-');
		num_len--;
	}
	while (i < padding - num_len) {
		count += ft_putchar('0');
		i++;	
	}
	return (count);
}

int	put_padding_zero(long n, int base, int num_len, t_flags flags) {
	int count;
	int i;	

	i = 0;
	count = 0;
	if (base == 16 && flags.pound) {
		if(n != 0) {
			count += ft_putchar('0');
			count += ft_putchar('x');
			num_len += 2;
		}
	} else {
		if (n > 0 && flags.plus && base != 8) {
			count += ft_putchar('+');
			num_len++;
		}
		else if (n < 0)
			count += ft_putchar('-');
	}
	while (i < flags.padding - num_len ) {
		count += ft_putchar('0');
		i++;
	}
	return (count);
}

int	put_no_padding(long n, int base, int is_signed, t_flags flags) {
	int count;

	count = 0;
	if (flags.padding == 0 && base != 16) {
		if (flags.plus && n >= 0) {
			count  += ft_putchar('+');
		}
	}
	if (flags.padding == 0 && flags.space) {
		if (n >= 0 && !flags.plus && !is_signed)
			count += ft_putchar(' ');
	}
	if (n < 0 && !flags.zero && !flags.padding) {
		count += ft_putchar('-');
	}
	return (count);
}

int put_padding_right_hex(long n, int num_len, t_flags flags) {
	int count;
	int i;

	count = 0;
	i = 0;
	if (flags.pound && n != 0) 
		num_len += 2;
	while (i < flags.padding - num_len) {
		count += ft_putchar(' ');
		i++;
	}
	if (flags.pound && n != 0)  {
		count += ft_putchar('0');
		count += ft_putchar('x');
	}
	return (count);
}

int put_padding_right_decimal_octal(long n, int base, int num_len, t_flags flags) {
	int count;
	int i;

	i = 0;
	count = 0;
	if (flags.plus) {
		if (n >= 0 && base != 8) {
			if (!flags.padding)
				count += ft_putchar('+');
			num_len++;
		}
	}
	while (i++ < flags.padding - num_len)
		count += ft_putchar(' ');
	if (n < 0 && !flags.plus)
		count += ft_putchar('-');
	if (flags.plus) {
		if (n >= 0 && base != 8) {
			count += ft_putchar('+');
		} else if (n < 0)
			count += ft_putchar('-');
	}
	return (count);
}

int put_padding_right(long n, int base, int num_len, t_flags flags) {
	int count;

	count = 0;
	if (base == 16) {
		return (put_padding_right_hex(n, num_len, flags));
	} else {
		return (put_padding_right_decimal_octal(n, base, num_len, flags));
	}
	return (count);
}

int	put_formatting_from_flags(long n, int base, t_flags flags, int is_signed) {
	int num_len;
	int count;
	
	count = 0;
	if (!is_signed || base == 8) {
		flags.plus = 0;
		flags.space = 0;
	}
	num_len = get_numlen(n, base);
	if (base == 17)
		base = 16;
	if (flags.dot) 
		return (put_dot(n, num_len, count, flags.padding));
	if (flags.zero && !flags.left) 
		return(put_padding_zero(n, base, num_len, flags));	
	if (!flags.padding)
		return (put_no_padding(n, base, is_signed, flags));
	if (flags.padding != 0 && !flags.left)
		return (put_padding_right(n, base, num_len, flags));
	return (count);
}


int	get_numlen_ull(unsigned long long n, int base) {
	if (base == 17 || base == 16)
		return(ft_numlen_hex(n));
	else if (base == 8) 
		return(ft_numlen_oct(n));
	else  
		return(ft_numlen_ull(n));
}

int	put_padding_zero_ull(unsigned long long n, int base, int num_len, t_flags flags) {
	int count;
	int i;

	count = 0;
	i = 0;
	if (base == 16 && flags.pound && n != 0) {
		count += ft_count_putstr("0x");
		num_len += 2;
	}
	while (i < flags.padding - num_len ) {
		count += ft_putchar('0');
		i++;
	}
	return (count);
}

int	put_formatting_from_flags_ull(unsigned long long n, int base, t_flags flags) {
	int i;
	int num_len;
	int count;

	count = 0;
	i = 0;
	num_len = get_numlen_ull(n, base);
	if (flags.zero && !flags.left)
		return (put_padding_zero_ull(n, base, num_len, flags));
	if (flags.padding != 0 && !flags.left) {
		if (base == 16 && flags.pound && n != 0) 
			num_len += 2;
		while (i++ < flags.padding - num_len) 
			count += ft_putchar(' ');
		if (base == 16 && flags.pound && n != 0) 
			count += ft_count_putstr("0x");
	}
	return (count);
}

int	get_numlen_args(long n, int base) {
	if (base == 17 || base == 16)
		return (ft_numlen_hex(n));
	if (base == 8)
		return (ft_numlen_oct(n));
	else
		return (ft_numlen_ll(n));

}

int	put_padding_left(long n, int base, int is_uppercase, t_flags flags) {
	int count;	
	int i;
	int num_len;

	i = 0;
	count = 0;
	num_len = get_numlen_args(n, base);
	if (flags.left && flags.plus && base != 8  && base != 16) {
		count += ft_putchar('+');
		num_len++;
	}
	if (flags.left && flags.pound && base == 16 && n != 0) {
		count += ft_count_putstr("0x");
		num_len++;
	}
	count += put_number(n, base, is_uppercase, "holder");
	if (flags.pound && base == 16 && n != 0) 
		num_len += 1;
	if (flags.left && flags.padding != 0) {
		while (i++ < flags.padding - num_len) 
			count += ft_putchar(' ');
	}
	return (count);
}

int     put_numbers_args(long n, int base, int is_uppercase, t_flags flags) { 
	int count;

	count = 0;
	if (base == 8 || base == 16 || base == 17)
		count += put_formatting_from_flags(n, base, flags, 0);
	else
		count += put_formatting_from_flags(n, base, flags, 1);
	if (base == 17)
		base = 16;
	if (flags.left) 
		return (put_padding_left(n, base, is_uppercase, flags));
	else {
		if (!flags.left && !flags.padding && flags.pound && base == 16 && n != 0)
			count += ft_count_putstr("0x");	
		if (flags.space && !flags.padding && !flags.plus && base == 10 && n >= 0) 
			count += ft_putchar(' ');
		count += put_number(n, base, is_uppercase, "holder");
		return (count);
	}
}

int     put_numbers_args_u(long n, int base, t_flags flags) { 
	int i;
	int num_len;
	int count;

	i = 0;
	count = 0;
	num_len = ft_numlen_ll(n);
	count += put_formatting_from_flags(n, base, flags, 0);
	count += putunit_max(n, base);
	if (flags.padding != 0 && flags.left) {
		while (i < flags.padding - num_len) {
			count += ft_putchar(' ');
			i++;
		}	
	}
	return (count);
}

int     put_character_args(char c, t_flags flags) { 
	int i;
	int count;

	i = 0;
	count = 0;
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
		while (i++ < flags.padding - str_len)
			count += ft_putchar(' ');
	}
	if (str == NULL)
		count += ft_count_putstr("(null)");
	else
		count += ft_count_putstr(str);
	if (flags.padding != 0 && flags.left) {
		while (i++ < flags.padding - str_len)
			count += ft_putchar(' ');
	}
	return (count);
}

int	put_number_ll(signed long long n, int base, int is_uppercase) {
	int	count;
	char	*symbols;
	unsigned long long nb; 

	count = 0;
	if (!is_uppercase)
		symbols = "0123456789abcdef";
	else
		symbols = "0123456789ABCDEF";
	if (n == 0)
		return (ft_putchar('0'));
	else if (n < 0) {
		nb = (unsigned long long)-n;
	} else {
		nb = (unsigned long long)n;
    	}
	if (nb >= (unsigned long long)base)
		count += put_number_ll(nb / base, base, is_uppercase);
	count += ft_putchar(symbols[nb % base]);
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
		n = -n;
		count++;
	}
	if (n >= (unsigned long long)base)
		count += put_number_ll(n / base, base, is_uppercase);
	count += ft_putchar(symbols[n % base]);
	return (count);
}

int     put_numbers_args_ll(signed long long n, int base, int is_uppercase, t_flags flags) { 
	int i;
	int num_len;
	int count;

	count = 0;
	i = 0;
	num_len = ft_numlen_ll(n);
	count += put_formatting_from_flags(n, base, flags, 1);
	if (flags.left && flags.plus) {
		if( n >= 0)
			count += ft_putchar('+');
		num_len++;
	}
	if (flags.space && !flags.padding && !flags.plus) {
		if (n >= 0) {
			count += ft_putchar(' ');
		}
	}	
	count += put_number_ll(n, base, is_uppercase);
	if (flags.padding != 0 && flags.left) {
		while (i < flags.padding - num_len) {
			count += ft_putchar(' ');
			i++;
		}	
	}
	return (count);
}

int     put_numbers_args_ull(unsigned long long n, int base, int is_uppercase, t_flags flags) { 
	int i;
	int num_len;
	int count;

	count = 0;
	i = 0;
	if (base == 16)
		num_len = ft_numlen_hex(n);
	else if (base == 8) {
		num_len = ft_numlen_oct(n);
	} else
		num_len = ft_numlen_ull(n);
	count += put_formatting_from_flags_ull(n, base, flags);	
	if (base == 16 && flags.pound && n != 0 && (!flags.padding || flags.left)) {
		count += ft_count_putstr("0x");
		num_len += 2;
	}
	count += put_number_ull(n, base, is_uppercase);
	if (flags.padding != 0 && flags.left) {
		while (i++ < flags.padding - num_len) 
			count += ft_putchar(' ');
	}
	return (count);
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
		while (i++ < flags.padding - num_len)
			count += ft_putchar(' ');
	}
	if (pointer == NULL)
		count += ft_count_putstr("(nil)");
	count += ft_count_putstr("0x");
	count += putunit_max(address, 16);
	if (flags.padding != 0 && flags.left) {
		while (i++ < flags.padding - num_len)
			count += ft_putchar(' ');
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
	return (bit1 == 0 && bit2 == 0 && bit3 == 0 && bit4 == 0) ? 0 :
	(bit1 == 0 && bit2 == 0 && bit3 == 0 && bit4 == 1) ? 1 :
	(bit1 == 0 && bit2 == 0 && bit3 == 1 && bit4 == 0) ? 2 :
	(bit1 == 0 && bit2 == 0 && bit3 == 1 && bit4 == 1) ? 3 :
	(bit1 == 0 && bit2 == 1 && bit3 == 0 && bit4 == 0) ? 4 :
	(bit1 == 0 && bit2 == 1 && bit3 == 0 && bit4 == 1) ? 5 :
	(bit1 == 0 && bit2 == 1 && bit3 == 1 && bit4 == 0) ? 6 :
	(bit1 == 0 && bit2 == 1 && bit3 == 1 && bit4 == 1) ? 7 :
	(bit1 == 1 && bit2 == 0 && bit3 == 0 && bit4 == 0) ? 8 :
	(bit1 == 1 && bit2 == 0 && bit3 == 0 && bit4 == 1) ? 9 :
	(bit1 == 1 && bit2 == 0 && bit3 == 1 && bit4 == 0) ? 10 :
	(bit1 == 1 && bit2 == 0 && bit3 == 1 && bit4 == 1) ? 11 :
	(bit1 == 1 && bit2 == 1 && bit3 == 0 && bit4 == 0) ? 12 :
	(bit1 == 1 && bit2 == 1 && bit3 == 0 && bit4 == 1) ? 13 :
	(bit1 == 1 && bit2 == 1 && bit3 == 1 && bit4 == 0) ? 14 : 
	(bit1 == 1 && bit2 == 1 && bit3 == 1 && bit4 == 1) ? 15 : 0;
}


char	get_hex_char(int num) {
	return (num == 0)  ? '0' :
	(num == 1)  ? '1' :
	(num == 2)  ? '2' :
	(num == 3)  ? '3' :
	(num == 4)  ? '4' :
	(num == 5)  ? '5' :
	(num == 6)  ? '6' :
	(num == 7)  ? '7' :
	(num == 8)  ? '8' :
	(num == 9)  ? '9' :
	(num == 10) ? 'a' :
	(num == 11) ? 'b' :
	(num == 12) ? 'c' :
	(num == 13) ? 'd' :
	(num == 14) ? 'e' :
	(num == 15) ? 'f' : '0';
}

char	get_hex_char_uppercase(int num) {
	return (num == 0)  ? '0' :
	(num == 1)  ? '1' :
	(num == 2)  ? '2' :
	(num == 3)  ? '3' :
	(num == 4)  ? '4' :
	(num == 5)  ? '5' :
	(num == 6)  ? '6' :
	(num == 7)  ? '7' :
	(num == 8)  ? '8' :
	(num == 9)  ? '9' :
	(num == 10) ? 'A' :
	(num == 11) ? 'B' :
	(num == 12) ? 'C' :
	(num == 13) ? 'D' :
	(num == 14) ? 'E' :
	(num == 15) ? 'F' : '0';
}

int	put_8bit_hex_value(unsigned int num, char *value) {
	int count;

	count = 0;
	if (num != 0) {	
		if (value[0] == '0' && value[1] == '0')
			count += ft_putchar('0');
		else {
			if (value[0] != '0')
				count += ft_putchar(value[0]);
			count += ft_putchar(value[1]);
		}
	} else {
		count += ft_putchar('0');
	}
	return (count);
}

int	put_8bit_hex_value_padding_left(char *value, unsigned int num, t_flags flags) {
	int count;
	int num_len;
	int i;

	i = 0;
	count = 0;
	num_len = 2;
	if (flags.pound && flags.left && !flags.zero && num != 0) {
		count += ft_count_putstr("0x");
		num_len += 2;
	}
	if (!flags.left && !flags.padding && !flags.zero && flags.pound && num != 0)
		count += ft_count_putstr("0x");
	if (value[0] == '0' && num == 0)
		num_len--;
	count += put_8bit_hex_value(num, value);
	if (flags.padding != 0 && flags.left) {
		while (i++ < flags.padding - num_len) 
			count += ft_putchar(' ');
	}
	return (count);
}

void	get_8bit_hex_values(int uppercase, int *bits, char *res) {
	if (!uppercase) {
		res[0] = get_hex_char(convert_hex_bits(bits[0], bits[1], bits[2], bits[3]));
		res[1] = get_hex_char(convert_hex_bits(bits[4], bits[5], bits[6], bits[7]));
	} else {
		res[0] = get_hex_char_uppercase(convert_hex_bits(bits[0], bits[1], bits[2], bits[3]));
		res[1] = get_hex_char_uppercase(convert_hex_bits(bits[4], bits[5], bits[6], bits[7]));
	}
	res[2] = '\0';
}

int 	put_8bit_hex(unsigned int num, int uppercase, t_flags flags) {
	int bits[8];
	int j;
	int i;
	char value[3];
	int count;

	count = 0;
	i = 7;
	j = 0;
	while (i > -1) 
		bits[j++] = (num >> i--) & 1;
	get_8bit_hex_values(uppercase, bits, value);
	if (value[0] == '0' && value[1] != '0')
		count += put_formatting_from_flags(1, 16, flags, 1);
	else if (num != 0)
		count += put_formatting_from_flags(11, 16, flags, 1);
	else
		count += put_formatting_from_flags(0, 16, flags, 1);
	return (count += put_8bit_hex_value_padding_left(value, num, flags) );
}

void	get_16bit_hex_values(int uppercase, int *bits, char *value) {
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
	value [4] = '\0';
}

int	get_padding_value(char *value) {
	int padding_value = 1111;
	if (value[0] == '0' && value[1] != '0') {
		padding_value /= 10;
	}
	else if (value[0] == '0' && value[1] == '0' && value[2] != '0') {
		padding_value /= 100;
	}
	else if (value[0] == '0' && value[1] == '0' && value[2] == '0' && value[3] != '0') {
		padding_value /= 1000;
	}
	return (padding_value);
}


int put_4hex_16bit(char *value) {
	ft_putchar(value[0]);
	ft_putchar(value[1]);
	ft_putchar(value[2]);
	ft_putchar(value[3]);
	return (4);
}

int	put_16bit_hex_value(char *value, unsigned int num) {
	int count;

	count = 0;
	if (num != 0) {
		if (value[0] == '0' && value[1] != '0') {
			count += ft_putchar(value[1]);
			count += ft_putchar(value[2]);
			count += ft_putchar(value[3]);
		}
		else if (value[0] == '0' && value[1] == '0' && value[2] != '0') {
			count += ft_putchar(value[2]);
			count += ft_putchar(value[3]);
		}
		else if (value[0] == '0' && value[1] == '0' && value[2] == '0' && value[3] != '0') {
			count += ft_putchar(value[3]);
		} else {
			if (value[0] == '0' && value[1] == '0' && value[2] == '0' && value[3] == '0') {
				count += ft_putchar('0');
			} else 
				count += put_4hex_16bit(value);
		}
	} else 
		count += ft_putchar('0');
	return (count);
}

int 	get_padding_left_for_numlen(char *value, unsigned int num) {
	if (num != 0) {
		if (value[0] == '0' && value[1] != '0') 
			return (-1);
		else if (value[0] == '0' && value[1] == '0' && value[2] != '0')
			return (-2);
		else if (value[0] == '0' && value[1] == '0' && value[2] == '0' && value[3] != '0')
			return (-3);
		else
			return (0);
	} else {
		return (-3);
	}
}

int     put_16bit_hex_value_padding_left(char *value, unsigned int num, t_flags flags) {
	int count;
	int num_len;
	int i;

	i = 0;
	count = 0;
	num_len = 4;
	if (flags.pound && flags.left && !flags.zero && num != 0) {
		count += ft_count_putstr("0x");
		num_len += 2;
	}
	if (!flags.left && !flags.padding && !flags.zero && flags.pound && num != 0) 
		count += ft_count_putstr("0x");
	num_len += get_padding_left_for_numlen(value, num);
	count += put_16bit_hex_value(value, num);
	if (flags.padding != 0 && flags.left) {
		while (i < flags.padding - num_len) {
			count += ft_putchar(' ');
			i++;
		}	
	}
	return (count);
}

int	put_16bit_hex(unsigned int num, int uppercase, t_flags flags) {
	int bits[16];
	int j;
	int i;
	char value[5];
	int count;	

	count = 0;
	i = 15;
	j = 0;
	while (i > -1) 
		bits[j++] = (num >> i--) & 1;
	get_16bit_hex_values(uppercase, bits, value);
	if (num != 0)
		count += put_formatting_from_flags(get_padding_value(value), 16, flags, 1);
	else
		count += put_formatting_from_flags(0, 16, flags, 1);
	count += put_16bit_hex_value_padding_left(value, num, flags);
	return (count);
}

int	put_padding_left_octal(int value, t_flags flags) {
	int count;
	int num_len;
	int i;

	i = 0;
	count = 0;
	num_len = ft_numlen(value);
	if (flags.padding != 0 && flags.left) {
		while (i < flags.padding - num_len) {
			count += ft_putchar(' ');
			i++;
		}	
	}
	return (count);
}

int	put_8bit_octal(unsigned int num, t_flags flags) {
	int bits[8];
	int j;
	int i;
	int value;
	int count;

	i = 7;
	j = 0;
	count = 0;
	value = 0;
	while (i > -1) 
		bits[j++] = (num >> i--) & 1;
	value += convert_octal_bits(0, bits[0], bits[1]) * 100;
	value += convert_octal_bits(bits[2], bits[3], bits[4]) * 10;
	value += convert_octal_bits(bits[5], bits[6], bits[7]);
	count += put_formatting_from_flags(value, 8, flags, 1);
	count += ft_putnbr_f(value);
	count += put_padding_left_octal(value, flags);
	return (count);
}


int	put_16bit_octal(unsigned int num, t_flags flags) {
	int bits[16];
	int j;
	int i;
	int value;
	int count;
	
	count = 0;
	i = 15;
	j = 0;
	value = 0;
	while (i > -1) 
		bits[j++] = (num >> i--) & 1;
	value += convert_octal_bits(0, 0, bits[0]) * 100000;
	value += convert_octal_bits(bits[1], bits[2], bits[3]) * 10000;
	value += convert_octal_bits(bits[4], bits[5], bits[6]) * 1000;
	value += convert_octal_bits(bits[7], bits[8], bits[9]) * 100;
	value += convert_octal_bits(bits[10], bits[11], bits[12]) * 10;
	value += convert_octal_bits(bits[13], bits[14], bits[15]);
	count += put_formatting_from_flags(value, 8, flags, 1);	
	count += ft_putnbr_f(value);
	count += put_padding_left_octal(value, flags);
	return (count);
}


int	get_decimal_value(int i, int is_signed, int top_value) {
	int value;
	int sign;

	value = 1;
	sign = 1;
	if (i == top_value && is_signed)
		sign = -1;
	while (i > 0) {
		value *= 2;
		i--;	
	}
	return (value * sign);
}

int	convert_binary_base10(int is_signed, int top_value, int *bits) {
	int j;
	int i;
	int value;

	value = 0;
	i = top_value;
	j = 0;
	while (i > -1) {		
		if (bits[j] == 1)
			value += get_decimal_value(i, is_signed, top_value);
		i--;
		j++;
	}
	return (value);
}

int	put_padding_left_value_base10(int value, int is_signed, t_flags flags) {
	int num_len;
	int count;
	int i;
	
	i = 0;
	count = 0;
	num_len = ft_numlen(value);
	if (flags.left && flags.padding != 0 && is_signed) {
		if (value < 0) 
			count += ft_putchar('-');
		if (value >= 0 && flags.plus) {
			count += ft_putchar('+');
			num_len++;
		}
	}
	if (is_signed && !flags.padding && !flags.plus && flags.space && value >= 0) 
		count += ft_putchar(' ');
	count += ft_putnbr_f(value);
	if (flags.padding != 0 && flags.left) {
		while (i++ < flags.padding - num_len) 
			count += ft_putchar(' ');
	}
	return (count);
}

int	put_8bit(unsigned int num, int is_signed, t_flags flags) {
	int bits[8];
	int j;
	int i;
	int value;
	int count;

	count = 0;
	i = 7;
	j = 0;
	value = 0;
	while (i > -1) 
		bits[j++] = (num >> i--) & 1;
	value = convert_binary_base10(is_signed, 7, bits);
	count += put_formatting_from_flags(value, 10, flags, is_signed);
	count += put_padding_left_value_base10(value, is_signed, flags);
	return (count);
}

int	put_16bit(unsigned int num, int is_signed, t_flags flags) {
	int bits[16];
	int j;
	int i;
	int value;
	int count;

	i = 15;
	j = 0;
	count = 0;
	value = 0;
	while (i > -1)
		bits[j++] = (num >> i--) & 1;
	value = convert_binary_base10(is_signed, 15, bits);
	count += put_formatting_from_flags(value, 10, flags, is_signed);
	count += put_padding_left_value_base10(value, is_signed, flags);
	return (count);	
}

int	print_float_decimal(long int_part, int precision, long double f, t_flags flags) {
	int count;
	long double fraction;
	int digit;
	char c;

	count = 0;
	if (precision != 0 || (precision == 0 && flags.pound)) {
    		write(1, ".", 1);
		count += 1;
	}
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

int	put_padding_zero_float(long int_part, int num_len, t_flags flags) {
	int count;
	int i;
	
	i = 0;
	count = 0;
	if (flags.plus && int_part >= 0) {
		count += ft_putchar('+');
		num_len++;
	}
	if (int_part < 0 )
		count += ft_putchar('-');
	while (i++ < flags.padding - num_len)
		count += ft_putchar('0');
	return(count);
}

int	put_padding_right_float(long int_part, int num_len, t_flags flags) {
	int count;
	int i;

	i = 0;
	count = 0;
	if (!flags.left && flags.padding != 0 && !flags.dot) {
		if (flags.zero) {
			count += put_padding_zero_float(int_part, num_len, flags);
		} else {
			if (flags.plus && int_part >= 0) 
				num_len++;
			while (i++ < flags.padding - num_len)
				count += ft_putchar(' ');
			if (flags.plus && int_part >= 0) 
				count += ft_putchar('+');
			if (int_part < 0)
				count += ft_putchar('-');
		}
	}
	return (count);
}

int	put_padding_left_float(int num_len, t_flags flags) {
	int count;
	int i;

	i = 0;
	count = 0;
	if (flags.left && flags.padding != 0 && !flags.dot) {
		while (i < flags.padding - num_len) {
			count += ft_putchar(' ');
			i++;
		}
	}
	return (count);
}

int put_float_value(long double f, long int_part, int precision, t_flags flags) {
	int count;

	count = 0;
	if (f < 0) {
		if (flags.left || flags.padding == 0 || flags.dot)
			count += ft_putchar('-');
		f = -f;
		int_part = -int_part;
	}
	if (!flags.padding && flags.plus && int_part >= 0)
		count += ft_putchar('+');
	if (flags.space && !flags.padding && !flags.plus && int_part >= 0) 
		count += ft_putchar(' ');

	if (f > 9223372036854775807) {
		count += put_number_ll(int_part, 10, 0); 
	} else {
		count += put_number_ll(int_part, 10, 0);
		count += print_float_decimal(int_part, precision, f, flags);
	}
	return (count);
}

int put_float(long double f, t_flags flags) {
	int precision;
	int count;
	long int_part;
	int num_len;

	num_len = 0;
	count = 0;
	int_part =  (long long)f;
	if (flags.dot) 
		precision = flags.padding;
	else 
		precision = 6;
	num_len = ft_numlen(int_part) + precision + 1;
	count += put_padding_right_float(int_part, num_len, flags);
	if (flags.left && flags.padding != 0 && flags.plus && int_part >= 0 && !flags.dot) {
		count += ft_putchar('+');
		num_len++;
	}	
	count += put_float_value(f, int_part, precision, flags);
	count += put_padding_left_float(num_len, flags);
	return (count);
}

int	check_c(char c) {
	if (c == 'c' || c == 'd' || c == 'i' || c == 's' || c == 'p')
		return (1);
	if (c == 'u' || c == 'x' || c == 'X' || c == 'o' || c == 'f')
		return (1);
	if (c == 'h' || c == 'l' || c =='L')
		return (1);
	return (0);
}


int	check_32bit_data_type(char c) {
	if (c == 'd' || c == 'i')
		return (1);
	if (c == 'u')
		return (1);
	if (c == 'x')
		return (1);
	if (c == 'X')
		return (1);
	if (c == 'o')
		return (1);
	return (0);

}

int	put_32bit_data(char *str, int i, va_list list, t_flags flags) {
	int count;

	count = 0;
	if (str[i] == 'd' || str[i] == 'i')
		count += put_numbers_args(va_arg(list, int), 10, 0, flags);
	else if (str[i] == 'u')
		count += put_numbers_args_u(va_arg(list, unsigned int), 10, flags);
	else if (str[i] == 'x')
		count += put_numbers_args(va_arg(list, unsigned int), 17, 0, flags);
	else if (str[i] == 'X')
		count += put_numbers_args(va_arg(list, unsigned int), 17, 1, flags);
	else if (str[i] == 'o')
		count += put_numbers_args(va_arg(list, unsigned int), 8, 0, flags);
	return (count);
}

int	put_8bit_data(char *str, int i, va_list list, t_flags flags) {
	int count;
	
	count = 0;
	if (str[i + 2] == 'u')
		count += put_8bit(va_arg(list, unsigned int), 0, flags);
	else if (str[i + 2] == 'd')
		count += put_8bit(va_arg(list, int), 1, flags);
	else if (str[i + 2] == 'i')
		count += put_8bit(va_arg(list, int), 1, flags);
	else if (str[i + 2] == 'o')
		count += put_8bit_octal(va_arg(list, unsigned int), flags);
	else if (str[i + 2] == 'x')
		count += put_8bit_hex(va_arg(list, unsigned int), 0, flags);
	else if (str[i + 2] == 'X')
		count += put_8bit_hex(va_arg(list, unsigned int), 1, flags);
	return (count);
}

int	put_16bit_data(char *str, int i, va_list list, t_flags flags) {
	int count;

	count = 0;
	if(str[i + 1] == 'u')
		count += put_16bit(va_arg(list, unsigned int), 0, flags);
	else if (str[i + 1] == 'd')
		count += put_16bit(va_arg(list, int), 1, flags);
	else if (str[i + 1] == 'i')
		count += put_16bit(va_arg(list, int), 1, flags);
	else if(str[i + 1] == 'o')
		count += put_16bit_octal(va_arg(list, unsigned int), flags);
	else if(str[i + 1] == 'x')
		count += put_16bit_hex(va_arg(list, unsigned int), 0, flags);
	else if (str[i + 1] == 'X')
		count += put_16bit_hex(va_arg(list, unsigned int), 1, flags);
	return (count);
}

int	put_64bit_data_l(char *str, int i, va_list list, t_flags flags) {
	int count;

	count = 0;
	if (str[i + 1] == 'u')
		count += put_numbers_args_ull(va_arg(list, unsigned long), 10, 0, flags);
	else if (str[i + 1] == 'd')
		count += put_numbers_args_ll(va_arg(list, signed long long), 10, 0, flags);
	else if (str[i + 1] == 'i')
		count += put_numbers_args_ll(va_arg(list, signed long long), 10, 0, flags);
	else if (str[i + 1] == 'o')
		count += put_numbers_args_ull(va_arg(list, unsigned long), 8, 0, flags);
	else if (str[i + 1] == 'x')
		count += put_numbers_args_ull(va_arg(list, unsigned long), 16, 0, flags);
	else if (str[i + 1] == 'X')
		count += put_numbers_args_ull(va_arg(list, unsigned long), 16, 1, flags);
	return (count);
}

int 	put_64bit_data_ll(char *str, int i, va_list list, t_flags flags) {
	int count;
	
	count = 0;
	if (str[i + 2] == 'u')
		count += put_numbers_args_ull(va_arg(list, unsigned long long), 10, 0, flags);
	else if (str[i + 2] == 'd')
		count += put_numbers_args_ll(va_arg(list, signed long long), 10, 0, flags);
	else if (str[i + 2] == 'i')
		count += put_numbers_args_ll(va_arg(list, signed long long), 10, 0, flags);
	else if (str[i + 2] == 'o')
		count += put_numbers_args_ull(va_arg(list, unsigned long long), 8, 0, flags);
	else if (str[i + 2] == 'x')
		count += put_numbers_args_ull(va_arg(list, unsigned long long), 16, 0, flags);
	else if (str[i + 2] == 'X')
		count += put_numbers_args_ull(va_arg(list, unsigned long long), 16, 1, flags);
	return (count);
}


int	check_i(char *str, int i) {
	if (str[i] == 'h' && str[i + 1] == 'h')
		return (2);
	else if (str[i] == 'h')
		return (1);
	else if (str[i] == 'l' && str[i + 1] == 'l')
		return (2);
	else if (str[i] == 'l')
		return (1);
	else if (str[i] == 'L')
		return (1);
	return (0);
}

int	print_data_type(char *str, int i, va_list list, t_flags flags) {
	int count;

	count = 0;
	if (str[i] == 's')
		count += put_string_args(va_arg(list, char*), flags);
	if (str[i] == 'p')
		count += put_pointer(va_arg(list, void*), flags);
	if (str[i] == 'f' || (str[i] == 'l' && str[i + 1] == 'f'))
		 count += put_float(va_arg(list, double), flags);
	if (check_32bit_data_type(str[i])) 
		count += put_32bit_data(str, i, list, flags);
	else if (str[i] == 'h' && str[i + 1] == 'h') 
		count += put_8bit_data(str, i, list, flags);
	else if (str[i] == 'h') 
		count += put_16bit_data(str, i, list, flags);
	else if (str[i] == 'l' && str[i + 1] == 'l') 
		count += put_64bit_data_ll(str, i, list, flags);
	else if (str[i] == 'l') 
		count += put_64bit_data_l(str, i, list, flags);
	else if (str[i] == 'L' && str[i + 1] == 'f') 
		count += put_float(va_arg(list, long double), flags);
	return (count);
}

int	parse_flag_parameters(char *str, int i, t_flags *flags) {
	char 	buffer[4095];
	int	j;

	j = 0;
	buffer[0] = '\0';
	while(!check_c(str[i]))
		buffer[j++] = str[i++];
	buffer[j] = '\0';
	parse_flags(buffer, flags);
	return (j);
}

int	ft_printf(char *str, ...) {
	va_list list;
	int	i;
	int 	count;
	t_flags flags;

	i = 0;
	count = 0;
	va_start(list, str);
	while (str[i]) {
		flags = init();
		while (str[i] != '%' && str[i]) 
			count += ft_putchar(str[i++]);
		if (!str[i]) break;
		if (str[i + 1] == '%') {
			count += ft_putchar('%');
			i++;	
		} else 
			i += parse_flag_parameters(str, i + 1, &flags) + 1;
		if (str[i] == 'c')
			 count +=  put_character_args(va_arg(list, int), flags);
		count += print_data_type(str, i, list, flags);
		i += check_i(str, i) + 1;
	}
	return(count);
}
