#include "../libft/libft.h"
#include <stdio.h>
#include <float.h>

static int g_passed = 0;
static int g_failed = 0;

// Standard C99 macro
#include <unistd.h>
#include <string.h>

char *g_fail_log[1024]; // Stores pointers to failed format strings

#define CHECK(format, ...) do { \
    int pipe_fd[2]; \
    char buf1[4096] = {0}, buf2[4096] = {0}; \
    int r1, r2; \
    int stdout_copy = dup(STDOUT_FILENO); \
    \
    /* 1. Capture Original printf */ \
    pipe(pipe_fd); \
    dup2(pipe_fd[1], STDOUT_FILENO); \
    r1 = printf(format, __VA_ARGS__); \
    fflush(stdout); \
    close(pipe_fd[1]); \
    read(pipe_fd[0], buf1, 4095); \
    close(pipe_fd[0]); \
    \
    /* 2. Capture Your ft_printf */ \
    pipe(pipe_fd); \
    dup2(pipe_fd[1], STDOUT_FILENO); \
    r2 = ft_printf(format, __VA_ARGS__); \
    fflush(stdout); \
    close(pipe_fd[1]); \
    read(pipe_fd[0], buf2, 4095); \
    close(pipe_fd[0]); \
    \
    /* Restore STDOUT */ \
    dup2(stdout_copy, STDOUT_FILENO); \
    close(stdout_copy); \
    \
    printf("Testing: %s\n", #__VA_ARGS__); \
    if (r1 == r2 && strcmp(buf1, buf2) == 0) { \
        printf("\033[32m  [OK] Matches\033[0m\n"); \
        g_passed++; \
    } else { \
        printf("\033[31m  [KO] Mismatch Found\033[0m\n"); \
        printf("    \033[33mEXPECTED:\033[0m [%s] (len: %d)\n", buf1, r1); \
        printf("    \033[36mACTUAL:  \033[0m [%s] (len: %d)\n", buf2, r2); \
        g_fail_log[g_failed] = #format " with " #__VA_ARGS__; \
        g_failed++; \
    } \
    printf("--------------------\n"); \
} while (0)

#define PRINT_REPORT() do { \
    printf("\n=== FINAL REPORT ===\n"); \
    printf("PASSED: %d\n", g_passed); \
    printf("FAILED: %d\n", g_failed); \
    if (g_failed > 0) { \
        printf("\nDetailed Failures:\n"); \
        for (int i = 0; i < g_failed; i++) { \
            printf("\033[31m[%d] %s\033[0m\n", i + 1, g_fail_log[i]); \
        } \
    } \
    printf("====================\n"); \
} while (0)

#define CHECK_F(format, ...) do { \
    int r1, r2; \
    printf("checking %s\n", format); \
    r1 = printf("ORIG: " format, __VA_ARGS__); \
    printf("\n"); \
    r2 = ft_printf("MINE: " format, __VA_ARGS__); \
    printf("\n"); \
    if (r1 != r2) { \
        printf("\033[31m[KO] Return values differ! (Orig: %d, Mine: %d)\033[0m\n", r1, r2); \
    } else { \
        printf("\033[32m[OK] Return values match: %d\033[0m\n", r1); \
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
	int	is_uppercase;

}		t_flags;
