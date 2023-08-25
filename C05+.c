ex00

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	factorial;
	int	i;

	if (nb < 0)
		return (0);
	i = 1;
	factorial = 1;
	while (i <= nb)
	{
		factorial = factorial * i;
		i++;
	}
	return (factorial);
}

int	main(void)
{
	int n;

	n = -2;
	while (n < 7)
	{
		printf("fact(%d) = %d\n", n, ft_iterative_factorial(n));
		n++;
	}
}


ex01

#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
}

int	main(void)
{
	int n;

	n = -2;
	while (n < 7)
	{
		printf("fact(%d) = %d\n", n, ft_recursive_factorial(n));
		n++;
	}
}


ex02

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int output;
	int i;

  output = 1;
  i = 0;
	if (power < 0)
		return (0);
	while (i < power)
	{
		output *= nb;
		i++;
	}
	return (output);
}

int	main(void)
{
	printf("10^2 = %d\n", ft_iterative_power(10, 2));
	printf("10^0 = %d\n", ft_iterative_power(10, 0));
	printf("10^-1 = %d\n", ft_iterative_power(10, -1));
	printf("10^5 = %d\n", ft_iterative_power(10, 5));
}


ex03


