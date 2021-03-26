/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:38:04 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/22 15:32:27 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "void_stack.h"
#include "libft.h"
#include <stdlib.h>

static t_stack	*stack_resize(t_stack *stack)
{
	t_stack *new;

	new = stack_new(stack->capacity * 2, stack->content_size);
	if (!new)
	{
		stack_del(&stack);
		return (NULL);
	}
	ft_memcpy(new->arr, stack->arr, stack->content_size * stack->count);
	new->count = stack->count;
	new->top = new->arr + (new->count - 1);
	stack_del(&stack);
	return (new);
}

t_stack			*stack_push(t_stack *stack, void *content)
{
	if (stack->count == stack->capacity)
		stack = stack_resize(stack);
	if (!stack)
		return (NULL);
	if (stack->count != 0)
		stack->top++;
	ft_memcpy(stack->top, content, stack->content_size);
	stack->count++;
	return (stack);
}
