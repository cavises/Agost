ex00

#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while (*s1 != '\0' && (*s1 == *s2) && n > 0)
	{
		s1++;
		s2++;
		n--;
	}
	return (*s1 - *s2);
}

int	main(void)
{
	char *str1;
	char *str2;

	str1 = "Helloo";
	str2 = "Heloo";
	printf("c  : %d\n", strncmp(str1, str2, 5));
	printf("ft : %d\n", ft_strncmp(str1, str2, 5));
}

ex01

#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while (*s1 != '\0' && (*s1 == *s2) && n > 0)
	{
		s1++;
		s2++;
		n--;
	}
	return (*(unsigned char*)s1 - *(unsigned char*)s2);
}

int	main(void)
{
	char *str1;
	char *str2;

	str1 = "Helloo";
	str2 = "Heloo";
	printf("c  : %d\n", strncmp(str1, str2, 5));
	printf("ft : %d\n", ft_strncmp(str1, str2, 5));
}


ex02

#include <stdio.h>
#include <string.h>

char	*ft_strcat(char *dest, char *src)
{
	int end_dest;
	int i_src;

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

int		main(void)
{
	char	*str_base;
	char	dest[100];
	char	dest2[100];
	char	*src;
	int		index;

	str_base = "Hello";
	src = " 42 42";
	index = 0;
	while (index < 6)
	{
		dest[index] = str_base[index];
		dest2[index] = str_base[index];
		index++;
	}
	printf("c  : %s$\n", strcat(dest, src));
	printf("ft : %s$\n", ft_strcat(dest2, src));
}



ex03

#include <stdio.h>
#include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int end_dest;
	int i_src;

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

int		main(void)
{
	char	*str_base;
	char	dest[100];
	char	dest2[100];
	char	*src;
	int		index;

	str_base = "Hello";
	src = " 424242";
	index = 0;
	while (index < 6)
	{
		dest[index] = str_base[index];
		dest2[index] = str_base[index];
		index++;
	}
	printf("c  : %s$\n", strncat(dest, src, 4));
	printf("ft : %s$\n", ft_strncat(dest2, src, 4));
}

ex04

#include <stdio.h>
#include <string.h>

int	ft_complete_search(int i_str, int i_find, char *str, char *to_find)
{
	int	i_next;

	i_next = 0;
	while (str[i_str + i_next] == to_find[i_next])
	{
		if (i_next == (i_find - 1))
			return (1);
		else if (i_next < i_find)
			i_next++;
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int			i_str;
	int			i_find;
	char		*p;

	i_str = 0;
	i_find = 0;
	while (to_find[i_find])
		i_find++;
	if (i_find > 0)
	{
		while (str[i_str])
		{
			if (str[i_str] == to_find[0])
			{
				if (ft_complete_search(i_str, i_find, str, to_find))
					return (p = &str[i_str]);
			}
			i_str++;
		}
	}
	else
		return (p = &str[0]);
	return (0);
}

int		main(void)
{
	char *src;
	char *to_find;
	char *result_c;
	char *result_ft;

	src = "Foo Fighters";
	to_find = "Fight";
	result_c = strstr(src, to_find);
	result_ft = ft_strstr(src, to_find);
	printf("%p / %p\n", result_c, result_ft);
	printf("c  : %s$\n", result_c);
	printf("ft : %s$\n", result_ft);
}



ex05

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

int				main(void)
{
	char	*str_base;
	char	dest[100];
	char	dest2[100];
	char	*src;
	int		i;

	str_base = "Hello";
	src = " 424242";
	i = 0;
	while (i < 10)
	{
		dest[i] = str_base[i];
		dest2[i] = str_base[i];
		i++;
	}
	//printf("c  : (%lu) $%s$\n", strlcat(dest, src, 0), dest);
	printf("ft : (%d) $%s$\n", ft_strlcat(dest2, src, 10), dest2);
  return (0);
}
