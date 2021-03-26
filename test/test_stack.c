/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:16:03 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/22 15:47:04 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "void_stack.h"
#include <stdio.h>

typedef struct	s_test
{
	int			value;
	char		*content;
}				t_test;

int main(void)
{
	t_stack 	*stack;
	t_test		test;
	t_test		*popped;

	test.content = "test content";
	test.value = 42;
	stack = stack_new(10, sizeof(t_test));
	if (!stack)
	{
		printf("error in stack_new\n");
		return (1);
	}
	stack = stack_push(stack, (void*)&test);
	stack = stack_push(stack, (void*)&test);
	printf("from stack %d %s\n", (((t_test*)(stack->top))->value), ((t_test*)(stack->top))->content);
	popped = (t_test*)stack_pop(stack);
	printf("from popped %d %s\n", popped->value, popped->content);
}
