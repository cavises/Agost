/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_dict.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siserran <siserran@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 13:37:04 by siserran          #+#    #+#             */
/*   Updated: 2023/08/27 18:49:08 by siserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int	ft_size_dict(char *dict)
{
	int		fd;
	int		nbytes;
	char	*buffer;
	int		size;

	size = 1;
	fd = open(dict, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Dict Error\n", 11);
		return (-1);
	}
	buffer = malloc(size * sizeof(char));
	if (!buffer)
		return (-1);
	nbytes = read(fd, buffer, size);
	while (nbytes > 0)
	{
		free(buffer);
		size += size;
		buffer = malloc(size * sizeof(char));
	}
	close(fd);
	return (size);
}
