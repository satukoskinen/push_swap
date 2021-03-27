# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/20 11:01:30 by skoskine          #+#    #+#              #
#    Updated: 2021/03/26 17:09:45 by skoskine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER = checker

SRC_DIR = src/
OBJ_DIR = obj/
HEADER_DIR = include/

STACK_SRC = $(addprefix $(SRC_DIR)stack/, \
	stack_del.c \
	stack_left_rotate.c \
	stack_new.c \
	stack_pop.c \
	stack_push.c \
	stack_peek.c \
	stack_right_rotate.c \
	stack_size.c \
	stack_is_empty.c \
	stack_swap.c \
)

PUSH_SWAP_SRC = $(STACK_SRC) $(addprefix $(SRC_DIR), \
	push_swap.c \
	read_arguments.c \
	sort_stack.c \
	stack_bubble_sort.c \
	stack_quick_sort.c \
	instructions_a.c \
	instructions_b.c \
	instructions_ab.c \
	stack_is_ordered.c \
	print_stacks.c \
)

CHECKER_SRC = $(STACK_SRC) $(addprefix $(SRC_DIR), \
	checker.c \
	read_arguments.c \
	checker_instructions.c \
	instructions_a.c \
	instructions_b.c \
	instructions_ab.c \
	stack_is_ordered.c \
	print_stacks.c \
)

PUSH_SWAP_OBJ = $(subst $(SRC_DIR), $(OBJ_DIR), $(PUSH_SWAP_SRC:.c=.o))

CHECKER_OBJ = $(subst $(SRC_DIR), $(OBJ_DIR), $(CHECKER_SRC:.c=.o))

LIBFT = libft/libft.a

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -fsanitize=address
CPPFLAGS = -I libft -I include
LDLIBS = -lft
LDFLAGS = -L libft -fsanitize=address

all: $(NAME) $(CHECKER)

$(NAME): $(OBJ_DIR) $(PUSH_SWAP_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(PUSH_SWAP_OBJ) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

$(CHECKER): $(OBJ_DIR) $(CHECKER_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(CHECKER_OBJ) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c -o $@ $< $(CPPFLAGS)

$(CHECKER_SRC): include/checker.h include/stack.h

$(PUSH_SWAP_SRC): include/push_swap.h include/stack.h

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)stack

$(LIBFT):
	$(MAKE) -C libft

clean:
	@$(MAKE) -C libft clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) -C libft fclean
	@rm -f $(NAME) $(CHECKER)

re: fclean all

.PHONY: all clean fclean re
