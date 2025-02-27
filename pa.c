#include "push_swap.h"

void pa(t_stack **a, t_stack **b)
{
    t_stack *tmp;

    tmp = NULL;
    if (!b)
        return ;
    tmp= (*b);
    (*b) = (*b)->next;
    tmp->next = (*a);
    (*a) = tmp;
}