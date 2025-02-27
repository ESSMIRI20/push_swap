#include "push_swap.h"

int len_stack(t_stack *stack)
{
    int i;

    i = 0;
    while (stack)
    {
        stack = stack->next;
        i++;
    }
    return (i);
}

void push_to_b(t_stack *a)
{
    int size;

    size = len_stack(a);
    if (size == 1)
        return ;
    else if (size == 2)
        sort_2_nmr(a);
    else if (size == 3)
        sort_3_nmr(a);
}