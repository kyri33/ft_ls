# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kioulian <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/19 12:39:08 by kioulian          #+#    #+#              #
#    Updated: 2016/11/19 13:02:15 by kioulian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = main.c ftls.c libft.a list.c

FLAGS = clang -Wall -Werror -Wextra -o

all : $(NAME)

$(NAME) :
	$(FLAGS) $(NAME) $(SRC)

fclean :
	rm $(NAME)

re : fclean all
