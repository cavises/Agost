/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_dict.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siserran <siserran@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 12:26:15 by siserran          #+#    #+#             */
/*   Updated: 2023/08/27 19:12:38 by siserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int	ft_size_dict(char *dict);

char	*ft_str_dict(char *dict)
{
	int		fd;
	char	*buffer;
	int		size;

	size = ft_size_dict(dict);
	fd = open(dict, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	buffer = malloc(size * sizeof(char));
	if (!buffer)
		return (0);
	read(fd, buffer, size);
	close(fd);
	return (buffer);
}
