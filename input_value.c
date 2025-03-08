/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessmiri <oessmiri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:28:23 by oessmiri          #+#    #+#             */
/*   Updated: 2025/03/08 14:41:27 by oessmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(const char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			count++;
		}
		i++;
	}
	return (count);
}

static char	*copy_word(const char *start, size_t length)
{
	size_t	i;
	char	*word;

	word = malloc(length + 1);
	i = 0;
	if (!word)
		return (NULL);
	while (i < length)
	{
		word[i] = start[i];
		i++;
	}
	word[length] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int			i;
	char		**result;
	const char	*start;

	if (!s)
		return (NULL);
	result = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			start = s;
			while (*s && *s != c)
				s++;
			result[i++] = copy_word(start, s - start);
		}
		else
			s++;
	}
	result[i] = NULL;
	return (result);
}

static void	helpe_func(t_stack **stack, char **r, int i, int j)
{
	while (r[i])
	{
		j = 0;
		if (r[i][j] == '-' || r[i][j] == '+')
			j++;
		if (!(r[i][j] <= 57 && r[i][j] >= 48))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		while (r[i][j])
		{
			if ((r[i][j] <= 57 && r[i][j] >= 48))
				j++;
			else
			{
				write(2, "Error\n", 6);
				exit(1);
			}
		}
		ft_lstadd_back(stack, ft_atoi(r[i]));
		check_double_value(*stack);
		i++;
	}	
}

void	check_int(t_stack **stack, char *s)
{
	int		i;
	int		j;
	char	**r;

	i = 0;
	j = 0;
	r = ft_split(s, ' ');
	if (!r || !r[i])
	{
		free(r);
		write(2, "Error\n", 6);
		exit(1);
	}
	helpe_func(stack, r, i, j);
}
