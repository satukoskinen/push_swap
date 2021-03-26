/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_right_rotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:40:04 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/22 14:13:09 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "void_stack.h"
#include "libft.h"

t_stack			*stack_right_rotate(t_stack *stack)
{
	void	*tmp;
	int		i;

	if (stack->count < 2)
		return (stack);
	tmp = malloc(stack->content_size);
	if (!tmp)
		return (NULL);
	ft_memcpy(tmp, stack->top, stack->content_size);
	i = stack->count - 1;
	while (i > 0)
	{
		ft_memcpy(stack->arr + i, stack->arr + i - 1, stack->content_size);
		i--;
	}
	ft_memcpy(stack->arr, tmp, stack->content_size);
	return (stack);
}
