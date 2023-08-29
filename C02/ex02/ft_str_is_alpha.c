/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaviede <dcaviede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:29:09 by dcaviede          #+#    #+#             */
/*   Updated: 2023/08/17 10:14:56 by dcaviede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	char	c;
	int		i;
	int		alpha;

	i = 0;
	alpha = 1;
	while (str[i] != '\0')
	{
		c = str[i];
		if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')))
			alpha = 0;
		i++;
	}
	return (alpha);
}
