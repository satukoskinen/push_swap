/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_min.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:44:47 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/27 18:44:48 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int		stack_min(t_stack *stack, int size)
{
	int	min;
	int	i;

	i = 0;
	min = stack_peek(stack);
	while (i < size)
	{
		if (min > *(stack->top - i))
			min = *(stack->top - i);
		i++;
	}
	return (min);
}
