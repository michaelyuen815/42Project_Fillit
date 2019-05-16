# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lzhansha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/16 12:07:48 by lzhansha          #+#    #+#              #
#    Updated: 2019/05/16 12:09:23 by lzhansha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCS = src/*.c
HDRS = includes/fillit.h includes/libft/libft.h

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror $(SRCS) -I $(HDRS) -o $(NAME)

clean:
	/bin/rm -rf *.o

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
