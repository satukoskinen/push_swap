/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 11:09:37 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/28 22:16:30 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "array.h"

static int		error(char *msg)
{
	ft_putstr_fd(msg, 2);
	return (1);
}

static t_array	*sort_stack(t_stack *a, t_stack *b)
{
	t_array *instructions;

	instructions = array_new(10, sizeof(int));
	if (instructions == NULL)
		return (NULL);
	if (stack_is_ordered(a, 1))
		return (instructions);
	if (stack_size(a) <= 3)
		stack_sort_three(a, stack_size(a), 1, &instructions);
	else
		stack_quick_sort(a, b, &instructions);
	return (instructions);
}

int				main(int argc, char **argv)
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
	if (instructions->size > 1)
		optimize_instructions(instructions);
	print_instructions(instructions);
	array_del(&instructions);
	return (0);
}
