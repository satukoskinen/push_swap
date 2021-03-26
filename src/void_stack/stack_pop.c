/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:37:36 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/23 21:19:01 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "void_stack.h"
#include "libft.h"

void		*stack_pop(t_stack *stack, void *dst)
{
	if (stack->count == 0 || dst == NULL)
		return (NULL);
	ft_memcpy(dst, stack->top, stack->content_size);
	stack->top--;
	stack->count--;
	return (dst);
}
