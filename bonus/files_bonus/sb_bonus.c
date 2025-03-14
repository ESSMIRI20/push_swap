/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessmiri <oessmiri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:50:38 by oessmiri          #+#    #+#             */
/*   Updated: 2025/03/09 09:27:36 by oessmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sb(t_stack *b, int i)
{
	int	c;

	if (b && b->next)
	{
		c = b->value;
		b->value = b->next->value;
		b->next->value = c;
		if (i == 1)
			put_str("sb\n");
	}
}
