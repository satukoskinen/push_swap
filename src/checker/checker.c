/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 11:09:29 by skoskine          #+#    #+#             */
/*   Updated: 2021/04/01 10:29:27 by skoskine         ###   ########.fr       */
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
	int	ret;

	ret = 0;
	if (!ft_strcmp((*argv)[*argc - 1], "-v") || !ft_strcmp((*argv)[*argc - 1], "-c"))
	{
		if ((*argv)[*argc - 1][1] == 'c')
			ret = VERBOSE_COLOURED;
		else
			ret = VERBOSE_UNCOLOURED;
		*argc = *argc - 1;
	}
	else if (!ft_strcmp((*argv)[1], "-v") || !ft_strcmp((*argv)[1], "-c"))
	{
		if ((*argv)[1][1] == 'c')
			ret = VERBOSE_COLOURED;
		else
			ret = VERBOSE_UNCOLOURED;
		*argc = *argc - 1;
		*argv = *argv + 1;
	}
	return (ret);
}

static int	init_stacks(t_stack **a, t_stack **b, int argc, char **argv)
{
	*a = read_arguments(argc, argv);
	if (*a == NULL)
		return (0);
	*b = stack_new(stack_size(*a));
	if (*b == NULL)
	{
		stack_del(a);
		return (0);
	}
	return (1);
}

int			main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	int			verbose;

	if (argc == 1)
		return (0);
	verbose = check_flags(&argc, &argv);
	if (!init_stacks(&a, &b, argc, argv))
		return (error("Error\n"));
	if (verbose)
		print_stacks(a, b, verbose, NULL);
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
