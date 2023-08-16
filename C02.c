EX00

char	*ft_strcpy(char *dest, char *src)
{
	int index;

	index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}


EX01

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int index;

	index = 0;
	while (index < n && src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	while (index < n)
	{
		dest[index] = '\0';
		index++;
	}
	return (dest);
}


EX02

#include <stdbool.h>

int		ft_str_is_alpha(char *str)
{
	int		index;
	bool	valid;
	char	curr;

	index = 0;
	valid = true;
	while (true)
	{
		curr = str[index];
		if (curr == '\0')
		{
			break ;
		}
		if (!((curr >= 'A' && curr <= 'Z') || (curr >= 'a' && curr <= 'z')))
		{
			valid = false;
			break ;
		}
		index++;
	}
	return (valid);
}


EX03

#include <stdbool.h>

int		ft_str_is_numeric(char *str)
{
	int		index;
	bool	valid;
	char	curr;

	index = 0;
	valid = true;
	while (true)
	{
		curr = str[index];
		if (curr == '\0')
		{
			break ;
		}
		if (!(curr >= '0' && curr <= '9'))
		{
			valid = false;
			break ;
		}
		index++;
	}
	return (valid);
}


EX04
#include <stdbool.h>

int		ft_str_is_lowercase(char *str)
{
	int		index;
	bool	valid;
	char	curr;

	index = 0;
	valid = true;
	while (true)
	{
		curr = str[index];
		if (curr == '\0')
		{
			break ;
		}
		if (!(curr >= 'a' && curr <= 'z'))
		{
			valid = false;
			break ;
		}
		index++;
	}
	return (valid);
}




EX05
#include <stdbool.h>

int		ft_str_is_uppercase(char *str)
{
	int		index;
	bool	valid;
	char	curr;

	index = 0;
	valid = true;
	while (true)
	{
		curr = str[index];
		if (curr == '\0')
		{
			break ;
		}
		if (!(curr >= 'A' && curr <= 'Z'))
		{
			valid = false;
			break ;
		}
		index++;
	}
	return (valid);
}

EX06
#include <stdbool.h>

int		ft_str_is_printable(char *str)
{
	int		index;
	bool	valid;
	char	curr;

	index = 0;
	valid = true;
	while (true)
	{
		curr = str[index];
		if (curr == '\0')
		{
			break ;
		}
		if (!(curr >= ' ') || curr == 127)
		{
			valid = false;
			break ;
		}
		index++;
	}
	return (valid);
}


EX07
#include <stdbool.h>

char	*ft_strupcase(char *str)
{
	int		index;
	char	curr;

	index = 0;
	while (true)
	{
		curr = str[index];
		if (curr == '\0')
		{
			break ;
		}
		if (curr >= 'a' && curr <= 'z')
		{
			str[index] = curr - 32;
		}
		index++;
	}
	return (str);
}


EX08
#include <stdbool.h>

char	*ft_strlowcase(char *str)
{
	int		index;
	char	curr;

	index = 0;
	while (true)
	{
		curr = str[index];
		if (curr == '\0')
		{
			break ;
		}
		if (curr >= 'A' && curr <= 'Z')
		{
			str[index] = curr + 32;
		}
		index++;
	}
	return (str);
}


EX09
#include <stdbool.h>

void	ft_transform_char(char *c, bool to_upper)
{
	if (!to_upper)
	{
		if (*c >= 'A' && *c <= 'Z')
		{
			*c = *c + 32;
		}
	}
	else
	{
		if (*c >= 'a' && *c <= 'z')
		{
			*c = *c - 32;
		}
	}
}

bool	is_char_alpha(char c)
{
	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

bool	is_char_numeric(char c)
{
	return (c >= '0' && c <= '9');
}

void	ft_strcapitalize_delegate(char *curr, bool *in_word, bool *skip_word)
{
	bool first_letter;

	first_letter = false;
	if (!*in_word)
	{
		if (is_char_numeric(*curr))
			*skip_word = true;
		else if (is_char_alpha(*curr) && !*skip_word)
		{
			*in_word = true;
			first_letter = true;
		}
	}
	ft_transform_char(curr, false);
	if (*in_word)
		ft_transform_char(curr, first_letter);
}

char	*ft_strcapitalize(char *str)
{
	int		index;
	char	*curr;
	bool	in_word;
	bool	skip_word;

	index = 0;
	in_word = false;
	skip_word = false;
	while (true)
	{
		curr = &str[index];
		if (*curr == '\0')
			break ;
		ft_strcapitalize_delegate(curr, &in_word, &skip_word);
		if (!(is_char_alpha(*curr) || is_char_numeric(*curr)))
		{
			in_word = false;
			skip_word = false;
		}
		index++;
	}
	return (str);
}


EX10
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	count;
	unsigned int	index;

	count = 0;
	index = 0;
	while (src[count] != '\0')
		count++;
	if (size != 0)
	{
		while (src[index] != '\0' && index < (size - 1))
		{
			dest[index] = src[index];
			index++;
		}
		dest[index] = '\0';
	}
	return (count);
}


EX11
#include <stdbool.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

bool	is_char_printable(char c)
{
	return (c >= ' ' && c != 127);
}

void	ft_putstr_non_printable(char *str)
{
	int				index;
	unsigned char	current;

	index = 0;
	while (true)
	{
		current = str[index];
		if (current == '\0')
			break ;
		if (is_char_printable(current))
			ft_putchar(current);
		else
		{
			ft_putchar('\\');
			ft_putchar("0123456789abcdef"[current / 16]);
			ft_putchar("0123456789abcdef"[current % 16]);
		}
		index++;
	}
}


EX12
#include <stdbool.h>
#include <unistd.h>

#define MAX_PAGE_SIZE 14

void	ft_buffer_number(int number, int radix, int buffer[], int index)
{
	if (number > radix - 1)
		ft_buffer_number(number / radix, radix, buffer, index + 1);
	buffer[index] = number % radix;
}

void	ft_write_hex(unsigned int number, int radix, int char_count)
{
	int	buffer[MAX_PAGE_SIZE + 1];
	int	index;

	index = -1;
	while (index++ < MAX_PAGE_SIZE)
		buffer[index] = 0;
	ft_buffer_number(number, radix, buffer, 0);
	index = -1;
	while (index++ < char_count)
		write(1, &"0123456789abcdefgh"[buffer[char_count - index]], 1);
}

void	ft_write_safe_char(char *c)
{
	if (*c >= ' ' && *c != 127)
		write(1, c, 1);
	else
		write(1, &".", 1);
}

void	ft_print_memory_at(void *start_addr, unsigned int size, char *curr_addr)
{
	int index;

	ft_write_hex((unsigned int)curr_addr, 16, MAX_PAGE_SIZE);
	write(1, &": ", 2);
	index = 0;
	while (index++ < 16)
	{
		if (start_addr + size <= (void *)(curr_addr + index - 1))
			write(1, &"  ", 2);
		else
			ft_write_hex((unsigned char)*(curr_addr + index - 1), 16, 1);
		if (index % 2 == 0)
			write(1, &" ", 1);
	}
	index = 0;
	while (index++ < 16)
		if (start_addr + size > (void *)(curr_addr + index - 1))
			ft_write_safe_char((char *)curr_addr + index - 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char	*curr_addr;

	curr_addr = (char *)addr;
	while ((void *)curr_addr < (addr + size))
	{
		ft_print_memory_at(addr, size, curr_addr);
		write(1, &"\n", 1);
		curr_addr += 16;
	}
	return (addr);
}


