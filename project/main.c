/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez-u <elopez-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:08:29 by elopez-u          #+#    #+#             */
/*   Updated: 2024/11/18 13:00:33 by elopez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stack(t_stack *stack)
{
	t_node	*tmp;

	while (stack->top)
	{
		tmp = stack->top;
		stack->top = stack->top->next;
		free(tmp);
	}
	stack->top = NULL;
}

static int	parse_and_validate(int *argc, char ***argv, int *split_flag)
{
	int	tmp_argc;

	if (*argc < 2)
		return (0);
	if (*argc == 2)
	{
		*split_flag = 1;
		*argv = ft_split((*argv)[1], ' ');
		if (!*argv)
			return (1);
		tmp_argc = 0;
		while ((*argv)[tmp_argc])
			tmp_argc++;
		*argc = tmp_argc;
	}
	if (!are_arguments_numbers(*argc, *argv)
		|| are_numbers_too_long(*argc, *argv)
		|| are_there_duplicates(*argc, *argv))
	{
		if (*split_flag == 1)
			free_split(*argv, *argc);
		ft_putstr("Error\n");
		return (1);
	}
	return (0);
}

static void	add_node_to_stack(t_stack *stack, int value)
{
	t_node	*new_node;
	t_node	*last_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
	{
		free_stack(stack);
		ft_putstr("Malloc Error\n");
		exit(1);
	}
	new_node->value = value;
	new_node->next = NULL;
	if (!stack->top)
		stack->top = new_node;
	else
	{
		last_node = stack->top;
		while (last_node->next)
			last_node = last_node->next;
		last_node->next = new_node;
	}
}

static void	init_stack(t_stack *stack, int argc, char *argv[], int split_flag)
{
	int	index;
	int	value;

	index = 1;
	if (split_flag)
		index = 0;
	stack->top = NULL;
	while (index < argc)
	{
		value = ft_atoi_long(argv[index]);
		add_node_to_stack(stack, value);
		index++;
	}
}

int	main(int argc, char *argv[])
{
	int		split_flag;
	t_stack	stack_a;
	t_stack	stack_b;

	split_flag = 0;
	if (parse_and_validate(&argc, &argv, &split_flag) != 0)
		return (1);
	stack_a.top = NULL;
	stack_b.top = NULL;
	init_stack(&stack_a, argc, argv, split_flag);
	push_swap(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	if (split_flag == 1)
		free_split(argv, argc);
	return (0);
}
