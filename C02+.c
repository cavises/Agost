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

ex11

