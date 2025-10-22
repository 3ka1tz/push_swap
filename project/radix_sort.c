/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez-u <elopez-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:57:03 by elopez-u          #+#    #+#             */
/*   Updated: 2024/11/18 11:16:02 by elopez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *str)
{
	if (!str)
		return ;
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

static int	get_max_value(t_stack *stack)
{
	t_node	*node;
	int		max_value;

	node = stack->top;
	max_value = node->value;
	while (node)
	{
		if (node->value > max_value)
			max_value = node->value;
		node = node->next;
	}
	return (max_value);
}

static int	get_max_bits(t_stack *stack)
{
	int	max_value;
	int	max_bits;

	max_value = get_max_value(stack);
	max_bits = 0;
	while ((max_value >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static void	push_elements_by_bit(t_stack *stack_a, t_stack *stack_b, int bit)
{
	int	index;
	int	stack_size;
	int	value;

	index = 0;
	stack_size = get_stack_size(stack_a);
	while (index < stack_size)
	{
		value = stack_a->top->value;
		if ((value >> bit) & 1)
			ra(stack_a);
		else
			pb(stack_a, stack_b);
		index++;
	}
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	bit;
	int	max_bits;

	bit = 0;
	max_bits = get_max_bits(stack_a);
	while (bit < max_bits)
	{
		push_elements_by_bit(stack_a, stack_b, bit);
		while (stack_b->top)
			pa(stack_a, stack_b);
		bit++;
	}
}
