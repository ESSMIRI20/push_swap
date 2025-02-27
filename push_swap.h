#ifndef  PUSH_SWAP_H
#define  PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_stack
{
    int value;
    struct s_stack  *next;
}t_stack;

char    **ft_split(char const *s, char c);
int     ft_atoi(char *s);
void check_int(t_stack **stack, char *s);
void    put_str(char *str);
void	ft_lstadd_back(t_stack **lst, int value);
void    sa(t_stack *a, int i);
void    sb(t_stack *b, int i);
void    ss(t_stack *a, t_stack *b);
void    pa(t_stack **a, t_stack **b);
void    pb(t_stack **a, t_stack **b);
void    ra(t_stack **a, int i);
void    rb(t_stack **b, int i);
void    rr(t_stack **a, t_stack **b);
void    rra(t_stack **a, int i);
void    rrb(t_stack **b, int i);
void    rrr(t_stack **a, t_stack **b);

#endif