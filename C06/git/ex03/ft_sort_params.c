/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaviede <dcaviede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 10:17:53 by dcaviede          #+#    #+#             */
/*   Updated: 2023/08/30 10:35:24 by dcaviede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_swap(char **a, char **b)
{
	char	*c;

	c = *a;
	*a = *b;
	*b = c;
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_sort_params(char **str, int size)
{
	int		i;
	int		swap;

	while (1 == 1)
	{
		i = 1;
		swap = 0;
		while (i < size)
		{
			if (ft_strcmp(str[i], str[i + 1]) > 0)
			{
				ft_swap(&str[i], &str[i + 1]);
				swap = 1;
			}
			i++;
		}
		if (swap == 0)
			break ;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc > 2)
		ft_sort_params(argv, argc - 1);
	i = 0;
	while (++i < argc)
	{
		ft_putstr(argv[i]);
		ft_putstr("\n");
	}
}
