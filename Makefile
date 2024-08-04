# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/04 00:35:09 by aflorido          #+#    #+#              #
#    Updated: 2024/08/04 00:53:15 by aflorido         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Variables ---
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
NAME	= minishell
RM		= rm -rf

# --- Sources ---
INC		= -Iincludes
SRC		= main.c
OBJ		= $(SRC:.c=.o)

# --- Targets ---
%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $^ -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re