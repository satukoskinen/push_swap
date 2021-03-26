/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   void_stack.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 21:12:28 by skoskine          #+#    #+#             */
/*   Updated: 2021/03/23 21:17:23 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct	s_stack
{
	void		*arr;
	void		*top;
	int			content_size;
	int			capacity;
	int			count;
}				t_stack;

t_stack			*stack_new(int capacity, int content_size);
t_stack			*stack_push(t_stack *stack, void *content);
void			*stack_pop(t_stack *stack, void *dst);
void			*stack_peek(t_stack *stack, void *dst);
void			stack_del(t_stack **stack);
t_stack			*stack_swap(t_stack *stack);
t_stack			*stack_left_rotate(t_stack *stack);
t_stack			*stack_right_rotate(t_stack *stack);
int				stack_size(t_stack *stack);
int				stack_is_empty(t_stack *stack);

#endif
