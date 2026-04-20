#include "../libft/libft.h"
#include <stdio.h>

int    ft_printf(char *str, ...); 
void    put_64bit_ull(unsigned long long num);

typedef struct args {
	int	h;
	int	hh;
	int	l;
	int	ll;
	int	zero;
	int	left;
	int	padding;
	int	pound;
	int	space;
	int 	plus;

}		t_args;
