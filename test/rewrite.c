//ft_putchar +
//ft_putstr +
//ft_putnbr +
//ft_atoi +
//ft_strsplit +

//start: 12:45pm
//end: 1:55pm

//About 1 hour 10 mins

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char c) {
	write(1, &c, 1);
}

void	ft_putstr(char *str) {
	int i;

	i = 0;
	while(str[i]) {
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(long long n) {

	if (n < 0) {
		ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	ft_putchar((n % 10) + 48);
}

int	ft_atoi(char *str) {
	long res;
	int sign;
	int i;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 8 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+') {
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while(str[i] <= '9' && str[i] >= '0' && str[i]) {
		res = res * 10 + str[i] - 48;
		i++;
	}
	return (res * sign);
}


int get_word_count(char *str, char c) {
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i]) {
		while (str[i] != c && str[i])
			i++; 
		count++;
		while (str[i] == c && str[i])
			i++;
	}
	return (count);
	
}

int	get_letter_count(char *str, int i, char c) {
	int count;
	int j;
	
	count = 0;
	j = i;	
	while (str[j] != c && str[j]) {
		count++;
		j++;
	}
	return (count);
}

char	*get_word(char *str, int i, char c) {
	char *res;
	int j;
	int k;


	j = i;
	k = 0;
	res = (char *)malloc(sizeof(char) * get_letter_count(str, i ,c));
	while (str[j] != c && str[j]) {
		res[k] = str[j];
		k++;
		j++;
	}
	res[k] = '\0';
	return (res);
}

char	**ft_strsplit(char *str, char c) {
	char	**res;
	int word_c;
	int letter_c;
	int i;
	int y;

	i = 0;
	y = 0;
	word_c = get_word_count(str, c);
	res = (char **)malloc(sizeof(char *) * word_c + 1);
	while (str[i]) {
		while (str[i] == c && str[i])
			i++;
		if (str[i] != c && str[i]) {
			res[y] = get_word(str, i , c);
			y++;
		}
		if (y == word_c)
			break;
		while (str[i] != c && str[i])
			i++;
		i++;
	}
	res[y] = 0;
	return(res);
}

void	print_list(char **str) {
	int i;

	i = 0;
	while (str[i]) {
		ft_putstr(str[i]);
		ft_putchar('\n');
		i++;
	}
}

int	main() {
	ft_putchar('c');
	ft_putchar('\n');
	ft_putstr("This is a word\n");
	ft_putnbr(103);
	ft_putchar('\n');
	ft_putnbr(-129);
	ft_putchar('\n');
	ft_putnbr(0);
	ft_putchar('\n');
	ft_putnbr(ft_atoi("89302"));
	ft_putchar('\n');
	ft_putnbr(ft_atoi("+89302"));
	ft_putchar('\n');
	ft_putnbr(ft_atoi("-89302"));
	ft_putchar('\n');
	ft_putnbr(ft_atoi("	89302"));
	ft_putchar('\n');
	ft_putnbr(ft_atoi("   89302"));
	ft_putchar('\n');

	char *str = "t h is has 3wro dzzz";
	char *str1 = "lkajdsf  aksldjf jfjfj oijdf& jf";
	char **example;

	example = ft_strsplit(str, ' ');
	printf("%s: \n\n", str);
	print_list(example);
	
	ft_putchar('\n');
	printf("%s: \n\n", str1);
	print_list(ft_strsplit(str1, 'j'));
	return(0);
}


