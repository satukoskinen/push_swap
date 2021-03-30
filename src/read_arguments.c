/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_arguments.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 16:54:37 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/29 18:56:02 by skoskine         ###   ########.fr       */
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

static int		parse_line_values(t_stack **stack, char *line)
{
	int				i;
	long long int	value;

	i = 0;
	while (line[i])
	{
		value = ft_atoll(&line[i]);
		if ((value == 0 && line[i] != '0')
			|| value < -2147483647 - 1 || value > 2147483647)
			return (0);
		else if (stack_contains(*stack, (int)value))
			return (0);
		if (!stack_push(stack, (int)value))
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

	if (!(new = stack_new(stack->capacity)))
	{
		stack_del(&stack);
		return (NULL);
	}
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
	if (!(stack = stack_new(10)))
		return (NULL);
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		if (!parse_line_values(&stack, line))
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
	t_stack			*stack;
	int				i;

	if (argc == 2 && !ft_isdigit(argv[1][0])
		&& argv[1][0] != '-' && argv[1][0] != '+')
		return (read_from_file(argv[1]));
	if (!(stack = stack_new(argc - 1)))
		return (NULL);
	i = 1;
	while (i < argc)
	{
		if (!parse_line_values(&stack, argv[i]))
		{
			stack_del(&stack);
			return (NULL);
		}
		i++;
	}
	stack = reverse_stack(stack);
	return (stack);
}
