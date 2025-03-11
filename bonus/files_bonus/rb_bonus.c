/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessmiri <oessmiri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:50:22 by oessmiri          #+#    #+#             */
/*   Updated: 2025/03/09 09:27:11 by oessmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rb(t_stack **b, int i)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!b || !*b || !(*b)->next)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = NULL;
	last = *b;
	while (last->next)
		last = last->next;
	last->next = tmp;
	if (i == 1)
		put_str("rb\n");
}
