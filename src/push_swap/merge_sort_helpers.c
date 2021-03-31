/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:32:35 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/31 17:44:59 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort_three(t_stack *stack, int size, int a,
t_array **instructions)
{
	if (size == 3)
		stack_sort_three(stack, size, a, instructions);
	else if (size == 2 && a && *(stack->top) > *(stack->top - 1))
		sa(stack, instructions);
	else if (size == 2 && !a && *(stack->top) < *(stack->top - 1))
		sb(stack, instructions);
}

void		rotate_to_bottom(t_stack *stack, int size, int a,
t_array **instructions)
{
	int	i;

	i = 0;
	while (i++ < size && size != stack_size(stack))
	{
		if (a)
			ra(stack, instructions);
		else
			rb(stack, instructions);
	}
}
