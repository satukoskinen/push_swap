/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_top.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 14:21:41 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/31 19:58:57 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_rr(t_stack *stack, int a, t_array **instructions)
{
	if (a)
	{
		ra(stack, instructions);
		sa(stack, instructions);
		rra(stack, instructions);
		sa(stack, instructions);
	}
	else
	{
		rb(stack, instructions);
		sb(stack, instructions);
		rrb(stack, instructions);
		sb(stack, instructions);
	}
}

static void	sort_r(t_stack *stack, int a, t_array **instructions)
{
	if (a)
	{
		sa(stack, instructions);
		ra(stack, instructions);
		sa(stack, instructions);
		rra(stack, instructions);
	}
	else
	{
		sb(stack, instructions);
		rb(stack, instructions);
		sb(stack, instructions);
		rrb(stack, instructions);
	}
}

static void	sort_reverse(t_stack *stack, int a, t_array **instructions)
{
	if (a)
	{
		sa(stack, instructions);
		ra(stack, instructions);
		sa(stack, instructions);
		rra(stack, instructions);
		sa(stack, instructions);
	}
	else
	{
		sb(stack, instructions);
		rb(stack, instructions);
		sb(stack, instructions);
		rrb(stack, instructions);
		sb(stack, instructions);
	}
}

void		sort_a_top_three(t_stack *stack, t_array **instructions)
{
	int		v1;
	int		v2;
	int		v3;

	v1 = *(stack->top);
	v2 = *(stack->top - 1);
	v3 = *(stack->top - 2);
	if (v1 < v2 && v2 > v3 && v1 < v3)
	{
		ra(stack, instructions);
		sa(stack, instructions);
		rra(stack, instructions);
	}
	else if (v1 > v2 && v2 < v3 && v1 < v3)
		sa(stack, instructions);
	else if (v1 < v2 && v2 > v3)
		sort_rr(stack, 1, instructions);
	else if (v1 > v2 && v2 < v3 && v1 > v3)
		sort_r(stack, 1, instructions);
	else if (v1 > v2 && v2 > v3 && v1 > v3)
		sort_reverse(stack, 1, instructions);
}

void		sort_b_top_three(t_stack *stack, t_array **instructions)
{
	int	v1;
	int	v2;
	int	v3;

	v1 = *(stack->top);
	v2 = *(stack->top - 1);
	v3 = *(stack->top - 2);
	if (v1 > v2 && v2 < v3 && v1 > v3)
	{
		rb(stack, instructions);
		sb(stack, instructions);
		rrb(stack, instructions);
	}
	else if (v1 < v2 && v2 > v3 && v1 > v3)
		sb(stack, instructions);
	else if (v1 > v2 && v2 < v3 && v1 < v3)
		sort_rr(stack, 0, instructions);
	else if (v1 < v2 && v2 > v3 && v1 < v3)
		sort_r(stack, 0, instructions);
	else if (v1 < v2 && v2 < v3 && v1 < v3)
		sort_reverse(stack, 0, instructions);
}
