NAME	=	ft_ls

SRC	=	init.c display.c flags.c sort.c stock.c utils.c\

INC	= 	my_ls.h

OBJ 	=	$(SRC:.c=.o)

CC	=	gcc

CFLAGS	+=	-Wall -Wextra -I .

PURPLE	=	\033[38;5;105m
BLUE	=	\033[38;5;141m
IDK	=	\033[38;5;177m
END	=	\033[0m


$(NAME):	lib $(OBJ)
	@$(CC) $(CFLAGS) ${SRC} ./lib/libft.a -o $(NAME)
	@echo "${PURPLE}LS COMPILED${END}"

all:		$(NAME)

lib:	
	@$(MAKE) -C ./lib
	@echo "${BLUE}LIBRARY COMPILED${END}"

$(OBJ):		$(INC)

clean:
	@/bin/rm -rf $(OBJ)
	@make -C ./lib/ clean
	@echo "${BLUE}clean obj${END}"

fclean:		clean
	@/bin/rm -rf $(NAME)
	@make -C ./lib/ fclean
	@echo "${BLUE}clean $(NAME)${END}"

re:		fclean all

.PHONY: all clean fclean re
