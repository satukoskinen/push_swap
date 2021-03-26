/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_is_empty.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 21:15:08 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/23 21:15:14 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "void_stack.h"

int				stack_is_empty(t_stack *stack)
{
	if (stack->count == 0)
		return (1);
	else
		return (0);
}
