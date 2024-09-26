NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra -g 
LIBFT = ./libft/libft.a

SRC = push_swap.c \
	ft_check_arg.c \
	ft_add_back.c \
	ft_free.c \
	ft_error_print.c \
	ft_stack_new.c \
	ft_check_dup.c \
	ft_check_sorted.c \
	lst_utils.c \
	operations.c \
	operations_2.c \
	algo_quick.c \

all: $(NAME)

$(NAME): $(SRC:.c=.o)
	@$(MAKE) --no-print-directory -C ./libft
	@echo "\033[1m \e[32m LIBFT done \033[0m "
	@$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)
	@echo "\033[1m \e[32m Ready to PUSH_SWAP \033[0m"

clean:
	@$(MAKE) clean -C ./libft
	@rm -rf $(SRC:.c=.o)
	@echo "\033[1m \e[32m OBJ deleted \033[0m"

fclean: clean
	@$(MAKE) fclean -C ./libft
	@rm -rf $(NAME)
	@echo "\033[1m \e[32m $(NAME) deleted \033[0m"

re: fclean all

.PHONY: all, clean, fclean, re
