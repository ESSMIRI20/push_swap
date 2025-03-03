#include "push_swap.h"

void rrb(t_stack **b, int i)
{
    t_stack *tmp;
    t_stack *t1;

    if (!b || !*b || !(*b)->next)
        return ;
    tmp = NULL;
    t1 = NULL;
    tmp = (*b);
    while ((*b)->next->next)
        (*b) = (*b)->next;
    t1 = (*b)->next;
    t1->next = (tmp);
    (*b)->next = NULL;
    (*b) = t1;
    if (i == 1)
        put_str("rrb\n");
}