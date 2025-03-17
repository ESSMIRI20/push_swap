/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oessmiri <oessmiri@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 12:01:25 by oessmiri          #+#    #+#             */
/*   Updated: 2025/03/17 09:12:33 by oessmiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_stack
{
	int				value;
	int				rank;
	int				index;
	int				cost;
	struct s_stack	*target;
	struct s_stack	*next;
}					t_stack;

char				*ft_strdup(const char *s);
int					ft_strlen(char *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*get_next_line(int fd);
char				*read_file(int fd, char *storage);
char				*extract_line(char *storage);
char				*update_storage(char *storage);
char				**ft_split(char const *s, char c);
long				ft_atoi(char *s);
void				check_int(t_stack **stack, char *s);
void				put_str(char *str);
void				ft_lstadd_back(t_stack **lst, int value);
void				sa(t_stack *a, int i);
void				sb(t_stack *b, int i);
void				ss(t_stack *a, t_stack *b, int i);
void				pa(t_stack **a, t_stack **b, int i);
void				pb(t_stack **a, t_stack **b, int i);
void				ra(t_stack **a, int i);
void				rb(t_stack **b, int i);
void				rr(t_stack **a, t_stack **b, int i);
void				rra(t_stack **a, int i);
void				rrb(t_stack **b, int i);
void				rrr(t_stack **a, t_stack **b, int i);
int					check_double_value(t_stack *s);
void				set_index(t_stack **stack);
int					len_stack(t_stack *stack);
int					check_sort(t_stack **s);
void				check_int(t_stack **stack, char *s);
int					ft_strcmp(char *s1, char *s2);
void				free_ft(t_stack *s);
int					count_words(const char *s, char c);
void				ft_free(char **result, int i);

#endif
