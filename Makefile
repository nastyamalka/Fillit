NAME = fillit

SRC = ft_read.c ft_write.c ft_fill_iter.c ft_podstanovka.c

INC = libft.h fillit.h

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -Wall -Werror -Wextra  -o $(NAME) $(OBJ)

%.o: %.c
	gcc -Wall -Wextra -Werror -c $<

clean:
	/bin/rm -f $(OBJ)

fclean:
	/bin/rm -f $(NAME) $(OBJ)

re: fclean all


.PHONY: re all clean fclean