/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:49:19 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/28 12:38:20 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"
# include "array.h"

t_stack		*read_arguments(int argc, char **argv);
t_array		*sort_stack(t_stack *a, t_stack *b);
void		stack_bubble_sort(t_stack *a, t_stack *b, t_array **instructions);
void		stack_quick_sort(t_stack *a, t_stack *b, t_array **instructions);
int			stack_is_ordered(t_stack *stack, int ascending);

void		print_stacks(t_stack *a, t_stack *b, char *instruction);
void		print_instructions(t_array *arr);

void		optimise_instructions(t_array *arr);

void		sort_a(t_stack *a, t_stack *b, int a_size, t_array **instructions);
void		sort_b_three(t_stack *stack, t_array **instructions);
void		sort_a_three(t_stack *stack, t_array **instructions);

int			stack_max(t_stack *stack, int size);
int			stack_min(t_stack *stack, int size);

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
