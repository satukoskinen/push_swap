/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_left_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:36:07 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/31 20:00:47 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*stack_left_rotate(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->count < 2)
		return (stack);
	tmp = stack->arr[0];
	i = 0;
	while (i < stack->count - 1)
	{
		stack->arr[i] = stack->arr[i + 1];
		i++;
	}
	stack->arr[i] = tmp;
	return (stack);
}
