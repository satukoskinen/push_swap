/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_instructions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 12:37:10 by skoskine          #+#    #+#             */
/*   Updated: 2021/04/02 15:58:38 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void		check_opposite_operations(t_array *arr)
{
	size_t	i;
	int		i_0;
	int		i_1;

	i = 0;
	while (i < arr->size - 1)
	{
		i_0 = *(int*)array_get(arr, i);
		i_1 = *(int*)array_get(arr, i + 1);
		if ((i_0 == PA && i_1 == PB) || (i_0 == PB && i_1 == PA)
		|| (i_0 == RA && i_1 == RRA) || (i_0 == RRA && i_1 == RA)
		|| (i_0 == RB && i_1 == RRB) || (i_0 == RRB && i_1 == RB)
		|| (i_0 == SA && i_1 == SA) || (i_0 == SB && i_1 == SB)
		|| (i_0 == SS && i_1 == SS) || (i_0 == RR && i_1 == RR)
		|| (i_0 == RRR && i_1 == RRR))
		{
			array_remove(arr, i);
			array_remove(arr, i);
			if (i > 0)
				i--;
		}
		else
			i++;
	}
}

static int	get_composite_operation(int i_0)
{
	if (i_0 == SA || i_0 == SB)
		return (SS);
	else if (i_0 == RA || i_0 == RB)
		return (RR);
	else if (i_0 == RRA || i_0 == RRB)
		return (RRR);
	return (0);
}

void		check_composite_operations(t_array *arr)
{
	size_t	i;
	int		i_0;
	int		i_1;

	i = 0;
	while (i < arr->size - 1)
	{
		i_0 = *(int*)array_get(arr, i);
		i_1 = *(int*)array_get(arr, i + 1);
		if ((i_0 == SA && i_1 == SB) || (i_0 == SB && i_1 == SA)
		|| (i_0 == RA && i_1 == RB) || (i_0 == RB && i_1 == RA)
		|| (i_0 == RRA && i_1 == RRB) || (i_0 == RRB && i_1 == RRA))
		{
			i_0 = get_composite_operation(i_0);
			array_remove(arr, i);
			array_remove(arr, i);
			array_insert(&arr, &i_0, i);
		}
		else
			i++;
	}
}

void		optimize_instructions(t_array *arr, int a_size)
{
	if (OPTIMIZE_ROTATIONS)
		check_rotations(arr, a_size);
	check_opposite_operations(arr);
	check_composite_operations(arr);
}
