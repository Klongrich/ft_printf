#include <unistd.h>
#include <stdio.h>
#include <float.h>

void print_binary_bytes(void *ptr, size_t size) {
    unsigned char *b = (unsigned char *)ptr;
    
    // Move through bytes from end to start (Sign bit is in the last byte)
    for (int i = size - 1; i >= 0; i--) {
        for (int j = 7; j >= 0; j--) {
            unsigned char bit = (b[i] >> j) & 1;
            printf("%u", bit);
        }
        printf(" "); // Space between bytes for readability
    }
    printf("\n");
}

void print_binary(void *ptr, size_t size) {
    unsigned char *b = (unsigned char *)ptr;
    int total_bits = size * 8;

    for (int i = size - 1; i >= 0; i--) {
        for (int j = 7; j >= 0; j--) {
            int bit_pos = (i * 8) + j; // Global bit position (0 to total_bits - 1)
            unsigned char bit = (b[i] >> j) & 1;

            printf("%u", bit);

            // 32-bit Float: Sign at 31, Exponent ends at 23
            if (size == 4) {
                if (bit_pos == 31 || bit_pos == 23) printf(" ");
            }
            // 64-bit Double: Sign at 63, Exponent ends at 52
            else if (size == 8) {
                if (bit_pos == 63 || bit_pos == 52) printf(" ");
            }
            // 128-bit Long Double (x86 80-bit Extended): 
            // Padding: 127-80 | Sign: 79 | Exponent: 78-64 | Mantissa: 63-0
            else if (size == 16) {
                if (bit_pos == 80) printf(" [PADDING] ");
                if (bit_pos == 79 || bit_pos == 64) printf(" ");
            }
        }
    }
    printf("\n");
}


void	print_arry(unsigned int *arr, int n) {
	int i;

	i = 0;
	while (i < n) {
		printf("%u", arr[i]);
		i++;
	}
	printf("\n");
}
	

int	get_decimal_value(int i) {
	int value;

	value = 1;
	while (i > 0) {
		value *= 2;
		i--;	
	}
	printf("i: %d value %d\n", i, value);
	return (value);
}

int	get_exp_value(int top_value, unsigned int *bits, int bias) {
	int j;
	int i;
	int value;

	value = 0;
	i = top_value;
	j = 0;
	while (i > -1) {		
		if (bits[j] == 1) {
			printf("i: %d ", i);
			value += get_decimal_value(i);
		}
		i--;
		j++;
	}
	return (value - bias);
}

double	get_mantissa_bit_value(int i) {
	double value;
	double res;

	value = 1.0;

	while (i >= 0) {
		value *= 2.0;
		i--;	
	}
	res = 1.0 / value;
	printf("i: %d res: %f\n", i,  res);
	return (1.0 / value);
}

double	get_mantissa_value(int top_value, unsigned int *bits) {
	int j;
	int i;
	double value;

	value = 0.0;
	i = 0;
	j = 0;
	while (i < top_value) {		
		if (bits[j] == 1) {
			printf("i: %d ", i);
			value += get_mantissa_bit_value(i);
		}
		i++;
		j++;
	}
	return (value);
}

void	print_64bit_binary(void *ptr, size_t size) {
	int i;
	int j;
	int bit_pos;
	unsigned char bit;
	unsigned char *b;
	int sign;
	unsigned int exp[12];
	unsigned int mantissa[60];
	int k;
	int l;

	
	k = 0;
	l = 0;
	b = (unsigned char *)ptr;
	i = size - 1;
	j = 7;
	while (i >= 0) {
		j = 7;
		while (j >= 0) {
			bit_pos = (i * 8) + j;
			bit = (b[i] >> j) & 1;
			if (bit_pos == 63)
				sign = bit;
			if (bit_pos <= 62 && bit_pos > 51) 
				exp[k++] = bit;
			if (bit_pos <= 51) 
				mantissa[l++] = bit;
			printf("%u", bit);
			if (bit_pos == 63 || bit_pos == 52)
				printf(" ");
			j--;
		}
		i--;
	}

	printf("\n\nSign: \n");
	printf("%d\n", sign);
	printf("Exp: \n");
	print_arry(exp, 11);
	printf("Manstissa \n");
	print_arry(mantissa, 52);
	printf("\n");

	int exp_value;
	double mantissa_value;
	int decimal_value_of_exp;

	exp_value = get_exp_value(10, exp, 1023);
	printf("\n");
	mantissa_value = get_mantissa_value(51, mantissa);
	printf("exp_value: %d\n", exp_value);
	printf("mantissa_value: %.15f\n", mantissa_value);

	decimal_value_of_exp =  get_decimal_value(exp_value);

	printf("decimal_value_of_exp: %d\n", decimal_value_of_exp); 

	double final_val;
	
	final_val = (1 + mantissa_value) * (double)decimal_value_of_exp;
	printf("\nIEEE 755: -> %f\n", final_val);
}

int	main() {
	float f_value;
	double value;
	long double long_value;

	float float_max_val = FLT_MAX;
	double double_max_val = DBL_MAX;
	long double long_double_max_val = LDBL_MAX;

	int d_bias = 1023;
	//implict 1 means add a 1 before the value. Example value = 0.48585949 -> 1.48585949
	//calculation notes
	//first it is sign value 1 = postive, 0 = negative
	//next 11 = expondent (for 64 it bias is 1023)
	//next 53 = Mantissa (value of 2^-1, 2^-2 ...) added with an implict 1 added
	//final calc = sign * 1.mantissa * 2 ^ expondent

	//cachtes for infinity and NaN (Not a Number) 
	//11 bits - all zeros (implict 1 becomes an implict 0)
	//11 bits - all ones (check Mantissa for infintity or NaN)
	//Mantissa is all zeros -> value is infinity
	//Manstiaa is not all zeros -> NaN (Not a Number)

	f_value = 489.049;
	value = 99490.94948;
	long_value = 9485.9585;

	//print_binary(&f_value, sizeof(f_value));
	printf("value: %f\n", value);

	//IEEE 754
	print_64bit_binary(&value, sizeof(value));
	printf("\n");
	double fract;

	fract = 1.0 / 4.0;
	printf("%f\n", fract);
	/*
	print_binary(&long_value, sizeof(long_value));
	printf("\n");
	print_binary(&float_max_val, sizeof(float_max_val));
	print_binary(&double_max_val, sizeof(double_max_val));
	print_binary(&long_double_max_val, sizeof(long_double_max_val));	
	printf("%f\n", float_max_val);
	printf("%f\n", double_max_val);
	printf("%f\n", long_double_max_val);
	printf("Float Size: %zu bytes\n", sizeof(f_value));
	printf("Double Size: %zu bytes\n", sizeof(value));
	printf("Long Double Size: %zu bytes\n", sizeof(long_value));
	printf("%f\n", value);
	printf("%Lf\n", long_value);
	*/
	return (0);
}
