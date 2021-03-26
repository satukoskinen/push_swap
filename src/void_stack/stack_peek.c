/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_peek.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 21:16:17 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/23 21:19:42 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "void_stack.h"
#include "libft.h"

void			*stack_peek(t_stack *stack, void *dst)
{
	if (stack->count == 0 || dst == NULL)
		return (NULL);
	ft_memcpy(dst, stack->top, stack->content_size);
	return (dst);
}