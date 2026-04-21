#include "../libft/libft.h"
#include <stdio.h>

// Standard C99 macro
#define CHECK(format, ...) \
    printf("checking %s", format); \
    printf("ORIG: " format, __VA_ARGS__); \
    ft_printf("MINE: " format, __VA_ARGS__); \
    printf("\n");

int    ft_printf(char *str, ...); 
void    put_64bit_ull(unsigned long long num);

typedef struct args {
	int	zero;
	int	left;
	int	padding;
	int	pound;
	int	space;
	int 	plus;

}		t_flags;
