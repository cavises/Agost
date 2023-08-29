/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaviede <dcaviede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 10:31:02 by dcaviede          #+#    #+#             */
/*   Updated: 2023/08/23 10:32:21 by dcaviede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_complete_search(int i_str, int i_find, char *str, char *to_find)
{
	int	i_next;

	i_next = 0;
	while (str[i_str + i_next] == to_find[i_next])
	{
		if (i_next == (i_find - 1))
			return (1);
		else if (i_next < i_find)
			i_next++;
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int			i_str;
	int			i_find;
	char		*p;

	i_str = 0;
	i_find = 0;
	while (to_find[i_find])
		i_find++;
	if (i_find > 0)
	{
		while (str[i_str])
		{
			if (str[i_str] == to_find[0])
			{
				if (ft_complete_search(i_str, i_find, str, to_find))
					return (p = &str[i_str]);
			}
			i_str++;
		}
	}
	else
		return (p = &str[0]);
	return (0);
}
