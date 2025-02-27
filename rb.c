#include "push_swap.h"

void rb(t_stack **b, int i)
{
    t_stack *tmp;

    if (!b || !*b || !(*b)->next)
        return ;
    
    tmp = NULL;
    tmp = (*b)->next;
    while ((tmp->next))
       (tmp) = (tmp)->next;
    tmp->next= (*b);
    (*b) = (*b)->next;
    tmp->next->next = NULL;
    if (i == 1)
        put_str("rb\n");
}