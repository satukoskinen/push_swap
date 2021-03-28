/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_quick_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 14:09:13 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/28 13:05:27 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int			select_pivot(t_stack *stack, int size)
{
	int	max;
	int	min;
	int	i;

	i = 0;
	max = stack_peek(stack);
	min = stack_peek(stack);
	while (i < size)
	{
		if (max < *(stack->top - i))
			max = *(stack->top - i);
		if (min > *(stack->top - i))
			min = *(stack->top - i);
		i++;
	}
	return ((max + min) / 2);
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

static int	partition_b(t_stack *a, t_stack *b, int b_size,
t_array **instructions)
{
	int	pivot;
	int i;
	int	a_size;

	pivot = select_pivot(b, b_size);
	i = 0;
	a_size = 0;
	while (i < b_size)
	{
		if (stack_max(b, b_size - i) < pivot)
			break ;
		if (stack_peek(b) >= pivot)
		{
			pa(a, b, instructions);
			a_size++;
		}
		else
			rb(b, instructions);
		i++;
	}
	while (i-- - a_size > 0 && b_size != (stack_size(b) + a_size))
		rrb(b, instructions);
	return (a_size);
}

void		sort_b(t_stack *a, t_stack *b, int b_size, t_array **instructions)
{
	int	a_size;

	if (b_size > 3)
		a_size = partition_b(a, b, b_size, instructions);
	else
		a_size = 0;
	if (b_size - a_size > 3)
		sort_b(a, b, b_size - a_size, instructions);
	else
		sort_top(b, b_size - a_size, 0, instructions);
	if (a_size > 3)
		sort_a(a, b, a_size, instructions);
	else
		sort_top(a, a_size, 1, instructions);
	while (a_size-- > 0)
		pb(a, b, instructions);
}

static int	partition_a(t_stack *a, t_stack *b, int a_size,
t_array **instructions)
{
	int	pivot;
	int i;
	int	b_size;

	pivot = select_pivot(a, a_size);
	i = 0;
	b_size = 0;
	while (i < a_size)
	{
		if (stack_min(a, a_size - i) > pivot)
			break ;
		if (stack_peek(a) <= pivot)
		{
			pb(a, b, instructions);
			b_size++;
		}
		else
			ra(a, instructions);
		i++;
	}
	while (i-- - b_size > 0 && a_size != (stack_size(a) + b_size))
		rra(a, instructions);
	return (b_size);
}

void		sort_a(t_stack *a, t_stack *b, int a_size, t_array **instructions)
{
	int	b_size;

	if (a_size > 3)
		b_size = partition_a(a, b, a_size, instructions);
	else
		b_size = 0;
	if (a_size - b_size > 3)
		sort_a(a, b, a_size - b_size, instructions);
	else
		sort_top(a, a_size - b_size, 1, instructions);
	if (b_size > 3)
		sort_b(a, b, b_size, instructions);
	else
		sort_top(b, b_size, 0, instructions);
	while (b_size-- > 0)
		pa(a, b, instructions);
}

void		stack_quick_sort(t_stack *a, t_stack *b, t_array **instructions)
{
	sort_a(a, b, stack_size(a), instructions);
}
