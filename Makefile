# Compiler and flags
CC = gcc
CFLAGS =  -g -Wno-dev

# Directories
LIBFT_DIR = libft
PRINTF_DIR = printf

# Libraries
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

# Source files
SRCS = push.c swap.c utils.c utils2.c handle_errors.c rotate.c rev_rotate.c miniswap.c sorting.c cost.c sorting_helpers.c helper.c main.c

# Object files
OBJS = $(SRCS:.c=.o)

# Executable
NAME = push_swap

# Rules
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

	@echo "$(NAME).a created"

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null
	@echo "libft.a created"

$(PRINTF):
	@$(MAKE) -C $(PRINTF_DIR) > /dev/null
	@echo "libftprintf.a created"

%.o: %.c push_swap.h
	@$(CC) $(CFLAGS) -c $< -o $@ > /dev/null

clean:
	@rm -f $(OBJS) > /dev/null
	@$(MAKE) -C $(LIBFT_DIR) clean > /dev/null
	@$(MAKE) -C $(PRINTF_DIR) clean > /dev/null
	@echo "Cleaned up object files"

fclean: clean
	@rm -f $(NAME) > /dev/null
	@$(MAKE) -C $(LIBFT_DIR) fclean > /dev/null
	@$(MAKE) -C $(PRINTF_DIR) fclean > /dev/null
	@echo "Cleaned up executable and libraries"

re: fclean all

.PHONY: all clean fclean re
