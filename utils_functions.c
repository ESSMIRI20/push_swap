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

void sort_3_nmr(t_stack *s)
{
    int a;
    int b;
    int c;

    a = s->value;
    b = s->next->value;
    c = s->next->next->value;
    if (a > b && b > c)
        ra(&s, 1);
    else if (b > a && b > c)
        rra(&s, 1);
    if (a > b)
        sa(s, 1);
    else
        return ;
}