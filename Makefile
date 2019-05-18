# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lzhansha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/16 12:07:48 by lzhansha          #+#    #+#              #
#    Updated: 2019/05/16 12:36:21 by lzhansha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCS = srcs/*.c

LIBDIR = libft
SRCDIR = srcs

all: $(NAME)

$(NAME):
	Make -C $(LIBDIR)
	gcc -Wall -Wextra -Werror -o $(NAME) $(SRCS) -I $(SRCDIR) -I $(LIBDIR) -L $(LIBDIR) -lft 

clean:
	/bin/rm -rf *.o
	Make clean -C $(LIBDIR)

fclean: clean
	/bin/rm -rf $(NAME)
	Make fclean -C $(LIBDIR)

re: fclean all
