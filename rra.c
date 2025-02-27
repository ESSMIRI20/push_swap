#include "push_swap.h"

void rra(t_stack **a, int i)
{
    t_stack *tmp;
    t_stack *t1;

    if (!a || !*a || !(*a)->next)
        return ;
    tmp = NULL;
    t1 = NULL;
    tmp = (*a);
    while ((*a)->next->next)
        (*a) = (*a)->next;
    t1 = (*a)->next;
    t1->next = (tmp);
    (*a)->next = NULL;
    (*a) = t1;
    if (i == 1)
        put_str("rra\n");
}