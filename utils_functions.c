#include "push_swap.h"

void put_str(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        write(1, &str[i], 1);
        i++;
    }
}

void sort_2_nmr(t_stack *s)
{
    if (s->value > s->next->value)
        sa(s, 1);
}

void sort_3_nmr(t_stack **s)
{
    if ((*s)->value > (*s)->next->value && (*s)->value > (*s)->next->next->value)
        ra(s, 1);
    else if ((*s)->next->value > (*s)->value && (*s)->next->value > (*s)->next->next->value)
        rra(s, 1);
    if ((*s)->value > (*s)->next->value)
        sa(*s, 1);
    else
        return ;
}