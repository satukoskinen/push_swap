#include "stack.h"
#include "push_swap.h"
#include "libft.h"

void	sort_a_three(t_stack *stack)
{
	int		v1;
	int		v2;
	int		v3;

	v1 = *(stack->top);
	v2 = *(stack->top - 1);
	v3 = *(stack->top - 2);
	if (v1 < v2 && v2 < v3)
		return ;
	else if (v1 < v2 && v2 > v3 && v1 < v3)
	{
		ra(stack);
		ft_putstr("ra\n");
		sa(stack);
		ft_putstr("sa\n");
		rra(stack);
		ft_putstr("rra\n");
	}
	else if (v1 > v2 && v2 < v3 && v1 < v3)
	{
		sa(stack);
		ft_putstr("sa\n");
	}
	else if (v1 < v2 && v2 > v3)
	{
		ra(stack);
		ft_putstr("ra\n");
		sa(stack);
		ft_putstr("sa\n");
		rra(stack);
		ft_putstr("rra\n");
		sa(stack);
		ft_putstr("sa\n");
	}
	else if (v1 > v2 && v2 < v3 && v1 > v3)
	{
		sa(stack);
		ft_putstr("sa\n");
		ra(stack);
		ft_putstr("ra\n");
		sa(stack);
		ft_putstr("sa\n");
		rra(stack);
		ft_putstr("rra\n");
	}
	else if (v1 > v2 && v2 > v3 && v1 > v3)
	{
		sa(stack);
		ft_putstr("sa\n");
		ra(stack);
		ft_putstr("ra\n");
		sa(stack);
		ft_putstr("sa\n");
		rra(stack);
		ft_putstr("rra\n");
		sa(stack);
		ft_putstr("sa\n");
	}
}

void	sort_b_three(t_stack *stack)
{
	int	v1;
	int	v2;
	int	v3;

	v1 = *(stack->top);
	v2 = *(stack->top - 1);
	v3 = *(stack->top - 2);
	if (v1 > v2 && v2 > v3)
		return ;
	else if (v1 > v2 && v2 < v3 && v1 > v3)
	{
		rb(stack);
		ft_putstr("rb\n");
		sb(stack);
		ft_putstr("sb\n");
		rrb(stack);
		ft_putstr("rrb\n");
	}
	else if (v1 < v2 && v2 > v3 && v1 > v3)
	{
		sb(stack);
		ft_putstr("sb\n");
	}
	else if (v1 > v2 && v2 < v3 && v1 < v3)
	{
		rb(stack);
		ft_putstr("rb\n");
		sb(stack);
		ft_putstr("sb\n");
		rrb(stack);
		ft_putstr("rrb\n");
		sb(stack);
		ft_putstr("sb\n");
	}
	else if (v1 < v2 && v2 > v3 && v1 < v3)
	{
		sb(stack);
		ft_putstr("sb\n");
		rb(stack);
		ft_putstr("rb\n");
		sb(stack);
		ft_putstr("sb\n");
		rrb(stack);
		ft_putstr("rrb\n");
	}
	else if (v1 < v2 && v2 < v3 && v1 < v3)
	{
		sb(stack);
		ft_putstr("sb\n");
		rb(stack);
		ft_putstr("rb\n");
		sb(stack);
		ft_putstr("sb\n");
		rrb(stack);
		ft_putstr("rrb\n");
		sb(stack);
		ft_putstr("sb\n");
	}
}
