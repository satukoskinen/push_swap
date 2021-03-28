/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 10:45:15 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/28 12:25:10 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	print_instructions(t_array *arr)
{
	size_t		i;
	static char	*instructions[] = { "sa", "ra", "rra", "sb", "rb", "rrb",
									"pa", "pb", "ss", "rr", "rrr", NULL};

	i = 0;
	while (i < arr->size)
	{
		ft_putendl(instructions[*(int*)array_get(arr, i)]);
		i++;
	}
}
