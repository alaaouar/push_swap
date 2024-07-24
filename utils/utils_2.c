/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:19:43 by alaaouar          #+#    #+#             */
/*   Updated: 2024/07/23 13:38:59 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		return (1);
	}
	return (0);
}

int	checker(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if ((ft_atol(av[i]) > 2147483647) || (ft_atol(av[i]) < -2147483648))
			return (1);
		i++;
	}
	return (0);
}

int	stack_sorted(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	push_min_to_b(t_list **a, t_list **b)
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
		rra(a);
	pb(a, b);
	return (0);
}

int	update_index(t_list **stack)
{
	t_list	*temp;
	int		i;

	i = 0;
	temp = *stack;
	if (!(*stack))
		return (1);
	while (temp)
	{
		temp->index = i;
		i++;
		temp = temp->next;
	}
	return (0);
}
