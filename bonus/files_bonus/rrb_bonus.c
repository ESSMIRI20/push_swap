/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessmiri <oessmiri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:50:31 by oessmiri          #+#    #+#             */
/*   Updated: 2025/03/09 09:27:23 by oessmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rrb(t_stack **b, int i)
{
	t_stack	*tmp;
	t_stack	*t1;

	if (!b || !*b || !(*b)->next)
		return ;
	tmp = NULL;
	t1 = NULL;
	tmp = (*b);
	while ((*b)->next->next)
		(*b) = (*b)->next;
	t1 = (*b)->next;
	t1->next = (tmp);
	(*b)->next = NULL;
	(*b) = t1;
	if (i == 1)
		put_str("rrb\n");
}
