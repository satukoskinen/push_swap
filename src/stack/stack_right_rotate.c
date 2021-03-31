/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_right_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:40:04 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/31 20:01:04 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*stack_right_rotate(t_stack *stack)
{
	int	tmp;
	int	i;

	if (stack->count < 2)
		return (stack);
	tmp = *stack->top;
	i = stack->count - 1;
	while (i > 0)
	{
		stack->arr[i] = stack->arr[i - 1];
		i--;
	}
	stack->arr[i] = tmp;
	return (stack);
}
