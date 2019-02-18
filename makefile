# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maboye <maboye@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/05 14:41:24 by fcatusse          #+#    #+#              #
#    Updated: 2019/02/12 21:48:51 by maboye           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	ft_ls

SRC		=	display.c \
			flags.c \
			ft_ls.c \
			ft_printf.c \
			print.c \
			quicksort.c \
			stock_list.c \
			sort.c \
			utils.c \
			main.c

OBJ 	=	$(SRC:.c=.o)

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror -I . -g -Ofast
#-fsanitize=address -g3

PURPLE	=	\033[38;5;105m
BLUE	=	\033[38;5;141m
IDK		=	\033[38;5;177m
END		=	\033[1;34m

all:		$(NAME)

$(NAME):	$(OBJ)
			@make -C libft
			@echo "${BLUE}LIBRARY COMPILED${END}"
			@$(CC) $(CFLAGS) libft/libft.a $(SRC) -o $(NAME)
			@echo "${PURPLE}LS COMPILED${END}"
clean:
			@/bin/rm -rf $(OBJ)
			@make -C libft/ clean
			@echo "${BLUE}clean obj${END}"

fclean:		clean
			@/bin/rm -rf $(NAME)
			@make -C libft/ fclean
			@echo "${BLUE}clean $(NAME)${END}"

re:			fclean all

.PHONY:		all clean fclean re
