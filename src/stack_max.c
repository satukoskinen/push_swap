/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_max.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:44:42 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/27 18:44:43 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int		stack_max(t_stack *stack, int size)
{
	int	max;
	int	i;

	i = 0;
	max = stack_peek(stack);
	while (i < size)
	{
		if (max < *(stack->top - i))
			max = *(stack->top - i);
		i++;
	}
	return (max);
}
