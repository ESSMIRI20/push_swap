#include "push_swap.h"

void target(t_stack **a, t_stack **b)
{
    t_stack *tmpa;
    t_stack *tmpb;
    t_stack *big_small;

    tmpa = *a;
    tmpb = *b;
    while (tmpb)
    {
        big_small = NULL;
        while (tmpa)
        {
            if (tmpa->value > tmpb->value && (big_small == NULL || tmpa->value < big_small->value))
                big_small = tmpa;
            tmpa = tmpa->next;
        }
        tmpb->target = big_small;
        tmpb = tmpb->next;
    }
}

void push_to_a(t_stack **a, t_stack **b)
{
    t_stack *tmpa;
    t_stack *tmpb;
    int     len;

    len = len_stack(*a);
    tmpa = *a;
    tmpb = *b;
    while (tmpb)
    {
        tmpa = *a;
        set_index(&tmpa);
        target(a, b);
       if (tmpb->target->index < len / 2)
           while (tmpa != tmpb->target)
           {
            tmpa = tmpa->next;
            ra(a, 1);
           }
       else
           while (tmpa != tmpb->target)
           {
            tmpa = tmpa->next;
            ra(a, 1);
           }
        pa(a, b);
        tmpb = *b;
    }
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