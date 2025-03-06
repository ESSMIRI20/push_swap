#include "push_swap.h"

void put_str(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
}

void sort_2_nmr(t_stack *s)
{
    if (s->value > s->next->value)
        sa(s, 1);
}

void sort_3_nmr(t_stack **s)
{
    if ((*s)->value > (*s)->next->value && (*s)->value > (*s)->next->next->value)
        ra(s, 1);
    else if ((*s)->next->value > (*s)->value && (*s)->next->value > (*s)->next->next->value)
        rra(s, 1);
    if ((*s)->value > (*s)->next->value)
        sa(*s, 1);
    else
        return ;
}

void min_value(t_stack **a)
{
    t_stack *tmpa;

    tmpa = *a;
    set_index(a);
        while (tmpa->rank != 0)
            tmpa = tmpa->next;
        while (*a != tmpa)
        {
            set_index(a);
            if ((*a)->index < len_stack(*a) / 2)
                ra(a, 1);
            else
                rra(a, 1);
        }
}

int check_sort(t_stack **s)
{
    t_stack *tmp;
    int     r;
    int     i;
    int     len;

    len = len_stack(*s);
    tmp = *s;
    i = 1;
    set_index(s);
    r = tmp->rank;
    tmp = tmp->next;
    while (tmp && tmp->rank > r)
    {
        r = tmp->rank;
        tmp = tmp->next;
        i++;
    }
    if (i == len)
        return (1);
    return (0);
}