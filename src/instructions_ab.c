/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_ab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 10:41:23 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/29 22:25:21 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "array.h"

void	pa(t_stack *a, t_stack *b, t_array **arr)
{
	int	instruction;

	instruction = PA;
	if (arr != NULL)
		array_add(arr, &instruction);
	if (!stack_is_empty(b))
		stack_push(&a, stack_pop(b));
}

void	pb(t_stack *a, t_stack *b, t_array **arr)
{
	int	instruction;

	instruction = PB;
	if (arr != NULL)
		array_add(arr, &instruction);
	if (!stack_is_empty(a))
		stack_push(&b, stack_pop(a));
}

void	ss(t_stack *a, t_stack *b, t_array **arr)
{
	int	instruction;

	instruction = SS;
	if (arr != NULL)
		array_add(arr, &instruction);
	if (stack_size(a) > 1)
		stack_swap(a);
	if (stack_size(b) > 1)
		stack_swap(b);
}

void	rr(t_stack *a, t_stack *b, t_array **arr)
{
	int	instruction;

	instruction = RR;
	if (arr != NULL)
		array_add(arr, &instruction);
	stack_right_rotate(a);
	stack_right_rotate(b);
}

void	rrr(t_stack *a, t_stack *b, t_array **arr)
{
	int	instruction;

	instruction = RRR;
	if (arr != NULL)
		array_add(arr, &instruction);
	stack_left_rotate(a);
	stack_left_rotate(b);
}
