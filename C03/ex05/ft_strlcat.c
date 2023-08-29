/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaviede <dcaviede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 12:58:25 by dcaviede          #+#    #+#             */
/*   Updated: 2023/08/23 12:58:45 by dcaviede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i_dest;
	unsigned int	i_src;
	unsigned int	i;

	i_dest = 0;
	i_src = 0;
	i = 0;
	while (dest[i_dest])
		i_dest++;
	while (src[i_src])
		i_src++;
	if (size <= i_dest)
		return (i_src + size);
	while (src[i] && (i_dest + i) < (size - 1))
	{
		dest[i_dest + i] = src[i];
		i++;
	}
	dest[i_dest + i] = '\0';
	return (i_src + i_dest);
}
