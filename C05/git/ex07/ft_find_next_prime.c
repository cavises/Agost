/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaviede <dcaviede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:27:18 by dcaviede          #+#    #+#             */
/*   Updated: 2023/08/28 10:28:54 by dcaviede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;
	int	divisors;

	i = 1;
	divisors = 0;
	if (nb <= 1)
		return (0);
	while (i <= nb)
	{
		if (nb % i == 0)
			divisors++;
		i++;
	}
	if (divisors == 2)
		return (1);
	else
		return (0);
}

int	ft_find_next_prime(int nb)
{
	while (1 == 1)
	{
		if (ft_is_prime(nb))
			return (nb);
		nb++;
	}
}
