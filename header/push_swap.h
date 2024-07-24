/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:19:43 by alaaouar          #+#    #+#             */
/*   Updated: 2024/07/23 13:38:59 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
#define PUSH_SWAP

# include <unistd.h>
# include <stdlib.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct s_list
{
	int				index;
	int				value;
	struct s_list	*next;
}					t_list;

t_list		*find_biggest(t_list *a);
t_list		*list_new(int val, unsigned int index, t_list *next);
t_list		*list_create(char **target);
t_list		*parse(char **av);
t_list		*list_create(char **target);
t_list		*list_new(int val, unsigned int index, t_list *next);
int			ft_isdigit(int c);
char		**ft_split(char const *s, char c);
char		*str_join(char **s1);
long		ft_atol(char *nptr);
void		ft_lstclear(t_list **lst);
int			repeted_number(t_list *list);
int			is_sorted(t_list *lst);
int 		check1_digit(char **str);
int			checker(char **av);
void		check_space(char **av);
void		error(void);
void		free_split(char **s1);
void		displayList(t_list *head);
int			ft_strlen(char *str);
size_t		aloc_size(char **av);
char		*str_join(char **s1);
char		**ft_split(char const *s, char c);
int			list_size(t_list *lst);
int			*bubble_sort(t_list **stack);
int			ft_isdigit(int c);
int 		check1_digit(char **str);
int			push_swap(t_list **a, t_list **b);
int			sort_2(t_list **stack_a);
int			sort_3(t_list **a);
int			sort_4(t_list **stack_a, t_list **stack_b);
int			sort_5(t_list **stack_a, t_list **stack_b);
int			stack_sorted(t_list **stack);
int			push_min_to_b(t_list **stack_a, t_list **stack_b);
int			update_index(t_list **stack);
int			push_min_to_b_5(t_list **stack_a, t_list **stack_b);
int			*covert_to_arr(t_list **a, int size);
int			ft_swap(t_list **stack);
int			ft_push(t_list **stack1, t_list **stack2);
int			ft_rotate(t_list **stack);
int			ft_reverse_rotate(t_list **stack);
int			find_min_index(t_list **stack);
void		push_biggest_to_top(t_list **b, int *arr);
void		ft_lstclear(t_list **lst);
void		push_to_a(t_list **a, t_list **b, int *arr, int size);
void		give_value(int *step, int *i);
void		sa(t_list **stack_a);
void		sb(t_list **stack_b);
void		ss(t_list **stack_a, t_list **stack_b);
void		pa(t_list **stack_a, t_list **stack_b);
void		pb(t_list **stack_a, t_list **stack_b);
void		ra(t_list **stack_a);
void		rb(t_list **stack_b);
void		rr(t_list **stack_a, t_list **stack_b);
void		rra(t_list **stack_a);
void		rrb(t_list **stack_b);
void		rrr(t_list **stack_a, t_list **stack_b);
void		sort_list(t_list **a, t_list **b);

#endif