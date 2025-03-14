/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_functions_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessmiri <oessmiri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:49:58 by oessmiri          #+#    #+#             */
/*   Updated: 2025/03/09 12:19:51 by oessmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	put_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

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

int	check_sort(t_stack **s)
{
	t_stack	*tmp;
	int		r;
	int		i;
	int		len;

	if (!s || !(*s))
		return (0);
	len = len_stack(*s);
	tmp = *s;
	i = 1;
	set_index(s);
	r = tmp->rank;
	tmp = tmp->next;
	while (tmp && tmp->rank > r)
	{
		r = tmp->rank;
		tmp = tmp->next;
		i++;
	}
	if (i == len)
		return (1);
	return (0);
}
