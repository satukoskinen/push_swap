/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_peek.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 21:15:27 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/27 18:45:08 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int				stack_peek(t_stack *stack)
{
	if (!stack_is_empty(stack))
		return (*stack->top);
	else
		return (0);
}
