/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaviede <dcaviede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 13:38:27 by dcaviede          #+#    #+#             */
/*   Updated: 2023/08/29 13:40:45 by dcaviede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc && argc > 0)
	{
		while (*argv[argc - i])
			write(1, argv[argc - i]++, 1);
		write(1, "\n", 1);
	}
}
