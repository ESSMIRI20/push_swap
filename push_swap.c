/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessmiri <oessmiri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:01:02 by oessmiri          #+#    #+#             */
/*   Updated: 2025/03/08 14:27:52 by oessmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_double_value(t_stack *s)
{
	t_stack	*node;

	while (s->next)
	{
		node = s->next;
		while (node)
		{
			if (s->value == node->value)
			{
				write(2, "Error\n", 6);
				exit(1);
			}
			node = node->next;
		}
		s = s->next;
	}
}

void	ft_lstadd_back(t_stack **lst, int value)
{
	t_stack	*node;
	t_stack	*new_node;

	if (!lst)
		return ;
	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->value = value;
	new_node->next = NULL;
	if (*lst == NULL)
		*lst = new_node;
	else
	{
		node = *lst;
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
}

int	main(int ac, char **av)
{
	int		i;
	t_stack	*a;
	t_stack	*b;

	i = 1;
	a = NULL;
	b = NULL;
	if (ac <= 1)
		return (0);
	while (i < ac)
	{
		check_int(&a, av[i]);
		i++;
	}
	if (check_sort(&a) == 0)
	{
		push_to_b(&a, &b);
		push_to_a(&a, &b);
		min_value(&a);
	}
	return (0);
}
