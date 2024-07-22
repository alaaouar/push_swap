/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 10:53:55 by alaaouar          #+#    #+#             */
/*   Updated: 2024/07/22 12:35:01 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	list_size(t_stack **stack)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = *stack;
	while (temp)
	{
		i++;
		temp = temp -> next;
	}
	return (i);
}
void	give_value(int *step, int *i)
{
	*step = 0;
	*i = 0;
}

int	*bubble_sort(t_stack **stack)
{
	int	*sorted;
	int	step;
	int	i;
	int	tmp;
	int	len;

	len = list_size(stack);
	sorted = covert_to_arr(stack, list_size(stack));
	give_value(&step, &i);
	while (step < len - 1)
	{
		i = 0;
		while (i < len - step - 1)
		{
			if (sorted[i] > sorted[i + 1])
			{
				tmp = sorted[i];
				sorted[i] = sorted[i + 1];
				sorted[i + 1] = tmp;
			}
			i++;
		}
		step++;
	}
	return (sorted);
}

void	helper_func(const char *str, int *index, int *sign)
{
	while (str[*index] == ' '
		|| (str[*index] >= '\t' && str[*index] <= '\r'))
		(*index)++;
	if (str[*index] == '-'
		&& (str[*index + 1] >= '0' && str[*index + 1] <= '9'))
	{
		(*sign) *= -1;
		(*index)++;
	}
	if (str[*index] == '+'
		&& (str[*index + 1] >= '0' && str[*index + 1] <= '9'))
		(*index)++;
}

long long	ft_atol(char *str)
{
	int			index;
	long long	results;
	int			sign;

	index = 0;
	results = 0;
	sign = 1;
	helper_func(str, &index, &sign);
	while (str[index])
	{
		if (str[index] >= '0' && str[index] <= '9')
			results = (results * 10) + (str[index] - '0');
		else
			break ;
		if ((results > 2147483648 && sign == -1)
			|| (results > 2147483647 && sign == 1))
			return (results * sign);
		index++;
	}
	return (results * sign);
}

void	ft_lstdelone(t_stack *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst -> content);
	free(lst);
}

void	ft_lstclear(t_stack **lst, void (*del)(void *))
{
	t_stack	*temp;
	t_stack	*n;

	n = *lst;
	if (!del || !lst)
		return ;
	while (n)
	{
		temp = n -> next;
		ft_lstdelone(n, del);
		n = temp;
	}
	*lst = NULL;
}

t_stack	*stack_fill(char **argv)
{
	int		i;
	t_stack	*stack;
	t_stack	*head;

	i = ft_strlen(*argv) - 1;
	stack = NULL;
	head = NULL;
	while (i >= 0)
	{
		stack = create_node(ft_atol(argv[i]));
		if (!stack)
		{
			ft_listclear(&head);
			return (NULL);
		}
		add_node_to_list(&head, stack, i);
		i--;
	}
	return (head);
}