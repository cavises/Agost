/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaviede <dcaviede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 09:40:13 by dcaviede          #+#    #+#             */
/*   Updated: 2023/08/28 09:41:52 by dcaviede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	output;
	int	i;

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
