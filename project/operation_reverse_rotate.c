/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez-u <elopez-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:36:01 by elopez-u          #+#    #+#             */
/*   Updated: 2024/10/31 17:34:32 by elopez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	reverse_rotate_stack(t_node **stack)
{
	t_node	*prev_last;
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return (0);
	prev_last = NULL;
	last = *stack;
	while (last->next)
	{
		prev_last = last;
		last = last->next;
	}
	prev_last->next = NULL;
	last->next = *stack;
	*stack = last;
	return (1);
}

void	rra(t_stack *stack_a)
{
	if (reverse_rotate_stack(&(stack_a->top)) == 1)
		ft_putstr("rra\n");
}

void	rrb(t_stack *stack_b)
{
	if (reverse_rotate_stack(&(stack_b->top)) == 1)
		ft_putstr("rrb\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	int	stack_a_reversed;
	int	stack_b_reversed;

	stack_a_reversed = reverse_rotate_stack(&(stack_a->top));
	stack_b_reversed = reverse_rotate_stack(&(stack_b->top));
	if (stack_a_reversed == 1 && stack_b_reversed == 1)
		ft_putstr("rrr\n");
}
