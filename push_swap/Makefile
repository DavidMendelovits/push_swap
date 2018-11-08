# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 15:53:57 by dmendelo          #+#    #+#              #
#    Updated: 2018/11/07 17:01:43 by dmendelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = ../libft/libft.a

SRC_DIR = src
SRC = push_swap

INC = -I inc -I ../libft/

OBJ_DIR = $(SRC_DIR)/obj
OBJ = $(patsubst %, $(OBJ_DIR)/%.o, $(SRC))

CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
		@printf "\nCompiling push_swap\n"
		@gcc $(CFLAGS) $(LIBFT) $(OBJ) -fsanitize=address -o $(NAME)
		@echo "Done!\n"

$(LIBFT):
		@printf "\nCompiling libft\n"
		@make -C ../libft
		@echo "Done!\n"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(OBJ_DIR)
		@echo "Compiling into object files...\n"
		@gcc $(CFLAGS) $(INC) -c $< -o $@

clean:
		@make -C ../libft clean
		@rm -rf $(OBJ_DIR)
		@echo "cllleeeeeaaned"

fclean: clean
		@make -C ../libft fclean
		@rm -f $(NAME)
		@echo "push_swap D E S T R O Y E D"

re: fclean all
