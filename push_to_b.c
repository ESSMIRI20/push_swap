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

void set_index(t_stack **stack)
{
    int i;
    int i2;
    t_stack *tmp;
    t_stack *tmp2;

    tmp = *stack;
    i2 = 0;
    while (tmp)
    {
        i = 0;
        tmp2 = *stack;
        while (tmp2)
        {
            if (tmp->value > tmp2->value)
                i++;
            tmp2 = tmp2->next;
        }
        tmp->rank = i;
        tmp->index = i2;
        tmp = tmp->next;
        i2++;
    }
}

void push_to_b(t_stack **a, t_stack **b)
{
    int len;
    int count;
    
    len = len_stack(*a);

    set_index(a);
    count = len;
    while (len > 3)
    {
        if ((*a)->rank < count - 3) {
            len--;
            pb(a, b);
        }
        if (len > 3 && !((*a)->rank < count - 3))
            ra(a, 1);
    }
    push_three(a);
}

void push_three(t_stack **a)
{
    int size;

    size = len_stack(*a);
    if (size == 1)
        return ;
    else if (size == 2)
        sort_2_nmr(*a);
    else if (size == 3)
        sort_3_nmr(a);
}