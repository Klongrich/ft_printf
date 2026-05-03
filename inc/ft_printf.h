#include "../libft/libft.h"
#include <stdio.h>
#include <float.h>

static int g_passed = 0;
static int g_failed = 0;

// Standard C99 macro
#define CHECK(format, ...) do { \
    int r1, r2; \
    printf("checking %s\n", format); \
    r1 = printf("ORIG: " format, __VA_ARGS__); \
    printf("\n"); \
    r2 = ft_printf("MINE: " format, __VA_ARGS__); \
    printf("\n"); \
    if (r1 != r2) { \
        printf("\033[31m[KO] Return values differ! (Orig: %d, Mine: %d)\033[0m\n", r1, r2); \
	g_failed++; \
    } else { \
        printf("\033[32m[OK] Return values match: %d\033[0m\n", r1); \
	g_passed++; \
    } \
    printf("--------------------\n"); \
} while (0)

int    ft_printf(char *str, ...); 

typedef struct args {
	int	zero;
	int	left;
	int	padding;
	int	pound;
	int	space;
	int 	plus;
	int	dot;

}		t_flags;
