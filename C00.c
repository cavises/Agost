/*===============================================================================================================
Exercici 06
===============================================================================================================*/

#include <unistd.h>

void	ft_putchar (char c)
{
	write (1, &c, 1);
}

void	ft_printfirstnum(int x)
{
	char	n;
	
	n = (char) x;
	if (x < 10)
	{	
		ft_putchar('0');
		ft_putchar(n);
	}
	else
		ft_putchar(n);
	ft_putchar(' ');
}

void	ft_printsecondnum(int x)
{
	char	n;
	
	n = (char) x;
	if (x < 10)
	{	
		ft_putchar('0');
		ft_putchar(n);
	}
	else
		ft_putchar(n);
	if (x < 99)
		ft_putchar(', ');
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while(i < 99)
	{
		ft_printfirstnum(i);
		j = i + 1;
		while (j <= 99)
		{
			ft_printsecondnum(j);
			j++;
		}
		i++;
	}
}

/* int main ()
{
	ft_print_comb2();
} */


/*===============================================================================================================
Exercici 07
===============================================================================================================*/

#include <unistd.h>
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/* Function that print on screen the integer writen in the main function:
   Because the max positive integer is 2147483647 we have to do a special
   work for the max negative -2147483648. We convert all negatives in 
   a positive but printing a '-' before. We reduce all numbers to a single 
   digit that we can print adding 48 to the digit (first position of 0 in 
   the ASCII table).*/
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
/*
int main (void)
{
	ft_putnbr(4563);
	ft_putchar('\n');
	ft_putnbr(-2147483648);
	ft_putchar('\n');
	ft_putnbr(42);
	ft_putchar('\n');
	ft_putnbr(2147483647);
	ft_putchar('\n');
	ft_putnbr(0);
	ft_putchar('\n');
	ft_putnbr(-5120);
	ft_putchar('\n');

}*/


/*===============================================================================================================
Exercici 08
===============================================================================================================*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaviede <dcaviede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 11:48:42 by dcaviede          #+#    #+#             */
/*   Updated: 2023/08/14 16:30:01 by dcaviede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_write_combn(int n, int vector[])
{
	int		i;
	int	last;

	i = 0;
	while (i < n)
	{
		ft_putchar(48 + vector[i]);
		i++;
	}
	i = n - 1;
	last = 0;
	while (i >= 0)
	{
		if (vector[i] != 9 - (n - 1 - i))
		{
			last = 1;
			break ;
		}
		i--;
	}
	if (last == 0)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	ft_fill_vector(int n, int i, int vector[])
{
	int	val;
	int	valmax;

	if (i == n)
	{
		ft_write_combn(n, vector);
	}
	else
	{
		valmax = 10 - (n - i);
		val = 0;
		while (val <= valmax)
		{
			vector[i] = val;
			ft_fill_vector(n, i + 1, vector);
			val++;
		}
	}
}

void	ft_print_combn(int n)
{
	int	vector[n];
	int	i;

	i = 0;
	while (i < n)
	{
		vector[i] = 0;
		i++;
	}
	i = 0;
	ft_fill_vector(n, i, vector);
}

int	main(void)
{
	ft_print_combn(4);
	return (0);
}
