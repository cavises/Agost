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

