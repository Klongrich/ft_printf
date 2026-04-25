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

	/*
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

	*/
	//Checking hh formating

	//No warnings given
	//8-bit singed character value values 127 to -128
	//checking single left align, right align, +, and 0
	printf("\n----------- CHECKING d --------------\n");

	printf("checking normal value\n");
	CHECK("%d\n", 12);
	printf("checking passing value of 123456\n");
	CHECK("%d\n", 123456);

	/*
	Values give warning to us %ld, despite undefined behvaior of such, all test do pass
	printf("Checking min and max value (-2147483648, 2147483647)");
	CHECK("min: %d - max: %d\n", -2147483648, 2147483647); 

	printf("Checking one under min, one over max hhd (-2147483649, 2147483648)\n");
	CHECK("%hhd - %d\n", -2147483649, 2147483648);
	
	printf("Checking values well under and well over max (-21147483648, 2222147483648)\n");
	CHECK("%d -  %d\n", -21147483648, 2222147483648);
	*/

	printf("checking 0\n");
	CHECK("%d\n", 0);

	printf("Checking + with (0)\n");
	CHECK("%+d\n", 0);
	
	printf("checking right padding d\n");
	CHECK("%10d - % 10d - %7d - %5d\n", 654, 389237, 49848, 0);
	printf("checking left padding d\n");
	CHECK("%-d, %-7d, %-5d - %-3d -\n", 674, 784, 900, 900);
	printf("checking 0 d\n");
	CHECK("%08d - %00d - %01d - %023d\n", 784, 837, 9485, 48);
	printf("checking + d\n");
	CHECK("%+hhd - %+hhd - %+hhd\n", 784, 837, 674);
	
	//0 with right align, left align, and +;
	printf("checking right padding w/ 0 d\n");
	CHECK("%02d - %010d - %05d %04d\n", 758, 859, 950, 758);
	printf("checking + with / 0 hhd\n");
	CHECK("%+07hhd - %+04hhd - %+01hhd %+010hhd\n", 37834, 2343, 48749, 7849);

	//+ with right align;
	printf("checking + with right padding\n");
	CHECK("%+8d - %+2d - %+10d - %+5d\n", 728, 928, 839, 0);

	//+ with left align;
	printf("checking + with left padding\n");
	CHECK("%+-8d - %+-2d - %+-10d - %+-8d - %+-4d -\n", 128, 3992, 94849, 23904, 0);

	printf("\n--------- END CHECKING hhd ------------\n");

	printf("\n----------- CHECKING hhd --------------\n");

	printf("checking normal value\n");
	CHECK("%hhd\n", 12);
	printf("checking passing value of 123456\n");
	CHECK("%hhd\n", 123456);

	printf("Checking min and max value (-128, 127)");
	CHECK("min: %hhd - max: %hhd\n", -128, 127); 

	printf("Checking one under min, one over max hhd (-129, 128)\n");
	CHECK("%hhd - %hhd\n", -129, 128);
	
	printf("Checking values well under and well over max (-12500, 34560)\n");
	CHECK("%hhd - %hhd\n", -12500, 34560);

	printf("checking 0\n");
	CHECK("%hhd\n", 0);

	printf("Checking + with (0)\n");
	CHECK("%+hhd\n", 0);
	
	printf("checking right padding hhd\n");
	CHECK("%10hhd - % 10hhd - %7hhd - %5hhd\n", 654, 389237, 49848, 0);
	printf("checking left padding hhd\n");
	CHECK("%-hhd, %-7hhd, %-5hhd - %-3hhd -\n", 674, 784, 900, 900);
	printf("checking 0 hhd\n");
	CHECK("%08hhd - %00hhd - %01hhd - %023hhd\n", 784, 837, 9485, 48);
	printf("checking + hhd\n");
	CHECK("%+hhd - %+hhd - %+hhd\n", 784, 837, 674);
	
	//0 with right align, left align, and +;
	printf("checking right padding w/ 0 hhd\n");
	CHECK("%02hhd - %010hhd - %05hhd %04hhd\n", 758, 859, 950, 758);
	printf("checking + with / 0 hhd\n");
	CHECK("%+07hhd - %+04hhd - %+01hhd %+010hhd\n", 37834, 2343, 48749, 7849);

	//+ with right align;
	printf("checking + with right padding\n");
	CHECK("%+8hhd - %+2hhd - %+10hhd - %+5hhd\n", 728, 928, 839, 0);

	//+ with left align;
	printf("checking + with left padding\n");
	CHECK("%+-8hhd - %+-2hhd - %+-10hhd - %+-8hhd - %+-4hhd -\n", 128, 3992, 94849, 23904, 0);

	printf("\n--------- END CHECKING hhd ------------\n");

	printf("\n----------- CHECKING hhi --------------\n");

	printf("checking normal value\n");
	CHECK("%hhi\n", 12);
	printf("checking passing value of 123456\n");
	CHECK("%hhi\n", 123456);

	printf("Checking min and max value (-128, 127)");
	CHECK("min: %hhi - max: %hhi\n", -128, 127); 

	printf("Checking one under min, one over max hhd (-129, 128)\n");
	CHECK("%hhi - %hhi\n", -129, 128);
	
	printf("Checking values well under and well over max (-12500, 34560)\n");
	CHECK("%hhi - %hhi\n", -12500, 34560);

	printf("checking 0\n");
	CHECK("%hhi\n", 0);

	printf("Checking + with (0)\n");
	CHECK("%+hhi\n", 0);
	
	printf("checking right padding hhi\n");
	CHECK("%10hhi - % 10hhi - %7hhi - %5hhi\n", 654, 389237, 49848, 0);
	printf("checking left padding hhi\n");
	CHECK("%-hhi, %-7hhi, %-5hhi - %-3hhi -\n", 674, 784, 900, 900);
	printf("checking 0 hhi\n");
	CHECK("%08hhi - %00hhi - %01hhi - %023hhi\n", 784, 837, 9485, 48);
	printf("checking + hhi\n");
	CHECK("%+hhi - %+hhi - %+hhi\n", 784, 837, 674);
	
	//0 with right align, left align, and +;
	printf("checking right padding w/ 0 hhi\n");
	CHECK("%02hhi - %010hhi - %05hhi %04hhi\n", 758, 859, 950, 758);
	printf("checking + with / 0 hhi\n");
	CHECK("%+07hhi - %+04hhi - %+01hhd %+010hhi\n", 37834, 2343, 48749, 7849);

	//+ with right align;
	printf("checking + with right padding\n");
	CHECK("%+8hhi - %+2hhi - %+10hhi - %+5hhi\n", 728, 928, 839, 0);

	//+ with left align;
	printf("checking + with left padding\n");
	CHECK("%+-8hhi - %+-2hhi - %+-10hhi - %+-8hhi - %+-4hhi -\n", 128, 3992, 94849, 23904, 0);

	printf("\n--------- END CHECKING hhi ------------\n");

	//with hext check 0c 40
	printf("\n----------- CHECKING hhx --------------\n");

	printf("checking normal value\n");
	CHECK("%hhx\n", 12);
	printf("checking passing value of 123456\n");
	CHECK("%hhx\n", 123456);

	printf("Checking min and max value (-128, 127)");
	CHECK("min: %hhx - max: %hhx\n", -128, 127); 

	printf("Checking one under min, one over max hhd (-129, 128)\n");
	CHECK("%hhx - %hhx\n", -129, 128);
	
	printf("Checking values well under and well over max (-12500, 34560)\n");
	CHECK("%hhx - %hhx\n", -12500, 34560);

	printf("checking 0\n");
	CHECK("%hhx\n", 0);

	printf("Checking # with (0)\n");
	CHECK("%#hhx\n", 0);

	printf("Checking hex value with hhx\n");
	CHECK("%hhx\n", 0xa0);
	
	printf("checking right padding hhx\n");
	CHECK("%10hhx - %10hhx - %7hhx - %5hhx\n", 654, 389237, 49848, 0);
	printf("checking left padding hhx\n");
	CHECK("%-hhx, %-7hhx, %-5hhx - %-3hhx -\n", 674, 784, 900, 900);
	printf("checking 0 hhx\n");
	CHECK("%08hhx - %00hhx - %01hhx - %023hhx\n", 784, 837, 9485, 48);
	
	printf("checking right padding w/ 0 hhx\n");
	CHECK("%02hhx - %010hhx - %05hhx - %04hhx\n", 758, 859, 950, 758);

	printf("checking right padding w/ # hhx\n");
	CHECK("%#10hhx - %#7hhx - %#6hhx - %#5hhx -\n", 474, 238, 0, 9485);

	printf("checking left padding w/ # hhx\n");
	CHECK("%-#5hhx - %-#hhx - %-#12hhx - %-#5hhx\n", 4848, 754, 0, 948);
	printf("\n--------- END CHECKING hhx ------------\n");

	printf("\n----------- CHECKING hx --------------\n");

	printf("checking normal value\n");
	CHECK("%hx\n", 12);
	printf("checking passing value of 123456\n");
	CHECK("%hx\n", 123456);

	printf("Checking min and max value (-128, 127)");
	CHECK("min: %hx - max: %hx\n", -128, 127); 

	printf("Checking one under min, one over max hhd (-129, 128)\n");
	CHECK("%hx - %hx\n", -129, 128);
	
	printf("Checking values well under and well over max (-12500, 34560)\n");
	CHECK("%hx - %hx\n", -12500, 34560);

	printf("checking 0\n");
	CHECK("%hx\n", 0);

	printf("Checking # with (0)\n");
	CHECK("%#hx\n", 0);

	printf("Checking hex value with hx\n");
	CHECK("%hx\n", 0xa0);
	
	printf("checking right padding hx\n");
	CHECK("%10hx - %10hx - %7hx - %5hx\n", 654, 389237, 49848, 0);
	printf("checking left padding hx\n");
	CHECK("%-hx, %-7hx, %-5hx - %-3hx -\n", 674, 784, 900, 900);
	printf("checking 0 hx\n");
	CHECK("%08hx - %00hx - %01hx - %023hx\n", 784, 837, 9485, 48);
	
	printf("checking right padding w/ 0 hx\n");
	CHECK("%02hx - %010hx - %05hx - %04hx\n", 758, 859, 950, 758);

	printf("checking right padding w/ # hx\n");
	CHECK("%#10hx - %#7hx - %#6hx - %#5hx -\n", 474, 238, 0, 9485);

	printf("checking left padding w/ # hx\n");
	CHECK("%-#5hx - %-#hx - %-#12hx - %-#5hx\n", 4848, 754, 0, 948);
	printf("\n--------- END CHECKING hhx ------------\n");

	printf("checking hx\n");
	CHECK("%hx - %hx - %hx - %hx\n", 0xffaa, 0x0faa, 0x00aa, 0x000a);
	
	printf ("checking x\n");
	CHECK("%x - %x - %x - %x - %x\n", 0xfabcf, 0x0fbca, 0x00bbf, 0x000fa, 0x0000b);

	printf("\n----------- CHECKING x --------------\n");

	printf("checking normal value\n");
	CHECK("%x\n", 12);
	printf("checking passing value of 123456\n");
	CHECK("%x\n", 123456);

	printf("Checking min and max value (-128, 127)");
	CHECK("min: %x - max: %x\n", -128, 127); 

	printf("Checking one under min, one over max hhd (-129, 128)\n");
	CHECK("%x - %x\n", -129, 128);
	
	printf("Checking values well under and well over max (-12500, 34560)\n");
	CHECK("%x - %x\n", -12500, 34560);

	printf("checking 0\n");
	CHECK("%x\n", 0);

	printf("Checking # with (0)\n");
	CHECK("%#x\n", 0);

	printf("Checking hex value with x\n");
	CHECK("%x\n", 0xa0);
	
	printf("checking right padding x\n");
	CHECK("%10x - %10x - %7x - %5x\n", 654, 389237, 49848, 0);
	printf("checking left padding x\n");
	CHECK("%-x, %-7x, %-5x - %-3x -\n", 674, 784, 900, 900);
	printf("checking 0 x\n");
	CHECK("%08x - %00x - %01x - %023x\n", 784, 837, 9485, 48);
	
	printf("checking right padding w/ 0 x\n");
	CHECK("%02x - %010x - %05x - %04x\n", 758, 859, 950, 758);

	printf("checking right padding w/ # x\n");
	CHECK("%#10x - %#7x - %#6x - %#5x -\n", 474, 238, 0, 9485);

	printf("checking left padding w/ # x\n");
	CHECK("%-#5x - %-#x - %-#12x - %-#5x\n", 4848, 754, 0, 948);
	printf("\n--------- END CHECKING x ------------\n");
	
	long long check;

	check = 18446744073709551615;


	ft_putchar('\n');
	ft_putnbr((signed char)check);
	ft_putchar('\n');
	ft_putnbr((unsigned char)check);
	ft_putchar('\n');	
	ft_putnbr((signed short)check);
	ft_putchar('\n');
	ft_putnbr((unsigned short)check);
	ft_putchar('\n');
	ft_putnbr((signed int)check);
	ft_putchar('\n');
	ft_putnbr((unsigned int)check);
	ft_putchar('\n');	
	ft_putnbr((signed long)check);

	ft_putchar('\n');
	ft_putchar('\n');
	
	ft_putnumber((signed char)check, 10);
	ft_putchar('\n');
	ft_putnumber((unsigned char)check, 10);
	ft_putchar('\n');
	ft_putnumber((unsigned char)check, 8);
	ft_putchar('\n');
	ft_putnumber((unsigned char)check, 16);	

	ft_putchar('\n');
	ft_putchar('\n');
	
	ft_putnumber((signed short)check, 10);
	ft_putchar('\n');
	ft_putnumber((unsigned short)check, 10);
	ft_putchar('\n');
	ft_putnumber((unsigned short)check, 8);
	ft_putchar('\n');
	ft_putnumber((unsigned short)check, 16);	
	
	ft_putchar('\n');
	ft_putchar('\n');
	
	ft_putnumber((signed int)check, 10);
	ft_putchar('\n');
	ft_putnumber((unsigned int)check, 10);
	ft_putchar('\n');
	ft_putnumber((unsigned int)check, 8);
	ft_putchar('\n');
	ft_putnumber((unsigned int)check, 16);	

	ft_putchar('\n');
	ft_putchar('\n');
	
	ft_putnumber((signed long long)check, 10);
	ft_putchar('\n');
	ft_putnumber_ull((unsigned long long)check, 10);
	ft_putchar('\n');
	ft_putnumber_ull((unsigned long long)check, 8);
	ft_putchar('\n');
	ft_putnumber_ull((unsigned long long)check, 16);	

	ft_putchar('\n');
	ft_putchar('\n');
	CHECK("\n %hhd - %hhx - %hho - %hu - %d -  %u - %ld\n", check, check, check, check, check, check, check, check);
	
	//0
	//0+

	//left
	//left +
	
	//right
	//right +

	//0, +, left, right, (# doesn't affect d)

	//Layout of all test
	//Base testing
	//Check min value / max value/ 0 / normal values / values well under min / values well over min.
	//0, #, -, +,  , 
	//c, s, p, o, x, X, d, i, u, f
	//hho, hhx, hhX, hhd, hhi, hhu
	//ho, hx, hX, hd, hi, hu
	//lo, lx, lX, ld, li, lu, lf
	//llo, llx, llX, lld, lli, llu,
	//Lf

	//combined paramter testing (0, -, +, , #);
	//0o, 0x, 0x, 0X, 0d, 0i, 0u, 0f
	//#0x, #0X, #0f
	//0 o, 0 x, 0 X, 0 d, 0 i, 0 u, 0 f
	//#0 x, #0 X, #0 f
	//+0o, +0x, +0X, +0d, +0i, +0u, +0f
	//+#0x, +#0X, +#0f
	//+0 o, +0 x, +0 X, +0 d, +0 i, +0 u, +0 f;
	//+#0 x, +#0 X, +0# f

	//Add # acccount for adding strings	
	//0hho, 0hhx, 0hhx, 0hhX, 0hhd, 0hhi, 0hh
        //0 hho, 0 hhx, 0 hhX, 0 hhd, 0 hhi, 0 hhu
        //+0hho, +0hhx, +0hhX, +0hhd, +0hhi, +0hhu
        //+0 hho, +0 hhx, +0 hhX, +0 hhd, +0 hhi, +0 hhu


	//Any testing paramters that cause a compiler warning are not accounted for.
	//Instead it is going to default to undefined behavoir. 

	//Figure out how to breakn down testing into subsections with automated tester. 
	//Use shell scripting with pipng outputs for automatic checks. 

	

	/*
	CHECK("%s %d\n", "test", 42);
	CHECK("%10s more testing %+010d\n", "another", 700);
	CHECK("%010hhu - %+-5hhd - %10hhi\n", 2345, 484, 8948);
 	CHECK("%010d - %+-5d - %10d\n", 2345, 484, 8948);
	CHECK("%#010hhx - %-#7hhx - %#+5hhx - %0-#5hhx\n", 1290, 388, 475, 838);
	CHECK("%#-10hhx - %-#7hhx %#+10hhx - %10hhx \n", 8490, 892, 0, 0);
	CHECK("%-#8hhx - %--+##hhx\n", 0, 0);
	
	CHECK("%010o - %o - %-+7o - %+12o\n", 155, 2376, 293, 2839);
	
	CHECK("%010hho - %hho - %7hho - %+-12hho -\n", 155, 2376, 293, 2839);
	CHECK("%010hho - %-09hho - %-7hho - %+-12hho -\n", 15345, 234376, 29343, 2839);
	CHECK("%010hho - %09hho - %7hho - %+12hho -\n", 15345, 234376, 29343, 2839);
	
	CHECK("%010hd - %+07hd - %#-2hd - %10hd\n", 7484, 8493, 92833, 95809);
	
	CHECK("%010hx - %+07hx - %#-2hx - %10hx\n", 7484, 8493, 92833, 95809);
	CHECK("%010hX - %+07hX - %#-2hX - %10hX\n", 7484, 8493, 92833, 95809);
	
	CHECK("%07lld - %+04lld - %-5lld\n", 9837523809280433355ULL, 748474, 92893);
	
	CHECK("%07llo - %+04llo - %-5llo\n", 9837523809280433355ULL, 748474, 92893); 
	

	CHECK("%20p - %-25p -\n", &num, &c);
	CHECK("%Lf\n", 40858.49494949494L);
	CHECK("%f\n", 434.23);
	CHECK("%Lf\n", 76855568958559.868595L);
	*/
	return(0);
}
