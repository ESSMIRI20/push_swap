/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessmiri <oessmiri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:01:02 by oessmiri          #+#    #+#             */
/*   Updated: 2025/03/11 14:25:37 by oessmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_lstadd_back(t_stack **lst, int value)
{
	t_stack	*node;
	t_stack	*new_node;

	if (!lst)
		return ;
	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		exit(255);
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

void	free_ft(t_stack *s)
{
	t_stack	*tmp;

	while (s)
	{
		tmp = s;
		s = s->next;
		free(tmp);
	}
}

void	read_content(t_stack **a, t_stack **b, char *str)
{
	if (ft_strcmp(str, "ra\n") == 0)
		ra(a, 0);
	else if (ft_strcmp (str, "rb\n") == 0)
		rb(b, 0);
	else if (ft_strcmp (str, "rr\n") == 0)
		rr(a, b, 0);
	else if (ft_strcmp (str, "pa\n") == 0)
		pa(a, b, 0);
	else if (ft_strcmp (str, "pb\n") == 0)
		pb(a, b, 0);
	else if (ft_strcmp (str, "rra\n") == 0)
		rra(a, 0);
	else if (ft_strcmp (str, "rrb\n") == 0)
		rrb(b, 0);
	else if (ft_strcmp (str, "rrr\n") == 0)
		rrr(a, b, 0);
	else if (ft_strcmp (str, "sa\n") == 0)
		sa(*a, 0);
	else if (ft_strcmp (str, "sb\n") == 0)
		sb(*b, 0);
	else if (ft_strcmp (str, "ss\n") == 0)
		ss(*a, *b, 0);
	else
		(free(str), free_ft(*a), write(2, "Error\n", 6), exit(255));
}

void	help(int ac, char **av, t_stack **a)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		check_int(a, av[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*str;

	a = NULL;
	b = NULL;
	if (ac <= 1)
		return (0);
	help(ac, av, &a);
	str = get_next_line(0);
	while (str)
	{
		read_content(&a, &b, str);
		free(str);
		str = get_next_line(0);
	}
	if (check_sort(&a) == 1 && !b)
		put_str("OK\n");
	else
		put_str("KO\n");
	free_ft(a);
	free_ft(b);
	return (0);
}
