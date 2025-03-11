/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessmiri <oessmiri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:57:07 by oessmiri          #+#    #+#             */
/*   Updated: 2025/03/11 10:31:24 by oessmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	target(t_stack **a, t_stack **b)
{
	t_stack	*tmpa;
	t_stack	*tmpb;
	t_stack	*big_small;

	tmpa = *a;
	tmpb = *b;
	while (tmpb)
	{
		big_small = NULL;
		tmpa = *a;
		while (tmpa)
		{
			if (tmpa->value > tmpb->value && (big_small == NULL
					|| tmpa->value < big_small->value))
				big_small = tmpa;
			tmpa = tmpa->next;
		}
		tmpb->target = big_small;
		tmpb = tmpb->next;
	}
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
