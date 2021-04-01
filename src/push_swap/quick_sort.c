/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 14:09:13 by skoskine          #+#    #+#             */
/*   Updated: 2021/04/01 10:58:43 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort_b(t_stack *a, t_stack *b, int b_size, t_array **instructions)
{
	int	a_size;

	if (b_size > 3)
		a_size = partition_b(a, b, b_size, instructions);
	else
		a_size = 0;
	b_size = b_size - a_size;
	if (b_size > 3)
		quick_sort_b(a, b, b_size, instructions);
	else
		sort_three(b, b_size, 0, instructions);
	if (a_size > 3)
		quick_sort_a(a, b, a_size, instructions);
	else
		sort_three(a, a_size, 1, instructions);
	while (a_size-- > 0)
		pb(a, b, instructions);
}

void	quick_sort_a(t_stack *a, t_stack *b, int a_size, t_array **instructions)
{
	int	b_size;

	if (a_size > 3)
		b_size = partition_a(a, b, a_size, instructions);
	else
		b_size = 0;
	a_size = a_size - b_size;
	if (a_size > 3)
		quick_sort_a(a, b, a_size, instructions);
	else
		sort_three(a, a_size, 1, instructions);
	if (b_size > 3)
		quick_sort_b(a, b, b_size, instructions);
	else
		sort_three(b, b_size, 0, instructions);
	while (b_size-- > 0)
		pa(a, b, instructions);
}

void	stack_quick_sort(t_stack *a, t_stack *b, t_array **instructions)
{
	quick_sort_a(a, b, stack_size(a), instructions);
}
