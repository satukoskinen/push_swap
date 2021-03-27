/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:48:47 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/27 18:38:29 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "stack.h"

enum		e_operation
{
	SA, RA, RRA, SB, RB, RRB, PA, PB, SS, RR, RRR
}			t_operation;

t_stack		*read_arguments(int argc, char **argv);
int			get_checker_instructions(t_stack *a, t_stack *b, int verbose);
int			stack_is_ordered(t_stack *stack, int ascending);
void		print_stacks(t_stack *a, t_stack *b, char *instruction);

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
