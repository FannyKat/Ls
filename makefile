NAME	=	ft_ls

SRC	=	init.c display.c check_dir.c\

OBJ 	=	$(SRC:.c=.o)

CC	=	 gcc

CFLAGS	=	-Wall -Wextra -I .

all:		$(NAME)

$(NAME):	$(OBJ)
		@make -C libft
		@$(CC) $(CFLAGS) ${SRC} libft/libft.a -o $(NAME)
clean:
		@/bin/rm -rf $(OBJ)
		@make -C libft/ clean

fclean:	clean
		@/bin/rm -rf $(NAME)
		@make -C libft/ fclean

re:		fclean all

.PHONY:		all clean fclean re
