/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bubble_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 09:05:52 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/27 18:30:38 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

static void	push_and_swap_to_a(t_stack *a, t_stack *b)
{
	int	swap;

	if (stack_is_empty(a) || stack_peek(a) > stack_peek(b))
		swap = 0;
	else
		swap = 1;
	pa(a, b);
	ft_putstr("pa\n");
	if (swap)
	{
		sa(a);
		ft_putstr("sa\n");
	}
}

static void	push_and_swap_to_b(t_stack *a, t_stack *b)
{
	int	swap;

	if (stack_is_empty(b) || stack_peek(a) > stack_peek(b))
		swap = 0;
	else
		swap = 1;
	pb(a, b);
	ft_putstr("pb\n");
	if (swap)
	{
		sb(b);
		ft_putstr("sb\n");
	}
}

void		stack_bubble_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	size;

	i = 0;
	size = stack_size(a);
	while (i < size)
	{
		while (!stack_is_empty(a))
		{
			push_and_swap_to_b(a, b);
			if (stack_is_ordered(a, 1) && stack_is_ordered(b, 0))
				break ;
		}
		while (!stack_is_empty(b))
		{
			push_and_swap_to_a(a, b);
		}
		if (stack_is_ordered(a, 1))
			break ;
		i++;
	}
}
