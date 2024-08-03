CC		= gcc
SRCS	= ft_abs.c ft_alnum.c ft_atoi.c ft_bzero.c ft_calloc.c \
		  ft_isalpha.c ft_isascii.c ft_isdigit.c ft_islower.c \
		  ft_isprint.c ft_isspace.c ft_isupper.c ft_itoa.c ft_max.c \
		  ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
		  ft_memrcpy.c ft_memset.c ft_min.c ft_putchar_fd.c ft_putendl_fd.c \
		  ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strcmp.c \
		  ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
		  ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
		  ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_nbrlen.c ft_unbrlen.c \
		  ft_putunbr_fd.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
		  ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c \
		  ft_lstsize.c ft_strdelchr.c ft_strnchr.c ft_printf.c \
		  ft_printf_utils.c ft_printf_utils2.c ft_printf_utils3.c ft_printf_utils4.c \
		  ft_printf_utils5.c ft_lstdelone.c ft_count_words.c ft_strchr_i.c ft_get_next_line.c \
		  ft_minf.c ft_maxf.c ft_mind.c ft_maxd.c ft_atol.c ft_atol_base.c ft_atohex.c ft_str_in_trim.c
OBJS	= $(SRCS:.c=.o)
NAME	= libft.a
CFLAGS	= -Wall -Wextra -Werror
LIBC	= ar rcs
RM		= rm -f

# COLORS #
C_GREEN	= \033[0;32m
C_RED	= \033[0;31m
C_BLUE	= \033[0;34m
C_DEF	= \033[0m

.c.o:
	@$(CC) $(CFLAGS) -c $< -I ./ -o $@

$(NAME): $(OBJS)
	@echo "$(C_BLUE)Compiling libft 2nd version...$(C_DEF)"
	@$(LIBC) $(NAME) $(OBJS)
	@echo "$(C_GREEN)Libft compiled!$(C_DEF)"

all: $(NAME)

clean:
	@$(RM) $(OBJS)
	@echo "$(C_RED)Libft cleaned!$(C_DEF)"

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all .c.o clean fclean re
