/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:37:36 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/23 23:24:49 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int				stack_pop(t_stack *stack)
{
	int	value;

	if (stack->count == 0)
		return (0);
	value = *stack->top;
	stack->count--;
	if (stack->count != 0)
		stack->top--;
	return (value);
}
