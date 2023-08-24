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

