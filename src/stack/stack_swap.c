/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:38:49 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/22 11:26:27 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack			*stack_swap(t_stack *stack)
{
	int	tmp;

	if (stack->count < 2)
		return (stack);
	tmp = *stack->top;
	*stack->top = *(stack->top - 1);
	*(stack->top - 1) = tmp;
	return (stack);
}
