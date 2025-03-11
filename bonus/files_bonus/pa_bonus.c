/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessmiri <oessmiri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:50:14 by oessmiri          #+#    #+#             */
/*   Updated: 2025/03/09 12:15:45 by oessmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pa(t_stack **a, t_stack **b, int i)
{
	t_stack	*tmp;

	tmp = NULL;
	if (!b || *b == NULL)
		return ;
	tmp = (*b);
	(*b) = (*b)->next;
	tmp->next = (*a);
	(*a) = tmp;
	if (i == 1)
		put_str("pa\n");
}
