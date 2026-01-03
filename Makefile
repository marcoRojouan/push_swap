# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrojouan <mrojouan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/11 19:59:51 by loup              #+#    #+#              #
#    Updated: 2026/01/03 15:22:19 by mrojouan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g -I ./
RM			= rm -f

SRCS		= push_swap.c \
			  algo_helper/push_swap_algo_utils.c \
			  algo_helper/push_swap_min_handler.c \
			  algo_helper/push_swap_radix.c \
			  algo_helper/push_swap_rotates.c \
			  algo_helper/push_swap_rrotates.c \
			  algo_helper/push_swap_swaps.c \
			  algo_helper/push_swap_pushs.c \
			  parsing_helper/push_swap_indexing.c \
			  parsing_helper/push_swap_verif_bis.c \
			  parsing_helper/push_swap_parsing.c \
			  parsing_helper/push_swap_split.c \
			  parsing_helper/push_swap_utils.c \
			  parsing_helper/push_swap_verif.c

OBJS		= $(SRCS:.c=.o)

HEADER		= push_swap.h

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o:		%.c $(HEADER)
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re