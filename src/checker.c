/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 11:09:29 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/27 18:40:59 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"

static int	error(char *msg)
{
	ft_putstr_fd(msg, 2);
	return (1);
}

static void	free_resources(t_stack **a, t_stack **b)
{
	stack_del(a);
	stack_del(b);
}

static int	check_flags(int *argc, char ***argv)
{
	if (!ft_strcmp((*argv)[*argc - 1], "-v"))
	{
		*argc = *argc - 1;
		return (1);
	}
	else if (!ft_strcmp((*argv)[1], "-v"))
	{
		*argc = *argc - 1;
		*argv = *argv + 1;
		return (1);
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	int			verbose;

	if (argc == 1)
		return (0);
	verbose = check_flags(&argc, &argv);
	if (!(a = read_arguments(argc, argv)))
		return (error("Error\n"));
	if (!(b = stack_new(stack_size(a))))
	{
		stack_del(&a);
		return (error("Error\n"));
	}
	if (!(get_checker_instructions(a, b, verbose)))
	{
		free_resources(&a, &b);
		return (error("Error\n"));
	}
	if (stack_is_empty(b) && stack_is_ordered(a, 1))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free_resources(&a, &b);
	return (0);
}
