#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpearson <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/18 11:51:28 by dpearson          #+#    #+#              #
#    Updated: 2017/09/18 11:51:44 by dpearson         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	libft.a

HEADER		=	./includes

FILENAMES	=	ft_memset.c ft_memcpy.c ft_memalloc.c ft_bzero.c ft_memccpy.c  \
				ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c   \
				ft_striteri.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strequ.c \
				ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strcat.c ft_strcpy.c  \
				ft_strtrim.c ft_toupper.c ft_tolower.c ft_putnbr.c             \
				ft_putchar.c ft_isalnum.c ft_isalpha.c ft_isascii.c            \
				ft_isprint.c ft_isdigit.c ft_isprint.c ft_putstr.c ft_putendl.c\
				ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c  \
				ft_itoa.c ft_memchr.c ft_memcmp.c ft_strdup.c ft_strncpy.c     \
				ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strcmp.c \
				ft_strcmp.c ft_strncmp.c ft_strstr.c ft_strnstr.c ft_strsplit.c\
				ft_atoi.c ft_memmove.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c  \
				ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_nbr_len.c ft_iseven.c  \
				ft_isodd.c ft_isupper.c ft_islower.c ft_realloc.c ft_strcdup.c \
				ft_strndup.c

SRC 		= 	$(addprefix srcs/, $(FILENAMES))

OBJECTS		= ${FILENAMES:c=o}

OPTION		=	-c -I $(HEADER)

all : $(NAME)

$(NAME):
	@ gcc -Wall -Wextra -Werror $(OPTION) $(SRC)
	@ ar rcs $(NAME) $(OBJECTS)
	@ ranlib $(NAME)

clean:
	@ rm -f $(OBJECTS)

fclean: clean
	@ rm -f $(NAME)

re: fclean all