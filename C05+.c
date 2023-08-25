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

#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
	  return (1);
	else
	  return (nb * ft_recursive_power(nb, power - 1));
}

int	main(void)
{
	printf("10^2 = %d\n", ft_recursive_power(10, 2));
	printf("10^0 = %d\n", ft_recursive_power(10, 0));
	printf("10^-1 = %d\n", ft_recursive_power(10, -1));
	printf("10^5 = %d\n", ft_recursive_power(10, 5));
}


ex04

#include <stdio.h>

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index <= 1)
		return (index);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

int	main(void)
{
	int	index;

	index = -2;
	while (index < 16)
	{
		printf("fibonacci(%d) = %d\n", index, ft_fibonacci(index));
		index++;
	}
}


ex05

#include <stdio.h>
#include <limits.h>

int	ft_sqrt(int nb)
{
	unsigned int		sqrt;
	unsigned int		i;

	if (nb < 0)
		return (0);
	if (nb <= 1)
		return (nb);
	i = 0;
	while ((sqrt = i * i) <= (unsigned int)nb)
		i++;
	i -= 1;
	return (i * i == (unsigned int)nb ? i : 0);
}

int	main(void)
{
	int nbr;

	nbr = -2;
	while (nbr < 26)
	{
		printf("sqrt(%d) = %d\n", nbr, ft_sqrt(nbr));
		nbr++;
	}
	printf("sqrt(%d) = %d\n", 1000000, ft_sqrt(1000000));
	printf("sqrt(%d) = %d\n", INT_MAX, ft_sqrt(INT_MAX));
	printf("sqrt(%d) = %d\n", INT_MIN, ft_sqrt(INT_MIN));
	printf("sqrt(%d) = %d\n", 2147395600, ft_sqrt(2147395600));
}


ex06


