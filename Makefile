#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpearson <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 03:40:05 by dpearson          #+#    #+#              #
#    Updated: 2017/11/08 03:40:08 by dpearson         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	fdf

LIBS		=	./libs

LIBFT_DIR	=	$(LIBS)/libft

MLX_DIR		=	$(LIBS)/miniLibX

INCLUDES	=	./includes

CFLAGS		+=	-Wall -Wextra -Werror
CFLAGS		+=	-I $(LIBFT_DIR)/ -I $(MLX_DIR) -I $(INCLUDES)
CFLAGS		+=	-L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

FILENAMES	=	main.c parse.c img.c draw.c pairs.c

SRC = $(addprefix srcs/, $(FILENAMES))

LIBFT		=	$(LIBFT_DIR)/libft.a

MLX			=	$(MLX_DIR)/libmlx.a

all: $(NAME)

$(LIBFT):
		@make -C $(LIBFT_DIR)

$(MLX):
		@make -C $(MLX_DIR)

$(NAME): $(LIBFT) $(MLX)
		@gcc $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)

clean:
		@make -C $(LIBFT_DIR) clean
		@make -C $(MLX_DIR) clean
fclean: clean
		@rm -rf $(NAME)
		@make -C $(LIBFT_DIR) fclean
re: fclean all