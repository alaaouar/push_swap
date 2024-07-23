/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:19:43 by alaaouar          #+#    #+#             */
/*   Updated: 2024/07/23 13:38:59 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

t_list *parse(char **av)
{
	char *str;
	char **arr;
	t_list	*stack;
	
    if (check1_digit(av))
		error();
	str = str_join(av);
	arr = ft_split(str, ' ');
	if (!check1_digit(arr))
	{
		free_split(arr);
		error();
	}
	free(str);
	if (!arr)
		return (NULL);
	stack = list_create(arr);
	if (!stack)
		ft_lstclear(&stack);
	free_split(arr);
	return (stack);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
    
	if (ac <= 1)
		return (0);
    stack_b = NULL;
    stack_a = parse(av);
	if (repeted_number(stack_a))
	{
		ft_lstclear(&stack_a);
		error();
	}
	if (is_sorted(stack_a))
		return (ft_lstclear(&stack_a), 0);
    push_swap(&stack_a, &stack_b);
    ft_lstclear(&stack_a);
    ft_lstclear(&stack_b);
	return (0);
}