/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elopez-u <elopez-u@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:10:55 by elopez-u          #+#    #+#             */
/*   Updated: 2024/11/18 11:15:05 by elopez-u         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_strndup(const char *s, size_t n)
{
	size_t	length;
	char	*dup;
	size_t	index;

	length = 0;
	while (s[length] && length < n)
		length++;
	dup = malloc(length + 1);
	if (!dup)
		return (NULL);
	index = 0;
	while (index < length)
	{
		dup[index] = s[index];
		index++;
	}
	dup[length] = '\0';
	return (dup);
}

static int	count_words(const char *s, char c)
{
	int	word_count;

	word_count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			word_count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (word_count);
}

static char	*get_next_word(const char **s, char c)
{
	const char	*start;
	const char	*temp;
	size_t		length;

	start = *s;
	while (*start == c)
		start++;
	if (!*start)
	{
		*s = start;
		return (NULL);
	}
	temp = start;
	while (*temp && *temp != c)
		temp++;
	length = temp - start;
	if (*temp)
		*s = temp + 1;
	else
		*s = temp;
	return (ft_strndup(start, length));
}

void	free_split(char **result, int array_size)
{
	if (result)
	{
		while (array_size > 0)
			free(result[--array_size]);
		free(result);
	}
}

char	**ft_split(char const *s, char c)
{
	int		word_count;
	char	**result;
	int		index;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	result = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	index = 0;
	while (index < word_count)
	{
		while (*s == c)
			s++;
		result[index] = get_next_word(&s, c);
		if (!result[index])
		{
			free_split(result, index);
			return (NULL);
		}
		index++;
	}
	result[index] = NULL;
	return (result);
}
