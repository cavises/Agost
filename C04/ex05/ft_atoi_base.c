/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaviede <dcaviede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 10:08:05 by dcaviede          #+#    #+#             */
/*   Updated: 2023/08/26 10:10:04 by dcaviede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_verify_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] == ' ')
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
	return (i);
}

int	ft_isdigit(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != 0 && base[i] != c)
		i++;
	return (i);
}

int	ft_atoi_base(char *str, char *base)
{
	int	basesize;
	int	nbr;
	int	sign;

	nbr = 0;
	sign = 1;
	basesize = ft_verify_base(base);
	if (basesize <= 1)
		return (0);
	while (*str != 0 && ((*str >= 9 && *str <= 13) || *str == 32))
		str++;
	while (*str != 0 && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str != 0 && (ft_isdigit(*str, base) < basesize))
	{
		nbr = (basesize * nbr) + (ft_isdigit(*str, base));
		str++;
	}
	return (nbr * sign);
}
