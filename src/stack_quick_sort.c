/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_quick_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 14:09:13 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/27 18:46:32 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int		select_pivot(t_stack *stack, int size)
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

void	sort_top(t_stack *stack, int count, int asc, int a)
{
	if (count <= 1)
		return ;
	else if (count == 2 && ((asc && *(stack->top) > *(stack->top - 1))
		|| (!asc && *(stack->top) < *(stack->top - 1))))
	{
		stack_swap(stack);
		if (a && asc)
			ft_putstr("sa\n");
		else
			ft_putstr("sb\n");
	}
	else if (count == 3 && a)
		sort_a_three(stack);
	else if (count == 3 && !a)
		sort_b_three(stack);
}

void	sort_b(t_stack *a, t_stack *b, int b_size)
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
			pa(a, b);
			ft_putstr("pa\n");
			a_size++;
		}
		else
		{
			rb(b);
			ft_putstr("rb\n");
		}
		i++;
	}
	while (i-- - a_size > 0 && b_size != (stack_size(b) + a_size))
	{
		rrb(b);
		ft_putstr("rrb\n");
	}
	if (b_size - a_size > 3)
		sort_b(a, b, b_size - a_size);
	else
		sort_top(b, b_size - a_size, 0, 0);
	if (a_size > 3)
		sort_a(a, b, a_size);
	else
		sort_top(a, a_size, 1, 1);
	while (a_size-- > 0)
	{
		pb(a, b);
		ft_putstr("pb\n");
	}
}

void	sort_a(t_stack *a, t_stack *b, int a_size)
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
			pb(a, b);
			ft_putstr("pb\n");
			b_size++;
		}
		else
		{
			ra(a);
			ft_putstr("ra\n");
		}
		i++;
	}
	while (i-- - b_size > 0 && a_size != (stack_size(a) + b_size))
	{
		rra(a);
		ft_putstr("rra\n");
	}
	if (a_size - b_size > 3)
		sort_a(a, b, a_size - b_size);
	else
		sort_top(a, a_size - b_size, 1, 1);
	if (b_size > 3)
		sort_b(a, b, b_size);
	else
		sort_top(b, b_size, 0, 0);
	while (b_size-- > 0)
	{
		pa(a, b);
		ft_putstr("pa\n");
	}
}

void	stack_quick_sort(t_stack *a, t_stack *b)
{
	sort_a(a, b, stack_size(a));
}
