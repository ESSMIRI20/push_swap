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
        tmpa = *a;
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

int calc(t_stack *tmpa, t_stack *tmpb)
{
    int len1;
    int len2;
    int min;

    len1 = len_stack(tmpa);
    len2 = len_stack(tmpb);
    min = len2;
    if (tmpb->index < len2 / 2)
    {
        if (tmpb->target->index < len1 / 2)
            min = tmpb->index + tmpb->target->index;
        else if (tmpb->target->index >= len1 / 2)
            min = tmpb->index + (len2 - tmpb->target->index);
    }
    else
    {
        printf("%d\n", tmpb->value);
        printf("%p\n", tmpb->target);
        if (tmpb->target->index < len1 / 2)
            min = (len2 - tmpb->index) + tmpb->target->index;
        else if (tmpb->target->index >= len1 / 2)
            min = (len2 - tmpb->index) + (len2 - tmpb->target->index);
    }
    return (min);
}

t_stack *clac_best_move(t_stack **a, t_stack **b)
{
    t_stack *tmpa;
    t_stack *tmpb;
    t_stack *best;
    int best_move;
    int len;

    tmpa = *a;
    tmpb = *b;
    len = len_stack(*b);
    best_move = len;
    while (tmpb)
    {
        if(best_move > calc(tmpa, tmpb))
        {
            best_move = calc(tmpa, tmpb);
            best = tmpb;
        }
        tmpb = tmpb->next;
    }
    return (best);
}

void push_to_a(t_stack **a, t_stack **b)
{
    t_stack *tmpa;
    t_stack *tmpb;
    t_stack *best;
    int     len;
    int     len2;
    int     i;

    len = len_stack(*a);
    len2 = len_stack(*b);
    tmpa = *a;
    tmpb = *b;
    i = 0;
    while (i < len2)
    {
        tmpa = *a;
        set_index(&tmpa);
        target(a, b);
        best = clac_best_move(a, b);
       if (best->target->index < len / 2)
           while (tmpa != best->target)
           {
                ra(a, 1);
                tmpa = *a;
           }
       else
           while (tmpa != best->target)
           {
            tmpa = tmpa->next;
            ra(a, 1);
           }
        pa(a, b);
        i++;
    }
}

// void push_to_a(t_stack **a, t_stack **b)
// {

// }