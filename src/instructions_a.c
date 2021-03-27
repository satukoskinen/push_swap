/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 10:40:29 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/27 18:37:41 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"

void	sa(t_stack *a)
{
	if (stack_size(a) > 1)
		stack_swap(a);
}

void	ra(t_stack *a)
{
	stack_right_rotate(a);
}

void	rra(t_stack *a)
{
	stack_left_rotate(a);
}
