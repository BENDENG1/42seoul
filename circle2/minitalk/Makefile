# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyroh <gyroh@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/14 16:27:08 by gyroh             #+#    #+#              #
#    Updated: 2023/01/25 13:57:27 by gyroh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER			= server
CLIENT			= client

CC				= cc
CFLAG			= -Wextra -Wall -Werror
RM				= rm -f
AR				= ar cr

SRCS_DIR		= ./srcs/
UTIL_SRCS		= minitalk_utils.c
SV_SRCS			= server.c
CL_SRCS			= client.c
PRINT_OBJS		= $(UTIL_SRCS:.c=.o)
SV_OBJS			= $(SV_SRCS:.c=.o)
CL_OBJS			= $(CL_SRCS:.c=.o)

LIBFT			= libft
LIBFT_FLAGS		= -L $(LIBFT) -lft
INC_FLAGS		= -I includes -I $(LIBFT)

SV_OBJECTS = $(SV_OBJS)
CL_OBJECTS = $(CL_OBJS)

all: $(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT):
	@make --silent --directory=$(LIBFT)

$(SERVER): $(SV_OBJECTS) $(PRINT_OBJS)
	$(CC) $(CFLAG) -o $(SERVER) $(SV_OBJECTS) $(PRINT_OBJS) $(LIBFT_FLAGS)

$(CLIENT): $(CL_OBJECTS) $(PRINT_OBJS)
	$(CC) $(CFLAG) -o $(CLIENT) $(CL_OBJECTS) $(PRINT_OBJS) $(LIBFT_FLAGS)

%.o: $(SRCS_DIR)%.c
	$(CC) $(CFLAG) -c $< -o $@ $(INC_FLAGS)

clean:
	@make clean --silent --directory=$(LIBFT)
	$(RM) $(SV_OBJS) $(CL_OBJS) $(PRINT_OBJS)

fclean: clean
	@make fclean --silent --directory=$(LIBFT)
	$(RM) $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all bonus clean fclean re $(LIBFT)
