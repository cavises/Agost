/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siserran <siserran@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 13:42:18 by siserran          #+#    #+#             */
/*   Updated: 2023/08/27 19:11:31 by siserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <unistd.h>
#include <stdlib.h>

int		ft_atoi(char *str);

int		ft_size_dict(char *dict);

char	*ft_str_dict(char *dict);

void	ft_build_table_dict(char *str, t_dict *table, int size, int k);

void	ft_print_number(int nbr, t_dict *table, int first);

int	ft_error(void)
{
	write(1, "Error\n", 6);
	return (-1);
}

int	ft_nlines(char *str_dict)
{
	int	nl;
	int	i;

	i = 0;
	nl = 1;
	while (str_dict[i] != '\0')
	{
		if (str_dict[i] == '\n')
		{
			nl++;
		}
		i++;
	}
	return (nl);
}

int	main(int argc, char **argv)
{
	int		num;
	int		size_dict;
	char	*dict;
	char	*str_dict;
	t_dict	*table;

	num = 0;
	if (argc == 2)
	{
		num = ft_atoi(argv[1]);
		dict = "numbers.dict";
	}
	if (argc == 3)
	{
		num = ft_atoi(argv[2]);
		dict = argv[1];
	}
	if ((argc != 2 && argc != 3) || num < 0)
		ft_error();
	table = (t_dict *)malloc(sizeof (t_dict) * ft_nlines(str_dict));
	ft_build_table_dict(ft_str_dict(dict), table, ft_size_dict(dict), 0);
	ft_print_number(num, table, 1);
	free (str_dict);
	free (table);
	return (0);
}
