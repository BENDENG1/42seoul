CC = gcc

INC = includes/
SRC = srcs
NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
RM = rm -r

SRCS = $(SRC)/ft_putchar.c $(SRC)/ft_putstr.c $(SRC)/ft_strcmp.c $(SRC)/ft_strlen.c $(SRC)/ft_swap.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar cr $@ $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re

