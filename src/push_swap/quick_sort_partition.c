/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_partition.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 20:31:17 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/29 20:41:34 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	select_pivot_median(t_stack *stack, int size)
{
	int	i;
	int	j;
	int	smaller;

	i = 0;
	while (i < size)
	{
		j = 0;
		smaller = 0;
		while (j < size)
		{
			if (*(stack->top - j) < *(stack->top - i))
				smaller++;
			if (smaller > size / 2)
				break ;
			j++;
		}
		if (smaller == size / 2)
			break ;
		i++;
	}
	return (*(stack->top - i));
}

/*
** static int	select_pivot_avg(t_stack *stack, int size)
** {
** 	double	sum;
** 	int		i;
**
** 	sum = 0;
** 	i = 0;
** 	while (i < size)
** 	{
** 		sum += *(stack->top - i);
** 		i++;
** 	}
** 	return (sum / size);
** }
*/

/*
** static int	select_pivot_median_of_three(t_stack *stack, int size)
** {
**	int	hi;
**	int	mid;
**	int	lo;
**
**	hi = *(stack->top);
**	mid = *(stack->top - size / 2);
**	lo = *(stack->top - (size - 1));
**	if ((hi > mid && hi < lo) || (hi < mid && hi > lo))
**		return (hi);
**	else if ((mid > hi && mid < lo) || (mid < hi && mid > lo))
**		return (mid);
**	else
**		return (lo);
**}
*/

int			partition_b(t_stack *a, t_stack *b, int b_size,
t_array **instructions)
{
	int	pivot;
	int i;
	int	a_size;

	pivot = select_pivot_median(b, b_size);
	i = 0;
	a_size = 0;
	while (i < b_size)
	{
		if (stack_peek(b) >= pivot)
		{
			pa(a, b, instructions);
			a_size++;
		}
		else
			rb(b, instructions);
		i++;
	}
	b_size = b_size - a_size;
	while (i-- > a_size && b_size != stack_size(b))
		rrb(b, instructions);
	return (a_size);
}

int			partition_a(t_stack *a, t_stack *b, int a_size,
t_array **instructions)
{
	int	pivot;
	int i;
	int	b_size;

	pivot = select_pivot_median(a, a_size);
	i = 0;
	b_size = 0;
	while (i < a_size)
	{
		if (stack_peek(a) <= pivot)
		{
			pb(a, b, instructions);
			b_size++;
		}
		else
			ra(a, instructions);
		i++;
	}
	a_size = a_size - b_size;
	while (i-- > b_size && a_size != stack_size(a))
		rra(a, instructions);
	return (b_size);
}
