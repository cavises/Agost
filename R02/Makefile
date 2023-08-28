FUNCTIONS = ft_atoi.c ft_size_dict.c ft_str_dict.c ft_print_number.c ft_build_table_dict.c struct.h
NAME = rush-02
MAIN = main.c

all: $(NAME)

$(NAME):
	@gcc -Wall -Werror -Wextra -o $(NAME) $(FUNCTIONS) $(MAIN)

fclean:
	@/bin/rm -f $(NAME)

re: fclean $(NAME)
