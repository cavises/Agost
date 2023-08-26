#include <stdio.h>

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

int		ft_atoi(char *str)
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

int main(int argc, char **argv)
{
  int num;
  char *dict;
  
  num = 0;
  if (argc != 2 || argc != 3)
    write(1, "Error\n", 6);
  if (argc == 2)
    num = ft_atoi(argv[1]);
    dict = "numbers.dict";
  if (argc == 3)
  {
    num = ft_atoi(argv[2]);
    dict = argv[1];
  }
  if (num < 0)
    write(1, "Error\n", 6);
  else
    ft_find_num(num, dict);
  return (0);
}
