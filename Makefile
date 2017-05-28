# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kioulian <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/19 12:39:08 by kioulian          #+#    #+#              #
#    Updated: 2017/05/28 11:17:41 by kioulian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = main.c ftls.c list.c sort.c

FLAGS = clang -Wall -Werror -Wextra -g -I includes -o

all : $(NAME)

$(NAME) : $(SRC)
	@make -C libft/ fclean && make -C libft/ all
	@$(FLAGS) $(NAME) $(SRC) libft/libft.a

clean:
	@make -C libft/ clean

fclean :
	@make -C libft/ fclean
	@rm -f $(NAME)

re : fclean all
