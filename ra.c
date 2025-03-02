#include "push_swap.h"

void ra(t_stack **a, int i)
{
    t_stack *tmp;

    if (!a || !*a || !(*a)->next)
        return ;
    
    tmp = (*a)->next;
    while ((tmp->next))
       (tmp) = (tmp)->next;
    tmp->next= (*a);
    (*a) = (*a)->next;
    tmp->next->next = NULL;
    if (i == 1)
        put_str("ra\n");
}