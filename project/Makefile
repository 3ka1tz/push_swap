# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elopez-u <elopez-u@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/30 11:54:07 by elopez-u          #+#    #+#              #
#    Updated: 2024/11/18 11:55:42 by elopez-u         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC = main.c\
	  ft_split.c\
	  argument_validation.c\
	  stack_indexing.c\
	  operation_push.c\
	  operation_swap.c\
	  operation_rotate.c\
	  operation_reverse_rotate.c\
	  small_stack_sort.c\
	  radix_sort.c\
	  push_swap.c\
	  
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re $(NAME)