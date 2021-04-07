# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/20 11:01:30 by skoskine          #+#    #+#              #
#    Updated: 2021/04/07 14:07:16 by skoskine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECKER = checker

SRC_DIR = src
OBJ_DIR = obj
DEP_DIR = .deps

STACK_SRC = $(addprefix $(SRC_DIR)/stack/, \
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

ARR_SRC = $(addprefix $(SRC_DIR)/array/, \
	array_add.c \
	array_del.c \
	array_get.c \
	array_indexof.c \
	array_insert.c \
	array_is_empty.c \
	array_new.c \
	array_remove.c \
	array_size.c \
)

COMMON_SRC = $(addprefix $(SRC_DIR)/common/, \
	read_arguments.c \
	instructions_a.c \
	instructions_b.c \
	instructions_ab.c \
	stack_is_ordered.c \
	print_stacks.c \
)

PUSH_SWAP_SRC = $(addprefix $(SRC_DIR)/push_swap/, \
	push_swap.c \
	bubble_sort.c \
	quick_sort.c \
	quick_sort_partition.c \
	merge_sort.c \
	merge_sort_helpers.c \
	sort_top.c \
	sort_three.c \
	print_instructions.c \
	optimize_instructions.c \
	optimize_rotations.c \
)

CHECKER_SRC = $(addprefix $(SRC_DIR)/checker/, \
	checker.c \
	checker_instructions.c \
)

PUSH_SWAP_SRC_ALL = $(STACK_SRC) $(ARR_SRC) $(COMMON_SRC) $(PUSH_SWAP_SRC)
CHECKER_SRC_ALL = $(STACK_SRC) $(ARR_SRC) $(COMMON_SRC) $(CHECKER_SRC)
SRC = $(STACK_SRC) $(ARR_SRC) $(COMMON_SRC) $(PUSH_SWAP_SRC) $(CHECKER_SRC)

PUSH_SWAP_OBJ = $(subst $(SRC_DIR), $(OBJ_DIR), $(PUSH_SWAP_SRC_ALL:.c=.o))
CHECKER_OBJ = $(subst $(SRC_DIR), $(OBJ_DIR), $(CHECKER_SRC_ALL:.c=.o))

LIBFT = libft/libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g
CPPFLAGS = -I libft -I $(SRC_DIR)/array -I $(SRC_DIR)/checker \
	-I $(SRC_DIR)/common -I $(SRC_DIR)/push_swap -I $(SRC_DIR)/stack
LDLIBS = -lft
LDFLAGS = -L libft #-fsanitize=address
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEP_DIR)/$*.d

COMPILE.c = $(CC) $(DEPFLAGS) $(CFLAGS) $(CPPFLAGS) -c

all: $(NAME) $(CHECKER)

$(NAME): $(PUSH_SWAP_OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) -o $@ $(PUSH_SWAP_OBJ) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

$(CHECKER): $(CHECKER_OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) -o $@ $(CHECKER_OBJ) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(DEP_DIR)/%.d | $(DEP_DIR) $(OBJ_DIR)
	@$(COMPILE.c) -o $@ $<

$(DEP_DIR): ; @mkdir -p $@/stack $@/array $@/push_swap $@/checker $@/common

$(OBJ_DIR): ; @mkdir -p $@/stack $@/array $@/push_swap $@/checker $@/common

DEPFILES = $(subst $(SRC_DIR), $(DEP_DIR), $(SRC:.c=.d))
$(DEPFILES):

$(LIBFT):
	$(MAKE) -C libft

clean:
	@$(MAKE) -C libft clean
	@rm -rf $(OBJ_DIR) $(DEP_DIR)

fclean: clean
	@$(MAKE) -C libft fclean
	@rm -f $(NAME) $(CHECKER)

re: fclean all

.PHONY: all clean fclean re

include $(wildcard $(DEPFILES))