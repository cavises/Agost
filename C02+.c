ex01



ex10
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	end_src;
	unsigned int	i;

	end_src = 0;
	i = 0;
	while (src[end_src] != '\0')
		end_src++;
	if (size != 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (end_src);
}

int				main(void)
{
	char	*string1;
	char	string2[20];
	int   length_src;

	string1 = "Hello 42";
	printf("base   : %s\n", string1);
	//length_src = strlcpy(string2, string1, 4);
	//printf("cpy c  : %s\n", string2);
	//printf("cpy c (nb) : %d\n", length_src);
	length_src = ft_strlcpy(string2, string1, 4);
	printf("cpy ft : %s\n", string2);
	printf("cpy ft (nb) : %d\n", length_src);
}

ex11

#include <stdbool.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_printable(char c)
{
	if (c >= ' ' && c != 127)
	  return (1);
  else
    return (0);
}

void	ft_putstr_non_printable(char *str)
{
	int		i_str;
	int   c;
	char	*basehexa;

	i_str = 0;
	basehexa = "0123456789abcdef";
	while (str[i_str] != '\0')
	{
		if (ft_printable(str[i_str]) == 1)
			ft_putchar(str[i_str]);
		else
		{
			ft_putchar('\\');
			if (str[i_str] < 0)
				c = 256 + str[i_str];
			else
				c = str[i_str];
			ft_putchar(basehexa[c / 16]);
			ft_putchar(basehexa[c % 16]);
		}
		i_str++;
	}
}

int		main(void)
{
	char	*string;
	char b;
	
  b = -43;
	//string = "Coucou\ntu vas bien ?";
	//string = &b;
	ft_putstr_non_printable(string);
}
