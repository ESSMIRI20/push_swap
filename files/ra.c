/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessmiri <oessmiri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:50:20 by oessmiri          #+#    #+#             */
/*   Updated: 2025/03/08 15:02:28 by oessmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a, int i)
{
	t_stack	*tmp;

	if (!a || !*a || !(*a)->next)
		return ;
	tmp = (*a)->next;
	while ((tmp->next))
		(tmp) = (tmp)->next;
	tmp->next = (*a);
	(*a) = (*a)->next;
	tmp->next->next = NULL;
	if (i == 1)
		put_str("ra\n");
}
