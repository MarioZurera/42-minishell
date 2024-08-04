# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tests.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aflorido <aflorido@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/04 18:26:52 by aflorido          #+#    #+#              #
#    Updated: 2024/08/04 18:27:20 by aflorido         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# TODO: Remove tests before submit
TEST_SRC	= tests/main.c \
		parse/dequote.c \
		utils/ft_strlen.c utils/ft_strdup.c\
		tests/test_dequoted.c
TEST_OBJ	= $(TEST_SRC:.c=.o)

# TODO: Remove tests before submit
test: $(TEST_OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(TEST_OBJ)
	@clear && ./$(NAME)
	@$(RM) $(NAME) $(TEST_OBJ)
