/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:14:36 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/22 14:15:07 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	sb(t_stack *b)
{
	if (stack_size(b) > 1)
		stack_swap(b);
}

void	rb(t_stack *b)
{
	stack_right_rotate(b);
}

void	rrb(t_stack *b)
{
	stack_left_rotate(b);
}