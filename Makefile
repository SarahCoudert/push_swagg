FLAGS=-Wall -Wextra -Werror

DEBUG =$(CFLAGS) -g

NAME=push_swap

CC=gcc

SRC_DIR = srcs

OBJ_DIR = objs

SRCS =	main.c \
		push_fnc.c \
		init.c

INC=libft/includes -I includes/

OBJS = $(SRCS:.c=.o)

SRC	:=	$(addprefix $(SRC_DIR)/, $(SRCS))

OBJ	:=	$(addprefix $(OBJ_DIR)/, $(OBJS))

RM=rm -f

RM_DIR=rm -rf


.PHONY: all, clean, fclean, re

all:
	@make $(NAME)

$(NAME): $(SRC)
	@make -C libft/
	@echo "\033[32mCompile all \".c\"\033[0m"
	@mkdir $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $(SRC) -I $(INC)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) libft/libft.a
	@mv $(OBJS) $(OBJ_DIR)
	@echo "\033[36mCreate $(NAME)\033[0m"

clean:
	@make -C libft/ clean
	@echo "\033[31mDelete all \".o\" in $(NAME)\033[0m"
	@$(RM_DIR) $(OBJ_DIR)

fclean: clean
	@make -C libft/ fclean
	@echo "\033[31mDelete $(NAME) executable\033[0m"
	@$(RM) $(NAME)

re: fclean all

debug:
	@make -C libft/ fclean
	@make -C libft/ debug
	@echo "\033[32mCompile all \".c\" with debug flag\033[0m"
	@$(CC) $(DEBUG) -c $(SRC) -I $(INC)
	@$(CC) $(DEBUG) -o $(NAME) $(OBJ) libft/libft.a
	@echo "\033[36mCreate $(NAME) with debug flag\033[0m"
