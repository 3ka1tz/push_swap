/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez-u <elopez-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:34:13 by elopez-u          #+#    #+#             */
/*   Updated: 2024/11/18 13:14:04 by elopez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
}	t_stack;

// Utility Functions
long	ft_atoi_long(const char *nptr);
void	free_split(char **result, int array_size);
char	**ft_split(char const *s, char c);
void	ft_putstr(char *str);

// Validation Functions
int		are_arguments_numbers(int argc, char *argv[]);
int		are_numbers_too_long(int argc, char *argv[]);
int		are_there_duplicates(int argc, char *argv[]);

// Stack Utilities
int		get_stack_size(t_stack *stack);
void	assign_indices_to_stack(t_stack *stack);

// Stack Operations
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

// Sorting Functions
void	sort_three(t_stack *stack);
void	sort_four(t_stack *stack_a, t_stack *stack_b);
void	sort_five(t_stack *stack_a, t_stack *stack_b);
void	radix_sort(t_stack *stack_a, t_stack *stack_b);

// Main Function
void	push_swap(t_stack *stack_a, t_stack *stack_b);

#endif