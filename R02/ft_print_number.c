/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaviede <dcaviede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 09:59:53 by dcaviede          #+#    #+#             */
/*   Updated: 2023/08/27 18:47:54 by siserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
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

int	ft_tens_and_units(int nbr)
{
	if (nbr >= 90)
		return (90);
	else if (nbr >= 80)
		return (80);
	else if (nbr >= 70)
		return (70);
	else if (nbr >= 60)
		return (60);
	else if (nbr >= 50)
		return (50);
	else if (nbr >= 40)
		return (40);
	else if (nbr >= 30)
		return (30);
	else if (nbr >= 20)
		return (20);
	else if (nbr <= 20)
		return (nbr);
	else
		return (0);
}

int	ft_multiples(int nbr)
{
	if (nbr >= 1000000000)
		return (1000000000);
	else if (nbr >= 1000000)
		return (1000000);
	else if (nbr >= 1000)
		return (1000);
	else if (nbr >= 100)
		return (100);
	else
		return (ft_tens_and_units(nbr));
}

void	ft_print_number(int nbr, t_dict *table, int *first)
{
	int	i;
	int	multiple;

	i = 0;
	multiple = ft_multiples(nbr);
	if (multiple >= 100)
		ft_print_number(nbr / multiple, table, first);
	if (*first == 0)
		write(1, " ", 1);
	*first = 0;
	while (table[i].k_nbr != multiple)
		i++;
	ft_putstr(table[i].values);
	if (multiple != 0 && nbr % multiple != 0)
		ft_print_number(nbr % multiple, table, first);
}
