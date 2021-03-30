/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 10:40:29 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/29 22:25:10 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "array.h"

void	sa(t_stack *a, t_array **arr)
{
	int	instruction;

	instruction = SA;
	if (arr != NULL)
		array_add(arr, &instruction);
	if (stack_size(a) > 1)
		stack_swap(a);
}

void	ra(t_stack *a, t_array **arr)
{
	int	instruction;

	instruction = RA;
	if (arr != NULL)
		array_add(arr, &instruction);
	stack_right_rotate(a);
}

void	rra(t_stack *a, t_array **arr)
{
	int	instruction;

	instruction = RRA;
	if (arr != NULL)
		array_add(arr, &instruction);
	stack_left_rotate(a);
}
