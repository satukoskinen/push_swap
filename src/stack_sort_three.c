/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:45:21 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/28 15:37:35 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"
#include "libft.h"

static void	sort_a_three(t_stack *stack, t_array **instructions)
{
	int		v1;
	int		v2;
	int		v3;

	v1 = *(stack->top);
	v2 = *(stack->top - 1);
	v3 = *(stack->top - 2);
	if (v1 < v2 && v2 < v3 && v1 < v3)
		return ;
	else if (v1 < v2 && v2 > v3 && v1 < v3)
	{
		sa(stack, instructions);
		ra(stack, instructions);
	}
	else if (v1 > v2 && v2 < v3 && v1 < v3)
		sa(stack, instructions);
	else if (v1 < v2 && v2 > v3)
		rra(stack, instructions);
	else if (v1 > v2 && v2 < v3 && v1 > v3)
		ra(stack, instructions);
	else if (v1 > v2 && v2 > v3 && v1 > v3)
	{
		sa(stack, instructions);
		rra(stack, instructions);
	}
}

static void	sort_b_three(t_stack *stack, t_array **instructions)
{
	int	v1;
	int	v2;
	int	v3;

	v1 = *(stack->top);
	v2 = *(stack->top - 1);
	v3 = *(stack->top - 2);
	if (v1 > v2 && v2 > v3)
		return ;
	else if (v1 > v2 && v2 < v3 && v1 > v3)
	{
		sb(stack, instructions);
		rb(stack, instructions);
	}
	else if (v1 < v2 && v2 > v3 && v1 > v3)
		sb(stack, instructions);
	else if (v1 > v2 && v2 < v3 && v1 < v3)
		rrb(stack, instructions);
	else if (v1 < v2 && v2 > v3 && v1 < v3)
		rb(stack, instructions);
	else if (v1 < v2 && v2 < v3 && v1 < v3)
	{
		sb(stack, instructions);
		rrb(stack, instructions);
	}
}

void		stack_sort_three(t_stack *stack, int a, t_array **instructions)
{
	if (stack_size(stack) <= 1)
		return ;
	else if (stack_size(stack) == 2 && ((a && *(stack->top) > *(stack->top - 1))
		|| (!a && *(stack->top) < *(stack->top - 1))))
	{
		if (a)
			sa(stack, instructions);
		else
			sb(stack, instructions);
	}
	else if (stack_size(stack) == 3 && a)
		sort_a_three(stack, instructions);
	else if (stack_size(stack) == 3 && !a)
		sort_b_three(stack, instructions);
}
