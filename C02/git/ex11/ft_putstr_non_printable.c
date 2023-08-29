/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaviede <dcaviede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:25:54 by dcaviede          #+#    #+#             */
/*   Updated: 2023/08/23 09:51:35 by dcaviede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_printable(char c)
{
	if (c >= ' ' && c != 127)
		return (1);
	else
		return (0);
}

void	ft_putstr_non_printable(char *str)
{
	int		i_str;
	int		c;
	char	*hexapattern;

	i_str = 0;
	hexapattern = "0123456789abcdef";
	while (str[i_str] != '\0')
	{
		if (ft_printable(str[i_str]) == 1)
			ft_putchar(str[i_str]);
		else
		{
			ft_putchar('\\');
			if (str[i_str] < 0)
				c = 256 + str[i_str];
			else
				c = str[i_str];
			ft_putchar(hexapattern[c / 16]);
			ft_putchar(hexapattern[c % 16]);
		}
		i_str++;
	}
}
