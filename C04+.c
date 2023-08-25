ex00

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(void)
{
	char *str;

	str = "Hello 424242";
	printf("c  : %lu\n", strlen(str));
	printf("ft : %d\n", ft_strlen(str));
}

ex01

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

int		main(void)
{
	char *str;

	str = "Hello 424242";
	ft_putstr(str);
}


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
  		ft_putchar('-');
  		ft_putchar('2');
  		ft_putnbr(147483648);
  	}
  	else if (nb < 0)
  	{
  		ft_putchar('-');
  		nb = -nb;
  		ft_putnbr(nb);
  	}
  	else if (nb > 9)
  	{
  		ft_putnbr(nb / 10);
  		ft_putnbr(nb % 10);
  	}
  	else
  		 ft_putchar(nb + 48);
}

int	main()
{
	ft_putnbr(-2147483648);
	write(1, "\n", 1);
	ft_putnbr(2147483647);
	write(1, "\n", 1);
	ft_putnbr(1234);
	write(1, "\n", 1);
	ft_putnbr(-1234);
	write(1, "\n", 1);
	ft_putnbr(0);
}



ex03

#include <stdio.h>
#include <stdlib.h>

int	ft_string(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int	ft_isspace(char c)
{
	if (ft_string(c, "\t\n\v\f\r ") == 1)
	  return (1);
  else
    return (0);
}

int	ft_isoperator(char c)
{
	if (ft_string(c, "+-") == 1)
	  return (1);
  else
    return (0);
}

int	ft_isnumber(char c)
{
	if (c >= '0' && c <= '9')
	  return (1);
  else
    return (0);
}

int		ft_atoi(char *str)
{
	int	output;
	int	sign;

	output = 0;
	sign = 1;
	while (ft_isspace(*str) == 1)
		str++;
	while (ft_isoperator(*str) == 1)
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_isnumber(*str) == 1)
	{
		output *= 10;
		output += *str - 48;
		str++;
	}
	return (output * sign);
}

int		main(void)
{
	char *str;
	char *str2;

	str = " ---+--+1234ab567";
	printf("%d\n", ft_atoi(str));
	str2 = " -1234ab567";
	printf("%d\n", atoi(str2));
}


ex04

#include <unistd.h>
#include <stdio.h>

void	ft_do_recursive_base(int nbr, char *base, int size)
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
		ft_do_recursive_base(n / size, base, size);
	a = base[n % size];
	write(1, &a, 1);
}

int	ft_verify_base(char *base)
{
	int	i;
	int j;

	i = 0;
	j = 1;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[j] != '\0')
		{
		  if (base[i] == base[j])
		    return (0);
		  j++;
		}
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
	if (ft_verify_base(base) == 1)
	{
		while (base[s] != '\0')
			s++;
		ft_do_recursive_base(nbr, base, s);
	}
}

int		main(void)
{
	ft_putnbr_base(-123456, "helo");
	printf("\n");
	fflush(stdout);
	ft_putnbr_base(-2147483648, "0123456789");
	printf("\n");
	fflush(stdout);
	ft_putnbr_base(2147483647, "0123456789");
}


ex05

