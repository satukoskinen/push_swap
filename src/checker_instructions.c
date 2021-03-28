/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 20:50:21 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/28 12:36:32 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static int	get_next_instruction(char **dst)
{
	char	buf[5];
	int		ret;
	int		i;

	i = 0;
	while (i < 4)
	{
		if ((ret = read(0, &buf[i], 1)) == 0 && i == 0)
			return (0);
		if (ret == -1 || buf[i] == '\n')
			break ;
		i++;
	}
	if (ret == -1 || i < 2 || i == 4)
		return (-1);
	buf[i] = '\0';
	*dst = ft_strdup(buf);
	if (*dst == NULL)
		return (-1);
	return (1);
}

static void	execute_instruction(int instruction, t_stack *a, t_stack *b)
{
	static void	(*fptr_1[])(t_stack *s, t_array **arr) =
	{ sa, ra, rra, sb, rb, rrb };
	static void	(*fptr_2[])(t_stack *a, t_stack *b, t_array **arr) =
	{ pa, pb, ss, rr, rrr };

	if (instruction >= SA && instruction <= RRA)
		fptr_1[instruction](a, NULL);
	else if (instruction >= SB && instruction <= RRB)
		fptr_1[instruction](b, NULL);
	else
		fptr_2[instruction - 6](a, b, NULL);
}

int			get_checker_instructions(t_stack *a, t_stack *b, int verbose)
{
	int			ret;
	char		*input;
	static char	*instructions[] = { "sa", "ra", "rra", "sb", "rb", "rrb",
									"pa", "pb", "ss", "rr", "rrr", NULL};

	input = NULL;
	while ((ret = get_next_instruction(&input)) > 0)
	{
		ret = 0;
		while (instructions[ret] && ft_strcmp(input, instructions[ret]))
			ret++;
		if (instructions[ret] == NULL)
			break ;
		execute_instruction(ret, a, b);
		ft_strdel(&input);
		if (verbose)
			print_stacks(a, b, instructions[ret]);
	}
	if (ret != 0)
	{
		free(input);
		return (0);
	}
	return (1);
}
