/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 10:59:43 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/28 10:11:25 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

t_array	*sort_stack(t_stack *a, t_stack *b)
{
	t_array *instructions;

	instructions = array_new(10, sizeof(int));
	if (instructions == NULL)
		return (NULL);
	if (stack_is_ordered(a, 1))
		return (instructions);
	if (stack_size(a) < 5)
		stack_bubble_sort(a, b, &instructions);
	else
		stack_quick_sort(a, b, &instructions);
	return (instructions);
}
