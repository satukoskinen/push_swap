/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:38:04 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/27 18:47:36 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"
#include <stdlib.h>

static t_stack	*stack_resize(t_stack **stack)
{
	t_stack *new;

	new = stack_new((*stack)->capacity * 2);
	if (!new)
	{
		stack_del(stack);
		return (NULL);
	}
	ft_memcpy((void*)new->arr, (void*)(*stack)->arr,
	sizeof(int) * (*stack)->count);
	new->count = (*stack)->count;
	new->top = &new->arr[new->count - 1];
	stack_del(stack);
	*stack = new;
	return (*stack);
}

t_stack			*stack_push(t_stack **stack, int value)
{
	if ((*stack)->count == (*stack)->capacity)
		*stack = stack_resize(stack);
	if (!*stack)
		return (NULL);
	(*stack)->arr[(*stack)->count] = value;
	if ((*stack)->count != 0)
		(*stack)->top++;
	(*stack)->count++;
	return ((*stack));
}
