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
	printf("\n----------- CHECKING c --------------\n");

	printf("checking normal value\n");
	CHECK("%c\n", 'c');

	printf("checking 0\n");
	CHECK("%c\n", 0);

	printf("checking right padding\n");
	CHECK("%10c - %7c - %3c - %7c\n", 'k', 0, 'l', 'z');

	printf("checking left padding\n");
	CHECK("%-8c - %-4c - %-4c -  %-3c\n", 'y', 'u', 0, 'p');
	printf("\n--------- END CHECKING c ------------\n");	

	printf("\n----------- CHECKING s --------------\n");

	printf("checking normal value\n");
	CHECK("%s\n", "checking");

	printf("checking NULL\n");
	CHECK("%s\n", NULL);

	printf("checking right padding\n");
	CHECK("%10s - %7s - %3s - %7s\n", "testing", NULL, "words", "Kalsdkj");

	printf("checking left padding\n");
	CHECK("%-8s - %-4s - %-4s -  %-3s\n", "asldfj", "words", NULL, "more words");
	CHECK("empty: %s\n", "");
	//undefined behavoir
	//CHECK("%0s\n", "hello");
	CHECK("%2s\n", "hello");
	CHECK("%10s\n", NULL);
	CHECK("%-10s\n", NULL);


	printf("\n--------- END CHECKING s ------------\n");

	printf("\n----------- CHECKING d --------------\n");

	printf("checking normal value\n");
	CHECK("%d\n", 12);
	printf("checking passing value of 123456\n");
	CHECK("%d\n", 123456);

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
	CHECK("%+d - %+d - %+d\n", 784, 837, 674);
	
	//0 with right align, left align, and +;
	printf("checking right padding w/ 0 d\n");
	CHECK("%02d - %010d - %05d %04d\n", 758, 859, 950, 758);
	printf("checking + with / 0 d\n");
	CHECK("%+07d - %+04d - %+01d %+010d\n", 37834, 2343, 48749, 7849);

	//+ with right align;
	printf("checking + with right padding\n");
	CHECK("%+8d - %+2d - %+10d - %+5d\n", 728, 928, 839, 0);

	//+ with left align;
	printf("checking + with left padding\n");
	CHECK("%+-8d - %+-2d - %+-10d - %+-8d - %+-4d -\n", 128, 3992, 94849, 23904, 0);

	printf("checking negative values with flags\n");
	CHECK("%05d\n", -42);
	CHECK("%+d\n", -42);
	CHECK("% d\n", 42);
	CHECK("% d\n", -42);

	printf("checking flag conflicts\n");
	CHECK("%-05d\n", 42);  // '-' wins over '0'
	CHECK("%+ d\n", 42);   // '+' wins over ' '

	printf("checking limits\n");
	CHECK("%d\n", -2147483648);
	CHECK("%015d\n", -2147483648);
	printf("\n--------- END CHECKING d ------------\n");

	printf("\n----------- CHECKING i --------------\n");

	printf("checking normal value\n");
	CHECK("%i\n", 12);
	printf("checking passing value of 123456\n");
	CHECK("%i\n", 123456);

	printf("checking 0\n");
	CHECK("%i\n", 0);

	printf("Checking + with (0)\n");
	CHECK("%+i\n", 0);
	
	printf("checking right padding i\n");
	CHECK("%10i - % 10i - %7i - %5i\n", 654, 389237, 49848, 0);
	printf("checking left padding i\n");
	CHECK("%-i, %-7i, %-5i - %-3i -\n", 674, 784, 900, 900);
	printf("checking 0 i\n");
	CHECK("%08i - %00i - %01i - %023i\n", 784, 837, 9485, 48);
	printf("checking + i\n");
	CHECK("%+i - %+i - %+i\n", 784, 837, 674);
	
	//0 with right align, left align, and +;
	printf("checking right padding w/ 0 i\n");
	CHECK("%02i - %010i - %05i %04i\n", 758, 859, 950, 758);
	printf("checking + with / 0 i\n");
	CHECK("%+07i - %+04i - %+01i %+010i\n", 37834, 2343, 48749, 7849);

	//+ with right align;
	printf("checking + with right padding\n");
	CHECK("%+8i - %+2i - %+10i - %+5i\n", 728, 928, 839, 0);

	//+ with left align;
	printf("checking + with left padding\n");
	CHECK("%+-8i - %+-2i - %+-10i - %+-8i - %+-4i -\n", 128, 3992, 94849, 23904, 0);

	printf("checking negative values with flags\n");
	CHECK("%05i\n", -42);
	CHECK("%+i\n", -42);
	CHECK("% i\n", 42);
	CHECK("% i\n", -42);

	printf("checking flag conflicts\n");
	CHECK("%-0id\n", 42);  // '-' wins over '0'
	CHECK("%+ i\n", 42);   // '+' wins over ' '

	printf("checking limits\n");
	CHECK("%i\n", -2147483648);
	CHECK("%015i\n", -2147483648);
	printf("\n--------- END CHECKING i ------------\n");

	printf("\n----------- CHECKING p --------------\n");
	
	printf("checking normal pointer passed\n");
	CHECK("%p\n", &num);

	printf("checking character pointer\n");
	CHECK("%p\n", &c);

	printf("checking right padding on p\n");
	CHECK("%20p - %25p -\n", &num, &c);

	printf("checking left padding on p\n");
	CHECK("%-20p - %-25p -\n", &c, &num);

	printf("\n--------- END CHECKING p ------------\n");

	printf("\n----------- CHECKING u --------------\n");

	printf("checking normal value\n");
	CHECK("%u\n", 12);
	printf("checking passing value of 123456\n");
	CHECK("%u\n", 123456);

	printf("checking 0\n");
	CHECK("%u\n", 0);

	printf("Checking + with (0)\n");
	CHECK("%+u\n", 0);
	
	printf("checking right padding u\n");
	CHECK("%10u - % 10u - %7u - %5u\n", 654, 389237, 49848, 0);
	printf("checking left padding u\n");
	CHECK("%-u, %-7u, %-5u - %-3u -\n", 674, 784, 900, 900);
	printf("checking 0 u\n");
	CHECK("%08u - %00u - %01u - %023u\n", 784, 837, 9485, 48);
	printf("checking + u\n");
	CHECK("%+u - %+u - %+u\n", 784, 837, 674);
	
	//0 with right align, left align, and +;
	printf("checking right padding w/ 0 u\n");
	CHECK("%02u - %010u - %05u %04u\n", 758, 859, 950, 758);
	printf("checking + with / 0 u\n");
	CHECK("%+07u - %+04u - %+01u %+010u\n", 37834, 2343, 48749, 7849);

	//+ with right align;
	printf("checking + with right padding\n");
	CHECK("%+8u - %+2u - %+10u - %+5u\n", 728, 928, 839, 0);

	//+ with left align;
	printf("checking + with left padding\n");
	CHECK("%+-8u - %+-2u - %+-10u - %+-8u - %+-4u -\n", 128, 3992, 94849, 23904, 0);

	printf("checking negative values with flags\n");
	CHECK("%05u\n", -42);
	CHECK("%+u\n", -42);
	CHECK("% u\n", 42);
	CHECK("% u\n", -42);

	printf("checking flag conflicts\n");
	CHECK("%-05u\n", 42);  // '-' wins over '0'
	CHECK("%+ u\n", 42);   // '+' wins over ' '

	printf("checking limits\n");
	CHECK("%u\n", 4294967295);
	CHECK("%015u\n",  4294967295);
	printf("\n--------- END CHECKING u ------------\n");

	printf("\n----------- CHECKING x --------------\n");

	printf("checking normal value\n");
	CHECK("%x\n", 12);
	printf("checking passing value of 123456\n");
	CHECK("%x\n", 123456);

	printf("checking 0\n");
	CHECK("%x\n", 0);

	printf("Checking + with (0)\n");
	CHECK("%+x\n", 0);
	
	printf("checking right padding x\n");
	CHECK("%10x - % 10x - %7x - %5x\n", 654, 389237, 49848, 0);
	printf("checking left padding x\n");
	CHECK("%-x, %-7x, %-5x - %-3x -\n", 674, 784, 900, 900);
	printf("checking 0 x\n");
	CHECK("%08x - %00x - %01x - %023x\n", 784, 837, 9485, 48);
	printf("checking + x\n");
	CHECK("%+x - %+x - %+x\n", 784, 837, 674);
	
	//0 with right align, left align, and +;
	printf("checking right padding w/ 0 x\n");
	CHECK("%02x - %010x - %05x %04x\n", 758, 859, 950, 758);
	printf("checking + with / 0 x\n");
	CHECK("%+07x - %+04x - %+01x %+010x\n", 37834, 2343, 48749, 7849);

	//+ with right align;
	printf("checking + with right padding\n");
	CHECK("%+8x - %+2x - %+10x - %+5x - %+7x\n", 728, 928, 94849, 0, 8743);

	//+ with left align;
	printf("checking + with left padding\n");
	CHECK("%+-8x - %+-2x - %+-10x - %+-8x - %+-4x -\n", 728, 928, 94849, 0, 0);

	printf("checking negative values with flags\n");
	CHECK("%05x\n", -42);
	CHECK("%+x\n", -42);
	CHECK("% x\n", 42);
	CHECK("% x\n", -42);

	printf("checking flag conflicts\n");
	CHECK("%-05x\n", 42);  // '-' wins over '0'
	CHECK("%+ u\n", 42);   // '+' wins over ' '

	printf("checking limits\n");
	CHECK("%x\n", 4294967295);
	CHECK("%015x\n",  4294967295);

	printf("checking # with x\n");
	CHECK("%#x - %#x - %#x\n", 84, 485, 23840);
	
	printf("checking # with 0 value for x\n");
	CHECK("%#x\n", 0);
	
	printf("checking # with left padding x\n");
	CHECK("%-#10x - %-#7x - %-#6x - %-#8x -\n", 948, 74758, 23849, 0);

	printf("checking # with right padding x\n");
	CHECK("%#8x - %#12x - %#7x - %#12x\n", 3849, 345, 985, 84830);

	printf("chcking # w/ 0 and x\n");
	CHECK("%#015x - %#07x - %#05x - %#010x -\n", 4294967295, 947, 75, 0);

	printf("\n--------- END CHECKING x ------------\n");

	printf("\n----------- CHECKING X --------------\n");

	printf("checking normal value\n");
	CHECK("%X\n", 12);
	printf("checking passing value of 123456\n");
	CHECK("%X\n", 123456);

	printf("checking 0\n");
	CHECK("%X\n", 0);

	printf("Checking + with (0)\n");
	CHECK("%+X\n", 0);
	
	printf("checking right padding X\n");
	CHECK("%10X - % 10X - %7X - %5X\n", 654, 389237, 49848, 0);
	printf("checking left padding X\n");
	CHECK("%-X, %-7X, %-5X - %-3X -\n", 674, 784, 900, 900);
	printf("checking 0 X\n");
	CHECK("%08X - %00X - %01X - %023X\n", 784, 837, 9485, 48);
	printf("checking + X\n");
	CHECK("%+X - %+X - %+X\n", 784, 837, 674);
	
	//0 with right align, left align, and +;
	printf("checking right padding w/ 0 X\n");
	CHECK("%02X - %010X - %05X %04X\n", 758, 859, 950, 758);
	printf("checking + with / 0 X\n");
	CHECK("%+07X - %+04X - %+01X %+010X\n", 37834, 2343, 48749, 7849);

	//+ with right align;
	printf("checking + with right padding\n");
	CHECK("%+8X - %+2X - %+10X - %+5X - %+7X\n", 728, 928, 94849, 0, 8743);

	//+ with left align;
	printf("checking + with left padding\n");
	CHECK("%+-8X - %+-2X - %+-10X - %+-8X - %+-4X -\n", 728, 928, 94849, 0, 0);

	printf("checking negative values with flags\n");
	CHECK("%05X\n", -42);
	CHECK("%+X\n", -42);
	CHECK("% X\n", 42);
	CHECK("% X\n", -42);

	printf("checking flag conflicts\n");
	CHECK("%-05X\n", 42);  // '-' wins over '0'
	CHECK("%+ X\n", 42);   // '+' wins over ' '

	printf("checking limits\n");
	CHECK("%X\n", 4294967295);
	CHECK("%015X\n",  4294967295);

	printf("checking # with X\n");
	CHECK("%#X - %#X - %#X\n", 84, 485, 23840);
	
	printf("checking # with 0 value for X\n");
	CHECK("%#X\n", 0);
	
	printf("checking # with left padding X\n");
	CHECK("%-#10X - %-#7X - %-#6X - %-#8X -\n", 948, 74758, 23849, 0);

	printf("checking # with right padding X\n");
	CHECK("%#8X - %#12X - %#7X - %#12X\n", 3849, 345, 985, 84830);

	printf("chcking # w/ 0 and X\n");
	CHECK("%#015X - %#07X - %#05X - %#010X -\n", 4294967295, 947, 75, 0);

	printf("\n--------- END CHECKING X ------------\n");

	printf("\n----------- CHECKING o --------------\n");

	printf("checking normal value\n");
	CHECK("%o\n", 12);
	printf("checking passing value of 123456\n");
	CHECK("%o\n", 123456);

	printf("checking 0\n");
	CHECK("%o\n", 0);

	printf("Checking + with (0)\n");
	CHECK("%+o\n", 0);
	
	printf("checking right padding o\n");
	CHECK("%10o - % 10o - %7o - %5o\n", 654, 389237, 49848, 0);
	printf("checking left padding o\n");
	CHECK("%-o, %-7o, %-5o - %-3o -\n", 674, 784, 900, 900);
	printf("checking 0 o\n");
	CHECK("%08o - %00o - %01o - %023o\n", 784, 837, 9485, 48);
	printf("checking + o\n");
	CHECK("%+o - %+o - %+o\n", 784, 837, 674);
	
	//0 with right align, left align, and +;
	printf("checking right padding w/ 0 o\n");
	CHECK("%02o - %010o - %05o %04o\n", 758, 859, 950, 758);
	printf("checking + with / 0 o\n");
	CHECK("%+07o - %+04o - %+01o %+010o\n", 37834, 2343, 48749, 7849);

	//+ with right align;
	printf("checking + with right padding\n");
	CHECK("%+8o - %+2o - %+10o - %+5o\n", 728, 928, 839, 0);

	//+ with left align;
	printf("checking + with left padding\n");
	CHECK("%+-8o - %+-2o - %+-10o - %+-8o - %+-4o -\n", 128, 3992, 94849, 23904, 0);

	printf("checking negative values with flags\n");
	CHECK("%05o\n", -42);
	CHECK("%+o\n", -42);
	CHECK("% o\n", 42);
	CHECK("% o\n", -42);

	printf("checking flag conflicts\n");
	CHECK("%-05o\n", 42);  // '-' wins over '0'
	CHECK("%+ o\n", 42);   // '+' wins over ' '

	printf("checking limits\n");
	CHECK("%o\n", 4294967295);
	CHECK("%015o\n",  4294967295);
	printf("\n--------- END CHECKING o ------------\n");
	
	printf("\n----------- CHECKING f --------------\n");

	printf("checking normal value\n");
	CHECK("%f\n", 12.5);
	printf("checking passing value of 123456\n");
	CHECK("%f\n", 123456);

	printf("checking 0\n");
	CHECK("%f\n", 0);

	printf("Checking + with (0)\n");
	CHECK("%+f\n", 0);
	
	printf("checking right padding f\n");
	CHECK("%10f - % 10f - %7f - %5f\n", 654, 389237, 49848, 0);
	printf("checking left padding f\n");
	CHECK("%-f, %-7f, %-5f - %-3f -\n", 674, 784, 900, 900);
	printf("checking 0 f\n");
	CHECK("%08f - %00f - %01f - %023f\n", 784, 837, 9485, 48);
	printf("checking + f\n");
	CHECK("%+f - %+f - %+f\n", 784, 837, 674);
	
	//0 with right align, left align, and +;
	printf("checking right padding w/ 0 f\n");
	CHECK("%02f - %010f - %05f %04f\n", 758, 859, 950, 758);
	printf("checking + with / 0 f\n");
	CHECK("%+07f - %+04f - %+01f %+010f\n", 37834, 2343, 48749, 7849);

	//+ with right align;
	printf("checking + with right padding\n");
	CHECK("%+8f - %+2f - %+10f - %+5f - %+7f\n", 728, 928, 94849, 0, 8743);

	//+ with left align;
	printf("checking + with left padding\n");
	CHECK("%+-8f - %+-2f - %+-10f - %+-8f - %+-4f -\n", 728, 928, 94849, 0, 0);

	printf("checking negative values with flags\n");
	CHECK("%05f\n", -42);
	CHECK("%+f\n", -42);
	CHECK("% f\n", 42);
	CHECK("% f\n", -42);

	printf("checking flag conflicts\n");
	CHECK("%-05f\n", 42);  // '-' wins over '0'
	CHECK("%+ f\n", 42);   // '+' wins over ' '

	printf("checking limits\n");
	CHECK("%f\n", 4294967295);
	CHECK("%015f\n",  4294967295);

	printf("checking # with f\n");
	CHECK("%#f - %#f - %#f\n", 84, 485, 23840);
	
	printf("checking # with 0 value for f\n");
	CHECK("%#f\n", 0);
	
	printf("checking # with left padding f\n");
	CHECK("%-#10f - %-#7f - %-#6f - %-#8f -\n", 948, 74758, 23849, 0);

	printf("checking # with right padding f\n");
	CHECK("%#8f - %#12f - %#7f - %#12f\n", 3849, 345, 985, 84830);

	printf("chcking # w/ 0 and f\n");
	CHECK("%#015f - %#07f - %#05f - %#010f -\n", 4294967295, 947, 75, 0);

	printf("\n--------- END CHECKING f ------------\n");

	printf("\n----------- CHECKING hhu --------------\n");

	printf("checking normal value\n");
	CHECK("%hhu\n", 12);
	printf("checking passing value of 123456\n");
	CHECK("%hhu\n", 123456);

	printf("checking 0\n");
	CHECK("%hhu\n", 0);

	printf("Checking + with (0)\n");
	CHECK("%+hhu\n", 0);
	
	printf("checking right padding hhu\n");
	CHECK("%10hhu - % 10hhu - %7hhu - %5hhu\n", 654, 389237, 49848, 0);
	printf("checking left padding hhu\n");
	CHECK("%-hhu, %-7hhu, %-5hhu - %-3hhu -\n", 674, 784, 900, 900);
	printf("checking 0 hhu\n");
	CHECK("%08hhu - %00hhu - %01hhu - %023hhu\n", 784, 837, 9485, 48);
	printf("checking + hhu\n");
	CHECK("%+hhu - %+hhu - %+hhu\n", 784, 837, 674);
	
	//0 with right align, left align, and +;
	printf("checking right padding w/ 0 hhu\n");
	CHECK("%02hhu - %010hhu - %05hhu %04hhu\n", 758, 859, 950, 758);
	printf("checking + with / 0 u\n");
	CHECK("%+07hhu - %+04hhu - %+01hhu %+010hhu\n", 37834, 2343, 48749, 7849);

	//+ with right align;
	printf("checking + with right padding\n");
	CHECK("%+8hhu - %+2hhu - %+10hhu - %+5hhu\n", 728, 928, 839, 0);

	//+ with left align;
	printf("checking + with left padding\n");
	CHECK("%+-8hhu - %+-2hhu - %+-10hhu - %+-8hhu - %+-4hhu -\n", 128, 3992, 94849, 23904, 0);

	printf("checking negative values with flags\n");
	CHECK("%05hhu\n", -42);
	CHECK("%+hhu\n", -42);
	CHECK("% hhu\n", 42);
	CHECK("% hhu\n", -42);

	printf("checking flag conflicts\n");
	CHECK("%-05hhu\n", 42);  // '-' wins over '0'
	CHECK("%+ hhu\n", 42);   // '+' wins over ' '

	printf("checking limits\n");
	CHECK("%hhu\n", 4294967295);
	CHECK("%015hhu\n",  4294967295);
	printf("\n--------- END CHECKING hhu ------------\n");

	
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

	printf("checking negative values with flags\n");
	CHECK("%05hhd\n", -42);
	CHECK("%+hhd\n", -42);
	CHECK("% hhd\n", 42);
	CHECK("% hhd\n", -42);

	printf("checking flag conflicts\n");
	CHECK("%-05hhd\n", 42);  // '-' wins over '0'
	CHECK("%+ hhd\n", 42);   // '+' wins over ' '

	printf("checking limits\n");
	CHECK("% hhd\n", 0);
	CHECK("%hhd\n", -2147483648);
	CHECK("%015hhd\n", -2147483648);
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

	printf("checking negative values with flags\n");
	CHECK("%05hhi\n", -42);
	CHECK("%+hhi\n", -42);
	CHECK("% hhi\n", 42);
	CHECK("% hhi\n", -42);

	printf("checking flag conflicts\n");
	CHECK("%-05hhi\n", 42);  // '-' wins over '0'
	CHECK("%+ hhi\n", 42);   // '+' wins over ' '

	printf("checking limits\n");
	CHECK("%hhi\n", -2147483648);
	CHECK("%015hhi\n", -2147483648);
	printf("\n--------- END CHECKING hhi ------------\n");

	printf("\n----------- CHECKING hho --------------\n");

	printf("checking normal value\n");
	CHECK("%hho\n", 12);
	printf("checking passing value of 123456\n");
	CHECK("%hho\n", 123456);

	printf("checking 0\n");
	CHECK("%hho\n", 0);

	printf("Checking + with (0)\n");
	CHECK("%+hho\n", 0);
	
	printf("checking right padding hho\n");
	CHECK("%10hho - % 10hho - %7hho - %5hho\n", 654, 389237, 49848, 0);
	printf("checking left padding hho\n");
	CHECK("%-hho, %-7hho, %-5hho - %-3hho -\n", 674, 784, 900, 900);
	printf("checking 0 hho\n");
	CHECK("%08hho - %00hho - %01hho - %023hho\n", 784, 837, 9485, 48);
	printf("checking + hho\n");
	CHECK("%+hho - %+hho - %+hho\n", 784, 837, 674);
	
	//0 with right align, left align, and +;
	printf("checking right padding w/ 0 hho\n");
	CHECK("%02hho - %010hho - %05hho %04hho\n", 758, 859, 950, 758);
	printf("checking + with / 0 hho\n");
	CHECK("%+07hho - %+04hho - %+01hho %+010hho\n", 37834, 2343, 48749, 7849);

	//+ with right align;
	printf("checking + with right padding\n");
	CHECK("%+8hho - %+2hho - %+10hho - %+5hho\n", 728, 928, 839, 0);

	//+ with left align;
	printf("checking + with left padding\n");
	CHECK("%+-8hho - %+-2hho - %+-10hho - %+-8hho - %+-4hho -\n", 128, 3992, 94849, 23904, 0);

	printf("checking negative values with flags\n");
	CHECK("%05hho\n", -42);
	CHECK("%+hho\n", -42);
	CHECK("% hho\n", 42);
	CHECK("% hho\n", -42);

	printf("checking flag conflicts\n");
	CHECK("%-05hho\n", 42);  // '-' wins over '0'
	CHECK("%+ hho\n", 42);   // '+' wins over ' '

	printf("checking limits\n");
	CHECK("%hho\n", 4294967295);
	CHECK("%015hho\n",  4294967295);
	printf("\n--------- END CHECKING hho ------------\n");

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
	CHECK("%-#12hhx - %-#hhx - %-#12hhx - %-#5hhx\n", 4848, 754, 0, 948);

	printf("\n--------- END CHECKING hhx ------------\n");

	printf("\n----------- CHECKING hhX --------------\n");

	printf("checking normal value\n");
	CHECK("%hhX\n", 12);
	printf("checking passing value of 123456\n");
	CHECK("%hhX\n", 123456);

	printf("Checking min and max value (-128, 127)");
	CHECK("min: %hhX - max: %hhX\n", -128, 127); 

	printf("Checking one under min, one over max hhX (-129, 128)\n");
	CHECK("%hhx - %hhX\n", -129, 128);
	
	printf("Checking values well under and well over max (-12500, 34560)\n");
	CHECK("%hhx - %hhX\n", -12500, 34560);

	printf("checking 0\n");
	CHECK("%hhX\n", 0);

	printf("Checking # with (0)\n");
	CHECK("%#hhX\n", 0);

	printf("Checking hex value with hhX\n");
	CHECK("%hhX\n", 0xa0);
	
	printf("checking right padding hhX\n");
	CHECK("%10hhX - %10hhX - %7hhX - %5hhX\n", 654, 389237, 49848, 0);
	printf("checking left padding hhX\n");
	CHECK("%-hhX, %-7hhX, %-5hhX - %-3hhX -\n", 674, 784, 900, 900);
	printf("checking 0 hhX\n");
	CHECK("%08hhX - %00hhX - %01hhX - %023hhX\n", 784, 837, 9485, 48);
	
	printf("checking right padding w/ 0 hhX\n");
	CHECK("%02hhX - %010hhX - %05hhX - %04hhX\n", 758, 859, 950, 758);

	printf("checking right padding w/ # hhX\n");
	CHECK("%#10hhX - %#7hhX - %#6hhX - %#5hhX -\n", 474, 238, 0, 9485);

	printf("checking left padding w/ # hhX\n");
	CHECK("%-#12hhX - %-#hhX - %-#12hhX - %-#5hhX\n", 4848, 754, 0, 948);

	printf("\n--------- END CHECKING hhX ------------\n");

	printf("\n----------- CHECKING hu --------------\n");

	printf("checking normal value\n");
	CHECK("%hu\n", 12);
	printf("checking passing value of 123456\n");
	CHECK("%hu\n", 123456);

	printf("checking 0\n");
	CHECK("%hu\n", 0);

	printf("Checking + with (0)\n");
	CHECK("%+hu\n", 0);
	
	printf("checking right padding hu\n");
	CHECK("%10hu - % 10hu - %7hu - %5hu\n", 654, 389237, 49848, 0);
	printf("checking left padding hu\n");
	CHECK("%-hu, %-7hu, %-5hu - %-3hu -\n", 674, 784, 900, 900);
	printf("checking 0 hu\n");
	CHECK("%08hhu - %00hu - %01hu - %023hu\n", 784, 837, 9485, 48);
	printf("checking + hu\n");
	CHECK("%+hu - %+hu - %+hu\n", 784, 837, 674);
	
	//0 with right align, left align, and +;
	printf("checking right padding w/ 0 hu\n");
	CHECK("%02hu - %010hu - %05hu %04hu\n", 758, 859, 950, 758);
	printf("checking + with / 0 u\n");
	CHECK("%+07hu - %+04hu - %+01hu %+010hu\n", 37834, 2343, 48749, 7849);

	//+ with right align;
	printf("checking + with right padding\n");
	CHECK("%+8hu - %+2hu - %+10hu - %+5hu\n", 728, 928, 839, 0);

	//+ with left align;
	printf("checking + with left padding\n");
	CHECK("%+-8hu - %+-2hu - %+-10hu - %+-8hu - %+-4hu -\n", 128, 3992, 94849, 23904, 0);

	printf("checking negative values with flags\n");
	CHECK("%05hu\n", -42);
	CHECK("%+hu\n", -42);
	CHECK("% hu\n", 42);
	CHECK("% hu\n", -42);

	printf("checking flag conflicts\n");
	CHECK("%-05hu\n", 42);  // '-' wins over '0'
	CHECK("%+ hu\n", 42);   // '+' wins over ' '

	printf("checking limits\n");
	CHECK("%hu\n", 4294967295);
	CHECK("%015hu\n",  4294967295);
	printf("\n--------- END CHECKING hu ------------\n");

	
	printf("\n----------- CHECKING hd --------------\n");

	printf("checking normal value\n");
	CHECK("%hd\n", 12);
	printf("checking passing value of 123456\n");
	CHECK("%hd\n", 123456);

	printf("Checking min and max value (-32768, 32767)");
	CHECK("min: %hd - max: %hd\n", -32768, 32767); 

	printf("Checking one under min, one over max hhd (-32769, 32768)\n");
	CHECK("%hd - %hd\n", -32769, 32768);
	
	printf("Checking values well under and well over max (-1250000, 3456000)\n");
	CHECK("%hd - %hd\n", -1250000, 3456000);

	printf("checking 0\n");
	CHECK("%hd\n", 0);

	printf("Checking + with (0)\n");
	CHECK("%+hd\n", 0);
	
	printf("checking right padding hd\n");
	CHECK("%10hd - % 10hd - %7hd - %5hd\n", 654, 389237, 49848, 0);
	printf("checking left padding hd\n");
	CHECK("%-hd, %-7hd, %-5hd - %-3hd -\n", 674, 784, 900, 900);
	printf("checking 0 hd\n");
	CHECK("%08hd - %00hd - %01hd - %023hd\n", 784, 837, 9485, 48);
	printf("checking + hd\n");
	CHECK("%+hd - %+hd - %+hd\n", 784, 837, 674);
	
	//0 with right align, left align, and +;
	printf("checking right padding w/ 0 hd\n");
	CHECK("%02hd - %010hd - %05hd %04hd\n", 758, 859, 950, 758);
	printf("checking + with / 0 hd\n");
	CHECK("%+07hd - %+04hd - %+01hd %+010hd\n", 37834, 2343, 48749, 7849);

	//+ with right align;
	printf("checking + with right padding\n");
	CHECK("%+8hd - %+2hd - %+10hd - %+5hd\n", 728, 928, 839, 0);

	//+ with left align;
	printf("checking + with left padding\n");
	CHECK("%+-8hd - %+-2hd - %+-10hd - %+-8hd - %+-4hd -\n", 128, 3992, 94849, 23904, 0);

	printf("checking negative values with flags\n");
	CHECK("%05hd\n", -42);
	CHECK("%+hd\n", -42);
	CHECK("% hd\n", 42);
	CHECK("% hd\n", -42);

	printf("checking flag conflicts\n");
	CHECK("%-05hd\n", 42);  // '-' wins over '0'
	CHECK("%+ hd\n", 42);   // '+' wins over ' '

	printf("checking limits\n");
	CHECK("% hd\n", 0);
	CHECK("%hd\n", -2147483648);
	CHECK("%015hd\n", -2147483648);
	printf("\n--------- END CHECKING hd ------------\n");

	printf("\n----------- CHECKING hi --------------\n");

	printf("checking normal value\n");
	CHECK("%hi\n", 12);
	printf("checking passing value of 123456\n");
	CHECK("%hi\n", 123456);

	printf("Checking min and max value (-32768, 32767)");
	CHECK("min: %hi - max: %hi\n", -32768, 32767); 

	printf("Checking one under min, one over max hhd (-32769, 32768)\n");
	CHECK("%hi - %hi\n", -32769, 32768);
	
	printf("Checking values well under and well over max (-150000, 3456000)\n");
	CHECK("%hi - %hi\n", -150000, 3456000);

	printf("checking 0\n");
	CHECK("%hi\n", 0);

	printf("Checking + with (0)\n");
	CHECK("%+hi\n", 0);
	
	printf("checking right padding hi\n");
	CHECK("%10hi - % 10hi - %7hi - %5hi\n", 654, 389237, 49848, 0);
	printf("checking left padding hi\n");
	CHECK("%-hi, %-7hi, %-5hi - %-3hi -\n", 674, 784, 900, 900);
	printf("checking 0 hi\n");
	CHECK("%08hi - %00hi - %01hi - %023hi\n", 784, 837, 9485, 48);
	printf("checking + hi\n");
	CHECK("%+hi - %+hi - %+hi\n", 784, 837, 674);
	
	//0 with right align, left align, and +;
	printf("checking right padding w/ 0 hi\n");
	CHECK("%02hi - %010hi - %05hi %04hi\n", 758, 859, 950, 758);
	printf("checking + with / 0 hi\n");
	CHECK("%+07hi - %+04hi - %+01hi %+010hi\n", 37834, 2343, 48749, 7849);

	//+ with right align;
	printf("checking + with right padding\n");
	CHECK("%+8hi - %+2hi - %+10hi - %+5hi\n", 728, 928, 839, 0);

	//+ with left align;
	printf("checking + with left padding\n");
	CHECK("%+-8hi - %+-2hi - %+-10hi - %+-8hi - %+-4hi -\n", 128, 3992, 94849, 23904, 0);

	printf("checking negative values with flags\n");
	CHECK("%05hi\n", -42);
	CHECK("%+hi\n", -42);
	CHECK("% hi\n", 42);
	CHECK("% hi\n", -42);

	printf("checking flag conflicts\n");
	CHECK("%-05hi\n", 42);  // '-' wins over '0'
	CHECK("%+ hi\n", 42);   // '+' wins over ' '

	printf("checking limits\n");
	CHECK("%hi\n", -2147483648);
	CHECK("%015hi\n", -2147483648);
	printf("\n--------- END CHECKING hi ------------\n");

	printf("\n----------- CHECKING ho --------------\n");

	printf("checking normal value\n");
	CHECK("%ho\n", 12);
	printf("checking passing value of 123456\n");
	CHECK("%ho\n", 123456);

	printf("checking 0\n");
	CHECK("%ho\n", 0);

	printf("Checking + with (0)\n");
	CHECK("%+ho\n", 0);
	
	printf("checking right padding ho\n");
	CHECK("%10ho - % 10ho - %7ho - %5ho\n", 654, 389237, 49848, 0);
	printf("checking left padding ho\n");
	CHECK("%-ho, %-7ho, %-5ho - %-3ho -\n", 674, 784, 900, 900);
	printf("checking 0 ho\n");
	CHECK("%08ho - %00ho - %01ho - %023ho\n", 784, 837, 9485, 48);
	printf("checking + ho\n");
	CHECK("%+ho - %+ho - %+ho\n", 784, 837, 674);
	
	//0 with right align, left align, and +;
	printf("checking right padding w/ 0 ho\n");
	CHECK("%02ho - %010ho - %05ho %04ho\n", 758, 859, 950, 758);
	printf("checking + with / 0 ho\n");
	CHECK("%+07ho - %+04ho - %+01ho %+010ho\n", 37834, 2343, 48749, 7849);

	//+ with right align;
	printf("checking + with right padding\n");
	CHECK("%+8ho - %+2ho - %+10ho - %+5ho\n", 728, 928, 839, 0);

	//+ with left align;
	printf("checking + with left padding\n");
	CHECK("%+-8ho - %+-2ho - %+-10ho - %+-8ho - %+-4ho -\n", 128, 3992, 94849, 23904, 0);

	printf("checking negative values with flags\n");
	CHECK("%05ho\n", -42);
	CHECK("%+ho\n", -42);
	CHECK("% ho\n", 42);
	CHECK("% ho\n", -42);

	printf("checking flag conflicts\n");
	CHECK("%-05ho\n", 42);  // '-' wins over '0'
	CHECK("%+ ho\n", 42);   // '+' wins over ' '

	printf("checking limits\n");
	CHECK("%ho\n", 4294967295);
	CHECK("%015ho\n",  4294967295);
	printf("\n--------- END CHECKING ho ------------\n");

	//with hext check 0c 40
	printf("\n----------- CHECKING hhx --------------\n");

	printf("checking normal value\n");
	CHECK("%hx\n", 12);
	printf("checking passing value of 123456\n");
	CHECK("%hx\n", 123456);

	printf("Checking min and max value (0, 65535)");
	CHECK("min: %hx - max: %hx\n", 0, 65535); 

	printf("Checking one under min, one over max hhd (-1, 65536)\n");
	CHECK("%hx - %hx\n", 0, 65536);
	
	printf("Checking values well under and well over max (-100, 3456000)\n");
	CHECK("%hx - %hx\n", -100, 3456000);

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
	CHECK("%-#12hx - %-#hx - %-#12hx - %-#5hx\n", 4848, 754, 0, 948);

	printf("\n--------- END CHECKING hx ------------\n");

	printf("\n----------- CHECKING hX --------------\n");

	printf("checking normal value\n");
	CHECK("%hX\n", 12);
	printf("checking passing value of 123456\n");
	CHECK("%hX\n", 123456);

	printf("Checking min and max value (0, 65535)");
	CHECK("min: %hX - max: %hX\n", 0, 65535); 

	printf("Checking one under min, one over max hhX (-1, 65536)\n");
	CHECK("%hx - %hX\n", -1, 65536);
	
	printf("Checking values well under and well over max (-100, 3456330)\n");
	CHECK("%hx - %hX\n", -100, 3456330);

	printf("checking 0\n");
	CHECK("%hX\n", 0);

	printf("Checking # with (0)\n");
	CHECK("%#hX\n", 0);

	printf("Checking hex value with hX\n");
	CHECK("%hX\n", 0xa0);
	
	printf("checking right padding hX\n");
	CHECK("%10hX - %10hX - %7hX - %5hX\n", 654, 389237, 49848, 0);
	printf("checking left padding hX\n");
	CHECK("%-hX, %-7hX, %-5hX - %-3hX -\n", 674, 784, 900, 900);
	printf("checking 0 hX\n");
	CHECK("%08hX - %00hX - %01hX - %023hX\n", 784, 837, 9485, 48);
	
	printf("checking right padding w/ 0 hX\n");
	CHECK("%02hX - %010hX - %05hX - %04hX\n", 758, 859, 950, 758);

	printf("checking right padding w/ # hX\n");
	CHECK("%#10hX - %#7hX - %#6hX - %#5hX -\n", 474, 238, 0, 9485);

	printf("checking left padding w/ # hX\n");
	CHECK("%-#12hX - %-#hX - %-#12hX - %-#5hX\n", 4848, 754, 0, 948);

	printf("\n--------- END CHECKING hX ------------\n");


	printf("\n----------- CHECKING lu --------------\n");

	printf("checking normal value\n");
	CHECK("%lu\n", 12);
	printf("checking passing value of 123456\n");
	CHECK("%lu\n", 123456);

	printf("checking 0\n");
	CHECK("%lu\n", 0);

	printf("Checking + with (0)\n");
	CHECK("%+lu\n", 0);
	
	printf("checking right padding lu\n");
	CHECK("%10lu - % 10lu - %7lu - %5lu\n", 654, 389237, 49848, 0);
	printf("checking left padding lu\n");
	CHECK("%-lu, %-7lu, %-5lu - %-3lu -\n", 674, 784, 900, 900);
	printf("checking 0 lu\n");
	CHECK("%08lu - %00lu - %01lu - %023lu\n", 784, 837, 9485, 48);
	printf("checking + lu\n");
	CHECK("%+lu - %+lu - %+lu\n", 784, 837, 674);
	
	//0 with right align, left align, and +;
	printf("checking right padding w/ 0 lu\n");
	CHECK("%02lu - %010lu - %05lu %04lu\n", 758, 859, 950, 758);
	printf("checking + with / 0 lu\n");
	CHECK("%+07lu - %+04lu - %+01lu %+010lu\n", 37834, 2343, 48749, 7849);

	//+ with right align;
	printf("checking + with right padding\n");
	CHECK("%+8lu - %+2lu - %+10lu - %+5lu\n", 728, 928, 839, 0);

	//+ with left align;
	printf("checking + with left padding\n");
	CHECK("%+-8lu - %+-2lu - %+-10lu - %+-8lu - %+-4lu -\n", 128, 3992, 94849, 23904, 0);

	printf("checking negative values with flags\n");
	CHECK("%05lu\n", -42);
	CHECK("%+lu\n", -42);
	CHECK("% lu\n", 42);
	CHECK("% lu\n", -42);

	printf("checking flag conflicts\n");
	CHECK("%-05lu\n", 42);  // '-' wins over '0'
	CHECK("%+ lu\n", 42);   // '+' wins over ' '

	printf("checking limits\n");
	CHECK("%lu\n", 18446744073709551615ULL);
	CHECK("%015lu\n", 18446744073709551613ULL);
	printf("\n--------- END CHECKING lu ------------\n");


	printf("\n----------- CHECKING ld --------------\n");

	printf("checking normal value\n");
	CHECK("%ld\n", 12LL);
	printf("checking passing value of 123456\n");
	CHECK("%ld\n", 123456LL);

	printf("Checking min and max value (-9223372036854775808, 9223372036854775807)");
	CHECK("min: %ld - max: %ld\n", -9223372036854775808LL, 9223372036854775807LL); 

	printf("checking 0\n");
	CHECK("%ld\n", 0);

	printf("Checking + with (0)\n");
	CHECK("%+ld\n", 0);
	
	printf("checking right padding ld\n");
	CHECK("%10ld - % 10ld - %7ld - %5ld\n", 654LL, 389237LL, 49848LL, 0);
	printf("checking left padding ld\n");
	CHECK("%-ld, %-7ld, %-5ld - %-3ld -\n", 674LL, 784LL, 900LL, 900LL);
	printf("checking 0 ld\n");
	CHECK("%08ld - %00ld - %01ld - %023ld\n", 784, 837, 9485, 48);
	printf("checking + ld\n");
	CHECK("%+ld - %+ld - %+ld\n", 784, 837, 674);
	
	//0 with right align, left align, and +;
	printf("checking right padding w/ 0 ld\n");
	CHECK("%02ld - %010ld - %05ld %04ld\n", 758, 859, 950, 758);
	printf("checking + with / 0 ld\n");
	CHECK("%+07ld - %+04ld - %+01ld %+010ld\n", 37834LL, -2343LL, 48749LL, -7849LL);

	//+ with right align;
	printf("checking + with right padding\n");
	CHECK("%+8ld - %+2ld - %+10ld - %+5ld\n", 728, 928, 839, 0);

	//+ with left align;
	printf("checking + with left padding\n");
	CHECK("%+-8ld - %+-2ld - %+-10ld - %+-8ld - %+-4ld -\n", 128, 3992, 94849, 23904, 0);

	printf("checking negative values with flags\n");
	CHECK("%05ld\n", -42);
	CHECK("%+ld\n", -42);
	CHECK("% ld\n", 42);
	CHECK("% ld\n", -42);

	printf("checking flag conflicts\n");
	CHECK("%-05ld\n", 42);  // '-' wins over '0'
	CHECK("%+ ld\n", 42);   // '+' wins over ' '

	printf("checking limits\n");
	CHECK("% ld\n", 0);
	CHECK("%ld\n", -2147483648);
	CHECK("%015ld\n", -2147483648);
	printf("\n--------- END CHECKING ld ------------\n");




	long long check;

	check = 18446744073709551615;

	//add hhx, hhi, etc to flag values being parsed.
	//add is_signed, is_unsigned, is_hex, etc ..
	//reuse parser -> pass flags
	
	//put_formatting_signed
	//put_formatting_unsigned
	//put_formatting_hex
	//put_formatting_oct
	//put_formatting_float
	//put_formatting_string
	//put_formatting_character
	//put_formatting_pointer 

	//Add if (is_hex)
	//              put_formatting_hex(va_lis(list, (unsigned long long)n), flags);
	//etc ...
	
	
	//padding number needs to know num lenght + if there are any additonal formatters being added (-, +, 0x);
	//if 0 is passed the (+, -) for singed goes to the far left (ex. -000047 || +000048) 

	//signed -> needs to know about + -> (+ or -);
	//unsigned -> nothing
	//hex - needs to know about (0x)
	//octal -> nothing
	//float needs to know about # as well as sign -> (#, +, -);

	
	//put_formatting_hex(long n, t_flags flags)
	//
	//	padding_right
	//		check for (0)
	//		check for (0x)
	//		put_padding(flags.padding, n)
	//
	//	check for (0x)
	//
	//	if (flags.hh)
	//		ft_putnumber(unsigned char)n, 16);	
	//	else if (flags.h)
	//		ft_putnumber(usigned short)n 16);
	// 	etc ...
	//
	//	padding_left
	//		check for (0x)
	//		put_padding(flags.padding, n)
	//

	//put_formatting_signed(long n, t_flags flags)
	//
	//	padding_right
	//		check for (0)
	//		check for (-, +)
	//		put_padding(n, flags);
	//
	//	check (-, +, space)
	//
	//	if (flag.hh)
	//		ft_putnumber(signed char)n, 10);
	//	else if (flags.h)
	//		ft_putnumber(signed short)n, 10);
	//	etc ..
	//	
	//	padding_left
	//		check for (-, +)
	//		put_padding(n, flags)
	//



	//What is an easier way to handle left and right formatting around the ft_putnumber function? 
	//I'm thinking maybe break it into 3 things.
	// 
	//	- put_right_padding_signed
	//	- put_left_padding_signed
	//	- put_no_padding_signed
	//
	//The idea of having hh, h, l, ll in a struct with base and is_signed, is_unsigned, is_hex, is_oct, is_flat.
	
	//Use ft_putnumber() to printf + get total value
	
	//Run current test we have written. 
	//100 / 100 
	//printf = compeleted

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

	CHECK("%12f\n", -12.849);
	CHECK("%12f\n", 12.849);
	CHECK("%+12f\n", 12.849);
	CHECK("%012f\n", 12.849);
	CHECK("%+015f\n", 12.849);
	CHECK("%+015f\n", -12.849);
	
	ft_putchar('\n');
	ft_putchar('\n');

	CHECK("%-12f -\n", -12.849);
	CHECK("%-12f -\n", 12.849);
	CHECK("%-012f -\n", 12.849);
	CHECK("%+-12f -\n", 12.849);
	CHECK("%+-12f -\n", -12.849);

	ft_putchar('\n');
	ft_putchar('\n');

	long double testing;
	double another_test;

	another_test = 9485949404.90495058403404840;
	testing = 4859.948494949949494949;
	printf("%#.100Lf\n", testing);
	printf("%#.100f\n", testing);

	CHECK("%.10d\n", -239);
	CHECK("%.10d\n", 239);
	CHECK("%.30f\n", another_test);
	CHECK("%.100Lf\n", testing);
	CHECK("%.100f\n", testing);
	CHECK("%.0f\n", 78.0);
	CHECK("%#.0f\n", 78.0);
	CHECK("%f\n", 78.0);

	long double ld;

	ld = 78.0;
	CHECK("%.0Lf\n", ld);
	CHECK("%#.0Lf\n", ld);
	CHECK("%Lf\n", ld);

	CHECK("%hx\n", 65536);
	CHECK("%hX\n", 65536);
	CHECK("%+-10hd -\n", 758);
	CHECK("%+-10hi -\n", 758);
	CHECK("%-10hu -\n", 8430);
	CHECK("%-10hd -\n", 8430);
	CHECK("%-10hi -\n", 8430);
	CHECK("%-10ho -\n", 8430);
	CHECK("%-#10hx -\n", 8430);
	CHECK("%-#10hX -\n", 8430);

	printf("testing\n");
	//CHECK("\n %hhd - %hhi - %ho - %hu - %d -  %u - %ld\n", -55, 110, check, check, check, check, check, check);
	//CHECK("%hd - %hi - %hu - %hx - %hX - %ho\n", check, check, check, check, check, check);
	//CHECK("%hhd - %hhi - %hhu - %hhx - %hhX - %hho\n", check, check, check, check, check, check);
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
