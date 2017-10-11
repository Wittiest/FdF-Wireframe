NAME	=	fdf

CFLAGS	+=	-Wall -Wextra -Werror
CFLAGS	+=	-I	libft -I minilibx
CFLAGS	+=	-L./miniLibX -lmlx -framework OpenGL -framework AppKit

SRC		=	main.c

LIBFT	=	libft/libft.a

MLX		=	miniLibX/libmlx.a

all: $(NAME)

$(LIBFT):
		@make -C libft

$(MLX):
		@make -C miniLibX

$(NAME): $(LIBFT) $(MLX)
		@gcc $(CFLAGS) $(SRC) $(LIBA) -o $(NAME)

clean:
		@make -C libft clean
		@make -C miniLibX clean
fclean: clean
		@rm -rf $(NAME)
		@make -C libft fclean

re: fclean all