/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 20:50:21 by skoskine          #+#    #+#             */
/*   Updated: 2021/04/07 12:56:25 by skoskine         ###   ########.fr       */
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

	ret = read(0, &buf, 4);
	if (ret == 0 || ret == -1)
		return (ret);
	if (buf[ret - 1] != '\n')
	{
		get_next_line(0, dst);
		return (-1);
	}
	buf[ret - 1] = '\0';
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
			print_stacks(a, b, verbose, instructions[ret]);
	}
	if (ret != 0)
	{
		free(input);
		return (0);
	}
	return (1);
}
