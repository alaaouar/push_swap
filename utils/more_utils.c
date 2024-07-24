/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:19:43 by alaaouar          #+#    #+#             */
/*   Updated: 2024/07/23 13:38:59 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*current;
	t_list	*nxt;

	if (!lst)
		return ;
	current = *lst;
	while (current)
	{
		nxt = current->next;
		free(current);
		current = nxt;
	}
	*lst = NULL;
}

t_list	*list_create(char **target)
{
	t_list	*list;
	t_list	*tmp;
	t_list	*head;
	int		i;

	i = 0;
	list = list_new(ft_atol(target[i]), i, NULL);
	if (!list)
		return (NULL);
	head = list;
	i++;
	while (target[i])
	{
		tmp = list_new(ft_atol(target[i]), i, NULL);
		if (!tmp)
			return (ft_lstclear(&head), NULL);
		list->next = tmp;
		list = tmp;
		i++;
	}
	return (head);
}

t_list	*list_new(int val, unsigned int index, t_list *next)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->index = index;
	list->value = val;
	list->next = next;
	return (list);
}

int	repeted_number(t_list *list)
{
	int		target;
	t_list	*tmp;

	while (list)
	{
		target = list->value;
		tmp = list->next;
		while (tmp)
		{
			if (target == tmp->value)
				return (1);
			tmp = tmp->next;
		}
		list = list->next;
	}
	return (0);
}

int	is_sorted(t_list *lst)
{
	t_list *sort;
	t_list *sort_next;

	sort = lst;
	sort_next = lst->next;
	while (sort->next)
	{
		if (sort->value > sort_next->value)
			return (0);
		sort_next = sort_next->next;
		sort = sort->next;
	}
	return (1);
}