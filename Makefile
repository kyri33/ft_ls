# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kioulian <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/19 12:39:08 by kioulian          #+#    #+#              #
#    Updated: 2016/06/19 17:36:32 by kioulian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = main.c ftls.c libft.a

FLAGS = clang -Wall -Werror -Wextra -o

all : $(NAME)

$(NAME) :
	$(FLAGS) $(NAME) $(SRC)

fclean :
	rm $(NAME)

re : fclean all
