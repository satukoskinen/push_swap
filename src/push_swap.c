/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 11:09:37 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/22 10:57:41 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	error(char *msg)
{
	ft_putstr_fd(msg, 2);
	return (1);
}

int			main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		return (0);
	if (!(a = read_arguments(argc, argv)))
		return (error("Error\n"));
	if (!(b = stack_new(stack_size(a))))
	{
		stack_del(&a);
		return (error("Error\n"));
	}
	sort_stack(a, b);
	stack_del(&a);
	stack_del(&b);
	return (0);
}
