ex00

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

#include <stdio.h>
#include <string.h>

int		main(void)
{
	char *src;
	char dest[12];

	src = "Hello World";
	printf("base   : %s\n", src);
	strcpy(dest, src);
	printf("cpy    : %s\n", dest);
	ft_strcpy(dest, src);
	printf("ft_cpy : %s\n", dest);
}


ex01

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

#include <stdio.h>
#include <string.h>

int		main(void)
{
	char *src;
	char dest[20];

	src = "Hello World";
	printf("base   : %s\n", src);
	strncpy(dest, src, 8);
	printf("cpy    : %s\n", dest);
	ft_strncpy(dest, src, 8);
	printf("ft_cpy : %s\n", dest);
}



ex02

int	ft_str_is_alpha(char *str)
{
	char	c;
	int		i;
	int		alpha;

	i = 0;
	alpha = 1;
	while (str[i] != '\0')
	{
		c = str[i];
		if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')))
			alpha = 0;
		i++;
	}
	return (alpha);
}

#include <stdbool.h>
#include <stdio.h>

int		main(void)
{
	char *str_valid;
	char *str_invalid;

	str_valid = "Hello";
	str_invalid = "Hell0";
	printf("should be 1: %d\n", ft_str_is_alpha(str_valid));
	printf("should be 0: %d\n", ft_str_is_alpha(str_invalid));
}




ex03

int	ft_str_is_numeric(char *str)
{
	int	i;
	int	num;

	i = 0;
	num = 1;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			num = 0;
		i++;
	}
	return (num);
}

#include <stdbool.h>
#include <stdio.h>

int		main(void)
{
	char *str_valid;
	char *str_invalid;

	str_valid = "123456";
	str_invalid = "123A56";
	printf("should be 1: %d\n", ft_str_is_numeric(str_valid));
	printf("should be 0: %d\n", ft_str_is_numeric(str_invalid));
}


ex04

int	ft_str_is_lowercase(char *str)
{
	int	i;
	int	lower;

	i = 0;
	lower = 1;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'a' && str[i] <= 'z'))
			lower = 0;
		i++;
	}
	return (lower);
}

#include <stdbool.h>
#include <stdio.h>

int		main(void)
{
	char *str_valid;
	char *str_invalid;

	str_valid = "HELLO";
	str_invalid = "HELLo";
	printf("should be 1: %d\n", ft_str_is_uppercase(str_valid));
	printf("should be 0: %d\n", ft_str_is_uppercase(str_invalid));
}



ex05

int	ft_str_is_uppercase(char *str)
{
	int	i;
	int	upper;

	i = 0;
	upper = 1;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'A' && str[i] <= 'Z'))
			upper = 0;
		i++;
	}
	return (upper);
}

#include <stdbool.h>
#include <stdio.h>

int		main(void)
{
	char *str_valid;
	char *str_invalid;

	str_valid = "HELLO";
	str_invalid = "HELLo";
	printf("should be 1: %d\n", ft_str_is_uppercase(str_valid));
	printf("should be 0: %d\n", ft_str_is_uppercase(str_invalid));
}



ex06

int	ft_str_is_printable(char *str)
{
	int	i;
	int	pr;

	i = 0;
	pr = 1;
	while (str[i] != '\0')
	{
		if (!(str[i] >= ' ') || str[i] == 127)
			pr = 0;
		i++;
	}
	return (pr);
}

#include <stdbool.h>
#include <stdio.h>

int		main(void)
{
	char *str_valid;
	char *str_invalid;

	str_valid = "Hell0";
	str_invalid = "hello\7F";
	printf("should be 1: %d\n", ft_str_is_printable(str_valid));
	printf("should be 0: %d\n", ft_str_is_printable(str_invalid));
}





ex07

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
		}
		i++;
	}
	return (str);
}

#include <stdbool.h>
#include <stdio.h>

int		main(void)
{
	char	*str_base;
	char	str_upper[6];
	int		index;

	str_base = "heLl0";
	index = 0;
	while (index < 6)
	{
		str_upper[index] = str_base[index] + 0;
		index++;
	}
	ft_strupcase(&str_upper[0]);
	printf("should be normal    : %s\n", str_base);
	printf("should be upper case: %s\n", str_upper);
}





ex08

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

#include <stdbool.h>
#include <stdio.h>

int		main(void)
{
	char	*str_base;
	char	str_lower[6];
	int		index;

	str_base = "HELl0";
	index = 0;
	while (index < 6)
	{
		str_lower[index] = str_base[index] + 0;
		index++;
	}
	ft_strlowcase(&str_lower[0]);
	printf("should be normal    : %s\n", str_base);
	printf("should be lower case: %s\n", str_lower);
}


ex09

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

#include <stdbool.h>
#include <stdio.h>

int		main(void)
{
	char	*str_base;
	char	str_cap[36];
	int		index;

	//str_base = "salut, c0mment tu vas ? 42mots quarante-deux; cinquante+et+un";
	str_base = "Vk_(7X)Vmf#H'Fk?>8j@} /7VVxh3(X{6)Xb";
	index = 0;
	while (index < 37)
	{
		str_cap[index] = str_base[index] + 0;
		index++;
	}
	ft_strcapitalize(&str_cap[0]);
	//printf("base        : %s\n", str_base);
	//printf("capitalized : %s\n", str_lower);
	printf("%s\n", str_cap);
}


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

#include <stdio.h>
#include <string.h>

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
	char	*hexapattern;

	i_str = 0;
	hexapattern = "0123456789abcdef";
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
			ft_putchar(hexapattern[c / 16]);
			ft_putchar(hexapattern[c % 16]);
		}
		i_str++;
	}
}

#include <stdio.h>
#include <string.h>

int		main(void)
{
	char	*string;
	char b;
	
  b = -43;
	string = "Coucou\ntu vas bien ?";
	//string = &b;
	ft_putstr_non_printable(string);
}
