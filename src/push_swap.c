/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 11:09:37 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/28 13:52:03 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "array.h"

static int	error(char *msg)
{
	ft_putstr_fd(msg, 2);
	return (1);
}

int			main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_array	*instructions;

	if (argc == 1)
		return (0);
	if (!(a = read_arguments(argc, argv)))
		return (error("Error\n"));
	if (!(b = stack_new(stack_size(a))))
	{
		stack_del(&a);
		return (error("Error\n"));
	}
	instructions = sort_stack(a, b);
	stack_del(&a);
	stack_del(&b);
	if (instructions == NULL)
		return (error("Error\n"));
	optimise_instructions(instructions);
	print_instructions(instructions);
	return (0);
}
