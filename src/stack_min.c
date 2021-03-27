#include "stack.h"

int		stack_min(t_stack *stack, int size)
{
	int	min;
	int	i;

	i = 0;
	min = stack_peek(stack);
	while (i < size)
	{
		if (min > *(stack->top - i))
			min = *(stack->top - i);
		i++;
	}
	return (min);
}
