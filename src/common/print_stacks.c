/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 20:23:01 by skoskine          #+#    #+#             */
/*   Updated: 2021/04/01 13:08:18 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "libft.h"

void		print_rotate_coloured(t_stack *a, t_stack *b, int i,
char *instruction)
{
	int	col_a;
	int	col_b;

	col_a = (instruction[1] == 'b' || instruction[2] == 'b') ? 0 : 1;
	col_b = (instruction[1] == 'a' || instruction[2] == 'a') ? 0 : 1;
	while (--i >= 0)
	{
		if (a->count < i + 1 && !col_b)
			ft_printf("        % 7d\n", b->arr[i]);
		else if (a->count < i + 1 && col_b)
			ft_printf("        \x1b[31m% 7d\x1b[0m\n", b->arr[i]);
		else if (b->count < i + 1 && !col_a)
			ft_printf("% 7d\n", a->arr[i]);
		else if (b->count < i + 1 && col_a)
			ft_printf("\x1b[31m% 7d\x1b[0m\n", a->arr[i]);
		else if (col_a && !col_b)
			ft_printf("\x1b[31m% 7d\x1b[0m % 7d\n", a->arr[i], b->arr[i]);
		else if (!col_a && col_b)
			ft_printf("% 7d \x1b[31m% 7d\x1b[0m\n", a->arr[i], b->arr[i]);
		else
			ft_printf("\x1b[31m% 7d\x1b[0m \x1b[31m% 7d\x1b[0m\n",
			a->arr[i], b->arr[i]);
	}
	ft_printf("________ ________\n    a        b\n\n\n");
}

void		print_swap_coloured(t_stack *a, t_stack *b, int i,
char *instruction)
{
	int	col_a;
	int	col_b;

	col_a = (instruction[1] == 'b') ? 0 : 1;
	col_b = (instruction[1] == 'a') ? 0 : 1;
	while (i)
	{
		if (a->count < i)
			ft_printf("       ");
		else if ((a->count != i && a->count != i + 1) || !col_a)
			ft_printf("% 7d", a->arr[i - 1]);
		else if ((a->count == i || a->count == i + 1) && col_a)
			ft_printf("\x1b[31m% 7d\x1b[0m", a->arr[i - 1]);
		if (b->count < i)
			ft_printf("\n");
		else if ((b->count != i && b->count != i + 1) || !col_b)
			ft_printf("% 7d\n", b->arr[i - 1]);
		else if ((b->count == i || b->count == i + 1) && col_b)
			ft_printf("\x1b[31m% 7d\x1b[0m\n", b->arr[i - 1]);
		i--;
	}
	ft_printf("________ ________\n    a        b\n\n\n");
}

void		print_push_coloured(t_stack *a, t_stack *b, int i,
char *instruction)
{
	int	pa;

	pa = (instruction[1] == 'a') ? 1 : 0;
	while (i)
	{
		if (a->count < i && (b->count != i || pa))
			ft_printf("        % 7d\n", b->arr[i - 1]);
		else if (a->count < i && b->count == i && !pa)
			ft_printf("        \x1b[31m% 7d\x1b[0m\n", b->arr[i - 1]);
		else if (b->count < i && (a->count != i || !pa))
			ft_printf("% 7d\n", a->arr[i - 1]);
		else if (b->count < i && a->count == i && pa)
			ft_printf("\x1b[31m% 7d\x1b[0m\n", a->arr[i - 1]);
		else if (a->count == i && pa)
			ft_printf("\x1b[31m% 7d\x1b[0m % 7d\n",
			a->arr[i - 1], b->arr[i - 1]);
		else if (b->count == i && !pa)
			ft_printf("% 7d \x1b[31m% 7d\x1b[0m\n",
			a->arr[i - 1], b->arr[i - 1]);
		else
			ft_printf("% 7d % 7d\n", a->arr[i - 1], b->arr[i - 1]);
		i--;
	}
	ft_printf("________ ________\n    a        b\n\n\n");
}

void		print_uncoloured(t_stack *a, t_stack *b, int i)
{
	while (i)
	{
		if (a->count < i)
			ft_printf("        % 7d\n", b->arr[i - 1]);
		else if (b->count < i)
			ft_printf("% 7d\n", a->arr[i - 1]);
		else
			ft_printf("% 7d % 7d\n", a->arr[i - 1], b->arr[i - 1]);
		i--;
	}
	ft_printf("________ ________\n    a        b\n\n");
}

void		print_stacks(t_stack *a, t_stack *b, int verbose, char *instruction)
{
	int	i;

	if (a->count > b->count)
		i = a->count;
	else
		i = b->count;
	if (instruction != NULL && verbose == VERBOSE_COLOURED)
	{
		ft_printf("\nexec \x1b[31m%s\x1b[0m:\n\n", instruction);
		if (instruction[0] == 'p')
			print_push_coloured(a, b, i, instruction);
		else if (instruction[0] == 's')
			print_swap_coloured(a, b, i, instruction);
		else if (instruction[0] == 'r')
			print_rotate_coloured(a, b, i, instruction);
	}
	else
	{
		if (instruction == NULL)
			ft_printf("start:\n\n");
		else
			ft_printf("\nexec %s\n\n", instruction);
		print_uncoloured(a, b, i);
	}
}
