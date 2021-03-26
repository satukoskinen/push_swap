/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_left_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:36:07 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/22 14:13:00 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "void_stack.h"
#include "libft.h"

t_stack			*stack_left_rotate(t_stack *stack)
{
	void	*tmp;
	int		i;

	if (stack->count < 2)
		return (stack);
	tmp = malloc(stack->content_size);
	if (!tmp)
		return (NULL);
	ft_memcpy(tmp, stack->arr, stack->content_size);
	i = 0;
	while (i < stack->count - 1)
	{
		ft_memcpy(stack->arr + i, stack->arr + i + 1, stack->content_size);
		i++;
	}
	ft_memcpy(stack->top, tmp, stack->content_size);
	return (stack);
}
