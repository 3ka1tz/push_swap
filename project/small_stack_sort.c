/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez-u <elopez-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 14:51:19 by elopez-u          #+#    #+#             */
/*   Updated: 2024/11/18 11:08:10 by elopez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min_position(t_stack *stack)
{
	t_node	*node;
	int		min_value;
	int		min_position;
	int		index;

	node = stack->top;
	min_value = node->value;
	min_position = 0;
	index = 0;
	while (node)
	{
		if (node->value < min_value)
		{
			min_value = node->value;
			min_position = index;
		}
		node = node->next;
		index++;
	}
	return (min_position);
}

static void	rotate_to_minimum(t_stack *stack_a)
{
	int	min_position;
	int	stack_size;

	min_position = find_min_position(stack_a);
	if (min_position == 0)
		return ;
	stack_size = get_stack_size(stack_a);
	if (min_position <= stack_size / 2)
	{
		while (min_position > 0)
		{
			ra(stack_a);
			min_position--;
		}
	}
	else
	{
		while (min_position < stack_size)
		{
			rra(stack_a);
			min_position++;
		}
	}
}

void	sort_three(t_stack *stack)
{
	int	val1;
	int	val2;
	int	val3;

	val1 = stack->top->value;
	val2 = stack->top->next->value;
	val3 = stack->top->next->next->value;
	if (val1 < val2 && val2 < val3)
		return ;
	else if (val1 < val2 && val1 < val3 && val2 > val3)
	{
		sa(stack);
		ra(stack);
	}
	else if (val1 > val2 && val1 < val3 && val2 < val3)
		sa(stack);
	else if (val1 < val2 && val1 > val3 && val2 > val3)
		rra(stack);
	else if (val1 > val3 && val2 < val3)
		ra(stack);
	else if (val1 > val2 && val2 > val3)
	{
		sa(stack);
		rra(stack);
	}
}

void	sort_four(t_stack *stack_a, t_stack *stack_b)
{
	rotate_to_minimum(stack_a);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	rotate_to_minimum(stack_a);
	pb(stack_a, stack_b);
	rotate_to_minimum(stack_a);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
