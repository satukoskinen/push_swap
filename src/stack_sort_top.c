/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_top.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 14:21:41 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/28 15:11:11 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		ra(stack, instructions);
		sa(stack, instructions);
		rra(stack, instructions);
	}
	else if (v1 > v2 && v2 < v3 && v1 < v3)
		sa(stack, instructions);
	else if (v1 < v2 && v2 > v3)
	{
		ra(stack, instructions);
		sa(stack, instructions);
		rra(stack, instructions);
		sa(stack, instructions);
	}
	else if (v1 > v2 && v2 < v3 && v1 > v3)
	{
		sa(stack, instructions);
		ra(stack, instructions);
		sa(stack, instructions);
		rra(stack, instructions);
	}
	else if (v1 > v2 && v2 > v3 && v1 > v3)
	{
		sa(stack, instructions);
		ra(stack, instructions);
		sa(stack, instructions);
		rra(stack, instructions);
		sa(stack, instructions);
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
		rb(stack, instructions);
		sb(stack, instructions);
		rrb(stack, instructions);
	}
	else if (v1 < v2 && v2 > v3 && v1 > v3)
		sb(stack, instructions);
	else if (v1 > v2 && v2 < v3 && v1 < v3)
	{
		rb(stack, instructions);
		sb(stack, instructions);
		rrb(stack, instructions);
		sb(stack, instructions);
	}
	else if (v1 < v2 && v2 > v3 && v1 < v3)
	{
		sb(stack, instructions);
		rb(stack, instructions);
		sb(stack, instructions);
		rrb(stack, instructions);
	}
	else if (v1 < v2 && v2 < v3 && v1 < v3)
	{
		sb(stack, instructions);
		rb(stack, instructions);
		sb(stack, instructions);
		rrb(stack, instructions);
		sb(stack, instructions);
	}
}

void		sort_top(t_stack *stack, int count, int a, t_array **instructions)
{
	if (count <= 1)
		return ;
	else if (count == 2 && ((a && *(stack->top) > *(stack->top - 1))
		|| (!a && *(stack->top) < *(stack->top - 1))))
	{
		if (a)
			sa(stack, instructions);
		else
			sb(stack, instructions);
	}
	else if (count == 3 && a)
		sort_a_three(stack, instructions);
	else if (count == 3 && !a)
		sort_b_three(stack, instructions);
}
