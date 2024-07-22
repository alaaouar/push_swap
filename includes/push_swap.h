/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 10:18:06 by alaaouar          #+#    #+#             */
/*   Updated: 2024/07/22 12:21:19 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
# include <stdbool.h>
#include "../libft/libft.h"
#include <stdio.h>


typedef struct n_list
{
	int				content;
	int				index;
	struct n_list	*prev;
	struct n_list	*next;
}					t_stack;

int					ft_swap(t_stack **stack);
long long			ft_atol(char *str);

int					ft_push(t_stack **stack1, t_stack **stack2);
int					ft_rotate(t_stack **stack);
int					ft_reverse_rotate(t_stack **stack);
int					sort_2(t_stack **stack_a);
int					sort_3(t_stack **a);
int					sort_4(t_stack **stack_a, t_stack **stack_b);
int					sort_5(t_stack **stack_a, t_stack **stack_b);
int					update_index(t_stack **stack);
int					find_min_index(t_stack **stack);
int					push_min_to_b(t_stack **a, t_stack **b);
int					push_min_to_b_5(t_stack **a, t_stack **b);

void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);

int					duplicate_error(t_stack *a, long nbr);
t_stack				*find_last_node(t_stack *head);
void				free_stack(t_stack **stack);
void				error_free(t_stack **a, char **argv, bool flag);
void				node_helper(t_stack **stack, int nbr);
void				stack_init(t_stack **a, char *av, bool flag);
char				**free_strs(char **strs);
void				add_node_to_list(t_stack **list, t_stack *stack, int index);
int					*covert_to_arr(t_stack **a, int size);
t_stack				*create_node(int content);
int					list_size(t_stack **stack);
int					*bubble_sort(t_stack **stack);
void				helper_func(const char *str, int *index, int *sign);

#endif
