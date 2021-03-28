/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:48:47 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/28 11:02:06 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "stack.h"
# include "array.h"

t_stack		*read_arguments(int argc, char **argv);
int			get_checker_instructions(t_stack *a, t_stack *b, int verbose);
int			stack_is_ordered(t_stack *stack, int ascending);
void		print_stacks(t_stack *a, t_stack *b, char *instruction);

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
