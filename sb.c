#include "push_swap.h"

void sb(t_stack *b, int i)
{
    int c;

    if (b && b->next)
    {
        c = b->value;
        b->value = b->next->value;
        b->next->value = c;
        if (i == 1)
            put_str("ba\n");
    }
}