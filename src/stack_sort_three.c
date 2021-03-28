/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sort_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:45:21 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/28 12:42:12 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"
#include "libft.h"

void	sort_a_three(t_stack *stack, t_array **instructions)
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

void	sort_b_three(t_stack *stack, t_array **instructions)
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
