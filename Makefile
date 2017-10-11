NAME	=	fdf

CFLAGS	+=	-Wall -Wextra -Werror
CFLAGS	+=	-I	libft -I minilibx

SRC		=	main.c

LIBA	=	libft/libft.a

all: $(NAME)

$(LIBFT):
		@make -C libft

$(NAME): $(LIBFT)
	@gcc $(CFLAGS) $(SRC) $(LIBA) -o $(NAME)

clean:
	@make -C libft clean

fclean: clean
		@rm -rf $(NAME)
		@make -C libft fclean

re: fclean all