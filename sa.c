#include "push_swap.h"

void sa(t_stack *a, int i)
{
    int c;

    if (a && a->next)
    {
        c = a->value;
        a->value = a->next->value;
        a->next->value = c;
        if (i == 1)
            put_str("sa\n");
    }
}