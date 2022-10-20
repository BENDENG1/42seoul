NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f

SRCS = ft_printf.c print_ptr_num.c print_str.c print_tools.c

OBJS = $(SRCS:.c=.o)

HEADER = ft_printf.h

all : $(NAME)

%.o:%.c
	$(CC) $(CFLAG) -c $< -o $@ -I $(HEADER)

$(NAME) : $(OBJS)
	$(AR) $@ $(OBJS)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re :
	fclean all

.PHONY : all clean fclean re
