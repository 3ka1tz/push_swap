/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez-u <elopez-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:59:12 by elopez-u          #+#    #+#             */
/*   Updated: 2024/10/31 17:34:01 by elopez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_stack(t_node **dst, t_node **src)
{
	t_node	*tmp;

	if (!*src)
		return (0);
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
	return (1);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	if (push_stack(&(stack_a->top), &(stack_b->top)) == 1)
		ft_putstr("pa\n");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	if (push_stack(&(stack_b->top), &(stack_a->top)) == 1)
		ft_putstr("pb\n");
}
