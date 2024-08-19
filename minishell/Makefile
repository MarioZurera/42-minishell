# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aflorido <aflorido@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/04 00:35:09 by aflorido          #+#    #+#              #
#    Updated: 2024/08/19 18:24:23 by aflorido         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Variables ---
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
NAME		= minishell
RM			= rm -rf

# --- Sources ---
INC			= includes

BUILTIN		= cd.c exit.c pwd.c env.c
ENV			= free_env.c init_env.c print_env.c set_env.c \
	unset_env.c
EXEC		= 
PARSE 		= 
PROMPT		= banner.c build_prompt.c get_prompt.c
UTILS		= ft_isalpha.c ft_isdigit.c ft_isalnum.c \
	ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c \
	ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
	ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
	ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
	ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
	ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
	ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \
	ft_isspace.c ft_isxdigit.c ft_abs.c ft_putchar.c ft_putstr.c \
	ft_strcpy.c ft_imin.c ft_imax.c ft_dmin.c ft_dmax.c \
	ft_strcmp.c ft_free_all.c ft_or.c ft_strjoin_sep.c

SRC			= main.c
SRC			+= $(addprefix builtin/, $(BUILTIN))
SRC			+= $(addprefix env/, $(ENV))
SRC			+= $(addprefix exec/, $(EXEC))
SRC			+= $(addprefix parse/, $(PARSE))
SRC			+= $(addprefix prompt/, $(PROMPT))
SRC			+= $(addprefix utils/, $(UTILS))

OBJ			= $(SRC:.c=.o)

# --- Targets ---

# TODO: comprobar instalacion de readline,
# segun SO: usar brew o apt-get para
# instalar readline

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC) -c $^ -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -lreadline -lhistory

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

norm:
	@norminette $(SRC) $(INC)

# I don't like this rule, but it's useful for now
run: all
	@clear ; ./$(NAME)

.PHONY: all clean fclean re norm run