/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 16:24:03 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/31 17:39:39 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			split_b_to_two(t_stack *a, t_stack *b, int b_size,
t_array **instructions)
{
	int	a_size;

	a_size = 0;
	while (a_size < b_size)
	{
		pa(a, b, instructions);
		a_size++;
		b_size--;
	}
	return (a_size);
}

void		merge_sort_b(t_stack *a, t_stack *b, int b_size,
t_array **instructions)
{
	int	a_size;

	if (b_size <= 3)
	{
		sort_stack(b, b_size, 0, instructions);
		return ;
	}
	a_size = split_b_to_two(a, b, b_size, instructions);
	b_size = b_size - a_size;
	merge_sort_b(a, b, b_size, instructions);
	merge_sort_a(a, b, a_size, instructions);
	rotate_to_bottom(b, b_size, 0, instructions);
	while (a_size > 0 && b_size > 0)
	{
		if (b->arr[0] < stack_peek(a) && b_size-- > 0)
			rrb(b, instructions);
		else if (a_size-- > 0)
			pb(a, b, instructions);
	}
	while (a_size-- > 0)
		pb(a, b, instructions);
	while (b_size-- > 0)
		rrb(b, instructions);
}

int			split_a_to_two(t_stack *a, t_stack *b, int a_size,
t_array **instructions)
{
	int	b_size;

	b_size = 0;
	while (b_size < a_size)
	{
		pb(a, b, instructions);
		b_size++;
		a_size--;
	}
	return (b_size);
}

void		merge_sort_a(t_stack *a, t_stack *b, int a_size,
t_array **instructions)
{
	int	b_size;

	if (a_size <= 3)
	{
		sort_stack(a, a_size, 1, instructions);
		return ;
	}
	b_size = split_a_to_two(a, b, a_size, instructions);
	a_size = a_size - b_size;
	merge_sort_b(a, b, b_size, instructions);
	merge_sort_a(a, b, a_size, instructions);
	rotate_to_bottom(a, a_size, 1, instructions);
	while (a_size > 0 && b_size > 0)
	{
		if (a->arr[0] > stack_peek(b) && a_size-- > 0)
			rra(a, instructions);
		else if (b_size-- > 0)
			pa(a, b, instructions);
	}
	while (a_size-- > 0)
		rra(a, instructions);
	while (b_size-- > 0)
		pa(a, b, instructions);
}

void		stack_merge_sort(t_stack *a, t_stack *b, t_array **instructions)
{
	merge_sort_a(a, b, stack_size(a), instructions);
}
