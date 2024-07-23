/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 23:46:05 by alaaouar          #+#    #+#             */
/*   Updated: 2024/07/23 14:57:08 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
void displayList(t_list *head) {
    t_list *current = head;

    printf("Linked List:\n");
    while (current != NULL) {
        printf("[%d, %d] -> ", current->index, current->value);
        current = current->next;
    }
    printf("NULL\n");
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
	displayList(stack_a);
    push_swap(&stack_a, &stack_b);
	displayList(stack_a);
    ft_lstclear(&stack_a);
    ft_lstclear(&stack_b);
	return (0);
}