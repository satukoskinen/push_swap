/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_del.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:35:44 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/22 13:58:00 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "void_stack.h"
#include <stdlib.h>

void			stack_del(t_stack **stack)
{
	free((*stack)->arr);
	free(*stack);
	*stack = NULL;
}
