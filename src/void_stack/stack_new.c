/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:36:54 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/22 15:36:10 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "void_stack.h"
#include <stdlib.h>

t_stack			*stack_new(int capacity, int content_size)
{
	t_stack *new;

	new = (t_stack*)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->arr = (void*)malloc(content_size * capacity);
	if (!new->arr)
	{
		free(new);
		return (NULL);
	}
	new->capacity = capacity;
	new->top = new->arr;
	new->count = 0;
	new->content_size = content_size;
	return (new);
}
