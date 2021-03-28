/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_quick_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 14:09:13 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/28 20:32:00 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void		sort_b(t_stack *a, t_stack *b, int b_size, t_array **instructions)
{
	int	a_size;

	if (b_size > 3)
		a_size = partition_b(a, b, b_size, instructions);
	else
		a_size = 0;
	if (b_size - a_size > 3)
		sort_b(a, b, b_size - a_size, instructions);
	else if (b_size - a_size < stack_size(b))
		sort_top(b, b_size - a_size, 0, instructions);
	else
		stack_sort_three(b, 0, instructions);
	if (a_size > 3)
		sort_a(a, b, a_size, instructions);
	else if (a_size < stack_size(a))
		sort_top(a, a_size, 1, instructions);
	else
		stack_sort_three(a, 1, instructions);
	while (a_size-- > 0)
		pb(a, b, instructions);
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
	else if (a_size - b_size < stack_size(a))
		sort_top(a, a_size - b_size, 1, instructions);
	else
		stack_sort_three(a, 1, instructions);
	if (b_size > 3)
		sort_b(a, b, b_size, instructions);
	else if (b_size < stack_size(b))
		sort_top(b, b_size, 0, instructions);
	else
		stack_sort_three(b, 0, instructions);
	while (b_size-- > 0)
		pa(a, b, instructions);
}

void		stack_quick_sort(t_stack *a, t_stack *b, t_array **instructions)
{
	sort_a(a, b, stack_size(a), instructions);
}
