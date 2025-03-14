/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessmiri <oessmiri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:57:07 by oessmiri          #+#    #+#             */
/*   Updated: 2025/03/11 13:50:56 by oessmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

long	ft_atoi(char *s)
{
	int		i;
	long	j;
	int		r;

	i = 0;
	j = 0;
	r = 1;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == ' ')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			r = -1;
		i++;
	}
	while (s[i] != '\0' && (s[i] <= 57 && s[i] >= 48))
	{
		j = j * 10;
		j += s[i] - 48;
		if (j * r > 2147483647 || j * r < -2147483648)
			return (2147483648);
		i++;
	}
	return (j * r);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] == s2[i]) && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	count_words(const char *s, char c)
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

void	ft_free(char **result, int i)
{
	int	j;

	(void) i;
	j = 0;
	while (result[j])
	{
		free(result[j]);
		j++;
	}
	free(result);
}

int	check_double_value(t_stack *s)
{
	t_stack	*node;

	while (s->next)
	{
		node = s->next;
		while (node)
		{
			if (s->value == node->value)
			{
				write(2, "Error\n", 6);
				return (0);
			}
			node = node->next;
		}
		s = s->next;
	}
	return (1);
}
