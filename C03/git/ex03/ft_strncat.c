/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaviede <dcaviede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:29:36 by dcaviede          #+#    #+#             */
/*   Updated: 2023/08/22 13:30:18 by dcaviede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int	end_dest;
	int	i_src;

	end_dest = 0;
	while (dest[end_dest] != '\0')
		end_dest++;
	i_src = 0;
	while (src[i_src] != '\0' && nb > 0)
	{
		dest[end_dest + i_src] = src[i_src];
		i_src++;
		nb--;
	}
	dest[end_dest + i_src] = '\0';
	return (dest);
}
