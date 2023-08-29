/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaviede <dcaviede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 11:30:34 by dcaviede          #+#    #+#             */
/*   Updated: 2023/08/29 12:56:08 by dcaviede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc && argc > 0)
	{
		while (*argv[i])
			write(1, argv[i]++, 1);
		write(1, "\n", 1);
	}
}
