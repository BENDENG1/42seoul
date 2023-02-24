CC = gcc
SRC = srcs
NAME = do-op
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS = $(SRC)/atoi.c $(SRC)/operator.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
