#include "stack.h"

int		stack_max(t_stack *stack, int size)
{
	int	max;
	int	i;

	i = 0;
	max = stack_peek(stack);
	while (i < size)
	{
		if (max < *(stack->top - i))
			max = *(stack->top - i);
		i++;
	}
	return (max);
}
