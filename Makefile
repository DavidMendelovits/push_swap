# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 14:49:34 by dmendelo          #+#    #+#              #
#    Updated: 2018/11/07 16:03:56 by dmendelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
		@make -C checker
		@make -C push_swap

clean:
		@make -C checker clean
		@make -C push_swap clean

fclean: clean
		@make -C checker fclean
		@make -C push_swap fclean

re: fclean all
