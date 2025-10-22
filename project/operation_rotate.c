/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez-u <elopez-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:22:03 by elopez-u          #+#    #+#             */
/*   Updated: 2024/10/31 17:34:37 by elopez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate_stack(t_node **stack)
{
	t_node	*tmp;
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return (0);
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	last = *stack;
	while (last && last->next)
		last = last->next;
	if (last)
		last->next = tmp;
	else
		*stack = tmp;
	return (1);
}

void	ra(t_stack *stack_a)
{
	if (rotate_stack(&(stack_a->top)) == 1)
		ft_putstr("ra\n");
}

void	rb(t_stack *stack_b)
{
	if (rotate_stack(&(stack_b->top)) == 1)
		ft_putstr("rb\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	int	stack_a_rotated;
	int	stack_b_rotated;

	stack_a_rotated = rotate_stack(&(stack_a->top));
	stack_b_rotated = rotate_stack(&(stack_b->top));
	if (stack_a_rotated == 1 && stack_b_rotated == 1)
		ft_putstr("rr\n");
}
