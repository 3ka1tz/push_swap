/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_indexing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez-u <elopez-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:16:08 by elopez-u          #+#    #+#             */
/*   Updated: 2024/11/18 11:18:08 by elopez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	copy_stack_to_array(t_stack *stack, int *values)
{
	int		i;
	t_node	*node;

	i = 0;
	node = stack->top;
	while (node)
	{
		values[i] = node->value;
		node = node->next;
		i++;
	}
}

static void	sort_array(int *values, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (values[i] > values[j])
			{
				tmp = values[i];
				values[i] = values[j];
				values[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static void	replace_values_with_indices(t_stack *stack, int *values, int size)
{
	t_node	*node;
	int		i;

	node = stack->top;
	while (node)
	{
		i = 0;
		while (i < size)
		{
			if (node->value == values[i])
			{
				node->value = i;
				break ;
			}
			i++;
		}
		node = node->next;
	}
}

void	assign_indices_to_stack(t_stack *stack)
{
	int		size;
	int		*values;

	size = get_stack_size(stack);
	values = malloc(sizeof(int) * size);
	if (!values)
	{
		ft_putstr("Error\n");
		exit(1);
	}
	copy_stack_to_array(stack, values);
	sort_array(values, size);
	replace_values_with_indices(stack, values, size);
	free(values);
}
