# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyroh <gyroh@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/12 15:31:32 by gyroh             #+#    #+#              #
#    Updated: 2023/02/25 15:31:54 by gyroh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./src
INC_DIR = ./include
HEADER = $(INC_DIR)/so_long.h

SRCS = $(addprefix $(SRC_DIR)/, \
	main.c \
	exit.c	\
	check_error.c	\
	check_clear.c	\
	print.c	\
	draw_utils1.c	\
	draw_utils2.c	\
	init.c	\
	hook.c	\
)

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = ./libft
LIBFT_AR = $(LIBFT_DIR)/libft.a

MLX_DIR = ./minilibx_opengl_20191021
MLX_AR = $(MLX_DIR)/libmlx.a

LIB_FLAG = -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

.PHONY : all
all: $(NAME)

.PHONY : clean
clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	rm -rf $(OBJS)

.PHONY : fclean
fclean:	clean
	rm -rf $(LIBFT_AR)
	rm -rf $(MLX_AR)
	rm -rf $(NAME)

.PHONY : re
re: fclean all

$(LIBFT_AR) :
	make -C $(LIBFT_DIR)

$(MLX_AR) :
	make -C $(MLX_DIR)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -I $(LIBFT_DIR) -I $(MLX_DIR) -I $(INC_DIR) -c $< -o $@

$(NAME) : $(LIBFT_AR) $(MLX_AR) $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(LIB_FLAG) $(LIBFT_AR) $(MLX_AR) $(OBJS) -I $(INC_DIR) -o $@
