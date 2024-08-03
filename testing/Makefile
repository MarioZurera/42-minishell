# COMMANDS #
AR			= ar
CC			= clang
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
RM_DIR		= rm -rf

# DIRECTORIES #
SRC_DIR		= src
OBJ_DIR		= objects
INC_DIR		= includes

# NAME #
NAME		= libtest.a
CAP_NAME	= $(shell echo $(NAME) | awk '{print toupper(substr($$0, 1, 1)) substr($$0, 2)}')

# NORMAL #
SRC_NAME	= test.c
OBJ_NAME	= $(notdir $(SRC_NAME:.c=.o))
SRCS		= $(addprefix $(SRC_DIR)/,$(SRC_NAME))
OBJS		= $(addprefix $(OBJ_DIR)/,$(OBJ_NAME))

# COLORS #
C_GREEN		= \033[0;32m
C_RED		= \033[0;31m
C_BLUE		= \033[0;34m
C_DEF		= \033[0m


###############################################################################
# ====================== # Makefile done by mzurera- # ====================== #
###############################################################################


all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(SRC_DIR)
	@mkdir -p $(INC_DIR)
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $@

$(NAME): $(OBJS)
	@echo "$(C_BLUE)Builing $(NAME)...$(C_DEF)"
	@$(AR) rcs $(NAME) $(OBJS)
	@echo "$(C_GREEN)$(CAP_NAME) built and ready to go!$(C_DEF)"

clean:
	@$(RM_DIR) $(OBJ_DIR)
	@$(RM_DIR) $(BUILD_DIR)
	@echo "$(C_RED)Cleaned objects folder!$(C_DEF)"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)
	@echo "$(C_RED)Cleaned $(NAME) program!$(C_DEF)"

re: fclean all

test:
	@$(CC) $(CFLAGS) -I $(INC_DIR) -c test_test.c -o test_test.o
	@$(CC) $(CFLAGS) test_test.o -L. -ltest -o test
	@echo "============= TEST COMPILED ============="
	@./test
	@echo
	@$(RM) test_test.o
	@$(RM) test

.PHONY: all clean fclean re .c.o
