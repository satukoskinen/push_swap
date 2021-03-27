/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_arguments.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:54:37 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/27 17:38:13 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"
#include <stdlib.h>
#include <fcntl.h>

static int		stack_contains(t_stack *stack, int value)
{
	int		i;

	i = 0;
	while (i < stack->count)
	{
		if (stack->arr[i] == value)
			return (1);
		i++;
	}
	return (0);
}

static int		parse_line_values(t_stack *stack, char *line)
{
	int		i;
	int		value;

	i = 0;
	while (line[i])
	{
		value = ft_atoi(&line[i]);
		if ((value == 0 && line[i] != '0') || stack_contains(stack, value))
			return (0);
		if (!stack_push(&stack, value))
			return (0);
		if (line[i] == '+' || line[i] == '-')
			i++;
		while (ft_isdigit(line[i]))
			i++;
		if (line[i])
			i++;
	}
	return (1);
}

static t_stack	*reverse_stack(t_stack *stack)
{
	t_stack	*new;
	int		i;

	if (!(new = stack_new(stack->capacity)))
	{
		stack_del(&stack);
		return (NULL);
	}
	i = 0;
	while (stack->count > 0)
		stack_push(&new, stack_pop(stack));
	stack_del(&stack);
	return (new);
}

static t_stack	*read_from_file(char *file)
{
	t_stack	*stack;
	int		fd;
	int		ret;
	char	*line;

	line = NULL;
	if (!(fd = open(file, O_RDONLY)))
		return (NULL);
	if (!(stack = stack_new(500)))
		return (NULL);
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		if (!parse_line_values(stack, line))
			break ;
		ft_strdel(&line);
	}
	if (ret != 0)
	{
		free(line);
		stack_del(&stack);
		return (NULL);
	}
	stack = reverse_stack(stack);
	return (stack);
}

t_stack			*read_arguments(int argc, char **argv)
{
	t_stack	*stack;
	int		i;
	int		value;

	if (argc == 2 && !ft_isdigit(argv[1][0]))
		return (read_from_file(argv[1]));
	if (!(stack = stack_new(argc - 1)))
		return (NULL);
	i = argc - 1;
	while (i > 0)
	{
		value = ft_atoi(argv[i]);
		if ((value == 0 && argv[i][0] != '0') || stack_contains(stack, value))
		{
			stack_del(&stack);
			return (NULL);
		}
		stack_push(&stack, value);
		i--;
	}
	return (stack);
}
