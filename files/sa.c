/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessmiri <oessmiri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:50:36 by oessmiri          #+#    #+#             */
/*   Updated: 2025/03/08 15:04:09 by oessmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a, int i)
{
	int	c;

	if (a && a->next)
	{
		c = a->value;
		a->value = a->next->value;
		a->next->value = c;
		if (i == 1)
			put_str("sa\n");
	}
}
