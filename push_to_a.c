/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessmiri <oessmiri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:01:30 by oessmiri          #+#    #+#             */
/*   Updated: 2025/03/08 14:48:57 by oessmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_cost(t_stack **s)
{
	int		len;
	t_stack	*tmpb;

	len = len_stack(*s);
	tmpb = *s;
	set_index(&tmpb);
	while (tmpb)
	{
		if (tmpb->index < (len / 2))
			tmpb->cost = tmpb->index;
		else
			tmpb->cost = len - tmpb->index;
		tmpb = tmpb->next;
	}
}

t_stack	*clac_best_move(t_stack **a, t_stack **b)
{
	t_stack	*tmpb;
	t_stack	*tmpa;
	t_stack	*best;
	int		best_move;

	tmpb = *b;
	tmpa = *a;
	best_move = INT_MAX;
	best = NULL;
	set_cost(&tmpa);
	set_cost(&tmpb);
	target(a, b);
	while (tmpb)
	{
		if (best_move > tmpb->cost + tmpb->target->cost)
		{
			best_move = tmpb->cost + tmpb->target->cost;
			best = tmpb;
		}
		tmpb = tmpb->next;
	}
	return (best);
}

void	put_func(void (*f)(t_stack **, int), t_stack **s, int n)
{
	while (n)
	{
		f(s, 1);
		n--;
	}
}

static	void	help_func(t_stack *best, t_stack **a, int lena)
{
	if (best->target->index < (lena / 2))
		put_func(ra, a, best->target->cost);
	else
		put_func(rra, a, best->target->cost);
}

void	push_to_a(t_stack **a, t_stack **b)
{
	t_stack	*best;
	int		lena;
	int		lenb;

	while (*b)
	{
		lenb = len_stack(*b);
		lena = len_stack(*a);
		best = clac_best_move(a, b);
		if (best->index < (lenb / 2))
		{
			put_func(rb, b, best->cost);
			help_func(best, a, lena);
		}
		else
		{
			put_func(rrb, b, best->cost);
			help_func(best, a, lena);
		}
		pa(a, b);
	}
}
