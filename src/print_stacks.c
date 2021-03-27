/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 20:23:01 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/27 18:43:35 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"

void		print_stacks(t_stack *a, t_stack *b, char *instruction)
{
	int	lines;

	if (instruction != NULL)
		ft_printf("%s:\n\n", instruction);
	if (stack_size(a) > stack_size(b))
		lines = stack_size(a);
	else
		lines = stack_size(b);
	while (lines)
	{
		if (stack_size(a) < lines)
			ft_printf("      % 5d\n", b->arr[lines - 1]);
		else if (stack_size(b) < lines)
			ft_printf("% 5d\n", a->arr[lines - 1]);
		else
			ft_printf("% 5d % 5d\n", a->arr[lines - 1], b->arr[lines - 1]);
		lines--;
	}
	ft_printf("_____ _____\n  a     b\n\n\n");
}
