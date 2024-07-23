/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:19:43 by alaaouar          #+#    #+#             */
/*   Updated: 2024/07/23 13:38:59 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	sort_2(t_list **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
	return (0);
}

int	sort_3(t_list **a)
{
	if (stack_sorted(a) == 1)
		return (0);
	if ((*a)->value > (*a)->next->value
		&& (*a)->value > (*a)->next->next->value)
	{
		ra(a);
		if ((*a)->value > (*a)->next->value)
			sa(a);
	}
	else if ((*a)->value > (*a)->next->value
		&& (*a)->value < (*a)->next->next->value)
		sa(a);
	else if ((*a)->value < (*a)->next->value
		&& (*a)->value > (*a)->next->next->value)
		rra(a);
	else if ((*a)->value < (*a)->next->value
		&& (*a)->value < (*a)->next->next->value)
	{
		rra(a);
		if ((*a)->value > (*a)->next->value)
			sa(a);
	}
	return (1);
}

int	sort_4(t_list **stack_a, t_list **stack_b)
{
	if (stack_sorted(stack_a) == 1)
		return (0);
	if (push_min_to_b(stack_a, stack_b) == 1)
		return (0);
	sort_3(stack_a);
	pa(stack_a, stack_b);
	if (update_index(stack_a) == 1)
		return (0);
	return (1);
}

int	sort_5(t_list **stack_a, t_list **stack_b)
{
	if (push_min_to_b_5(stack_a, stack_b) == 1)
		return (0);
	update_index(stack_a);
	sort_4(stack_a, stack_b);
	pa(stack_a, stack_b);
	if (update_index(stack_a) == 1)
		return (0);
	return (1);
}
int	find_min_index(t_list **stack)
{
	t_list	*temp;
	int		min;
	int		index;

	temp = *stack;
	min = temp -> value;
	index = 0;
	while (temp)
	{
		if (temp -> value < min)
		{
			min = temp -> value;
			index = temp -> index;
		}
		temp = temp -> next;
	}
	return (index);
}

int	push_min_to_b_5(t_list **a, t_list **b)
{
	int	min_index;

	if (!(*a))
		return (1);
	min_index = find_min_index(a);
	if (min_index == 1)
		sa(a);
	else if (min_index == 2)
	{
		ra(a);
		sa(a);
	}
	else if (min_index == 3)
	{
		rra(a);
		rra(a);
	}
	else if (min_index == 4)
		rra(a);
	pb(a, b);
	return (0);
}

int	*covert_to_arr(t_list **a, int size)
{
	int		*arr;
	int		i;
	t_list	*temp;

	temp = *a;
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		arr[i] = temp->value;
		i++;
		temp = temp->next;
	}
	return (arr);
}
