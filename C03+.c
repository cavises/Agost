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

