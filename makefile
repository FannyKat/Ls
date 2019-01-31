NAME	=	ft_ls

SRC		=	init.c\

OBJ 	=	$(SRC:.c=.o)

CC		=	clang

CFLAGS	=	-Wall -Wextra -I .

all:		$(NAME)

$(NAME):	$(OBJ)
			@make -C libft
			@$(CC) $(CFLAGS) libft/libft.a $(SRC) -o $(NAME)
clean:
			@/bin/rm -rf $(OBJ)
			@make -C libft/ clean

fclean:		clean
			@/bin/rm -rf $(NAME)
			@make -C libft/ fclean

re:			fclean all

.PHONY:		all clean fclean re
