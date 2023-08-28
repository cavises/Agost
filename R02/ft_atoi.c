/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siserran <siserran@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 12:30:16 by siserran          #+#    #+#             */
/*   Updated: 2023/08/27 12:30:23 by siserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* function atoi to convert argv char to int*/
int	ft_string(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int	ft_isspace(char c)
{
	if (ft_string(c, "\t\n\v\f\r ") == 1)
		return (1);
	else
		return (0);
}

int	ft_isoperator(char c)
{
	if (ft_string(c, "+-") == 1)
		return (1);
	else
		return (0);
}

int	ft_isnumber(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int	output;
	int	sign;

	output = 0;
	sign = 1;
	while (ft_isspace(*str) == 1)
		str++;
	while (ft_isoperator(*str) == 1)
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_isnumber(*str) == 1)
	{
		output *= 10;
		output += *str - 48;
		str++;
	}
	return (output * sign);
}
