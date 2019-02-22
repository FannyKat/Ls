NAME	=	ft_ls

SRC		=	init.c display.c flags.c sort.c stock.c utils.c\

OBJ 	=	$(SRC:.c=.o)

CC		=	gcc

CFLAGS	+=	-Wall -Wextra -I .

PURPLE	=	\033[38;5;105m
BLUE	=	\033[38;5;141m
IDK		=	\033[38;5;177m
END		=	\033[1;34m


$(NAME):	$(OBJ)
	@make -C ../libft
	@echo "${BLUE}LIBRARY COMPILED${END}"
	@$(CC) $(CFLAGS) ${SRC} ../libft/libft.a -o $(NAME)
	@echo "${PURPLE}LS COMPILED${END}"

all:		$(NAME)

clean:
	@/bin/rm -rf $(OBJ)
	@make -C ../libft/ clean
	@echo "${BLUE}clean obj${END}"

fclean:		clean
	@/bin/rm -rf $(NAME)
	@make -C ../libft/ fclean
	@echo "${BLUE}clean $(NAME)${END}"

re:			fclean all

.PHONY: all clean fclean re
