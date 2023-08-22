ex00

#include <stdio.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

int	main(void)
{
	char *str;

	str = "Hello ";
	printf("c  : %lu\n", strlen(str));
	printf("ft : %d\n", ft_strlen(str));
}
++++++++++++++++++++++++
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
+++++++++++++++++++++++++++

ex01

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int		main(void)
{
	char *str;

	str = "Hello World";
	ft_putstr(str);
}
++++++++++++++++++++++++++++
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
+++++++++++++++++++++++++++++

ex02

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putnbr(nb / 10);
		ft_putchar('8');
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nb);
	}
	else
	{
		if (nb > 9)
			ft_putnbr(nb / 10);
		ft_putchar(48 + nb % 10);
	}
}

int		main(void)
{
	ft_putnbr(42);
	ft_putchar('\n');
	ft_putnbr(4242);
	ft_putchar('\n');
	ft_putnbr(20000706);
	ft_putchar('\n');
	ft_putnbr(+2147483647);
	ft_putchar('\n');
	ft_putnbr(-2147483648);
}
+++++++++++++++++++++++++++++++++
#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	c;

	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-nb);
	}
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		c = nb % 10 + '0';
		write(1, &c, 1);
	}
	else if (nb <= 9)
	{
		c = nb + '0';
		write(1, &c, 1);
	}
}

/*int	main()
{
	ft_putnbr(-2147483648);
	write(1, "\n", 1);
	ft_putnbr(2147483647);
	write(1, "\n", 1);
	ft_putnbr(1234);
	write(1, "\n", 1);
	ft_putnbr(-1234);
}*/

+++++++++++++++++++++++++++++++++++++



ex03

#include <stdbool.h>
#include <stdio.h>

bool	is_in_string(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (true);
		str++;
	}
	return (false);
}

bool	is_space(char c)
{
	return (is_in_string(c, "\t\n\v\f\r "));
}

bool	is_operator(char c)
{
	return (is_in_string(c, "+-"));
}

bool	is_number(char c)
{
	return (c >= '0' && c <= '9');
}

int		ft_atoi(char *str)
{
	int	result;
	int	minus;

	result = 0;
	minus = 1;
	while (is_space(*str))
		str++;
	while (is_operator(*str))
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	while (is_number(*str))
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	return (result * minus);
}

int		main(void)
{
	char *str;

	str = " ---+--+1234ab567";
	printf("%d\n", ft_atoi(str));
}

+++++++++++++++++++++++++++++++
int	ft_atoi(char *str)
{
	int	c;
	int	s;
	int	res;

	c = 0;
	s = 1;
	res = 0;
	while (str[c] && ((str[c] >= 9 && str[c] <= 13) || str[c] == 32))
		c++;
	while (str[c] && (str[c] == '+' || str[c] == '-'))
	{
		if (str[c] == '-')
			s *= -1;
		c++;
	}
	while (str[c] && (str[c] >= '0' && str[c] <= '9'))
	{
		res = (str[c] - '0') + (res * 10);
		c++;
	}
	return (res * s);
}
/*
#include <stdio.h>
int	main()
{
	int	n;

	n = ft_atoi("");//-12066
	printf("%d", n);
}*/

++++++++++++++++++++++++++++++++++




ex04

#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <limits.h>

int		ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

bool	is_base_valid(char *str)
{
	char	*curr;
	int		index;
	int		jndex;

	curr = str;
	if (str == 0 || ft_strlen(str) <= 1)
		return (false);
	while (*curr)
	{
		if (*curr == '\t' || *curr == '\n' || *curr == '\v' || *curr == '\f'
			|| *curr == '\r' || *curr == ' ' || *curr == '+' || *curr == '-')
			return (false);
		curr++;
	}
	index = 0;
	while (index < curr - str)
	{
		jndex = index + 1;
		while (jndex < curr - str)
			if (str[index] == str[jndex++])
				return (false);
		index++;
	}
	return (true);
}

void	ft_putnbr_base_recursive(int number, char *base, int radix)
{
	if (number == -2147483648)
	{
		ft_putnbr_base_recursive(number / radix, base, radix);
		write(1, &(base[-(number % radix)]), 1);
		return ;
	}
	if (number < 0)
	{
		write(1, "-", 1);
		ft_putnbr_base_recursive(-number, base, radix);
		return ;
	}
	if (number > radix - 1)
		ft_putnbr_base_recursive(number / radix, base, radix);
	write(1, &(base[number % radix]), 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	radix;

	if (!is_base_valid(base))
		return ;
	radix = ft_strlen(base);
	ft_putnbr_base_recursive(nbr, base, radix);
}

int		main(void)
{
	ft_putnbr_base(-123456, "helo");
	printf("\n");
	fflush(stdout);
	ft_putnbr_base(INT_MIN, "0123456789");
	printf("\n");
	fflush(stdout);
	ft_putnbr_base(INT_MAX, "0123456789");
}

+++++++++++++++++++++++++++++++++++++++++++++

#include <unistd.h>

void	ft_putnbr_base_rec(int nbr, char *base, int size)
{
	unsigned char	a;
	unsigned int	n;

	if (nbr < 0)
	{
		write(1, "-", 1);
		n = nbr * (-1);
	}
	else
		n = nbr;
	if (n >= (unsigned int)size)
		ft_putnbr_base_rec(n / size, base, size);
	a = base[n % size];
	write(1, &a, 1);
}

int	ft_ver_bas(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == base[i + 1])
			return (0);
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	s;

	s = 0;
	if (ft_ver_bas(base) == 1)
	{
		while (base[s] != '\0')
			s++;
		ft_putnbr_base_rec(nbr, base, s);
	}
}

+++++++++++++++++++++++++++++++++++++++++++

	

	
ex05

#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>

#define NO_MATCH -1

int		ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

bool	is_space(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r' || c == ' ');
}

bool	is_base_valid(char *str)
{
	char	*curr;
	int		index;
	int		jndex;

	curr = str;
	if (str == 0 || ft_strlen(str) <= 1)
		return (false);
	while (*curr)
	{
		if (is_space(*curr) || *curr == '+' || *curr == '-')
			return (false);
		curr++;
	}
	index = 0;
	while (index < curr - str)
	{
		jndex = index + 1;
		while (jndex < curr - str)
			if (str[index] == str[jndex++])
				return (false);
		index++;
	}
	return (true);
}

int		resolve_base(char *base, char match)
{
	int		index;

	index = 0;
	while (base[index])
	{
		if (base[index] == match)
			return (index);
		index++;
	}
	return (NO_MATCH);
}

int		ft_atoi_base(char *str, char *base)
{
	int	radix;
	int	result;
	int	minus;
	int	resolved;

	if (!is_base_valid(base))
		return (0);
	radix = ft_strlen(base);
	result = 0;
	minus = 1;
	while (is_space(*str))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	while ((resolved = resolve_base(base, *str)) != NO_MATCH)
	{
		result *= radix;
		result += resolved;
		str++;
	}
	return (result * minus);
}

int		main(void)
{
	printf("%d\n", ft_atoi_base("-123456", "0123456789"));
	fflush(stdout);
	printf("%d\n", ft_atoi_base("11110001001000000", "01"));
	fflush(stdout);
	printf("%d\n", ft_atoi_base("-1e240", "0123456789abcdef"));
	fflush(stdout);
}

+++++++++++++++++++++++++++++++++++++++++++

int	digit(char s, char *base)
{
	int	n;

	n = 0;
	while (base[n] != 0 && base[n] != s)
		n++;
	return (n);
}

int	verificar(char *base)
{
	int	i;
	int	o;

	i = 0;
	o = 0;
	while (base[i])
	{
		o = 0;
		while (o < i)
		{
			if (base[i] == base[o] || (base[i] >= 9 && base[i] <= 13)
				|| base[i] == 32 || base[i] == '-' || base[i] == '+')
				return (0);
			o++;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	basesize;
	int	nb;
	int	neg;

	nb = 0;
	neg = 1;
	basesize = verificar(base);
	if (basesize <= 1)
		return (0);
	while (*str != 0 && ((*str >= 9 && *str <= 13) || *str == 32))
		str++;
	while (*str != 0 && (*str == '-' || *str == '+'))
	{
		if (*str++ == '-')
			neg *= -1;
	}
	while (*str != 0 && (digit(*str, base) < basesize))
	{
		nb = (basesize * nb) + (digit(*str, base));
		str++;
	}
	return (nb * neg);
}
/*
#include <stdio.h>
int main()
{
	int	n;

	n = ft_atoi_base("", "01234567");//-12066
	printf("%d", n);
}*/


