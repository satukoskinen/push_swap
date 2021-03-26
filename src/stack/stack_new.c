/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:36:54 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/22 11:17:36 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

t_stack			*stack_new(int capacity)
{
	t_stack *new;

	new = (t_stack*)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->arr = (int*)malloc(sizeof(int) * capacity);
	if (!new->arr)
	{
		free(new);
		return (NULL);
	}
	new->capacity = capacity;
	new->top = new->arr;
	new->count = 0;
	return (new);
}
