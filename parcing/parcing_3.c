/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 10:27:46 by alaaouar          #+#    #+#             */
/*   Updated: 2024/07/22 10:59:26 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/push_swap.h"

t_stack *find_last_node(t_stack *head)
{
    if (head == NULL)
        return (NULL);
    while (head->next)
        head = head->next;
    return (head);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (NULL == stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	error_free(t_stack **a, char **argv, bool flag)
{
	free_stack(a);
	if (flag)
		free_strs(argv);
	write(2, "Error\n", 6);
	exit(1);
}
