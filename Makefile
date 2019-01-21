# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfrederi <cfrederi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/27 14:41:21 by cfrederi          #+#    #+#              #
#    Updated: 2018/09/16 00:37:38 by cfrederi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PS_NAME		= push_swap
CK_NAME		= checker

CC				= gcc 
CFLAGS			= -Wall -Wextra -Werror 

LIBFTINC		= -I./libft/
LIBFTLINK		= -L./libft -lft

PS_SRC_PATH	= ./src/
PS_FILES		= push_swap.c algo.c push.c solve.c check.c stack.c ft_lickity_split.c reverse_rotate.c \
				  stack_sort.c rotate.c swap.c min_solve.c small.c
PS_SRC			= $(addprefix $(PS_SRC_PATH), $(PS_FILES))
PS_OBJ			= $(addprefix $(PS_SRC_PATH), $(PS_FILES:.c=.o))
PS_INC			= -I./includes/ $(LIBFTINC)

CK_SRC_PATH		= ./src/
CK_FILES		= init.c push.c rotate.c check.c reverse_rotate.c swap.c stack.c ft_lickity_split.c \
					input.c
CK_SRC			= $(addprefix $(CK_SRC_PATH), $(CK_FILES))
CK_OBJ			= $(addprefix $(CK_SRC_PATH), $(CK_FILES:.c=.o))
CK_INC			= -I./includes/ $(LIBFTINC)

all: $(PS_NAME) $(CK_NAME) 

$(PS_NAME):
	echo "push_swap : Sources compiling..."
	make -C libft
	$(CC) -I includes  $(CFLAGS) $(PS_INC) $(PS_SRC) -L. ./libft/libft.a -o $(PS_NAME)
	echo "push_swap : compiled with success!"

$(CK_NAME):
	echo "checker : Sources compiling..."
	$(CC) -o $(CK_NAME) $(CFLAGS) $(CK_INC) $(CK_SRC) -L. ./libft/libft.a
	echo "checker: compiled with success!"

clean:
	make clean -C libft
	rm -f $(PS_SRC_PATH)*.o
	echo "Objects removed"

fclean: clean
	make fclean -C libft
	rm -f $(PS_NAME) $(CK_NAME)
	echo "./checker and ./push_swap removed"

re: fclean all
	make -C libft/ re

.PHONY: all, clean, fclean, re

