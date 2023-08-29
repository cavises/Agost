/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaviede <dcaviede@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:05:49 by dcaviede          #+#    #+#             */
/*   Updated: 2023/08/18 11:11:09 by dcaviede         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_capitalize(char c, int fl_capitalize)
{
	if (fl_capitalize == 0)
	{
		if (c >= 'A' && c <= 'Z')
			c = c + 32;
	}
	else
	{
		if (c >= 'a' && c <= 'z')
			c = c - 32;
	}
	return (c);
}

int	ft_is_alpha(char c)
{
	int	fl_alpha;

	fl_alpha = 0;
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		fl_alpha = 1;
	return (fl_alpha);
}

int	ft_is_num(char c)
{
	int	fl_num;

	fl_num = 0;
	if (c >= '0' && c <= '9')
		fl_num = 1;
	return (fl_num);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	fl_firstchar;
	int	fl_capitalize;
	int	fl_alpha;
	int	fl_num;

	i = 0;
	fl_firstchar = 1;
	while (str[i] != '\0')
	{
		fl_alpha = ft_is_alpha(str[i]);
		fl_num = ft_is_num(str[i]);
		if (fl_firstchar == 1 && fl_alpha == 1 && fl_num == 0)
			fl_capitalize = 1;
		else
			fl_capitalize = 0;
		str[i] = ft_capitalize(str[i], fl_capitalize);
		if (fl_alpha == 0 && fl_num == 0)
			fl_firstchar = 1;
		else
			fl_firstchar = 0;
		i++;
	}
	return (str);
}
