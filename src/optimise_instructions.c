/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimise_instructions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 12:37:10 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/28 13:42:37 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	optimise_instructions(t_array *arr)
{
	size_t	i;
	int		i_0;
	int		i_1;

	i = 0;
	if (arr->size == 0)
		return ;
	while (i < arr->size - 1)
	{
		i_0 = *(int*)array_get(arr, i);
		i_1 = *(int*)array_get(arr, i + 1);
		if ((i_0 == PA && i_1 == PB) || (i_0 == PB && i_1 == PA)
		|| (i_0 == RA && i_1 == RRA) || (i_0 == RRA && i_1 == RA)
		|| (i_0 == RB && i_1 == RRB) || (i_0 == RRB && i_1 == RB)
		|| (i_0 == SA && i_1 == SA) || (i_0 == SB && i_1 == SB))
		{
			array_remove(arr, i);
			array_remove(arr, i);
			if (i > 0)
				i--;
		}
/*		else if ((i_0 == SA && i_1 == SB) || (i_0 == SB && i_1 == SA))
		{
			array_remove(arr, i);
			array_remove(arr, i);
			i_0 = SS;
			array_insert(&arr, &i_0, i);
		}
*/		else
			i++;
	}
}
