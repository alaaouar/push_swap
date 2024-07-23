/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:19:43 by alaaouar          #+#    #+#             */
/*   Updated: 2024/07/23 13:38:59 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	get_range(t_list **a)
{
	int	size;
	int	range;

	size = list_size(*a);
	if (size >= 6 && size <= 18)
		range = 3;
	else if (size <= 100)
		range = 15;
	else if (size <= 500)
		range = 45;
	else
		range = 50;
	return (range);
}

void	sort_helper(int *i, int *range, t_list **b, int size)
{
	if (list_size(*b) > 1)
		rb(b);
	if (*i < *range)
		*i += 1;
	if (*range < size - 1)
		*range += 1;
}

void	sort_helper2(int *i, int *range, t_list **b, int size)
{
	if (list_size(*b) > 1 && ((*b)->next->value > (*b)->value))
		sb(b);
	if (*i < *range)
		*i += 1;
	if (*range < size - 1)
		*range += 1;
}

void	sort_list(t_list **a, t_list **b)
{
    int		*arr;
	int		i;
	int		range;
	int		size;

	size = list_size(*a);
	arr = bubble_sort(a);
	range = get_range(a);
	i = 0;
	while ((*a))
	{
		if ((*a)->value <= arr[i])
		{
			pb(a, b);
			sort_helper(&i, &range, b, size);
		}
		else if ((*a)->value <= arr[range])
		{
			pb(a, b);
			sort_helper2(&i, &range, b, size);
		}
		else
			ra(a);
	}
	push_to_a(a, b, arr, size - 1);
}

void	push_to_a(t_list **a, t_list **b, int *arr, int size)
{
	while ((*b))
	{
		if ((*b)->value == arr[size])
		{
			pa(a, b);
			size--;
		}
		else if ((*b)-> next && (*b)->next->value == arr[size])
			sb(b);
		else
			push_biggest_to_top(b, arr);
	}
	free(arr);
}
void	give_value(int *step, int *i)
{
	*step = 0;
	*i = 0;
}