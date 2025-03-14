/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessmiri <oessmiri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:50:17 by oessmiri          #+#    #+#             */
/*   Updated: 2025/03/09 11:40:04 by oessmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	pb(t_stack **a, t_stack **b, int i)
{
	t_stack	*tmp;

	tmp = NULL;
	if (!a || !*a)
		return ;
	tmp = (*a);
	(*a) = (*a)->next;
	tmp->next = (*b);
	(*b) = tmp;
	if (i == 1)
		put_str("pb\n");
}
