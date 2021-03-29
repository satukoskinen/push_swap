/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 20:23:01 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/29 14:45:06 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft.h"

void		print_rotate_coloured(t_stack *a, t_stack *b, int i,
char *instruction)
{
	int	colour_a;
	int	colour_b;

	colour_a = (instruction[1] == 'b' || instruction[2] == 'b') ? 0 : 1;
	colour_b = (instruction[1] == 'a' || instruction[2] == 'a') ? 0 : 1;
	while (--i >= 0)
	{
		if (a->count < i + 1 && !colour_b)
			ft_printf("      % 5d\n", b->arr[i]);
		else if (a->count < i + 1 && colour_b)
			ft_printf("      \x1b[31m% 5d\x1b[0m\n", b->arr[i]);
		else if (b->count < i + 1 && !colour_a)
			ft_printf("% 5d\n", a->arr[i]);
		else if (b->count < i + 1 && colour_a)
			ft_printf("\x1b[31m% 5d\x1b[0m\n", a->arr[i]);
		else if (colour_a && !colour_b)
			ft_printf("\x1b[31m% 5d\x1b[0m % 5d\n", a->arr[i], b->arr[i]);
		else if (!colour_a && colour_b)
			ft_printf("% 5d \x1b[31m% 5d\x1b[0m\n", a->arr[i], b->arr[i]);
		else
			ft_printf("\x1b[31m% 5d\x1b[0m \x1b[31m% 5d\x1b[0m\n",
			a->arr[i], b->arr[i]);
	}
	ft_printf("_____ _____\n  a     b\n\n\n");
}

void		print_swap_coloured(t_stack *a, t_stack *b, int i,
char *instruction)
{
	int	sa;

	sa = (instruction[1] == 'a') ? 1 : 0;
	while (i)
	{
		if (a->count < i && ((b->count != i && b->count != i + 1) || sa))
			ft_printf("      % 5d\n", b->arr[i - 1]);
		else if (a->count < i && ((b->count == i || b->count == i + 1)) && !sa)
			ft_printf("      \x1b[31m% 5d\x1b[0m\n", b->arr[i - 1]);
		else if (b->count < i && ((a->count != i && a->count != i + 1) || !sa))
			ft_printf("% 5d\n", a->arr[i - 1]);
		else if (b->count < i && (a->count == i || a->count == i + 1) && sa)
			ft_printf("\x1b[31m% 5d\x1b[0m\n", a->arr[i - 1]);
		else if ((a->count == i || a->count == i + 1) && sa)
			ft_printf("\x1b[31m% 5d\x1b[0m % 5d\n",
			a->arr[i - 1], b->arr[i - 1]);
		else if ((b->count == i || b->count == i + 1) && !sa)
			ft_printf("% 5d \x1b[31m% 5d\x1b[0m\n",
			a->arr[i - 1], b->arr[i - 1]);
		else
			ft_printf("% 5d % 5d\n",
			a->arr[i - 1], b->arr[i - 1]);
		i--;
	}
	ft_printf("_____ _____\n  a     b\n\n\n");
}

void		print_push_coloured(t_stack *a, t_stack *b, int i,
char *instruction)
{
	int	pa;

	pa = (instruction[1] == 'a') ? 1 : 0;
	while (i)
	{
		if (a->count < i && (b->count != i || pa))
			ft_printf("      % 5d\n", b->arr[i - 1]);
		else if (a->count < i && b->count == i && !pa)
			ft_printf("      \x1b[31m% 5d\x1b[0m\n", b->arr[i - 1]);
		else if (b->count < i && (a->count != i || !pa))
			ft_printf("% 5d\n", a->arr[i - 1]);
		else if (b->count < i && a->count == i && pa)
			ft_printf("\x1b[31m% 5d\x1b[0m\n", a->arr[i - 1]);
		else if (a->count == i && pa)
			ft_printf("\x1b[31m% 5d\x1b[0m % 5d\n",
			a->arr[i - 1], b->arr[i - 1]);
		else if (b->count == i && !pa)
			ft_printf("% 5d \x1b[31m% 5d\x1b[0m\n",
			a->arr[i - 1], b->arr[i - 1]);
		else
			ft_printf("% 5d % 5d\n", a->arr[i - 1], b->arr[i - 1]);
		i--;
	}
	ft_printf("_____ _____\n  a     b\n\n\n");
}

void		print_uncoloured(t_stack *a, t_stack *b, int i)
{
	while (i)
	{
		if (a->count < i)
			ft_printf("      % 5d\n", b->arr[i - 1]);
		else if (b->count < i)
			ft_printf("% 5d\n", a->arr[i - 1]);
		else
			ft_printf("% 5d % 5d\n", a->arr[i - 1], b->arr[i - 1]);
		i--;
	}
	ft_printf("_____ _____\n  a     b\n\n");
}

void		print_stacks(t_stack *a, t_stack *b, char *instruction)
{
	int	i;

	if (a->count > b->count)
		i = a->count;
	else
		i = b->count;
	if (instruction != NULL)
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
		ft_printf("start:\n\n");
		print_uncoloured(a, b, i);
	}
}
