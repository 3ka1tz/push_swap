/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez-u <elopez-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:51:00 by elopez-u          #+#    #+#             */
/*   Updated: 2024/11/18 13:19:11 by elopez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	are_arguments_numbers(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][0] == '-')
		{
			if (argv[i][1] == '\0')
				return (0);
			j++;
		}
		while (argv[i][j])
		{
			if ((argv[i][j]) < '0' || (argv[i][j]) > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

long	ft_atoi_long(const char *nptr)
{
	int		sign;
	long	result;

	sign = 1;
	result = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		nptr++;
	}
	return (result * sign);
}

int	are_numbers_too_long(int argc, char *argv[])
{
	int		index;
	long	number;

	index = 1;
	while (index < argc)
	{
		number = ft_atoi_long(argv[index]);
		if (number > INT_MAX || number < INT_MIN)
			return (1);
		index++;
	}
	return (0);
}

static int	is_duplicate(long number, long *seen_numbers, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (seen_numbers[i] == number)
			return (1);
		i++;
	}
	return (0);
}

int	are_there_duplicates(int argc, char *argv[])
{
	long	number;
	long	*seen_numbers;
	int		i;

	if (argc < 2)
		return (0);
	seen_numbers = (long *)malloc((argc - 1) * sizeof(long));
	if (!seen_numbers)
		return (1);
	i = 1;
	while (i < argc)
	{
		number = ft_atoi_long(argv[i]);
		if (is_duplicate(number, seen_numbers, i - 1))
		{
			free(seen_numbers);
			return (1);
		}
		seen_numbers[i - 1] = number;
		i++;
	}
	free(seen_numbers);
	return (0);
}
