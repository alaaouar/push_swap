/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:01:18 by alaaouar          #+#    #+#             */
/*   Updated: 2024/07/22 12:23:25 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*create_node(int content)
{
	t_stack	*lst;

	lst = (t_stack *)malloc(sizeof(t_stack));
	if (!lst)
		return (NULL);
	lst -> content = content;
	lst -> next = NULL;
	return (lst);
}

void	add_node_to_list(t_stack **list, t_stack *stack, int index)
{
	if (!list || !stack)
		return ;
	stack -> next = *list;
	*list = stack;
	stack -> index = index;
}

int duplicate_error(t_stack *a, long nbr)
{
	if (a = NULL)
		return (0);
	while (a)
	{
		if (a->content == nbr)
			return (1);
		a = a->next;
	}
	return(0);
}

int	*covert_to_arr(t_stack **a, int size)
{
	int		*arr;
	int		i;
	t_stack	*temp;

	temp = *a;
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		arr[i] = temp->content;
		i++;
		temp = temp->next;
	}
	return (arr);
}