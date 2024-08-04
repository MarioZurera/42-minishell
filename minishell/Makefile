# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/04 00:35:09 by aflorido          #+#    #+#              #
#    Updated: 2024/08/04 18:40:40 by aflorido         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Variables ---
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
NAME		= minishell
RM			= rm -rf

# --- Sources ---
INC			= -Iincludes

SRC			= main.c \
		parse/dequote.c \
		utils/ft_strlen.c utils/ft_strdup.c
OBJ			= $(SRC:.c=.o)

# --- Targets ---
%.o: %.c
	@$(CC) $(CFLAGS) $(INC) -c $^ -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

# If tests directory exists, add file tests/tests.mk to the Makefile
ifneq ($(wildcard tests),)
include tests/tests.mk
else
test:
	@echo "No tests directory found"
endif

.PHONY: all clean fclean re