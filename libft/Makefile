#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chyuen <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/29 19:30:06 by chyuen            #+#    #+#              #
#    Updated: 2019/04/29 19:38:23 by chyuen           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRCS = 	./ft_strrchr.c \
		./ft_putstr.c \
		./ft_strcmp.c \
		./ft_strlcat.c \
		./ft_memcpy.c \
		./ft_memmove.c \
		./ft_strsplit.c \
		./ft_strncpy.c \
		./ft_lstmap.c \
		./ft_lstadd.c \
		./ft_striter.c \
		./ft_strstr.c \
		./ft_isdigit.c \
		./ft_putnbr.c \
		./ft_memccpy.c \
		./ft_strdel.c \
		./ft_memchr.c \
		./ft_bzero.c \
		./ft_isalnum.c \
		./ft_putstr_fd.c \
		./ft_lstiter.c \
		./ft_lstdelone.c \
		./ft_toupper.c \
		./ft_strcpy.c \
		./ft_lstnew.c \
		./ft_strdup.c \
		./ft_putnbr_fd.c \
		./ft_striteri.c \
		./ft_strmap.c \
		./ft_putendl_fd.c \
		./ft_memdel.c \
		./ft_strnstr.c \
		./ft_putchar.c \
		./ft_isascii.c \
		./ft_strlen.c \
		./ft_strsub.c \
		./ft_strnew.c \
		./ft_memalloc.c \
		./ft_putendl.c \
		./ft_strncat.c \
		./ft_itoa.c \
		./ft_strncmp.c \
		./ft_memcmp.c \
		./ft_strtrim.c \
		./ft_strequ.c \
		./ft_putchar_fd.c \
		./ft_memset.c \
		./ft_isalpha.c \
		./ft_strcat.c \
		./ft_tolower.c \
		./ft_strnequ.c \
		./ft_strjoin.c \
		./ft_atoi.c \
		./ft_strclr.c \
		./ft_strmapi.c \
		./ft_isprint.c \
		./ft_lstdel.c \
		./ft_strchr.c \

OSRCS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	gcc -c $(SRCS) -Wall -Wextra -Werror
	ar rcs $(NAME) $(OSRCS)

clean:
	/bin/rm -f $(OSRCS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
