#include "push_swap.h"

// void	ft_lstadd_front(t_stack **lst, int value)
// {
// 	t_stack	*new_node;

// 	new_node = (t_stack *)malloc(sizeof(t_stack));
// 	if (!new_node)
// 		return;
// 	new_node->value = value;
// 	new_node->next = *lst;
// 	*lst = new_node;
// }

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
    {
        *lst = new_node;
    }
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
     i++;
    // while (i < ac)
    // {
    check_int(&a, av[1]);
     check_int(&b, av[2]);
    //     i++;
    //}
        ss(a, b);
        while (a)
        {
            printf("%d ", a->value);
            a = a->next;
        }
        printf("\n");
        while (b)
        {
            printf("%d ", b->value);
            b = b->next;
        }
    ac = 7;
    return 0;
}