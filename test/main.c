#include "ft_printf.h"
#include <stdio.h>


void	checking(char *str) {
	ft_printf("\nchecking %s:\n", str);
}

void	runcheck(char *str, ...) {
	va_list list;

	va_start(list, str);

	
}


int	main() {
	char c;
	char *str;
	int num;

	c = 'k';
	str = "testing";
	num = 42;

	printf("no paramters passed\n");
	ft_printf("Testing STR\n");

	checking("strings");
	ft_printf("%s\n", str);
	ft_printf("testing str ->: %s\n", str);

	checking("characters");
	ft_printf("tesing character: %c\n", c);

	checking("integers");
	ft_printf("%d\n", num);
	ft_printf("%i\n", num);

	checking("pointers");
	ft_printf("%p\n", &num);
	printf("%p\n", &num);

	checking("unsigned integers");
	ft_printf("%u\n", -123);
	printf("%u\n", -123);

	checking("hex");
	ft_printf("%x\n", 12884083);
	printf("%x\n", 12884083);	

	checking("oct");
	printf("%o\n", 7594739);
	ft_printf("%o\n", 7594739);

	checking("hhu");
	printf("%hhu\n", 300);	
	printf("%hhu\n", 750);

	ft_printf("%hhu\n", 300);
	ft_printf("%hhu\n", 750);

	checking("hhd");
	printf("%hhd\n", 750);
	ft_printf("%hhd\n", 750);

	checking("hho");
	printf("%hho\n", 12389);
	printf("%hho\n", 750750);
	ft_printf("%hho\n", 12389);	
	ft_printf("%hho\n", 750750);

	checking("hhx");
	printf("%hhx\n", 7544);
	printf("%hhx\n", 78327);
	ft_printf("%hhx\n", 7544);
	ft_printf("%hhx\n", 78327);

	checking("hhX");
	printf("%hhX\n", 78327);
	ft_printf("%hhX\n", 78327);

	checking("ho");
	printf("%ho\n", 1234458);
	ft_printf("%ho\n", 1234458);	

	checking("f");
	printf("%f\n", 78.1234);
	printf("%f\n", 64.7485763829);
	ft_printf("%f\n", 78.1234);
	ft_printf("%f\n", 64.7485763829);

	checking("hu");
	printf("%hu\n", 70000);
	ft_printf("%hu\n", 70000);

	checking ("hd");
	printf ("%hd\n", 686868);
	ft_printf("%hd\n", 686868);

	checking("hx");
	printf("%hx\n", 123456);
	ft_printf("%hx\n", 123456);

	checking("hX");
	printf("%hX\n", 654321);
	ft_printf("%hX\n", 654321);

	checking("ld");
	printf("%ld\n", 9223372036854775807);
	ft_printf("%ld\n", 9223372036854775807);

	checking("lu");
	printf("%lu\n", 983752380928043);
	ft_printf("%lu\n", 983752380928043);

	checking ("llu");
	printf("%llu\n", 9837523809280433355ULL);
	ft_printf("%llu\n", 9837523809280433355ULL);

        checking ("lld");
        printf("%lld\n", 9837523809280433355ULL);
        ft_printf("%lld\n", 9837523809280433355ULL);

	checking("u");
	printf("%u\n", 4294967295U);
	ft_printf("%u\n", 4294967295U);

	checking ("#hhx");
	printf("%#hhx\n", 748839);
	ft_printf("%#hhx\n", 748839);

	checking ("#010x");
	printf("%#010x\n", 700);
	ft_printf("%#010x\n", 700);

	checking("+010d");
	printf("%#10x test %+05d\n", 23, 55);
	ft_printf("%#10x test %+05d\n", 23, 55);

	checking(" ");
	printf("i: %d j: %d k:%d\n", 10, 20, 30);
	ft_printf("i: %d j: %d k:%d\n", 10, 20, 30);
	
	checking("%10s");
	printf("%10s testing %-5s :\n", "Kyle", "kyle");
	ft_printf("%10s testing %-5s :\n", "Kyle", "kyle");

	checking("%5c");
	printf("%5c testing %-12c another: \n", 'K', 'L');
	ft_printf("%5c testing %-12c another: \n", 'K', 'L');

	checking("#010X");
        printf("%#010X\n", 700);
        ft_printf("%#010X\n", 700);

	checking("#010o");
	printf("%#010o more numbers %-5o\n", 345, 500);
	ft_printf("%#010o more numbers %-5o\n", 345, 500);
	printf("\n");

	CHECK("%s %d\n", "test", 42);
	CHECK("%10s more testing %+010d\n", "another", 700);
	return(0);
}
