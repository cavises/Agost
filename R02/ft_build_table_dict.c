/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_table_dict.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaviede <dcaviede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 09:16:05 by dcaviede          #+#    #+#             */
/*   Updated: 2023/08/27 19:30:30 by siserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <stdlib.h>

int	ft_atoi(char *str);

void	ft_build_table_dict(char *str, t_dict *table, int size, int k)
{
	int		i;
	int		j;
	char	*tmp;

	j = -1;
	i = -1;
	while (++i < size)
	{
		while (str[i] != ':')
		{
			tmp[i] = str[i];
			i++;
		}
		table[++j].k_nbr = ft_atoi(tmp);
		i++;
		while (str[i] == ' ')
			i++;
		k = 0;
		while (str[i] != '\n')
		{
			table[j].values[k++] = str[i];
			i++;
		}
	}
}
