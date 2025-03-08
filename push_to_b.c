/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessmiri <oessmiri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:01:36 by oessmiri          #+#    #+#             */
/*   Updated: 2025/03/08 14:54:00 by oessmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	len_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	set_index(t_stack **stack)
{
	int		i;
	int		i2;
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *stack;
	i2 = 0;
	while (tmp)
	{
		i = 0;
		tmp2 = *stack;
		while (tmp2)
		{
			if (tmp->value > tmp2->value)
				i++;
			tmp2 = tmp2->next;
		}
		tmp->rank = i;
		tmp->index = i2;
		tmp = tmp->next;
		i2++;
	}
}

void	push_three(t_stack **a)
{
	int	size;

	size = len_stack(*a);
	if (size == 1)
		return ;
	else if (size == 2)
		sort_2_nmr(*a);
	else if (size == 3)
		sort_3_nmr(a);
}

void	push_to_b(t_stack **a, t_stack **b)
{
	int		len;
	int		count;
	float	percent;

	len = len_stack(*a);
	count = len;
	if (len <= 5)
		percent = 0.7;
	else if (len > 5 && len <= 100)
		percent = 0.5;
	else
		percent = 0.3;
	while (len > 3)
	{
		if ((*a)->rank < len_stack(*a) * percent)
		{
			len--;
			pb(a, b);
			set_index(a);
		}
		else
			ra(a, 1);
	}
	push_three(a);
}
