#include "push_swap.h"

// void rb(t_stack **b, int i)
// {
//     t_stack *tmp;

//     if (!b || !*b || !(*b)->next)
//         return ;
    
//     tmp = NULL;
//     tmp = (*b)->next;
//     while ((tmp->next))
//        (tmp) = (tmp)->next;
//     tmp->next= (*b);
//     (*b) = (*b)->next;
//     tmp->next->next = NULL;
//     if (i == 1)
//         put_str("rb\n");
// }

void rb(t_stack **b, int i)
{
    t_stack *tmp;
    t_stack *last;

    if (!b || !*b || !(*b)->next)
        return;
    
    tmp = *b;
    *b = (*b)->next;
    tmp->next = NULL;

    last = *b;
    while (last->next)
        last = last->next;
    
    last->next = tmp;
    
    if (i == 1)
        put_str("rb\n");
}