https://github.com/Kuraigus/Piscina-42/blob/master/Rush02/ex00/functions/ft_verify_values.c


MAIN

#include "headers/structs.h"
#include "headers/headers.h"
#include "headers/ft.h"

#define MAX_BUF_SIZE 4096

int	main(int argc, char *argv[])
{
	int		tam_vet;
	int		tam_lin;
	char	res[MAX_BUF_SIZE];
	t_word	*test;

	if (ft_verify_values(argv[1], argc))
	{
		ft_putstr("error\n");
		return (0);
	}
	ft_open_file(res, MAX_BUF_SIZE);
	tam_vet = ft_strlen(res);
	tam_lin = ft_strlen_newline(res);
	test = (t_word*)malloc(sizeof(t_word) * tam_lin);
	ft_populate_struct(res, test, tam_vet, 0);
	if (ft_check_dict(tam_lin, argv[1], test))
		return (0);
	ft_print_three_numbers(argv[1], test, tam_lin);
	return (0);
}

MAKEFILE

FUNCTIONS = functions/ft_charcmp.c functions/ft_check_dict.c functions/ft_check_input.c functions/ft_create_line.c functions/ft_open_file.c functions/ft_populate_struct.c functions/ft_print_three_numbers.c functions/ft_putchar.c functions/ft_putstr.c functions/ft_strcmp.c functions/ft_strlen.c functions/ft_strlen_newline.c functions/ft_valuelen.c functions/ft_verify_values.c
NAME = rush-02
MAIN = main.c

all: $(NAME)

$(NAME):
	@gcc -Wall -Werror -Wextra -o $(NAME) $(FUNCTIONS) $(MAIN)

fclean:
	@/bin/rm -f $(NAME)

re: fclean $(NAME)

INDEXATION
typedef struct	s_word
{
	char keys[513];
	char values[513];
}				t_word;


PRINT 3 NUMBERS

#include "../headers/structs.h"
#include "../headers/ft.h"
#include "../headers/headers.h"

void	ft_print_hundred(char *argv, int j, t_word *test)
{
	while (j < 10)
	{
		if (ft_charcmp(argv[0], test[j].keys[0]))
		{
			ft_putstr(test[j].values);
			ft_putstr(" hundred ");
		}
		j++;
	}
}

void	ft_print_decimal(char *argv, int j, t_word *test)
{
	j = 20;
	while (j < 29)
	{
		if (ft_charcmp(argv[1], test[j].keys[0]))
		{
			ft_putstr(test[j].values);
			ft_putchar('-');
		}
		j++;
	}
}

void	ft_print_unity(char *argv, int j, t_word *test)
{
	while (j < 10)
	{
		if (ft_charcmp(argv[2], test[j].keys[0]))
		{
			ft_putstr(test[j].values);
		}
		j++;
	}
}

void	ft_print_three_numbers(char *argv, t_word *test, int tam_lin)
{
	int i;

	i = 0;
	while (i < tam_lin)
	{
		if (i == 0)
			ft_print_hundred(argv, 0, test);
		else if (i == 1)
			ft_print_decimal(argv, 20, test);
		else if (i == 2)
			ft_print_unity(argv, 0, test);
		i++;
	}
	ft_putchar('\n');
}


POPULATE STRUCT

#include "../headers/structs.h"

void	ft_populate_struct(char *res, t_word *test, int tam_vet, int k)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (i < tam_vet)
	{
		k = 0;
		while (res[i] != ':')
		{
			test[j].keys[k++] = res[i];
			i++;
		}
		i++;
		k = 0;
		while (res[i] == ' ')
			i++;
		while (res[i] != '\n')
		{
			test[j].values[k++] = res[i];
			i++;
		}
		i++;
		j++;
	}
}


OPEN FILE

#include "../headers/ft.h"
#include "../headers/headers.h"

void	ft_open_file(char *res, int size)
{
	int		file;
	int		ret;

	file = open("numbers.dict", O_RDONLY);
	ret = read(file, res, size);
}

==================================================================================================================
https://github.com/kingdcreations/42Rush-02/blob/master/src/main.c

MAKEFILE

NAME = rush-02

SRCS = src/main.c src/ft_util.c src/ft_rush02.c

OBJS = ${SRC:.c=.o}

FLAGS = -Wall -Werror -Wextra

all:	${NAME}

${NAME}: ${OBJS}
	cc -o ${NAME} ${SRCS} -Iincludes ${FLAGS}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean


MAIN

#include "ft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	getdec(int nb)
{
	if (nb >= 90)
		return (90);
	else if (nb >= 80)
		return (80);
	else if (nb >= 70)
		return (70);
	else if (nb >= 60)
		return (60);
	else if (nb >= 50)
		return (50);
	else if (nb >= 40)
		return (40);
	else if (nb >= 30)
		return (30);
	else if (nb >= 20)
		return (20);
	else if (nb <= 20)
		return (nb);
	else
		return (0);
}

int	getmult(int nb)
{
	if (nb >= 1000000000)
		return (1000000000);
	else if (nb >= 1000000)
		return (1000000);
	else if (nb >= 1000)
		return (1000);
	else if (nb >= 100)
		return (100);
	else
		return (getdec(nb));
}

void	ft_print(int n, t_list *tab, int *first)
{
	int i;
	int mult;

	i = 0;
	mult = getmult(n);
	if (mult >= 100)
		ft_print(n / mult, tab, first);
	if (*first == 0)
		write(1, " ", 1);
	*first = 0;
	while (tab[i].nb != mult)
		i++;
	ft_putstr(tab[i].val);
	if (mult != 0 && n % mult != 0)
		ft_print(n % mult, tab, first);
}

int	main(int ac, char **av)
{
	t_list *tab;
	int *first;
	int addr_first;

	addr_first = 1;
	first = &addr_first;
	if (ac == 2)
	{
		if (ft_atoi(av[1]) < 0)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		tab = process("dict.txt");
		ft_print(ft_atoi(av[1]), tab, first);
	}
	return (0);
}

UTIL

#include "ft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		len;
	char		*dst;

	len = 0;
	while (src[len] != '\0')
		len++;
	if (!(dst = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	negative;

	negative = 1;
	res = 0;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' ||
			*str == '\v' || *str == '\f' || *str == '\r'))
		++str;
	if (*str == '-')
		negative = -1;
	if (*str == '-' || *str == '+')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		++str;
	}
	return (res * negative);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}


RUSH02

#include "ft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char	*ft_getnb(int fd)
{
	int	i;
	char	c[1];
	char	*str;

	if (!(str = malloc(sizeof(char) * 128)))
		exit(1);
	i = 0;
	read(fd, c, 1);
	while (c[0] == '\n')
		read(fd, c, 1);
	while (c[0] >= '0' && c[0] <= '9')
	{
		str[i] = c[0];
		read(fd, c, 1);
		i++;
	}
	return (str);
}

char	*ft_getval(int fd, char *c)
{
	int	i;
	char	*str;

	if (!(str = malloc(sizeof(char) * 128)))
		exit(1);
	i = 0;
	while (c[0] != '\n')
	{
		str[i] = c[0];
		read(fd, c, 1);
		i++;
	}
	return (str);
}

t_list	*process(char *file)
{
	int	i;
	int	fd;
	char	c[1];
	t_list	*tab;
	char *tmp;

	fd = open(file, O_RDONLY);
	if (fd == -1 || !(tab = malloc(sizeof(t_list) * 33)))
		exit(1);
	i = 0;
	while (i < 32)
	{
		tab[i].nb = ft_atoi(ft_getnb(fd));
		read(fd, c, 1);
		while (c[0] == ' ')
			read(fd, c, 1);
		if (c[0] == ':')
			read(fd, c, 1);
		while (c[0] == ' ')
			read(fd, c, 1);
		tmp = ft_getval(fd, c);
		tab[i].val = ft_strdup(tmp);
		free(tmp);
		i++;
	}
	close(fd);
	return (tab);
}


INCLUDES

#ifndef FT_H
# define FT_H

typedef struct	s_list
{
	int	nb;
	char	*val;
}		t_list;
int	ft_atoi(const char *str);
char	*ft_strdup(char *src);
void	ft_putstr(char *str);
char	*ft_getnb(int fd);
char	*ft_getval(int fd, char *c);
t_list	*process(char *file);

#endif


