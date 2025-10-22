/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez-u <elopez-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:07:40 by elopez-u          #+#    #+#             */
/*   Updated: 2024/10/31 17:34:41 by elopez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap_stack(t_node **stack)
{
	t_node	*tmp1;
	t_node	*tmp2;

	if (!*stack || !(*stack)->next)
		return (0);
	tmp1 = *stack;
	tmp2 = (*stack)->next;
	tmp1->next = tmp2->next;
	tmp2->next = tmp1;
	*stack = tmp2;
	return (1);
}

void	sa(t_stack *stack_a)
{
	if (swap_stack(&(stack_a->top)) == 1)
		ft_putstr("sa\n");
}

void	sb(t_stack *stack_b)
{
	if (swap_stack(&(stack_b->top)) == 1)
		ft_putstr("sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	int	stack_a_swapped;
	int	stack_b_swapped;

	stack_a_swapped = swap_stack(&(stack_a->top));
	stack_b_swapped = swap_stack(&(stack_b->top));
	if (stack_a_swapped == 1 && stack_b_swapped == 1)
		ft_putstr("ss\n");
}
