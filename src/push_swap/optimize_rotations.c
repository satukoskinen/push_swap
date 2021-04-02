/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_rotations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 13:58:59 by skoskine          #+#    #+#             */
/*   Updated: 2021/04/02 16:00:34 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void		remove_instructions(t_array *arr, size_t i, int count)
{
	int	j;

	j = 0;
	while (j++ < count)
		array_remove(arr, i);
}

void		check_b_rotations(t_array *arr, size_t *i, int *count, int b_size)
{
	int	current;
	int	prev;

	current = *(int*)array_get(arr, *i);
	if (i != 0)
		prev = *(int*)array_get(arr, *i - 1);
	else
		prev = -1;
	if (current != prev)
		*count = 0;
	*count = *count + 1;
	if (*count == b_size - 1 && b_size != 2)
	{
		remove_instructions(arr, *i - *count + 1, *count);
		if (current == RB)
			current = RRB;
		else
			current = RB;
		array_insert(&arr, &current, *i - *count + 1);
		*i -= *count;
		*count = 0;
	}
}

void		check_a_rotations(t_array *arr, size_t *i, int *count, int a_size)
{
	int	current;
	int	prev;

	current = *(int*)array_get(arr, *i);
	if (*i != 0)
		prev = *(int*)array_get(arr, *i - 1);
	else
		prev = -1;
	if (current != prev)
		*count = 0;
	*count = *count + 1;
	if (*count == a_size - 1 && a_size != 2)
	{
		remove_instructions(arr, *i - *count + 1, *count);
		if (current == RA)
			current = RRA;
		else
			current = RA;
		array_insert(&arr, &current, *i - *count + 1);
		*i -= *count;
		*count = 0;
	}
}

void		update_stack_sizes(int current, int *a_size, int *b_size)
{
	if (current == PA)
	{
		*a_size = *a_size + 1;
		*b_size = *b_size - 1;
	}
	else if (current == PB)
	{
		*a_size = *a_size - 1;
		*b_size = *b_size + 1;
	}
}

void		check_rotations(t_array *arr, int a_size)
{
	size_t	i;
	int		b_size;
	int		current;
	int		count;

	i = 0;
	b_size = 0;
	count = 0;
	while (i < arr->size)
	{
		current = *(int*)array_get(arr, i);
		if (current == PA || current == PB)
			update_stack_sizes(current, &a_size, &b_size);
		if (current == RA || current == RRA)
			check_a_rotations(arr, &i, &count, a_size);
		if (current == RB || current == RRB)
			check_b_rotations(arr, &i, &count, b_size);
		else
			count = 0;
		i++;
	}
}
