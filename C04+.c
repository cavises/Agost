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

