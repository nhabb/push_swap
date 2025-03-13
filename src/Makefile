FLAG = -Wall -Wextra -Werror

NAME = push_swap

SRC = atoi.c \
      cost.c \
      error_handling.c \
      minisort_helper.c \
      input.c \
      main.c \
	linked_list.c \
      many_args.c \
      minisort.c \
      quotedargs.c \
      operations_helper.c \
      push.c \
	quoted_helper.c \
      rev_rotate.c \
      rotate.c \
      swap.c \
      target.c \
      turk_helper.c\
	turk.c \
	utils.c \
      one_argument.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(FLAG) -o $(NAME) $(OBJ)
	@echo "$(NAME) created"

%.o: %.c
	@gcc $(FLAG) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "OBJ deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all

.PHONY: all clean fclean re

