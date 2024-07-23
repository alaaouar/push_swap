/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaaouar <alaaouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 23:46:05 by alaaouar          #+#    #+#             */
/*   Updated: 2024/07/23 12:27:41 by alaaouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	check_space(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
        j = 0;
		while (av[i][j] == ' ')
			j++;
		if (!av[i][j])
			error();
		i++;
	}
	return ;
}

int	ft_isdigit(int c)
{
	return (c <= 57 && c >= 48);
}

int check1_digit(char **str)
{
	int i = 0;
	int j;
	while(str[i])
	{
		j = 0;
		if (str[i][j] == '-' || str[i][j] == '+')
			j++;
		while(str[i][j])
		{
			if(!(str[i][j] >= '0' && str[i][j] <= '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
void	free_split(char **s1)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		free(s1[i]);
		i++;
	}
	free(s1);
}

t_list *parse(int ac, char **av)
{
	char *str;
	char **arr;
	t_list	*stack;
	
    if (check_digit(ac,av))
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
    char **str;
    
    if (ac >= 2)
    {
        stack_b = NULL;
        stack_a = parse(ac, av);
    }
	if (repeted_number(stack_a))
	{
		ft_lstclear(&stack_a);
		error();
	}
	if (is_sorted(stack_a))
		return (ft_lstclear(&stack_a), 0);
	displayList(stack_a);
    // push_swap(&stack_a, &stack_b);
    // ft_lstclear(&stack_a);
    // ft_lstclear(&stack_b);

	return (0);
}