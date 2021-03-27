/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:49:19 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/27 18:28:01 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"

enum		e_operation
{
	SA, RA, RRA, SB, RB, RRB, PA, PB, SS, RR, RRR
}			t_operation;

t_stack		*read_arguments(int argc, char **argv);
void		sort_stack(t_stack *a, t_stack *b);
void		stack_bubble_sort(t_stack *a, t_stack *b);
void		stack_quick_sort(t_stack *a, t_stack *b);
int			stack_is_ordered(t_stack *stack, int ascending);
void		print_stacks(t_stack *a, t_stack *b, char *instruction);

void		sort_b_three(t_stack *stack);
void		sort_a_three(t_stack *stack);

int			stack_max(t_stack *stack, int size);
int			stack_min(t_stack *stack, int size);

void		sa(t_stack *a);
void		sb(t_stack *b);
void		ss(t_stack *a, t_stack *b);
void		pa(t_stack *a, t_stack *b);
void		pb(t_stack *a, t_stack *b);
void		ra(t_stack *a);
void		rb(t_stack *b);
void		rr(t_stack *a, t_stack *b);
void		rra(t_stack *a);
void		rrb(t_stack *b);
void		rrr(t_stack *a, t_stack *b);

#endif
