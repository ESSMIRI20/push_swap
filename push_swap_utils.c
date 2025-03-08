/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessmiri <oessmiri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:57:07 by oessmiri          #+#    #+#             */
/*   Updated: 2025/03/08 14:59:12 by oessmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *s)
{
	int	i;
	int	j;
	int	r;

	i = 0;
	j = 0;
	r = 1;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == ' ')
	{
		i++;
	}
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
