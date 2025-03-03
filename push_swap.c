#include "push_swap.h"

void check_double_value(t_stack *s)
{
    t_stack *node;
    while (s->next)
    {
        node = s->next;
        while (node)
        {
            if (s->value == node->value)
            {
                put_str("Error\n");
                exit(1); 
            }
            node = node->next;
        }
        s = s->next;
    }
}

void ft_lstadd_back(t_stack **lst, int value)
{
    t_stack *node;
    t_stack *new_node;

    if (!lst)
        return ;
    
    new_node = (t_stack *)malloc(sizeof(t_stack));
    if (!new_node)
        return ;
    new_node->value = value;
    new_node->next = NULL;

    if (*lst == NULL)
        *lst = new_node;
    else
    {
        node = *lst;
        while (node->next)
            node = node->next;
        node->next = new_node;
    }
}

int main(int ac, char **av)
{
     int i = 1;
    t_stack *a = NULL;
    t_stack *b = NULL;

    while (i < ac)
    {
        check_int(&a, av[i]);
        i++;
    }
    if (check_sort(&a) == 0)
    {
        push_to_b(&a, &b);
       push_to_a(&a, &b);
       min_value(&a);
    }
        int print = 0;
        while (print && a)
        {
            dprintf(2, "%d  ", a->value);
            a = a->next;
        }
        dprintf(2, "\n");
         while (print && b)
        {
            dprintf(2, "%d  ", b->value);
            b = b->next;
        }
    ac = 7;
    return 0;
}