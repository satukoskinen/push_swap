/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:38:49 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/27 18:47:04 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "void_stack.h"
#include "libft.h"

t_stack			*stack_swap(t_stack *stack)
{
	void	*tmp;

	if (stack->count < 2)
		return (stack);
	tmp = malloc(stack->content_size);
	if (!tmp)
		return (NULL);
	ft_memcpy(tmp, stack->top, stack->content_size);
	ft_memcpy(stack->top, stack->top - stack->content_size,
	stack->content_size);
	ft_memcpy(stack->top - stack->content_size, tmp, stack->content_size);
	return (stack);
}
