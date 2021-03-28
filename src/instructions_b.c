/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:14:36 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/28 12:24:55 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "array.h"
#include "libft.h"

void	sb(t_stack *b, t_array **arr)
{
	int	instruction;

	instruction = SB;
	if (arr != NULL)
		array_add(arr, &instruction);
	if (stack_size(b) > 1)
		stack_swap(b);
}

void	rb(t_stack *b, t_array **arr)
{
	int	instruction;

	instruction = RB;
	if (arr != NULL)
		array_add(arr, &instruction);
	stack_right_rotate(b);
}

void	rrb(t_stack *b, t_array **arr)
{
	int	instruction;

	instruction = RRB;
	if (arr != NULL)
		array_add(arr, &instruction);
	stack_left_rotate(b);
}
