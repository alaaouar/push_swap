/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:48:58 by alaaouar          #+#    #+#             */
/*   Updated: 2024/07/23 14:52:35 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int list_size(t_list *lst)
{
    int count = 0;
    while (lst)
    {
        count++;
        lst = lst->next;
    }
    return count;
}

void	push_helper(t_list **b, int *arr, int *distance)
{
	int	size;

	size = list_size(*b);
	while (*distance)
	{
		if ((*b)->next->value == arr[size - 1])
		{
			sb(b);
			break ;
		}
		rb(b);
		*distance -= 1;
	}
}

void	push_biggest_to_top(t_list **b, int *arr)
{
	int		biggest;
	t_list	*tmp;
	t_list	*tmp2;
	int		distance;

	distance = 0;
	tmp2 = find_biggest(*b);
	tmp = *b;
	biggest = tmp2->value;
	while (tmp->value != biggest)
	{
		distance++;
		tmp = tmp->next;
	}
	if (distance < list_size(*b) / 2)
		push_helper(b, arr, &distance);
	else
	{
		distance = list_size(*b) - distance;
		while (distance != 0)
		{
			rrb(b);
			distance--;
		}
	}
}

t_list	*find_biggest(t_list *a)
{
	t_list	*next;
	t_list	*max;

	max = a;
	while (a->next != NULL)
	{
		next = a->next;
		if (next != NULL && next->value > max->value)
		{
			max = next;
		}
		a = next;
	}
	return (max);
}

int	push_swap(t_list **a, t_list **b)
{
	if (list_size(*a) == 2)
		return (sort_2(a));
	else if (list_size(*a) == 3)
		return (sort_3(a));
	else if (list_size(*a) == 4)
		return (sort_4(a, b));
	else if (list_size(*a) == 5)
		return (sort_5(a, b));
	push_swap(a, b);
	return (0);
}
