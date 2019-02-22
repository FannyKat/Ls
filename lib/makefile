NAME	=		libft.a

FLAGS	=		-Wall -Werror -Wextra -I. -c

SRCS	=		ft_memset.c ft_bzero.c ft_memcpy.c ft_lstmerge.c ft_xlstadd.c\
				ft_strlen.c ft_strdup.c ft_strcpy.c ft_strcat.c ft_strchr.c\
				ft_strcmp.c ft_atoi.c ft_memalloc.c ft_memdel.c ft_strnew.c\
				ft_strdel.c ft_strclr.c ft_strsub.c ft_strjoin.c ft_strsplit.c\
				ft_itoa.c ft_putchar.c ft_putstr.c ft_lstnew.c ft_lstdelone.c\
				ft_lstadd.c ft_lstiter.c ft_memmove.c ft_memcmp.c ft_isspace.c\
				ft_swap.c get_next_line.c ft_lstdel.c\

OBJ		= 	$(SRCS:.c=.o)

$(NAME): 	$(OBJ)
			@ar rc $(NAME) $(OBJ)

all: 		$(NAME)

$(OBJ): 	$(SRCS)
			@gcc $(FLAGS) $(SRCS)

clean:
			@rm -rf $(OBJ)

fclean: 	clean
			@rm -rf $(NAME)

re: 		fclean all

.PHONY:		 all clean fclean re
