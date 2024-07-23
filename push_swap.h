/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 23:46:19 by alaaouar          #+#    #+#             */
/*   Updated: 2024/07/23 14:56:10 by alaaouar         ###   ########.fr       */
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
//		utils
int			ft_isdigit(int c);
char		**ft_split(char const *s, char c);
char		*str_join(char **s1);
long		ft_atol(const char *nptr);
void		ft_lstclear(t_list **lst);
t_list		*list_new(int val, unsigned int index, t_list *next);
t_list		*list_create(char **target);
int			repeted_number(t_list *list);
int			is_sorted(t_list *lst);
int 		check1_digit(char **str);
void		check_space(char **av);
void		error(void);
void		free_split(char **s1);
//		main
t_list		*parse(char **av);
void		displayList(t_list *head);
//		utils_1
int			ft_strlen(char *str);
size_t		aloc_size(char **av);
//		more_utils
void		ft_lstclear(t_list **lst);
t_list		*list_create(char **target);
t_list		*list_new(int val, unsigned int index, t_list *next);
int			list_size(t_list *lst);
int			*bubble_sort(t_list **stack);
//		utils_2
int			ft_isdigit(int c);
char		**ft_split(char const *s, char c);
char		*str_join(char **s1);
long		ft_atol(const char *nptr);
int 		check1_digit(char **str);

//		sort_small
int			push_swap(t_list **a, t_list **b);
int			sort_2(t_list **stack_a);
int			sort_3(t_list **a);
int			sort_4(t_list **stack_a, t_list **stack_b);
int			sort_5(t_list **stack_a, t_list **stack_b);
void		push_to_a(t_list **a, t_list **b, int *arr, int size);
void		push_biggest_to_top(t_list **b, int *arr);
int			stack_sorted(t_list **stack);
int			push_min_to_b(t_list **stack_a, t_list **stack_b);
//		sort_big
int			update_index(t_list **stack);
int			push_min_to_b_5(t_list **stack_a, t_list **stack_b);
t_list		*find_biggest(t_list *a);
int			*covert_to_arr(t_list **a, int size);
// 			instructions
int			ft_swap(t_list **stack);
int			ft_push(t_list **stack1, t_list **stack2);
int			ft_rotate(t_list **stack);
int			ft_reverse_rotate(t_list **stack);
void		give_value(int *step, int *i);
int			find_min_index(t_list **stack);

// 			rules
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


#endif