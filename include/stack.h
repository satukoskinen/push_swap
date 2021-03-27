/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 21:12:28 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/27 16:48:18 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct	s_stack
{
	int			*arr;
	int			*top;
	int			capacity;
	int			count;
}				t_stack;

t_stack			*stack_new(int capacity);
t_stack			*stack_push(t_stack **stack, int value);
int				stack_pop(t_stack *stack);
int				stack_peek(t_stack *stack);
void			stack_del(t_stack **stack);
t_stack			*stack_swap(t_stack *stack);
t_stack			*stack_left_rotate(t_stack *stack);
t_stack			*stack_right_rotate(t_stack *stack);
int				stack_size(t_stack *stack);
int				stack_is_empty(t_stack *stack);

#endif
