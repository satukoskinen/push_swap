/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 10:59:43 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/27 18:45:54 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void		sort_stack(t_stack *a, t_stack *b)
{
	if (stack_is_ordered(a, 1))
		return ;
	if (stack_size(a) < 5)
		stack_bubble_sort(a, b);
	else
		stack_quick_sort(a, b);
}
