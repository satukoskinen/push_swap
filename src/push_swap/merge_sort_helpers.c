/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 17:32:35 by skoskine          #+#    #+#             */
/*   Updated: 2021/04/01 10:57:30 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_to_bottom(t_stack *stack, int size, int a,
t_array **instructions)
{
	int	i;

	i = 0;
	while (i++ < size)
	{
		if (a)
			ra(stack, instructions);
		else
			rb(stack, instructions);
	}
}
