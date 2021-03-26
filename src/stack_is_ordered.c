/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_is_ordered.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 20:35:14 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/24 08:36:15 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int		stack_is_ordered(t_stack *stack, int ascending)
{
	int	value;
	int	prev;
	int	i;

	if (stack_is_empty(stack))
		return (1);
	i = stack_size(stack) - 1;
	prev = stack->arr[i--];
	while (i >= 0)
	{
		value = stack->arr[i];
		if (ascending && value < prev)
			return (0);
		else if (!ascending && value > prev)
			return (0);
		prev = value;
		i--;
	}
	return (1);
}
