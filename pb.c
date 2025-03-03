#include "push_swap.h"

void pb(t_stack **a, t_stack **b)
{
    t_stack *tmp;

    tmp = NULL;
    if (!a || !*a)
        return ;
    tmp= (*a);
    (*a) = (*a)->next;
    tmp->next = (*b);
    (*b) = tmp;
    put_str("pb\n");
}