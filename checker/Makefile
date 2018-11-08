# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmendelo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 15:53:57 by dmendelo          #+#    #+#              #
#    Updated: 2018/11/07 16:04:26 by dmendelo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

LIBFT = ../libft/libft.a

SRC_DIR = src
SRC = checker

INC = -I inc -I ../libft/

OBJ_DIR = $(SRC_DIR)/obj
OBJ = $(patsubst %, $(OBJ_DIR)/%.o, $(SRC))

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
		@printf "\nCompiling checker\n"
		@gcc $(CFLAGS) $(LIBFT) $(OBJ) -o $(NAME)
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
		@echo "checker D E S T R O Y E D"

re: fclean all
