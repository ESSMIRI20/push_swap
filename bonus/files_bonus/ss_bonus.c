/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessmiri <oessmiri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:50:41 by oessmiri          #+#    #+#             */
/*   Updated: 2025/03/09 11:42:02 by oessmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ss(t_stack *a, t_stack *b, int i)
{
	sa(a, 0);
	sb(b, 0);
	if (i == 1)
		put_str("ss\n");
}
