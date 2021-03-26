/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 10:59:43 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/24 09:06:14 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void		sort_stack(t_stack *a, t_stack *b)
{
	if (stack_is_ordered(a, 1))
		return ;
	stack_bubble_sort(a, b);
}
