/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaviede <dcaviede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 11:59:04 by dcaviede          #+#    #+#             */
/*   Updated: 2023/08/17 11:59:49 by dcaviede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	i;
	int	lower;

	i = 0;
	lower = 1;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'a' && str[i] <= 'z'))
			lower = 0;
		i++;
	}
	return (lower);
}
