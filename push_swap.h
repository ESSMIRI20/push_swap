#ifndef  PUSH_SWAP_H
#define  PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> //?
#include <limits.h>

typedef struct s_stack
{
    int value;
    int rank;
    int     index;
    int     cost;
    struct s_stack *target;
    struct s_stack  *next;
}t_stack;

char    **ft_split(char const *s, char c);
int     ft_atoi(char *s);
void    check_int(t_stack **stack, char *s);
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
void    sort_2_nmr(t_stack *s);
void    sort_3_nmr(t_stack **s);
void    check_double_value(t_stack *s);
void    push_three(t_stack **a);
void    set_index(t_stack **stack);
void    push_to_b(t_stack **a, t_stack **b);
void    push_to_a(t_stack **a, t_stack **b);
int     len_stack(t_stack *stack);
void min_value(t_stack **a);
int check_sort(t_stack **s);

#endif