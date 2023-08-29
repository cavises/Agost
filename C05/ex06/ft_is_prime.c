/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaviede <dcaviede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:14:40 by dcaviede          #+#    #+#             */
/*   Updated: 2023/08/28 10:16:38 by dcaviede         ###   ########.fr       */
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
