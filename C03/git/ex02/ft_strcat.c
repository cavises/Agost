/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaviede <dcaviede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:55:00 by dcaviede          #+#    #+#             */
/*   Updated: 2023/08/22 12:58:19 by dcaviede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	end_dest;
	int	i_src;

	end_dest = 0;
	while (dest[end_dest] != '\0')
		end_dest++;
	i_src = 0;
	while (src[i_src] != '\0')
	{
		dest[end_dest + i_src] = src[i_src];
		i_src++;
	}
	dest[end_dest + i_src] = '\0';
	return (dest);
}
