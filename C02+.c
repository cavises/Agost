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

