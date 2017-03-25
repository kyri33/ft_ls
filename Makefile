# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kioulian <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/19 12:39:08 by kioulian          #+#    #+#              #
#    Updated: 2017/03/25 14:03:47 by kioulian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = main.c ftls.c libft/libft.a list.c sort.c

FLAGS = clang -Wall -Werror -Wextra -g -I includes -o

all : $(NAME)

$(NAME) :
	@make -C libft/ fclean && make -C libft/ all
	@$(FLAGS) $(NAME) $(SRC)

clean:
	@make -C libft/ clean

fclean :
	@make -C libft/ fclean
	@rm -f $(NAME)

re : fclean all
