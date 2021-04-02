/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:49:19 by skoskine          #+#    #+#             */
/*   Updated: 2021/04/02 15:52:50 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"
# include "array.h"

# define OPTIMIZE_ROTATIONS 1

t_stack		*read_arguments(int argc, char **argv);

void		sort_three(t_stack *stack, int size, int a,
			t_array **instructions);
void		sort_top(t_stack *stack, int count, int a, t_array **instructions);
void		sort_a_top_three(t_stack *stack, t_array **instructions);
void		sort_b_top_three(t_stack *stack, t_array **instructions);
void		stack_bubble_sort(t_stack *a, t_stack *b, t_array **instructions);
void		stack_quick_sort(t_stack *a, t_stack *b, t_array **instructions);
void		quick_sort_a(t_stack *a, t_stack *b, int a_size,
			t_array **instructions);
int			partition_a(t_stack *a, t_stack *b, int a_size,
			t_array **instructions);
int			partition_b(t_stack *a, t_stack *b, int b_size,
			t_array **instructions);
void		stack_merge_sort(t_stack *a, t_stack *b, t_array **instructions);
void		merge_sort_a(t_stack *a, t_stack *b, int a_size,
			t_array **instructions);
void		merge_sort_b(t_stack *a, t_stack *b, int b_size,
			t_array **instructions);
void		rotate_to_bottom(t_stack *stack, int size, int a,
			t_array **instructions);
int			stack_is_ordered(t_stack *stack, int ascending);
int			stack_top_is_ordered(t_stack *stack, int size, int ascending);
void		print_stacks(t_stack *a, t_stack *b, int verbose, char *instr);

void		print_instructions(t_array *arr);
void		optimize_instructions(t_array *arr, int stack_size);
void		check_rotations(t_array *arr, int a_size);

void		sa(t_stack *a, t_array **arr);
void		sb(t_stack *b, t_array **arr);
void		ss(t_stack *a, t_stack *b, t_array **arr);
void		pa(t_stack *a, t_stack *b, t_array **arr);
void		pb(t_stack *a, t_stack *b, t_array **arr);
void		ra(t_stack *a, t_array **arr);
void		rb(t_stack *b, t_array **arr);
void		rr(t_stack *a, t_stack *b, t_array **arr);
void		rra(t_stack *a, t_array **arr);
void		rrb(t_stack *b, t_array **arr);
void		rrr(t_stack *a, t_stack *b, t_array **arr);

#endif
